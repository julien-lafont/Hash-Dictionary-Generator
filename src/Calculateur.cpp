#include "Moteur.h"
#include "Calculateur.h"


Calculateur::Calculateur(int num) {
    _num = num;
    _actif = true;
    _moteur = Moteur::Get();
    _queue_resultats = new queue<CleValeur>();

    Log::info("Calculateur %d : Creation", _num);
}


void Calculateur::init(DICOS dico, int nbCalculsParIteration){
    _dico = dico;
    _nbCalculsParIteration = nbCalculsParIteration;

    // Initialiser le hasheur
    switch(dico) {
        case DICO_MD5MAISON:
            _hasheur = new HasheurMd5();
        break;
        default:
            _hasheur = new HasheurCmd();
            _hasheur->initialiser(dico);
        break;
    }
}


void Calculateur::setMoteurResponsable(Moteur *mot) {
    _moteur = mot;
}

void Calculateur::run() {

    for(;;) {

        initialiser_cycle();
        if (!verifier_cycle_valide()) break;

        effectuer_cycle();
        
        terminer_cycle();
    }

    pthread_exit((void*)1);
}

bool Calculateur::verifier_cycle_valide() {
    return _chaine_debut.length()>0;
}

void Calculateur::initialiser_cycle() {
    _chaine_debut = _moteur->genererProchaineChaine(_num);
}

void Calculateur::terminer_cycle() {
     _moteur->recupererResultat(_num, _queue_resultats);
}

void Calculateur::effectuer_cycle() {
    Log::trace("Calculateur %d : Nouveau cycle '%s'", _num, _chaine_debut.c_str());

    for (int i=0; i<_nbCalculsParIteration; i++) {

        // Calculer l'empreinte de la chaine
        CleValeur res(_chaine_debut, _hasheur->hasher(_chaine_debut));
        _queue_resultats->push(res);

        // Récupérer la chaine suivante à calculer
        _chaine_debut = BruteForceUtil::calculerNextChaine(_chaine_debut);

    }
}

Calculateur::~Calculateur() {
    // Libérer mémoire
    delete _queue_resultats;
    delete _hasheur;
    delete _moteur;
}

