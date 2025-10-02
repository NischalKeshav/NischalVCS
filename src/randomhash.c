#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char* random_hash(int len) {
    static const char hex[] = "0123456789abcdef";
    char *hash = malloc(len * 2 + 1); // 
    if (!hash) return NULL;

    for (int i = 0; i < len; i++) {
        int byte = rand() % 256;       
        hash[i * 2]     = hex[(byte >> 4) & 0xF]; 
        hash[i * 2 + 1] = hex[byte & 0xF];      
    }

    hash[len * 2] = '\0';
    return hash;
}