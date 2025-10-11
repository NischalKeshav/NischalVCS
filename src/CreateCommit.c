#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "convertJSONtoStruct.h"
#include "randomhash.h"
#include "CreateCommit.h"
#include "GetAllFilesInDir.h"


void CreateCommit(const char *message) {
    
    printf("Creating commit with message: %s\n", message);
    FilePaths *allPaths = GetAllFilesInDir();

    printf("Files in current directory:\n");
    for (size_t i = 0; i < allPaths->count; i++) {
        printf(" - %s\n", allPaths->paths[i]);
    }
    for (size_t i = 0; i < allPaths->count; i++) {
        free(allPaths->paths[i]);
    }

    free(allPaths->paths);
    free(allPaths);
}