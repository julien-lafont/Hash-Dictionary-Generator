#include "BenchmarkUtil.h"

long BenchmarkUtil::getDiffMs(struct timeval *start, struct timeval *end) {
    long msec;
    msec=(end->tv_sec-start->tv_sec)*1000;
    msec+=(end->tv_usec-start->tv_usec)/1000;
    return msec;
}

void BenchmarkUtil::timer(struct timeval *t ) {
    gettimeofday(t, 0);
}
