#include "main.h"

/**
 * _strcmp - Compare two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: The difference between the ASCII values of the first differing characters.
 */
int _strcmp(char *s1, char *s2) {
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    
    return (s1[i] - s2[i]);
}

/**
 * _strncmp - Compare at most the first 'n' characters of two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The number of the first characters to compare.
 * Return: 0 if the two strings are identical, or the difference in ASCII values.
 */
int _strncmp(char *s1, char *s2, int n) {
    int i;

    for (i = 0; s1[i] && s2[i] && n > i; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    
    return (0);
}

/**
 * _atoi - Convert a string to an integer.
 * @s: Pointer to a string.
 * Return: The integer value or -1 if conversion fails.
 */
int _atoi(char *s) {
    int i = 0, n = 0;

    if (s == NULL)
        return (0);
    
    for (i = 0; s[i]; i++) {
        if (s[i] >= '0' && s[i] <= '9')
            n = n * 10 + (s[i] - '0');
        else
            return (-1);
    }
    
    return (n);
}

/**
 * _strcpy - Copy a string from src to dest.
 * @src: Pointer to the source string.
 * @dest: Pointer to the destination buffer.
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, char *src) {
    char *p_dest = dest;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    
    *dest = '\0';
    return (p_dest);
}

/**
 * _strcat - Concatenate two strings, overwriting the null byte in dest.
 * @src: Pointer to the source string.
 * @dest: Pointer to the destination buffer.
 * Return: Pointer to dest.
 */
char *_strcat(char *dest, char *src) {
    char *p_dest = dest;
    int l = 0;

    while (*dest != '\0') {
        l++;
        dest++;
    }
    
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    
    *dest = '\0';
    return (p_dest);
}
