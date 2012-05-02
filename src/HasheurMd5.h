#ifndef HASHEURMD5_H
#define	HASHEURMD5_H

#include <string>
#include <cstdio>

#include "Hasheur.h"
#include "enums.h"
#include "Md5ManuelUtil.h"

/**
 * Hasheur MD5
 * Fournir un résultat à la fonction md5() de PHP
 *
 * La fonction codée en dur offre des performances intéressantes
 * @see Md5ManuelUtil
 */
class HasheurMd5 : public Hasheur {
public:

    
    /**
     * Hasher une clé avec l'algorithme MD5 "manuel"
     * @param cle
     * @return empreinte de la clé
     */
    string hasher(const char* cle);
    
};

#endif	/* HASHEURMD5_H */
