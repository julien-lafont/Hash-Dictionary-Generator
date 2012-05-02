#ifndef SORTIE_H
#define	SORTIE_H

#include <string>

#include "enums.h"

using namespace std;

/**
 * Sortie générique indiquant comment l'empreinte générée va être enregistrée
 *
 * Enregistrer dans un fichier, dans une base de donnée, ne pas enregistrer, etc...
 *
 */
class Sortie {
public:

    
    /**
     * Ecrire une clé dans le dictionnaire
     * @param cle
     * @param valeur
     */
    virtual void ecrire(string cle, string valeur) = 0;


    /**
     * Sélectionner le dictionnaire
     * @param dico
     */
    virtual void definirDico(DICOS dico)=0;


    /**
     * Vider le dictionnaire
     * @param dico
     */
    virtual void viderDico(DICOS dico)=0;

    /**
     * Récupère la dernière clé enregistrée dans la sortie
     */
    virtual string recupererDerniereCle()=0;

    /**
     * La sortie est-elle valide ?
     */
    virtual bool estValide()=0;

    /**
     * Fermer le dictionnaire
     */
    virtual void fermer();


    /**
     * Génère un objet sortie du type désiré
     * (Pattern Factory)
     * @param sortie
     * @return
     */
    static Sortie* genererSortie(SORTIES sortie);

    
    virtual ~Sortie();
    
};

#endif	/* SORTIE_H */

