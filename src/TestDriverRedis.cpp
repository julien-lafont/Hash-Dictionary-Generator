/* 
 * Classe :   TestDriverRedis
 * Objectif :
 */

#include "TestDriverRedis.h"

TestDriverRedis::TestDriverRedis() {
    TEST_ADD(TestDriverRedis::testConnexion);
    TEST_ADD(TestDriverRedis::testAddGetExist);
    TEST_ADD(TestDriverRedis::testSets);
}

void TestDriverRedis::testAddGetExist() {
    Redis r("localhost", REDIS_DEFAULT_PORT, false);
    if (!r.estConnecte()) return;
    r.setDb(9);     // DB non utilisé par les dictionnaires
    r.flushDb(9);   // Vide la table au début du test
    

    TEST_ASSERT(r.add("TESTA", "RESA")==true);
    TEST_ASSERT(r.add("testB", "resB")==true);

    TEST_ASSERT(r.exist("TESTA")==true);
    TEST_ASSERT(r.exist("testB")==true);
    TEST_ASSERT(r.exist("TESTB")==false);
    TEST_ASSERT(r.exist("Rien")==false);

    TEST_ASSERT(r.get("TESTA").compare("RESA")==0);
    TEST_ASSERT(r.get("testB").compare("resB")==0);
    TEST_ASSERT(r.get("Rien").empty());

    r.flushDb(9);   // Remet à l'état initial
    r.deconnexion();
}

void TestDriverRedis::testConnexion() {
    Redis r("localhost", REDIS_DEFAULT_PORT, false);
    TEST_ASSERT(r.estConnecte() == true);
    TEST_ASSERT(r.ping()==true);

    r.deconnexion();
    TEST_ASSERT(r.estConnecte()==false);
    TEST_ASSERT(r.ping()==false);

    r.connexion("localhost", REDIS_DEFAULT_PORT);
    TEST_ASSERT(r.estConnecte() == true);
    TEST_ASSERT(r.ping()==true);

    r.deconnexion();
    TEST_ASSERT(r.estConnecte()==false);
    TEST_ASSERT(r.ping()==false);

}

void TestDriverRedis::testSets() {
    Redis r("localhost", REDIS_DEFAULT_PORT, false);
    if (!r.estConnecte()) return;
    r.setDb(9);     // DB non utilisé par les dictionnaires
    r.flushDb(9);   // Vide la table au début du test
    
    TEST_ASSERT(r.setAdd("setA", "valA")==true);
    TEST_ASSERT(r.setAdd("setA", "valB")==true);

    TEST_ASSERT(r.setExist("setA", "valA")==true);
    TEST_ASSERT(r.setExist("setA", "valC")==false);
    TEST_ASSERT(r.setExist("setB", "valA")==false);

    TEST_ASSERT(r.setNb("setA")==2);
    TEST_ASSERT(r.setNb("setB")==0);

    string res1(r.setPop("setA"));
    TEST_ASSERT(res1.compare("valA")==0 || res1.compare("valB")==0);
    string res2(r.setPop("setA"));
    TEST_ASSERT((res2.compare("valA")==0 || res2.compare("valB")==0) && res1.compare(res2)!=0);

    TEST_ASSERT(r.setNb("setA")==0);

    r.flushDb(9);   // Remet à l'état initial
    r.deconnexion();
}

