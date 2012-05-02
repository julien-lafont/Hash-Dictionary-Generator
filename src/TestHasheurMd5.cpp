#include "TestHasheurMd5.h"

TestHasheurMd5::TestHasheurMd5() {
    TEST_ADD(TestHasheurMd5::testHasher);
}

void TestHasheurMd5::testHasher() {

    HasheurMd5 h;

    TEST_ASSERT(h.hasher("a").compare("0cc175b9c0f1b6a831c399e269772661")==0);
    TEST_ASSERT(h.hasher("b").compare("92eb5ffee6ae2fec3ad71c777531578f")==0);
    TEST_ASSERT(h.hasher("aa").compare("4124bc0a9335c27f086f24ba207a4912")==0);
    TEST_ASSERT(h.hasher("abc").compare("900150983cd24fb0d6963f7d28e17f72")==0);
    TEST_ASSERT(h.hasher("abc123").compare("e99a18c428cb38d5f260853678922e03")==0);
    TEST_ASSERT(h.hasher("abc123ABC").compare("baaab6fa3b287456d2ff691027920826")==0);
    TEST_ASSERT(h.hasher("anticonstitutionnellement").compare("99c1c137d8d85917f632a0e34a35a5f7")==0);
}

