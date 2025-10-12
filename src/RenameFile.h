#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <stdio.h>

/**
 * @brief Renames a file from an old path to a new path.
 * @param old_path The full path of the original file, including its name.
 * @param new_path The full path for the new file, including its new name.
 * @return 0 on success, or a non-zero value on failure.
 */
int rename_file(const char *old_path, const char *new_path);

#endif /* FILE_OPERATIONS_H */
