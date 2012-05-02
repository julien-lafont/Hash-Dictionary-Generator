/* 
 * Classe :   Hasheur
 * Objectif :
 */

#include "Hasheur.h"



/**
 * Raccourci vers la fonction hasher (chaine de caractère C-like)
 * @param cle
 * @return empreinte de la clé
 */
string Hasheur::hasher(const string cle) {
    return hasher(cle.c_str());
}

void Hasheur::initialiser(DICOS dico) {

}

Hasheur::~Hasheur() {
}

void Hasheur::fermer() {

}
