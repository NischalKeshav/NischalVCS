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
#include "ManageHeadfile.h"
#include <stdbool.h>



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

char *getCurrentCommitHash(const char *headFilePath) {
    FILE *file = fopen(headFilePath, "r");
    if (!file) {
        perror("Failed to open HEAD file for reading");
        return NULL;
    }
    char *commitHash = (char *)malloc(41 * sizeof(char)); 
    if (fgets(commitHash, 41, file) == NULL) {
        perror("Failed to read commit hash from HEAD file");
        fclose(file);
        free(commitHash);
        return NULL;
    }
    size_t len = strlen(commitHash);
    if (len > 0 && commitHash[len - 1] == '\n') {
        commitHash[len - 1] = '\0';
    }
    fclose(file);
    return commitHash;
}

bool isHeadFileExists(const char *headFilePath) {
    return access(headFilePath, F_OK) == 0;
}


