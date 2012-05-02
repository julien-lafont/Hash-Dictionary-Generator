/* 
 * Classe :   Moteur
 * Objectif :
 */

#include "Moteur.h"
#include "Calculateur.h"

void *ThreadStart(void *objetEnvoye) {
    Calculateur *c = (Calculateur *)objetEnvoye;
    c->run();
    return (NULL);
}


Moteur::Moteur()  {
   
   // Mutex génération de la chaine
   pthread_mutex_t _mutex_generation_chaine;
   if (pthread_mutex_init(&_mutex_generation_chaine, NULL)!=0) {
       Log::error("Impossible d'initialiser le mutex de generation");
       exit(EXIT_FAILURE);
   }
   
   // Mutex enregistrement des données
   pthread_mutex_t _mutex_enregistrement;
   if (pthread_mutex_init(&_mutex_enregistrement, NULL)!=0) {
       Log::error("Impossible d'initialiser le mutex de generation");
       exit(EXIT_FAILURE);
   }

}

Moteur::~Moteur() {
    pthread_mutex_destroy(&_mutex_generation_chaine);
    pthread_mutex_destroy(&_mutex_enregistrement);
    delete _sortie;
}


void Moteur::init(DICOS dico, int nb_threads, SORTIES sortie, bool reinit) {
    
    _terminer = false;
    
    // Ouvrir la sortie appropriée
    _sortie = Sortie::genererSortie(sortie);
    bool sortie_valide = _sortie->estValide();
    Notify(sortie_valide ? ORDRE_SORTIE_OK : ORDRE_SORTIE_ERREUR, "");

    if (sortie_valide)
    {
        // Configuration du nombre de threads
        _nb_threads = nb_threads;

        // Gestion du dictionnaire à utiliser
        _dico = dico;
        _sortie->definirDico(dico);

        // Cas où l'on réinitialise la base de donnée
        if (reinit) {
            _sortie->viderDico(dico);
            _prochaine_chaine = "a";
        }
        // Sinon on doit récupérer la dernière chaine entrée pour continuer les calculs
        else {
            string chaine(_sortie->recupererDerniereCle());
            if (chaine.empty())  _prochaine_chaine = "a";
            else                 _prochaine_chaine = BruteForceUtil::calculerNextChaine(chaine);
            
            Log::info("On recommence les calculs à partir de la chaine : %s", _prochaine_chaine.c_str());
        }

        // On récupère le nbre de calculs par itérations
        _nbCalculsParIteration = (dico==DICO_MD5MAISON) ? MOTEUR_NB_ITERATIONS_MD5NATIF : MOTEUR_NB_ITERATIONS_CMD;

        Notify(ORDRE_PREMIERE_CHAINE, _prochaine_chaine);
    }
    

}


void Moteur::lancerCalculateur(){
    pthread_t threads[_nb_threads];

    Notify(ORDRE_MOTEUR_PRET, "");

    int rc, t;
    for (t=0;t<_nb_threads;t++){

        Calculateur* calcul = new Calculateur(t);
        calcul->init(_dico, _nbCalculsParIteration);

        rc = pthread_create(&threads[t], NULL, ThreadStart, (void *)calcul);
        if (rc<0) {
            Log::error("impossible d'initialiser le thread %d", t);
            exit(-1);
        }
        Log::trace("Thread %d lancé", t);
    }

    Notify(ORDRE_CALCULATEUR_PRET, "");
    
    void *ret;
    for (t=0;t<_nb_threads;t++){
        (void)pthread_join(threads[t], &ret);
         Log::info("Calculateur%d::terminé", t);
    }


    // Fermer proprement la sortie
    _sortie->fermer();

    Log::info("Moteur::Fin");
     
}

string Moteur::genererProchaineChaine(int num) {

    pthread_mutex_lock(&_mutex_generation_chaine);
    
    string aCalculer(_prochaine_chaine);
    
    if (_terminer) {
        _prochaine_chaine.clear();
        aCalculer.clear();
    }
    else  {
        _prochaine_chaine = BruteForceUtil::calculerIteration(_prochaine_chaine, _nbCalculsParIteration);
    }

    bench_chaine = _prochaine_chaine;
    pthread_mutex_unlock(&_mutex_generation_chaine);

    return aCalculer;
}

void Moteur::recupererResultat(int num, queue<CleValeur> *queue) {
    pthread_mutex_lock(&_mutex_enregistrement);

    while (!queue->empty()) {
        const CleValeur cv = queue->front();
        _sortie->ecrire(cv.cle, cv.valeur);
        queue->pop();
    }

    bench_nb += _nbCalculsParIteration;
    bench_total += _nbCalculsParIteration;

    pthread_mutex_unlock(&_mutex_enregistrement);
}

void Moteur::terminerCalculateurs() {
    Log::info("Moteur::OrdreRecuTerminerCalculateurs");
    _terminer = true;
}

void Moteur::getBench(structBenchRes *res) {

    res->chaine = bench_chaine;
    res->nb = bench_nb;
    res->total = bench_total;
    res->ordre_fin = _terminer;

    // Remet à 0 à chaque appel pour calculer la vitesse instantannée
    bench_nb = 0;
}


