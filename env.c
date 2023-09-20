#include "main.h"

/**
 * _env - Function that prints all environment variables.
 */
void _env(void) {
    int i;

    for (i = 0; environ[i]; i++) {
        _puts(environ[i]);
        __putchar('\n');
    }
}

/**
 * _getenv - Retrieve the value of an environment variable.
 * @var: The name of the environment variable.
 *
 * Return: If the variable is found, a pointer to its value is returned.
 * Otherwise, NULL is returned.
 */
char *_getenv(char *var) {
    int i;
    int len = _slen(var);

    for (i = 0; environ[i]; i++) {
        if (_strncmp(environ[i], var, len) == 0 && environ[i][len] == '=') {
            return (&environ[i][len + 1]);
        }
    }
    return (NULL);
}

/**
 * free_env - Frees memory allocated for an array of environment variables.
 * @old_env: A pointer to an array of environment variables.
 */
void free_env(char **old_env) {
    int i;

    for (i = 0; old_env[i]; i++)
        free(old_env[i]);
    free(old_env);
}

/**
 * _setenv - Sets a new environment variable or updates an existing one.
 * @name: The name of the environment variable to set.
 * @value: The value to assign to the environment variable.
 * @count: An integer indicating whether to free the old environment.
 *
 * Return: Always returns 0.
 */
int _setenv(char *name, const char *value, int count) {
    char *var = NULL, **new_env = NULL, **old_env = environ;
    int count_var = 0, i = 0, lname = _slen(name);
    int len_var = lname + _slen((char *)(value)) + 2;

    var = _getenv(name);

    while (environ[count_var])
        count_var++;

    if (var) {
        new_env = (char **)malloc(sizeof(char *) * (count_var + 1));
        for (i = 0; environ[i]; i++)
            new_env[i] = _strdup(environ[i]);
        new_env[i] = NULL;
        environ = new_env;

        for (i = 0; new_env[i]; i++) {
            if (_strncmp(new_env[i], name, lname) == 0 && new_env[i][lname] == '=') {
                free(new_env[i]);
                new_env[i] = (char *)malloc(sizeof(char) * len_var);
                _strcpy(new_env[i], name);
                _strcat(new_env[i], "=");
                _strcat(new_env[i], (char *)value);
                _strcat(new_env[i], "\0");
                break;
            }
        }
    }

    if (!var) {
        new_env = (char **)malloc(sizeof(char *) * (count_var + 2));
        for (i = 0; environ[i]; i++)
            new_env[i] = _strdup(environ[i]);
        new_env[i] = (char *)malloc(sizeof(char) * len_var);
        _strcpy(new_env[i], name);
        _strcat(new_env[i], "=");
        _strcat(new_env[i], (char *)value);
        _strcat(new_env[i], "\0");
        new_env[i + 1] = NULL;
        environ = new_env;
    }

    if (count > 0)
        free_env(old_env);
    count++;

    return 0;
}

/**
 * _unsetenv - Removes an environment variable from the list.
 * @name: The name of the environment variable to remove.
 * @count: Indicate whether to free memory associated with the removed variable.
 *
 * Return: Always returns 0.
 */
int _unsetenv(char *name, int count) {
    char *var, *del_var;
    int i = 0, lname = _slen(name);

    var = _getenv(name);

    if (var) {
        for (i = 0; environ[i]; i++) {
            if (_strncmp(environ[i], name, lname) == 0 && environ[i][lname] == '=') {
                del_var = environ[i];
                break;
            }
        }
        for (; environ[i];) {
            environ[i] = environ[i + 1];
            i++;
        }

        if (count > 0)
            free(del_var);
    }

    return 0;
}
