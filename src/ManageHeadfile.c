#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "JSONutils.h"
#include "randomhash.h"
#include "CreateCommit.h"
#include "GetAllFilesInDir.h"
#include "JSONutils.h"
#include <unistd.h>

int createHeadFile(const char *headFilePath, const char *commitHash) {
    if (access(headFilePath, F_OK) == 0) {
        printf("File '%s' exists.\n", headFilePath);
    }
    FILE *file = fopen(headFilePath, "w");
    if (!file) {
        perror("Failed to open HEAD file for writing");
        return -1;
    }
    fprintf(file, "%s\n", commitHash);
    fclose(file);
    return 0;
}       

int SetHeadToCommit(const char *headFilePath, const char *commitHash) {
    FILE *file = fopen(headFilePath, "w");
    if (!file) {
        perror("Failed to open HEAD file for writing");
        return -1;
    }
    fprintf(file, "%s\n", commitHash);
    fclose(file);
    return 0;
}  
