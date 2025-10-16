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
    index->entries[0] = createEntry("src/main.c", "a1b2c3d4e5f6", 100644);
    index->entries[1] = createEntry("include/header.h", "f6e5d4c3b2a1", 100644);
    index->entries[2] = createEntry("README.md", "1234567890ab", 100644);
    
    return index;
}

int CreateInitCommit() {
    char *message = "Initial commit";
    printf("Creating initial commit with message: %s\n", message);
    
    // Create test index with entries
    struct Index *index = createTestIndex();
    if (!index) {
        fprintf(stderr, "Error: failed to create test index\n");
        return -1;
    }
    
    // Write to file
    int result = WriteIndexToJSONFile(index, "InitCommit.json");
    
    // Clean up
    freeIndex(index);
    
    if (result != 0) {
        fprintf(stderr, "Error: failed to write index file\n");
        return -1;
    }
    
    printf("Successfully created initial commit\n");
    return 0;
}