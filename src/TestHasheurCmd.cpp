/* 
 * Classe :   TestHasheurCmd
 * Objectif :
 */

#include "TestHasheurCmd.h"
#include "TestHasheurMd5.h"

TestHasheurCmd::TestHasheurCmd() {
    TEST_ADD(TestHasheurCmd::testHasherCk);
    TEST_ADD(TestHasheurCmd::testHasherMd5);
    TEST_ADD(TestHasheurCmd::testHasherSha512);
}

void TestHasheurCmd::testHasherCk() {

    HasheurCmd h;
    h.initialiser(DICO_CK);

    TEST_ASSERT(h.hasher("a").compare("2418082923")==0);
    TEST_ASSERT(h.hasher("b").compare("2454254050")==0);
    TEST_ASSERT(h.hasher("aa").compare("1937200591")==0);
    TEST_ASSERT(h.hasher("abc").compare("1112837078")==0);
    TEST_ASSERT(h.hasher("abc123").compare("1780844725")==0);
    TEST_ASSERT(h.hasher("abc123ABC").compare("3649495046")==0);
    TEST_ASSERT(h.hasher("anticonstitutionnellement").compare("3394806735")==0);

}

void TestHasheurCmd::testHasherMd5() {

    HasheurCmd h;
    h.initialiser(DICO_MD5);

    TEST_ASSERT(h.hasher("a").compare("60b725f10c9c85c70d97880dfe8191b3")==0);
    TEST_ASSERT(h.hasher("b").compare("3b5d5c3712955042212316173ccf37be")==0);
    TEST_ASSERT(h.hasher("aa").compare("d404401c8c6495b206fc35c95e55a6d5")==0);
    TEST_ASSERT(h.hasher("abc").compare("0bee89b07a248e27c83fc3d5951213c1")==0);
    TEST_ASSERT(h.hasher("abc123").compare("2c6c8ab6ba8b9c98a1939450eb4089ed")==0);
    TEST_ASSERT(h.hasher("abc123ABC").compare("15bffbb53a5f5bfc1bd7ad379a60d0b1")==0);
    TEST_ASSERT(h.hasher("anticonstitutionnellement").compare("ac160fbd7073e1de0871373a69d53338")==0);
}

void TestHasheurCmd::testHasherSha512() {

    HasheurCmd h;
    h.initialiser(DICO_SHA512);

    TEST_ASSERT(h.hasher("a").compare("162b0b32f02482d5aca0a7c93dd03ceac3acd7e410a5f18f3fb990fc958ae0df6f32233b91831eaf99ca581a8c4ddf9c8ba315ac482db6d4ea01cc7884a635be")==0);
    TEST_ASSERT(h.hasher("b").compare("868a6ac6e1d0293d74fad07f6d95952b3e01d3d3153db677a75d8077983fd4e30db6bfc89b7608a93fb26469233a9f1a09572d687a9c5da78b203eb151040a15")==0);
    TEST_ASSERT(h.hasher("aa").compare("b6cfe6b77a8be877e0c13f20e94cd54e7678dc661d34bbad2498429fa7042a94d35ba3638810b64888d1950a036a1aabfbba5c30d6e256e89ed7a25e1f563388")==0);
    TEST_ASSERT(h.hasher("abc").compare("4f285d0c0cc77286d8731798b7aae2639e28270d4166f40d769cbbdca5230714d848483d364e2f39fe6cb9083c15229b39a33615ebc6d57605f7c43f6906739d")==0);
    TEST_ASSERT(h.hasher("abc123").compare("9760a80808894b09441d602b4fc779877756d98e976cdd33c64919b13b4f89dfb2d768562be616cbebf375f3f76598ca1dd5a90749e55899222a80ee3c7b15a5")==0);
    TEST_ASSERT(h.hasher("abc123ABC").compare("efbe140703be8b59efdc779b2b9a9f046293b09c9d358029cfbc75443ec36e6a6e67858fa423eaaff7637c4dd089f3b5530061881c321a9c9439516057ef85f2")==0);
    TEST_ASSERT(h.hasher("anticonstitutionnellement").compare("272cbf3188b5e6f583283a44f9769155dfbbbb793ce1635d4c6831c57db124bb2198fd6cb9f67c7f358e18999d447141bd0d8b187c368838dcf847014ff1e35f")==0);
}
