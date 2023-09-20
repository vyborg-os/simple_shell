#include "main.h"

/**
 * check_command_path - Locate the full path to an executable command.
 * @cmd: The command string for which to find the executable path.
 *
 * Return: An allocated string containing the full path to the executable,
 *         or NULL if the executable is not found.
 */
char *check_command_path(char *cmd) {
    char *path = NULL, *path_dup = NULL, *token, *file_path = NULL;
    size_t cmd_len = 0, dir_len = 0;
    struct stat f_stat;

    if (cmd[0] == '/' || cmd[1] == '/')
        return NULL;

    path = _getenv("PATH");

    if (path == NULL)
        return NULL;

    if (path[0] == '\0')
        return NULL;

    path_dup = _strdup(path);
    cmd_len = _slen(cmd);
    token = strtok(path_dup, ":");

    while (token) {
        dir_len = _slen(token);
        file_path = malloc(cmd_len + dir_len + 2);
        _strcpy(file_path, token);
        _strcat(file_path, "/");
        _strcat(file_path, cmd);
        _strcat(file_path, "\0");

        if (stat(file_path, &f_stat) == 0) {
            free(path_dup);
            return file_path;
        }

        token = strtok(NULL, ":");
        free(file_path);
        file_path = NULL;
    }

    free(path_dup);

    if (file_path)
        free(file_path);

    return NULL;
}
