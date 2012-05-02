
#ifndef TESTBRUTEFORCE_H
#define	TESTBRUTEFORCE_H

#include "cpptest/cpptest.h"
#include "BruteForceUtil.h"

/**
 * Classe de test sur l'algorithme de calcul bruteforce
 */
class TestBruteForce : public Test::Suite {
public:
    /**
     * Initialisation et lancement des tests
     */
    TestBruteForce();
private:
    void testBruteNextChaine();
    void testCalculerIteration();
};

#endif	/* TESTBRUTEFORCE_H */

