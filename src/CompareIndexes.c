#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "JSONutils.h"
#include "randomhash.h"
#include "CreateCommit.h"
#include "GetAllFilesInDir.h"
#include "CreateIndex.h"
#include "CompareIndexes.h"



struct Index *CompareIndexes(struct Index *Index1, struct Index *Index2) {
    struct Index *result = malloc(sizeof(struct Index));
    if (result == NULL) {
        return NULL;  
    }
    
    *result = *Index2;
    return result;
}
