#ifndef TESTDRIVERREDIS_H
#define	TESTDRIVERREDIS_H

#include "cpptest/cpptest.h"
#include "Redis.h"
#include <string>

using namespace std;

/**
 * Tests unitaires du driver REDIS
 */
class TestDriverRedis : public Test::Suite {
public:
    /**
     * Initialisation et lancement des tests
     */
    TestDriverRedis();
private:
    void testConnexion();
    void testAddGetExist();
    void testSets();

};

#endif	/* TESTDRIVERREDIS_H */

