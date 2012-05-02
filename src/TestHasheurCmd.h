#ifndef TESTHASHEURCMD_H
#define	TESTHASHEURCMD_H

#include "cpptest/cpptest.h"
#include "HasheurCmd.h"

/**
 * Classe de test sur les fonctions de hash Linux
 */
class TestHasheurCmd : public Test::Suite {
public:
    /**
     * Initialisation et lancement des tests
     */
    TestHasheurCmd();
    
private:
    void testHasherCk();
    void testHasherMd5();
    void testHasherSha512();
};

#endif	/* TESTHASHEURCMD_H */

