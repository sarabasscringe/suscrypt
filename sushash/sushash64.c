#include <string.h>
unsigned long long SEED = 0x517cc1b727220a95ULL; // always keep this in your project at the top or C will think seed is undefined

unsigned long long sushash64(char* str) {
    // FIND SUPER-SECURE-CRYPTLIB AT github.com/sarabasscringe0/susc
    unsigned long long hash = SEED;
    int len = strlen(str);
    for (int i = 0;i < len;i++) { // operations
        hash ^= str[i];
        hash = (hash << 5) | (hash >> 59);
        hash *= SEED;
    }
    return hash;
}
