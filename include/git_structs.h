#ifndef GIT_STRUCTS_H
#define GIT_STRUCTS_H

// Represents a Git blob (file contents)
struct Blob {
    char *id;        // SHA-1 hash (string)
    unsigned long size;     // file size
    char *content;   // file content
};

// Represents a Git tree entry (directory)
struct TreeEntry {
    char *name;      // filename
    char *mode;      // file permissions (e.g. "100644")
    char *id;        // SHA-1 of blob/tree
};

// Represents a commit
struct Commit {
    char *id;        // SHA-1 hash of this commit
    char *tree;      // SHA-1 of root tree
    char *parent;    // SHA-1 of parent commit
    char *author;    // "Name <email> timestamp tz"
    char *committer;
    char *message;
};

#endif // GIT_STRUCTS_H
