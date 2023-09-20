#include "main.h"

/**
 * check_if_exit - Checks for the "exit" command and handles its argument
 * @args: An array of pointers to strings containing command-line & arguments
 * @shellname: The name of the shell program
 * @count: The current command count
 * @cec: The exit status of a child process
 * @a:An array of pointers to strings containing all commands-line & arguments
 * Return:  0, if no additional argument is provided
 * -2, displaying an error message if a non-valid integer argument is provided
 * The integer exit status, if a valid integer argument is provided
 * 0,if the given command is not "exit"
 */

int check_if_exit(char **args, char *shellname, int count, int cec, char **a)
{
	int r_atoi = 0;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (!args[1])
		{ free(args);
		if (a)
		free(a);
		return (cec); }
		r_atoi = _atoi(args[1]);
		if (r_atoi == -1)
		{
			_puts_len(2, shellname, _slen(shellname));
			write(2, ": ", 2);
			print_number(2, count);
			write(2, ": ", 2);
			_puts_len(2, "exit", _slen("exit"));
			write(2, ": ", 2);
			_puts_len(2, "Illegal number", _slen("Illegal number"));
			write(2, ": ", 2);
			_puts_len(2, args[1], _slen(args[1]));
			write(2, "\n", 1);
			free(args);
			if (a)
			free(a);
			return (-2);
		}
		free(args);
		if (a)
		free(a);
		return (r_atoi);
	}
	return (-1);
}
/**
 * check_is_env_cd - Checks if the command entered is "setenv" or "unsetenv"
 * and calls the appropriate function.
 * @args: An array of strings containing command-line arguments.
 * @shellname: The name of the shell program
 * @count: The current command count
 * @ex_code: exit code of the last executed command
 * Return: 2 if "setenv", 1 if "unsetenv", -1 on error.
 */
int check_is_env_cd(char **args, char *shellname, int count, int ex_code)
{
static int check;
int ret_cd = 0, i = 0;
if ((_strcmp(args[0], "setenv")) == 0)
{
if (!args[1] || !args[2])
{ free(args);
return (-1); }
_setenv(args[1], args[2], check);
check = 1;
free(args);
return (2); }
if ((_strcmp(args[0], "unsetenv")) == 0)
{
if (!args[1])
{ free(args);
return (-1); }
_unsetenv(args[1], check);
free(args);
return (1); }
if ((_strcmp(args[0], "env")) == 0)
{ _env();
free(args);
return (1); }
if ((_strcmp(args[0], "cd")) == 0)
{ ret_cd = _cd(args[1], shellname, count, check);
if (ret_cd == -2)
{check = 1;
free(args);
return (2); }
free(args);
return (1); }
if (check_is_comment(args))
return (1);
if ((_strcmp(args[0], "echo")) == 0 || args[0][0] == '$')
{_echo(args, ex_code);
free(args);
return (1); }
for (i = 0; args[i]; i++)
if (args[i][0] == '$')
_echo_get_var(args, i);
return (0); }


/**
 * _cd - function that prints all environment variables
 * @dest_dir: destination directory
 * @shellname: The name of the shell program
 * @count: The current command count
 * @check: check if _setenv already called or not
 * Return: integer number
 */
int _cd(char *dest_dir, char *shellname, int count, int check)
{
char *current_dir;
int old = 0;
struct stat dirStat;

if (!dest_dir)
dest_dir = _getenv("HOME");
if (!dest_dir)
return (-1);
current_dir = getcwd(NULL, 100);
if (_strcmp(dest_dir, "-") == 0)
{old = 1;
dest_dir = _getenv("OLDPWD");
if (!dest_dir)
{print_err_oldpwd(current_dir);
return (-1); }
}
if (!(stat(dest_dir, &dirStat) == 0 && S_ISDIR(dirStat.st_mode)))
{print_err_cd(shellname, dest_dir, count);
free(current_dir);
return (-1); }
check = (check == 1) ? 1 : 0;
if (chdir(dest_dir) == 0)
{_setenv("OLDPWD", current_dir, check);
free(current_dir);
current_dir = getcwd(NULL, 100);
_setenv("PWD", current_dir, 1);
if (old)
{_puts_std(1, current_dir);
__putchar('\n'); }
free(current_dir);
return (-2); }
else
{free(current_dir);
if (errno == EACCES)
{print_err_cd(shellname, dest_dir, count);
return (13); }
if (errno == ENOENT)
{print_err_cd(shellname, dest_dir, count);
return (2); }
}
return (0); }

/**
 * print_err_cd - Print an error message related to cd command
 * @shellname: The name of the shell invoking the function
 * @dir_name: name of directory associated with the error
 * @count: a count associated with the current operation
 */
void print_err_cd(char *shellname, char *dir_name, int count)
{
int len;
len = _slen(shellname);

_puts_len(2, shellname, len);
write(2, ": ", 2);
print_number(2, count);
write(2, ": ", 2);
_puts_len(2, "cd: can't cd to ", 16);
_puts_len(2, dir_name, _slen(dir_name));
write(2, "\n", 1);
}

/**
 * print_err_oldpwd - Print an error message related to 'cd -' command
 * and the old path not set
 * @current_dir: name of directory associated with the error
 */
void print_err_oldpwd(char *current_dir)
{
_puts_std(1, current_dir);
__putchar('\n');
free(current_dir);
}
