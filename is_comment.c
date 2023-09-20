#include "main.h"

/**
 * check_is_comment - function that handle comments
 * @args: An array of strings containing command-line arguments.
 * Return: 0 if command is # or 1 is otherwise
 */

int check_is_comment(char **args)
{
	int i = 0;

	for (i = 0; args[i]; i++)
		if (args[i][0] == '#')
		{ args[i] = NULL;
			if (i == 0)
			{ free(args);
				return (1); }
			break; }
	return (0);

}

