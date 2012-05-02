#ifndef HASHEUR_H
#define	HASHEUR_H

#include <iostream>
#include <string>
#include <cstring>

#include "enums.h"

using namespace std;

/**
 * Hasheur générique permettant de générer une empreinte à partir d'une clé
 */
class Hasheur {
public:

    /**
     * Hasher une clé de type char*
     * @param cle
     * @return Empreinte de la clé
     */
    virtual string hasher(const char* cle)=0;



    /**
     * Fermer le hasheur courant (facultatif)
     */
    virtual void fermer();

    /**
     * Initialiser Hasheur (facultatif)
     * @param dico Dictionnaire précier à charger
     */
    virtual void initialiser(DICOS dico);

    /**
     * Destructeur (facultatif)
     */
    virtual ~Hasheur();



    /**
     * Hasher une clé de type String
     * @param cle
     * @return Empreinte de la clé
     */
    string hasher(const string cle);



};

#endif	/* HASHEUR_H */

