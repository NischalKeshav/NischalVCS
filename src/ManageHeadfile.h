#ifndef MANAGE_HEAD_FILE_H  
#define MANAGE_HEAD_FILE_H  
#include <stdbool.h>

int createHeadFile(const char *headFilePath, const char *commitHash);
int SetHeadToCommit(const char *headFilePath, const char *commitHash);
char *getCurrentCommitLocation(const char *headFilePath);
bool isHeadFileExists(const char *headFilePath);

#endif // MANAGE_HEAD_FILE_H