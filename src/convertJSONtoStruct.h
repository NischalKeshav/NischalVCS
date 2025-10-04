#ifndef CONVERTJSONTOSTRUCT_H
#define CONVERTJSONTOSTRUCT_H

#include <stddef.h>

// Single entry in the index
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

/**
 * Parse JSON text into an Index structure
 * @param jsonText - JSON string to parse
 * @return Pointer to newly allocated Index, or NULL on error
 */
struct Index *parseIndexJSON(const char *jsonText);

/**
 * Load and parse index from a JSON file
 * @param filename - Path to the JSON file
 * @return Pointer to newly allocated Index, or NULL on error
 */
struct Index *loadIndexFromFile(const char *filename);

/**
 * Display the index by printing entries
 * @param index - Pointer to Index structure to display
 */
void displayIndex(const struct Index *index);

/**
 * Free memory allocated for an Index structure
 * @param index - Pointer to Index to free
 */
void freeIndex(struct Index *index);

#endif // CONVERTJSONTOSTRUCT_H