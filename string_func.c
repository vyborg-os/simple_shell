#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

/**
 * _strncmp - This function compares at most the first 'n'
 * characters of the two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: number of the first characters to compares
 * Return: 0 if the two string are identical or number represent the difference
 * between ASCII value of the two first difference char between to strings
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && n > i; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * *_atoi - convert a string to an integer
 * @s: pointer to a string
 * Return: an integer
 */
int _atoi(char *s)
{
	int i = 0, n = 0;

	if (s == NULL)
		return (0);
	for (i = 0; s[i]; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			n = n * 10 + (s[i] - '0');
		else
			return (-1);
	}
	return (n);
}

/**
 * *_strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @src: pointer to a string
 * @dest: pointer to a buffer
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *p_dest = NULL;

	p_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (p_dest);
}
/**
 * *_strcat -  appends the src string to the dest string,
 * overwriting the terminating null byte (\0) at the end of dest,
 * and then adds a terminating null byte
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @src: pointer to a string
 * @dest: pointer to a buffer
 * Return: the pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	char *p_dest = dest;
	int l = 0;

	while (*dest != '\0')
	{
		l++;
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (p_dest);
}


