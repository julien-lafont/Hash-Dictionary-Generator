#ifndef BRUTEFORCEUTIL_H
#define	BRUTEFORCEUTIL_H

#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

/**
 * Utilitaire permettant de générer les chaines de caractères à la manière
 * d'une attaque par brute force
 */
class BruteForceUtil {
public:

    /**
     * Retourne la prochaine chaine alphanumerique dans l'ordre alphabetique
     * @param chaine Chaine de départ
     * @return la chaine suivante dans une méthode par bruteforce
     */
    static string calculerNextChaine(string chaine);


    /**
     * Retourne la chaine qui sera obtenue après N passe d'un anglorithme de bruteforce
     * @param depart Chaine de départ (incluse dans le comptage)
     * @param nb Nombre de passe à effectuer
     * @return Chaine suivante (exclu du comptage)
     */
    static string calculerIteration(string depart, int nb);


};

#endif	/* BRUTEFORCEUTIL_H */

