#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "JSONutils.h"
#include "randomhash.h"
#include "CreateCommit.h"
#include "GetAllFilesInDir.h"
#include "CreateIndex.h"

int CreateCommit(const char *message,  char *hash) {
    printf("Creating commit with message: %s\n hash: %s\n", message, hash);

    FilePaths *allPaths = GetAllFilesInDir();
    if (!allPaths) {
            fprintf(stderr, "Error: Failed to get file paths\n");
            return -1;
        }

    for (size_t i = 0; i < allPaths->count; i++) {
        printf("File %zu: %s\n", i + 1, allPaths->paths[i]);
    }

    free(allPaths);
    return 0;
}