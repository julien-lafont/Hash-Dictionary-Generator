#ifndef SIGNAUX_H
#define	SIGNAUX_H

#include <cstdlib>
#include <csignal>
#include <cstdio>
#include <iostream>

#include "Log.h"
#include "Singleton.h"
#include "Moteur.h"

using namespace std;

/**
 * Gestion des signaux
 */
class Signaux {
public:

    /**
     * Initialise l'écouteur des signaux
     */
    static void init();

};

#endif	/* SIGNAUX_H */

