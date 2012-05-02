/* 
 * Classe :   CleValeur
 * Objectif :
 */

#include "CleValeur.h"

CleValeur::CleValeur(string cle, string valeur) {
    this->cle = cle;
    this->valeur = valeur;
}

// Entrée 
ostream &operator<<(ostream &stream, const CleValeur &ob) {
    stream << ob.cle << "\t" << ob.valeur;
}

// Sorties
istream &operator>>(istream &stream, CleValeur &ob) {
    stream >> ob.cle >> ob.valeur;
    return stream;
}

