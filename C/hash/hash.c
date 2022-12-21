#include "hash.h"

int hash(int element, int i, int size){

    long long int ee, ii, ss;

    ee = element;
    ii = i;
    ss = size;

    return (ee + 17*ii + 19*ii*ii) % ss;
}
