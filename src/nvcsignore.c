#include <stdio.h>
#include "nvcsignore.h"

int write_nvcsignore(void) {
    const char *path = ".nvcsignore";
    const char *contents =
        "# .nvcsignore — patterns for files that should not be tracked by NVCS\n"
        "# Syntax follows the same basic rules as .gitignore:\n"
        "#  - Lines starting with # are comments\n"
        "#  - Blank lines are ignored\n"
        "#  - Trailing/leading whitespace is ignored\n"
        "#  - \"*\" matches any string, \"?\" matches one character\n"
        "#  - A leading slash (/) matches the repository root\n"
        "#  - A trailing slash (/) indicates a directory\n"
        "#  - \"!\" negates a pattern\n\n"
        "# --- Build artifacts ---\n"
        "mygit\n"
        "src/mygit\n"
        "src/main\n"
        "*.o\n"
        "*.exe\n"
        "*.out\n"
        "*.so\n"
        "*.a\n\n"
        "# --- Editor / OS files ---\n"
        ".DS_Store\n"
        "*~\n"
        "*.swp\n"
        "*.swo\n"
        ".vscode/\n"
        ".idea/\n\n"
        "# --- Logs / temporary folders ---\n"
        "*.log\n"
        "tmp/\n"
        "temp/\n\n"
        "# --- Optional: ignore test/build directories ---\n"
        "build/\n"
        "dist/\n\n"
        "# --- Keep NVCS metadata tracked ---\n"
        "!.nvcs\n";

    FILE *f = fopen(path, "w");
    if (!f) return -1;
    if (fputs(contents, f) == EOF) {
        fclose(f);
        return -1;
    }
    fclose(f);
    return 0;
}
