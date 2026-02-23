// hi this is the place i debug susc
// ignore this unless youre a contributor or in general i guess it doesnt really matter

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
char* suscrypt(char* str, char* key, char type) {
    // FIND SUPER-SECURE-CRYPTLIB AT github.com/sarabasscringe0/susc
    // works both ways, both to encrypt and decrypt, just specify it as d = decrypt, e = encrypt
    char* data;
    int str_len;
    // if decoding, make hex into string, if encoding just allocate space for data
    if (type == 'd') {
        str_len = strlen(str)/2;
        data = malloc(str_len+1);
        for (int i = 0;i < str_len;i++) {
            sscanf(str + 2*i, "%2hhX", &data[i]);
        }
        data[str_len] = '\0';
    } else {
        str_len = strlen(str);
        data = malloc(str_len + 1);
        strcpy(data, str);
    }
    // XOR key and data
    int key_len = strlen(key);
    for (int i = 0;i < str_len;i++) {
        data[i] ^= key[i % key_len];
    }
    // if encoding, output as hex
    if (type == 'e') {
        char* output = malloc(str_len * 2 + 1);
        for (int i = 0;i < str_len;i++){
            sprintf(output + 2*i,"%02X", (unsigned char)data[i]);
        }
        output[str_len*2] = '\0';
        return output;
    } else {
        return data;
    }
}


// ignore the main function, its not important if youre gonna use it in your own project
int main() {
    char* data = "19000F1E0A54571F131F17";
    char* password = "secret password";
    printf("%s\n","starting hash..");

    char* hash = suscrypt(data, password, 'd');

    printf("data: %s\n",data);
    printf("key: %s\n",password);
    printf("hash: %s\n",hash);
    return 0;
}
