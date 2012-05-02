#include "TestBruteForce.h"

TestBruteForce::TestBruteForce() {
        TEST_ADD(TestBruteForce::testBruteNextChaine);
        TEST_ADD(TestBruteForce::testCalculerIteration);
}

void TestBruteForce::testBruteNextChaine() {
    
    TEST_ASSERT(BruteForceUtil::calculerNextChaine("a").compare("b") == 0);
    TEST_ASSERT(BruteForceUtil::calculerNextChaine("aa").compare("ab") == 0);
    TEST_ASSERT(BruteForceUtil::calculerNextChaine("z").compare("aa") == 0);
    TEST_ASSERT(BruteForceUtil::calculerNextChaine("az").compare("ba") == 0);
    TEST_ASSERT(BruteForceUtil::calculerNextChaine("aaa").compare("aab") == 0);
    TEST_ASSERT(BruteForceUtil::calculerNextChaine("aaz").compare("aba") == 0);
    TEST_ASSERT(BruteForceUtil::calculerNextChaine("aza").compare("azb") == 0);
    TEST_ASSERT(BruteForceUtil::calculerNextChaine("azz").compare("baa") == 0);
    TEST_ASSERT(BruteForceUtil::calculerNextChaine("zzzz").compare("aaaaa") == 0);

}

void TestBruteForce::testCalculerIteration() {
    
    TEST_ASSERT(BruteForceUtil::calculerIteration("a",1).compare("b") == 0);
    TEST_ASSERT(BruteForceUtil::calculerIteration("a",2).compare("c") == 0);
    TEST_ASSERT(BruteForceUtil::calculerIteration("a",9).compare("j") == 0);
    TEST_ASSERT(BruteForceUtil::calculerIteration("a",20).compare("u") == 0);
    TEST_ASSERT(BruteForceUtil::calculerIteration("a",30).compare("ae") == 0);
    TEST_ASSERT(BruteForceUtil::calculerIteration("a",40).compare("ao") == 0);
}
