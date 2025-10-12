#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "JSONutils.h"
#include "randomhash.h"
#include "CreateCommit.h"
#include "GetAllFilesInDir.h"


int CreateCommit(const char *message) {
    
    printf("Creating commit with message: %s\n", message);
    FilePaths *allPaths = GetAllFilesInDir();

    

    free(allPaths);
    return 0;
}