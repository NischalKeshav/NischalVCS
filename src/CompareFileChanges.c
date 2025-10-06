#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <unistd.h>
#include "cJSON.h"
#include "convertJSONtoStruct.h"
#include "randomhash.h"


void CompareFileChanges(const char *filePath1, const char *filePath2) {
    
    printf("Comparing files: %s and %s\n", filePath1, filePath2);
}   



bool are_files_identical(const char *path1, const char *path2) {
    // Step 1: Compare file metadata (size)
    struct stat st1, st2;
    if (stat(path1, &st1) != 0 || stat(path2, &st2) != 0) {
        perror("Error reading file info");
        return false;
    }
    if (st1.st_size != st2.st_size) {
        return false; // different sizes → not identical
    }

    // Step 2: Open files
    FILE *f1 = fopen(path1, "rb");
    FILE *f2 = fopen(path2, "rb");
    if (!f1 || !f2) {
        perror("Error opening file");
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return false;
    }


    const size_t BUFFER_SIZE = 4096;
    unsigned char buf1[BUFFER_SIZE];
    unsigned char buf2[BUFFER_SIZE];

    bool identical = true;
    size_t bytesRead1, bytesRead2;

    while ((bytesRead1 = fread(buf1, 1, BUFFER_SIZE, f1)) > 0) {
        bytesRead2 = fread(buf2, 1, BUFFER_SIZE, f2);
        if (bytesRead1 != bytesRead2 || memcmp(buf1, buf2, bytesRead1) != 0) {
            identical = false;
            break;
        }
    }

    fclose(f1);
    fclose(f2);
    return identical;
}
