/* 
 * Classe :   SortieRedis
 * Objectif :
 */

#include <stdlib.h>

#include "SortieRedis.h"


SortieRedis::SortieRedis() {

    _redis = new Redis("localhost", REDIS_DEFAULT_PORT, false);
   
}

SortieRedis::~SortieRedis() {
    if (_redis != NULL) {
        _redis->deconnexion();
        delete _redis; _redis = NULL;
    }
}

void SortieRedis::ecrire(string cle, string valeur) {
    _redis->setAdd(valeur.c_str(), cle.c_str());
    _derniereCle = cle;
}

void SortieRedis::definirDico(DICOS dico) {
    _redis->setDb(dico);
}

void SortieRedis::fermer() {
    // Enregistre la dernière clé avant de fermer la connexion
    _redis->add("derniereCle", _derniereCle.c_str());
    _redis->deconnexion();
}

void SortieRedis::viderDico(DICOS dico) {
    _redis->flushDb(dico);
}

string SortieRedis::recupererDerniereCle() {
    return _redis->get("derniereCle");
}

bool SortieRedis::estValide() {
    bool res = _redis->ping();
    return res;
}