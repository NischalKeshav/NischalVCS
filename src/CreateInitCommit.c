#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "JSONutils.h"
#include "randomhash.h"
#include "CreateCommit.h"
#include "GetAllFilesInDir.h"
#include "JSONutils.h"

// Helper function to create a single IndexEntry
struct IndexEntry createEntry(const char *path, const char *hash, int mode) {
    struct IndexEntry entry;
    entry.path = strdup(path);
    entry.hash = strdup(hash);
    entry.mode = mode;
    return entry;
}


struct Index *createTestIndex() {
    struct Index *index = malloc(sizeof(struct Index));
    if (!index) {
        fprintf(stderr, "Failed to allocate Index\n");
        return NULL;
    }
    

    index->count = 3;
    index->entries = malloc(sizeof(struct IndexEntry) * index->count);
    if (!index->entries) {
        fprintf(stderr, "Failed to allocate entries\n");
        free(index);
        return NULL;
    }
    
    // Create sample entries

    return index;
}

int CreateInitCommit() {
    char *message = "Initial commit";
    printf("Creating initial commit with message: %s\n", message);
    

    struct Index *index = createTestIndex();
    if (!index) {
        fprintf(stderr, "Error: failed to create test index\n");
        return -1;
    }

    int result = WriteIndexToJSONFile(index, ".nvcs/refs/commits/InitCommit.json");
    

    freeIndex(index);
    
    if (result != 0) {
        fprintf(stderr, "Error: failed to write index file\n");
        return -1;
    }
    
    printf("Successfully created initial commit\n");
    return 0;
}