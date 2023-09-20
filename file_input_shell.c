#include "main.h"

/**
 * input_file_shell - function that execute command in non-interactive mode
 * @argv: An array of pointers that contains the command-line arguments
 *      provided to shell
 * Return:  it exits with an exit code when all commands have been executed
 *            or an error occurs
 */
void input_file_shell(char *argv[])
{
char **args, *cmd, *cmd1, buffer[1024] = {'\0'}, buffer1[1024] = {'\0'};
ssize_t r = 0;
int fd, i, j = 0, ex_cod = 0, c_e_c = 0, count = 0, c_exit = 0;
check_file_exist_argv(argv);
fd = open(argv[1], O_RDONLY);
if (fd == -1)
exit(1);
r = read(fd, buffer, sizeof(buffer));
if (r == -1)
exit(1);
while (1)
{
for (i = 0; buffer[i]; i++, j++, count++)
{ buffer1[j] = buffer[i];
if (buffer[i] == '\n')
{ buffer1[j] = '\0';
if (!buffer1[0])
{ j = -1;
continue; }
args = strtok_alloc(buffer1, r);
if (!args[0])
{ free(args);
continue; }
if ((check_is_env_cd(args, argv[0], count, ex_cod)))
continue;
c_exit = check_if_exit(args, argv[0], count, c_e_c, NULL);
if (c_exit >= 0 || c_exit == -2)
{c_exit = (c_exit >= 0) ? c_exit : 2;
exit(c_exit); }
cmd1 = check_command_path(args[0]);
cmd = !cmd1 ? args[0] : cmd1;
if ((check_file(argv[0], cmd, args, count)))
continue;
c_e_c = exec_cmd(cmd, args);
_free(NULL, cmd1);
free(args);
j = -1; }
}
exit(ex_cod); }
}



/**
 * check_file_exist_argv - function that check is an given file exist or not ,
 * and print message to stderr if the file not exist
 * @argv: array of pointer that point to each argumrnt passed to program
 * Return: 1 if file exist or 0 if not exist.
 */
int check_file_exist_argv(char *argv[])
{
int len;
struct stat f_stat;

if ((stat(argv[1], &f_stat) == 0))
return (1);
len = _slen(argv[0]);
_puts_len(2, argv[0], len);
write(2, ": 0: Can't open ", 16);
_puts_len(2, argv[1], _slen(argv[1]));
write(2, "\n", 1);
exit(127);
}


