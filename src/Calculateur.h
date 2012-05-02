#ifndef CALCULATEUR_H
#define	CALCULATEUR_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>

#include "Hasheur.h"
#include "CleValeur.h"
#include "HasheurMd5.h"
#include "HasheurCmd.h"

using namespace std;

/**
 * Thread chargé d'exécuter en boucle des calculs d'empreintes
 * @param num Numéro du thread
 */
class Calculateur {
public:
    Calculateur (int num);
    ~Calculateur ();

    /**
     * Initialiser et configurer le calculateur
     * @param dico
     */
    void init(DICOS dico, int nbCalculsParCycle);

    /**
     * Définir le moteur responsable de ce calculateur
     * (INDISPENSABLE)
     * @param mot
     */
    void setMoteurResponsable(Moteur *mot);

    /**
     * Boucle de fonctionnement du thread
     * Fonctionne tant que le thread ne recoit pas un ordre explicite d'arrêt
     */
    void run();

private:

    // Configuration
    DICOS _dico;                            // Choix du dictionnaire d'empreinte
    bool _actif;                            // Etat du calculateur
    int _num;                               // Numéro du calculateur
    int _nbCalculsParIteration;             // Nombres de calculs par Cycle

    // Calculs
    string _chaine_debut;                   // Chaine à traduire
    queue<CleValeur> *_queue_resultats;     // Liste des résultats en FIFO
    
    // Références
    Hasheur *_hasheur;                      // Hasheur sélectionné
    Moteur *_moteur;                        // Moteur responsable

    // Méthodes
    void initialiser_cycle();
    void terminer_cycle();
    void effectuer_cycle();
    bool verifier_cycle_valide();
   
};

#endif	/* CALCULATEUR_H */

