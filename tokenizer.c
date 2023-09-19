#include "shell.h"

/**
 * **strtow - Splits a given string into words, ignoring repeated delimiters.
 * @str: The input string to be split.
 * @d: The delimiter string used for splitting.
 *
 * Return: A pointer to an array of strings representing the words, or NULL on failure.
 */

char **strtow(char *str, char *d)
{
    int i, j, k, m, numWords = 0;
    char **wordsArray;

    if (str == NULL || str[0] == 0)
        return (NULL);
    if (!d)
        d = " ";
    for (i = 0; str[i] != '\0'; i++)
        if (!isDelimiter(str[i], d) && (isDelimiter(str[i + 1], d) || !str[i + 1]))
            numWords++;

    if (numWords == 0)
        return (NULL);
    wordsArray = malloc((1 + numWords) * sizeof(char *));
    if (!wordsArray)
        return (NULL);
    for (i = 0, j = 0; j < numWords; j++)
    {
        while (isDelimiter(str[i], d))
            i++;
        k = 0;
        while (!isDelimiter(str[i + k], d) && str[i + k])
            k++;
        wordsArray[j] = malloc((k + 1) * sizeof(char));
        if (!wordsArray[j])
        {
            for (k = 0; k < j; k++)
                free(wordsArray[k]);
            free(wordsArray);
            return (NULL);
        }
        for (m = 0; m < k; m++)
            wordsArray[j][m] = str[i++];
        wordsArray[j][m] = 0;
    }
    wordsArray[j] = NULL;
    return (wordsArray);
}

/**
 * **strtow2 - Splits a string into words using a specified delimiter.
 * @str: The input string to be split.
 * @d: The delimiter character used for splitting.
 *
 * Return: A pointer to an array of strings representing the words, or NULL on failure.
 */
char **strtow2(char *str, char d)
{
    int i, j, k, m, numWords = 0;
    char **wordsArray;

    if (str == NULL || str[0] == 0)
        return (NULL);
    for (i = 0; str[i] != '\0'; i++)
        if ((str[i] != d && str[i + 1] == d) ||
            (str[i] != d && !str[i + 1]) || str[i + 1] == d)
            numWords++;
    if (numWords == 0)
        return (NULL);
    wordsArray = malloc((1 + numWords) * sizeof(char *));
    if (!wordsArray)
        return (NULL);
    for (i = 0, j = 0; j < numWords; j++)
    {
        while (str[i] == d && str[i] != d)
            i++;
        k = 0;
        while (str[i + k] != d && str[i + k] && str[i + k] != d)
            k++;
        wordsArray[j] = malloc((k + 1) * sizeof(char));
        if (!wordsArray[j])
        {
            for (k = 0; k < j; k++)
                free(wordsArray[k]);
            free(wordsArray);
            return (NULL);
        }
        for (m = 0; m < k; m++)
            wordsArray[j][m] = str[i++];
        wordsArray[j][m] = 0;
    }
    wordsArray[j] = NULL;
    return (wordsArray);
}
