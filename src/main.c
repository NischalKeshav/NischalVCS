#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <unistd.h>
#include "randomhash.h"
#include "nvcsignore.h"
#include "convertJSONtoStruct.h"
#include "CreateCommit.h"
#include "CompareFileChanges.h"
#include "GetAllFilesInDir.h"

struct stat st = {0};



int cmd_init(void) {
    printf("Initialized empty NVCIS.001 repository\n");
    printf("%s\n", random_hash(20));
    mkdir(".nvcs", 0700);
    mkdir(".nvcs/objects", 0700);
    mkdir(".nvcs/refs", 0700);
    mkdir(".nvcs/refs/commits", 0700);
    if (write_nvcsignore() != 0) {
        fprintf(stderr, "Warning: failed to write .nvcsignore\n Repo created without .nvcsignore\n");

    }
    return 0;
}

int cmd_add(const char *filename) {
    printf("Adding file: %s\n", filename);
    
    return 0;
}

int cmd_commit(const char *message) {
    printf("Commit with message %s\n", message);
    CreateCommit(message);
    return 0;
}

int cmd_log(void) {
    printf("Showing commit log\n");
    
    struct Index *index = loadIndexFromFile("new.json");
    if (index) {
        displayIndex(index);
        freeIndex(index);
    }
    
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [options]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "init") == 0) {
        return cmd_init();
    } else if (strcmp(argv[1], "add") == 0) {
        if (argc < 3) {
            fprintf(stderr, "mygit add <file>\n");
            return 1;
        }
        return cmd_add(argv[2]);
    } else if (strcmp(argv[1], "commit") == 0) {
        if (argc < 4 || strcmp(argv[2], "-m") != 0) {
            fprintf(stderr, "mygit commit -m \"message\"\n");
            cmd_commit("hello");
            return 1;
        }
        return cmd_commit(argv[3]);
    } else if (strcmp(argv[1], "log") == 0) {
        return cmd_log();
    } else {
        fprintf(stderr, "Unknown command: %s\n", argv[1]);
        return 1;
    }
}
