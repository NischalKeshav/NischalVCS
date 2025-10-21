#ifndef CONVERTJSONTOSTRUCT_H
#define CONVERTJSONTOSTRUCT_H

#include <stddef.h>




struct IndexEntry {
    char *path;   // filename
    char *hash;   // blob SHA-1
    int mode;     // permissions/mode
};


struct Index {
    struct IndexEntry *entries;
    size_t count;
};


#define NULL_INDEX (struct Index){ .entries = NULL, .count = 0 }

/**
 * @param jsonText - JSON string to parse
 * @return Pointer to newly allocated Index, or NULL on error
 */
struct Index *parseIndexJSON(const char *jsonText);

/**

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
int WriteIndexToJSONFile(const struct Index *index, const char *filename);

/**
 * Find the hash of a file in an Index by its path.
 * @param index - Pointer to Index structure to search
 * @param filename - File name (path) to search for
 * @return Pointer to hash string if found, or NULL if not found
 *         (Do not free the returned pointer — it belongs to the Index)
 */
const char *findHashByFilename(const struct Index *index, const char *filename);






#endif // CONVERTJSONTOSTRUCT_H
