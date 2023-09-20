#include "main.h"
/**
 * check_file_exist - function that check is an given file exist or not ,
 * and print message to stderr if the file not exist
 *
 * @shellname: The name of the shell invoking the function
 * @fname: a pointer to string that contains filename
 * @err_msg: Error message to be displayed if the file is not executable
 * @count: a count associated with the current operation
 *
 * Return: 1 if file exist or 0 if not exist.
 */
int check_file_exist(char *shellname, char *fname, char *err_msg, int count)
{
int len;
struct stat f_stat;

if ((stat(fname, &f_stat) == 0) && (fname[0] == '.' || fname[0] == '/'))
return (1);

len = _slen(shellname);

_puts_len(2, shellname, len);
write(2, ": ", 2);
print_number(2, count);
write(2, ": ", 2);
_puts_len(2, fname, _slen(fname));
write(2, ": ", 2);
_puts_len(2, err_msg, _slen(err_msg));
write(2, "\n", 1);
return (0);
}

/**
 * check_file_perm - function that check is a given file is executable
 * and print message to stderr if not executable
 *
 * @shellname: The name of the shell invoking the function
 * @filename: a pointer to string that contains filename
 * @err_msg: Error message to be displayed
 * @count: a count associated with the current operation
 *
 * Return: 1 if file executable or 0 if not executable
 */
int check_file_perm(char *shellname, char *filename, char *err_msg, int count)
{
int len;
struct stat f_stat;

if ((stat(filename, &f_stat) == 0))
if (f_stat.st_mode & S_IXUSR)
return (1);

len = _slen(shellname) - 2;
shellname = shellname + 2;
_puts_len(2, shellname, len);
write(2, ": ", 2);
print_number(2, count);
write(2, ": ", 2);
_puts_len(2, filename, _slen(filename));
write(2, ": ", 2);
_puts_len(2, err_msg, _slen(err_msg));
write(2, "\n", 1);
return (0);
}
/**
 * check_file - Check the existence and permissions of a file
 *
 * @shellname: The name of the shell invoking the function
 * @fname: pointer to the file associated with the error
 * @args: Array of arguments
 * @count: a count associated with the current operation
 *
 * Return: 0 on success, 126 if permission denied, 127 if file not found
 */
int check_file(char *shellname, char *fname, char **args, int count)
{
struct stat f_stat;

if (!((stat(fname, &f_stat) == 0) && (fname[0] == '.' || fname[0] == '/')))
{
print_err_file(shellname, fname, "not found", count);
free(args);
return (127);
}
/* if ((stat(fname, &f_stat) == 0)) */
if (!(f_stat.st_mode & S_IXUSR))
{
print_err_file(shellname, fname, "permission denied", count);
free(args);
return (126);
}
return (0);

}

/**
 * print_err_file - Print an error message related to a file
 *
 * @shellname: The name of the shell invoking the function
 * @filename: the file associated with the error
 * @err_msg: Error message to be displayed
 * @count: a count associated with the current operation
 */
void print_err_file(char *shellname, char *filename, char *err_msg, int count)
{
int len;
len = _slen(shellname);

_puts_len(2, shellname, len);
write(2, ": ", 2);
print_number(2, count);
write(2, ": ", 2);
_puts_len(2, filename, _slen(filename));
write(2, ": ", 2);
_puts_len(2, err_msg, _slen(err_msg));
write(2, "\n", 1);
}

/**
 * _putchar_err - write the character c to stdout
 *
 * @c: The character to print
 * @std:  file descriptors / standard I/O streams
 *
 * Return: 1 : On success .
 *        -1 : is returned, and errno is set appropriately.
 */

int _putchar_err(int std, char c)
{
return (write(std, &c, 1));
}

