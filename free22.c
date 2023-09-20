#include "main.h"
/**
 * _free - Frees the occupied memory by the char pointers
 * @a: pointer to a character array
 * @b: another character array
 */
void _free(char *a, char *b)
{
	if (a)
		free(a);

	if (b)
		free(b);
}

/**
 * _free_with_null - Frees the occupied memory by the char pointers
 * and sets them to NULL
 * @a: pointer to a character array
 * @b: another character array
 */
void _free_with_null(char **a, char **b)
{
	if (a && *a)
	{
		free(*a);
		*a = NULL;
	}
	if (b && *b)
	{
		free(*b);
		*b = NULL;
	}
}

