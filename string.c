#include "shell.h"

/**
 * _strlen - Determines the length of a string.
 * @s: The string for which to find the length.
 *
 * Return: The integer representing the length of the string.
 */
int _strlen(char *s)
{
    int length = 0;

    if (!s)
        return (0);

    while (*s++)
        length++;
    return (length);
}

/**
 * _strcmp - Performs a lexicographic comparison of two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: A negative value if s1 < s2, a positive value if s1 > s2,
 *         and zero if s1 is equal to s2.
 */
int _strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    if (*s1 == *s2)
        return (0);
    else
        return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Checks if the haystack string starts with the needle substring.
 * @haystack: The string in which to search.
 * @needle: The substring to find at the beginning of the haystack.
 *
 * Return: A pointer to the next character in haystack if it starts with needle,
 *         or NULL if it does not.
 */
char *starts_with(const char *haystack, const char *needle)
{
    while (*needle)
        if (*needle++ != *haystack++)
            return (NULL);
    return ((char *)haystack);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination buffer where the strings will be combined.
 * @src: The source buffer containing the string to append to dest.
 *
 * Return: A pointer to the destination buffer after concatenation.
 */
char *_strcat(char *dest, char *src)
{
    char *result = dest;

    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = *src;
    return (result);
}
