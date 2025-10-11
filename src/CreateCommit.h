#ifndef RANDOMHASH_H
#define RANDOMHASH_H


typedef struct {
    char **paths;
    size_t count;
    size_t capacity;
} FilePaths;

int CreateCommit(char *message);
FilePaths *GetAllFilesInDir(void);

#endif 