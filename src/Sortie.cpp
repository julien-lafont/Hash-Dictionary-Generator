/* 
 * Classe :   Sortie
 * Objectif :
 */

#include "Sortie.h"
#include "Log.h"
#include "SortieNull.h"
#include "SortieRedis.h"
#include "SortieFichier.h"

Sortie::~Sortie() {
}

void Sortie::fermer() {
}

Sortie* Sortie::genererSortie(SORTIES sortie) {
    switch(sortie) {
        case SORTIE_VIDE:
            return new SortieNull();
        break;
        case SORTIE_REDIS:
            return new SortieRedis();
        break;
        case SORTIE_FICHIER:
            return new SortieFichier();
        break;
    }
}

