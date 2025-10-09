#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>


typedef struct {
    char **paths;
    size_t count;
    size_t capacity;
} FilePaths;

FilePaths GetAllFilesInDir() {
    DIR *d;
    struct dirent *dir;
    FilePaths result = {NULL, 0, 0};

    d = opendir(".");
    if (d) {
        result.capacity = 10;
        result.paths = malloc(result.capacity * sizeof(char *));
        if (!result.paths) {
            perror("malloc");
            closedir(d);
            return result;
        }

        while ((dir = readdir(d)) != NULL) {
            if (result.count >= result.capacity) {
                result.capacity *= 2;
                result.paths = realloc(result.paths, result.capacity * sizeof(char *));
                if (!result.paths) {
                    perror("realloc");
                    closedir(d);
                    result.count = 0;
                    result.capacity = 0;
                    return result;
                }
            }
            result.paths[result.count] = strdup(dir->d_name);
            result.count++;
        }
        closedir(d);
    }

    return result;
}
