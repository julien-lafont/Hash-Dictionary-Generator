#ifndef MOTEUR_H
#define	MOTEUR_H

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <cstdlib>

#include "Log.h"
#include "Singleton.h"
#include "enums.h"
#include "BruteForceUtil.h"
#include "BenchmarkUtil.h"
#include "Sortie.h"
#include "CleValeur.h"
#include "SortieNull.h"
#include "SortieFichier.h"
#include "SortieRedis.h"
#include "ObserverObservable.h"


#define MOTEUR_NB_ITERATIONS_MD5NATIF 500
#define MOTEUR_NB_ITERATIONS_CMD 10

using namespace std;

/**
 * Moteur principal du programme en charge de répartir la charge de calcul entre
 * les différents calculateurs, puis d'enregistrer les résultats dans la sortie
 * adéquate
 */
class Moteur : public Singleton<Moteur>, public Observable {
public:
    Moteur();
    virtual ~Moteur();

    /**
     * Initialiser et configurer le moteur
     * @param dico          Dictionnaire utilité pour le calcul des empreintes
     * @param nb_threads    Nombre de threads à utiliser
     * @param sortie        Sur quelle sortie enregistrer les résultats
     * @param reinit        Réinitialiser la base de donnée ?
     */
    void init(DICOS dico, int nb_threads, SORTIES sortie, bool reinit);

    /**
     * Lance les calculateurs
     */
    void lancerCalculateur();

    /**
     * Retourne la prochaine chaine qu'un calculateur devra prendre comme base
     * de calcul
     * @param num : Numéro du calculateur appelant la méthode
     * @return Chaine à utiliser comme base de calcul
     */
    string genererProchaineChaine(int num);

    /**
     * Le calculateur envoie ses résultats de calcul via cette méthode
     * Le moteur va dépiler chaque élément de la queue puis les persister
     * @param num Numéro du calculateur
     * @param queue Liste des résultats fournis par le calculateur
     */
    void recupererResultat(int num, queue<CleValeur> *queue);

    /**
     * Demande aux calculateurs de s'arrêter dés la fin de leur cycle actuel
     */
    void terminerCalculateurs();

    void getBench(structBenchRes *res);

    
private:

    // Configuration
    int _nb_threads;
    DICOS _dico;
    string _prochaine_chaine;
    bool _terminer; // Le moteur doit-il se terminer ?
    int _nbCalculsParIteration;

    // Gestion synchronisation
    pthread_mutex_t _mutex_generation_chaine;
    pthread_mutex_t _mutex_enregistrement;

    // Gestion des bencharks
    string bench_chaine;
    unsigned long bench_nb;
    unsigned long bench_total;

    // Outils
    Sortie *_sortie;

};
#endif /* MOTEUR_H */