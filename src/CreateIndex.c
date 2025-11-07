#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "JSONutils.h"
#include "randomhash.h"
#include "CreateCommit.h"
#include "GetAllFilesInDir.h"
#include "CreateIndex.h"

struct Index CreateIndex(const char *RepoPath) {
    printf("Creating index by for repository at path: %s\n", RepoPath);
    FilePaths *Set = GetAllFilesInDir();
    
    return NULL_INDEX;
   
}
