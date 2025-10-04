#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

struct IndexEntry {
    char *path;   // filename
    char *hash;   // blob SHA-1
    int mode;     // permissions/mode
};

// Whole index
struct Index {
    struct IndexEntry *entries;
    size_t count;
};      


struct Index *parseIndexJSON(const char *jsonText) {
    cJSON *root = cJSON_Parse(jsonText);
    if (!root) {
        printf("Error before: %s\n", cJSON_GetErrorPtr());
        return NULL;
    }

    size_t entryCount = cJSON_GetArraySize(root);
    struct Index *index = malloc(sizeof(struct Index));
    index->entries = malloc(sizeof(struct IndexEntry) * entryCount);
    index->count = 0;

    cJSON *file = NULL;
    cJSON_ArrayForEach(file, root) {
        const char *path = file->string;   // key name
        cJSON *hashNode = cJSON_GetObjectItem(file, "hash");
        cJSON *modeNode = cJSON_GetObjectItem(file, "mode");

        index->entries[index->count].path = strdup(path);
        index->entries[index->count].hash = strdup(hashNode->valuestring);
        index->entries[index->count].mode = modeNode->valueint;

        index->count++;
    }

    cJSON_Delete(root);
    return index;
}
