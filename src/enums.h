/* 
 * File:   enums.h
 * Author: ubuntu
 *
 * Created on 29 mars 2011, 03:01
 */

#ifndef ENUMS_H
#define	ENUMS_H

#include <string>

using namespace std;

/**
 * Nombre de dictionnaires activés
 */
int const NB_ALGOS = 9;

/**
 * Dictionnaires activés
 */
enum DICOS {
    DICO_SUM,
    DICO_CK,
    DICO_MD5,
    DICO_SHA1,
    DICO_SHA224,
    DICO_SHA256,
    DICO_SHA384,
    DICO_SHA512,
    DICO_MD5MAISON
};

/**
 * Taille des empreintes générées par les différents dictionnaire
 */
int const TAILLES_ALGOS[] = {
    5,
    9,
    32,
    40,
    56,
    64,
    96,
    128,
    -1
};

/**
 * Sortie d'enregistrement possibles
 */
enum SORTIES {
    SORTIE_VIDE,
    SORTIE_FICHIER,
    SORTIE_REDIS
};

/**
 * Ordres transmis entre observer(ui)/observable(moteur)
 */
enum ORDRES {
    ORDRE_MOTEUR_PRET,
    ORDRE_SORTIE_OK,
    ORDRE_SORTIE_ERREUR,
    ORDRE_CALCULATEUR_PRET,
    ORDRE_PREMIERE_CHAINE,
    ORDRE_DEBUT_CONNEXION,
    ORDRE_MAJ_VITESSE,
    ORDRE_MAJ_CHAINE,
    ORDRE_DEMANDE_ARRET,
    ORDRE_ARRET
};

/**
 * Structures utilisée pour récupérer des informations sur le moteur
 *  à partir de l'UI, dans l'objectif d'afficher les benchs
 */
struct structBenchRes {
    string chaine;          // Dernière chaine
    unsigned long nb;       // Nombre de calculs effectués durant ce cycle
    unsigned long total;    // Nombre de calculs total effectués
    bool ordre_fin;         // Etat du moteur ?
};


#endif	/* ENUMS_H */

