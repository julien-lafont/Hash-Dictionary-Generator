#ifndef HASHEURCMD_H
#define	HASHEURCMD_H

#include <string>
#include <cstdio>

#include "Hasheur.h"
#include "enums.h"

using namespace std;

/**
 * Hasheur utilisant les utilitaires GNU du Shell pour calculer les empreintes
 *
 * Fait des appels au shell et récupère le résultat
 *
 * Hasheurs disponibles :
 *  - CK
 *  - CKSUM
 *  - MD5
 *  - SHA1
 *  - SHA224
 *  - SHA256
 *  - SHA384
 *  - SHA512
 *
 * Avantage : Utilise les concepts étudiées en cours
 * 
 * Inconvénients : Très (très très très) lent
 * 
 */
class HasheurCmd : public Hasheur {
public:

    /**
     * Initialise le hasheur avec l'algorithme donnée
     * @param type Algorithme à charger
     */
    void initialiser(DICOS type);
    
    virtual ~HasheurCmd();

 
    /**
     * Hasher une clé
     * @param cle
     * @return empreinte de la clé
     */
    string hasher(const char* cle);

    /**
     * Fermer correctement le hasheur
     */
    void fermer();

private:
    char* _commande;
    int _taille_buffer;
    int _taille_commande;
    static char* _format;

     /**
     * Charge un algorithme précis
     * @param type Algorithme à charger
     */
    void chargerAlgorithme(DICOS type);

    /**
     * Transforme un dico en chaine de caractère (pour affichage)
     * @param _type
     * @return
     */
    char* typeToCommande(DICOS _type);
};

#endif	/* HASHEURCMD_H */
