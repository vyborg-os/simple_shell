#include "main.h"
/**
 * _echo - Display text with variable expansion
 * @args: Array of arguments including variables
 * @exit_code: Exit code of the previous command
 *
 * Return: Always 0
 */
int _echo(char **args, int exit_code)
{
	char *var = NULL;
	pid_t pid;
	int i = 0, check = 0;

	for (i = 1; args[i]; i++)
	{
		if ((_strcmp(args[i], "$$")) == 0)
		{
			pid = (int)getpid();
			print_number(1, pid);
			continue;
		}
		else if ((_strcmp(args[i], "$?")) == 0)
		{
			print_number(1, exit_code);
			continue;
		}
		else if (args[i][0] == '$' && args[i][1])
		{
			args[i]++;
			var = _getenv(args[i]);
			if (var)
				_puts(var);
			continue;
		}
		else
		{
			if (check == 1)
				__putchar(' ');
			_puts(args[i]);
			check = 1;
		}
	}
	__putchar('\n');
	return (0);
}
/**
 * _echo_get_var - Get and expand a specific variable in the args
 * @args: Array of arguments including variables
 * @indice: Index of the argument containing the variable
 *
 * Return: 0 on success otherwise -1 if the variable is not found
 */
int _echo_get_var(char **args, int indice)
{   char *var;

	args[indice]++;
	var = _getenv(args[indice]);
	if (var)
	{args[indice] = var;
		return (0); }

	return (-1);
}

