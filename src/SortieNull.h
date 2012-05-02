#ifndef SORTIENULL_H
#define	SORTIENULL_H

#include "Sortie.h"
#include <string>

using namespace std;

/**
 * Les clés générés ne sont pas enregistrées
 * Equivalent de la redirection > /dev/null
 */
class SortieNull : public Sortie {
public:

    void ecrire(string cle, string valeur);
    void definirDico(DICOS dico);
    void viderDico(DICOS dico);
    string recupererDerniereCle();
    bool estValide();
    
};

#endif	/* SORTIENULL_H */

