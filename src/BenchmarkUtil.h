#ifndef BENCHMARKUtil_H
#define	BENCHMARKUtil_H

#include <sys/time.h>
#include <cstdlib>

/**
 * Classe utilitaire permettant de faciliter les benchmark
 */
class BenchmarkUtil {
public:

    /**
     * Calculer la différence de temps en millisecondes entre 2 timers
     * @param start
     * @param end
     * @return différence temporelles en ms
     */
    static long getDiffMs(struct timeval *start, struct timeval *end);

    /**
     * Initialise un timer à l'heure courante
     * @param t timer à initialiser
     */
    static void timer(struct timeval *t );

};

#endif	/* BENCHMARKUtil_H */

