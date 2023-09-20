#include "main.h"
/**
 * _puts_std - writes the character c to stdout
 * @c: pointer to string
 * @std: file descriptors / standard I/O streams
 * Return: number of characters printed.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _puts_std(int std, char *c)
{
	return (write(std, c, _slen(c)));
}


/**
 * strtok_alloc - Tokenizes a given string based on space delemitor (" ")
 *				 and allocates memory for tokens
 * @line: The input line
 * @read: The number of characters read from the line
 *
 * Return: A double pointer to an array of strings containing the tokens
 *         NULL is returned on failure
 */
char **strtok_alloc(char *line, ssize_t read)
{
	int c = 0, i;
	char *tok_cpy, *tok = NULL, **args, *line2;

	if (read == -1)
	{
		if (line)
			free(line);
		p_err_getline();
	}
	if (read > 0 && line[read - 1] == '\n')
		line[read - 1] = '\0';

	line2 = _strdup(line);
	if (line2 == NULL)
	{   free(line);
		exit(EXIT_FAILURE); }

	tok = strtok(line2, " ");
	tok_cpy = tok;
	for (c = 0; tok; c++)
		tok = strtok(NULL, " ");
	args = (char **)malloc(sizeof(char *) * (c + 1));
	if (args == NULL)
	{   free(line2);
		free(line);
		exit(EXIT_FAILURE);
	}
	tok_cpy = strtok(line, " ");
	for (i = 0; tok_cpy; i++)
	{
		args[i] = tok_cpy;
		tok_cpy = strtok(NULL, " ");
	}
	args[i] = NULL;
	free(line2);

	if (args[0] == NULL)
	{free(args);
	return (NULL); }
	return (args);
}


/**
 * strtok_alloc_semi_colom - Tokenizes a given line based on (;) or (||)
 *							or (&&) delemitors and allocates memory for tokens
 * @line: The input line
 * @read: The number of characters read from the line
 *
 * Return: A double pointer to an array of strings containing the tokens
 *         NULL is returned on failure
 */
char **strtok_alloc_semi_colom(char *line, ssize_t read)
{
	int c = 0, i;
	char *tok_cpy, *tok = NULL, **args_c, *line2;

	if (read == -1)
	{
		if (line)
			free(line);
		p_err_getline();
	}
	if (read > 0 && line[read - 1] == '\n')
		line[read - 1] = '\0';

	line2 = _strdup(line);
	if (line2 == NULL)
	{   free(line);
		exit(EXIT_FAILURE); }

	tok = strtok(line2, ";||&&");
	tok_cpy = tok;
	for (c = 0; tok; c++)
		tok = strtok(NULL, ";||&&");
	args_c = (char **)malloc(sizeof(char *) * (c + 1));
	if (args_c == NULL)
	{   free(line2);
		free(line);
		exit(EXIT_FAILURE);
	}
	tok_cpy = strtok(line, ";||&&");
	for (i = 0; tok_cpy; i++)
	{
		args_c[i] = tok_cpy;
		tok_cpy = strtok(NULL, ";||&&");
	}
	args_c[i] = NULL;
	free(line2);

	if (args_c[0] == NULL)
	{free(args_c);
	return (NULL); }
	return (args_c);
}

