#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdlib.h> // For size_t
#include <dirent.h> // For DIR and struct dirent
#include <sys/stat.h> // For struct stat (if you plan to use it later)

/**
 * @brief Custom data structure to hold dynamically allocated file paths.
 * * This structure is designed to store an array of string pointers (paths), 
 * along with its current count and allocated capacity for future expansion.
 */
typedef struct {
    char **paths;
    size_t count;
    size_t capacity;
    
} FilePaths;

/**
 * @brief Lists and prints all files and directories in the current directory.
 * * Note: This implementation currently prints to stdout and does not use  \n
 * the FilePaths structure, but it is declared here for future use.
 * * @return int 0 upon successful directory read, non-zero otherwise.
 */
FilePaths *GetAllFilesInDir();

#endif // FILE_UTILS_H