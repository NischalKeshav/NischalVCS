#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief Renames a file by moving it from an old path to a new one.

 * @param old_path The full path of the original file, including its name.
 * @param new_path The full path for the new file, including its new name.
 * @return 0 on success, or a non-zero value on failure.
 */
int rename_file(const char *old_path, const char *new_path) {

    int result = rename(old_path, new_path);
    return result;
}
