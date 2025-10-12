#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "JSONutils.h"

struct Index *parseIndexJSON(const char *jsonText) {
    cJSON *root = cJSON_Parse(jsonText);
    if (!root) {
        fprintf(stderr, "Error parsing JSON: %s\n", cJSON_GetErrorPtr());
        return NULL;
    }

    size_t entryCount = cJSON_GetArraySize(root);
    struct Index *index = malloc(sizeof(struct Index));
    if (!index) {
        cJSON_Delete(root);
        return NULL;
    }
    
    index->entries = malloc(sizeof(struct IndexEntry) * entryCount);
    if (!index->entries) {
        free(index);
        cJSON_Delete(root);
        return NULL;
    }
    
    index->count = 0;

    cJSON *file = NULL;
    cJSON_ArrayForEach(file, root) {
        const char *path = file->string;
        cJSON *hashNode = cJSON_GetObjectItem(file, "hash");
        cJSON *modeNode = cJSON_GetObjectItem(file, "mode");

        // ADD NULL CHECKS
        if (!hashNode || !modeNode || !hashNode->valuestring) {
            fprintf(stderr, "Warning: skipping malformed entry\n");
            continue;
        }

        index->entries[index->count].path = strdup(path);
        index->entries[index->count].hash = strdup(hashNode->valuestring);
        index->entries[index->count].mode = modeNode->valueint;

        index->count++;
    }

    cJSON_Delete(root);
    return index;
}

struct Index *loadIndexFromFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        perror("Reason");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long len = ftell(fp);
    if (len <= 0) {
        fprintf(stderr, "Error: file '%s' is empty or invalid\n", filename);
        fclose(fp);
        return NULL;
    }
    rewind(fp);

    char *data = malloc(len + 1);
    if (!data) {
        fprintf(stderr, "Error: memory allocation failed\n");
        fclose(fp);
        return NULL;
    }
    
    fread(data, 1, len, fp);
    data[len] = '\0';
    fclose(fp);

    printf("DEBUG: File content:\n%s\n", data);  // Debug print

    struct Index *index = parseIndexJSON(data);
    free(data);
    
    return index;
}

void displayIndex(const struct Index *index) {
    if (!index) {
        printf("No index data to display\n");
        return;
    }

    for (size_t i = 0; i < index->count; i++) {
        printf("File: %s\n", index->entries[i].path);
        printf("  Hash: %s\n", index->entries[i].hash);
        printf("  Mode: %d\n\n", index->entries[i].mode);
    }
}

void freeIndex(struct Index *index) {
    if (!index) return;
    
    for (size_t i = 0; i < index->count; i++) {
        free(index->entries[i].path);
        free(index->entries[i].hash);
    }
    free(index->entries);
    free(index);
}
