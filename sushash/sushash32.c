#include <string.h>
unsigned long SEED = 0xA3F7C92DUL; // always keep this in your project at the top or C will think seed is undefined

unsigned long sushash32(char* str) {
    // FIND SUPER-SECURE-CRYPTLIB AT github.com/sarabasscringe0/susc
    unsigned long hash = SEED;
    int len = strlen(str);
    for (int i = 0;i < len;i++) { // operations
        hash ^= str[i];
        hash = (hash << 3) | (hash >> 29);
        hash *= SEED;
    }
    return hash;
}
