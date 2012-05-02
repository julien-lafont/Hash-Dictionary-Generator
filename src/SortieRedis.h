#ifndef SORTIEREDIS_H
#define	SORTIEREDIS_H

#include <string>

#include "Redis.h"
#include "Sortie.h"
#include "enums.h"

using namespace std;

/**
 * Enregistrement des empreintes dans une base de donnée REDIS (NoSQL)
 * 
 */
class SortieRedis : public Sortie {
public:
    SortieRedis();
    virtual ~SortieRedis();

    /**
     * Ecriture de la clé et de son empreinte dans la BDD
     * @param cle
     * @param valeur
     */
    void ecrire(string cle, string valeur);

    /**
     * Choisi le dictionnaire en fonction de son ID
     * @param dico
     */
    void definirDico(DICOS dico);

    /**
     * Ferme le dictionnaire
     */
    void fermer();

    /**
     * Vide le dictionnaire
     * @param dico
     */
    void viderDico(DICOS dico);

    /**
     * Récupère la dernière clé enregistrée dans la sortie
     */
    string recupererDerniereCle();

    /**
     * La sortie est-elle valide ?
     */
    bool estValide();
    
private:

    /**
     * Connecteur à la base de donnée Redis
     */
    Redis *_redis;

    /**
     * Dernière clé entrée
     */
    string _derniereCle;

};

#endif	/* SORTIEREDIS_H */

