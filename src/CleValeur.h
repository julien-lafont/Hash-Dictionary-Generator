#ifndef CLEVALEUR_H
#define	CLEVALEUR_H

#include <string>
#include <ostream>

class Moteur;
class Calculateur;

using namespace std;

/**
 * Classe conteneur permettant d'enregistrée une donnée composée (clé, valeur)
 * @param cle
 * @param valeur
 */
class CleValeur {
public:
    CleValeur(string cle, string valeur);

    friend ostream &operator<<(ostream &stream, const CleValeur &ob);
    friend istream &operator>>(istream &stream, CleValeur &ob);
    friend class Moteur;
    friend class Calculateur;

private:
    string cle;
    string valeur;

};



#endif	/* CLEVALEUR_H */

