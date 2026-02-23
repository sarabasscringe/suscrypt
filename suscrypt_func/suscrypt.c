#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
