/* 
 * Classe :   HasheurMd5
 * Objectif :
 */

#include "HasheurMd5.h"



string HasheurMd5::hasher(const char* cle) {
    return md5(cle);
}
