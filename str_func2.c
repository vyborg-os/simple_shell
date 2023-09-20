#include "main.h"

/**
 * _strdup - Duplicate a string.
 * @str: Pointer to the string to duplicate.
 * Return: A pointer to the duplicated string, or NULL if it fails.
 */
char *_strdup(const char *str) {
    int i = 0;
    char *duplicate_str = NULL;

    if (str == NULL)
        return (NULL);

    while (str[i])
        i++;

    duplicate_str = (char *)malloc((i + 1) * sizeof(char));
    if (duplicate_str == NULL)
        return (NULL);

    for (i = 0; str[i]; i++)
        duplicate_str[i] = str[i];
    duplicate_str[i] = '\0';

    return (duplicate_str);
}
