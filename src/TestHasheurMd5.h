#ifndef TESTHASHEURMD5_H
#define	TESTHASHEURMD5_H

#include "cpptest/cpptest.h"
#include "HasheurMd5.h"

/**
 * Classe de test sur le hasheur natif MD5
 */
class TestHasheurMd5 : public Test::Suite {
public:
    /**
     * Initialisation et lancement des tests
     */
    TestHasheurMd5();
private:
    void testHasher();

};

#endif	/* TESTHASHEURMD5_H */

