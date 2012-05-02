/* 
 * Classe :   BruteForceUtil
 * Objectif :
 */

#include "BruteForceUtil.h"

string BruteForceUtil::calculerNextChaine(string chaine) {
    
    int taille = chaine.size();

    bool up=false;  // Tant qu'on a pas fini
    for (int i=taille-1; i>=0 && !up; i--) {
        if (chaine[i]!='z') { 
            chaine[i]++;
            up=true;    // On a augmenté une lettre, c'est fini
        } else { // On doit regarder la lettre suivante
            chaine[i]='a';
            
            // Si on est à la fin, on doit agrandir la zone de mémoire réservée
            if (i==0) {
                chaine.insert(0, "a");
            }
        }
        
    }

    return chaine;

}

/**
 * Retourne la chaine qui sera obtenue après N passe d'un anglorithme de bruteforce
 * @param depart Chaine de départ (incluse dans le comptage)
 * @param nb Nombre de passe à effectuer
 * @return Chaine suivante (exclu du comptage)
 * @todo    Ameliorer l'algorithme (prédictif)
 */
string BruteForceUtil::calculerIteration(string depart, int nb) {
    if (nb>0)   return calculerIteration(calculerNextChaine(depart), --nb);
    else        return depart;
    
}
