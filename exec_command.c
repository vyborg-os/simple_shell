#include "main.h"
/**
 * exec_cmd - Execute a command with arguments
 * @args: An array of strings representing the command and its arguments
 * @cmd: pointer to strings representing the command name
 * Return: exit status
 */
int exec_cmd(char *cmd, char *args[])
{
	int status = 0, child_exit_code;
	pid_t child_pid, term_ch_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(cmd, args, environ) == -1)
			perror("execve");
	}
	else
	{
		term_ch_pid = waitpid(child_pid, &status, 0);
		if (term_ch_pid == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status))
		{child_exit_code = WEXITSTATUS(status);
			return (child_exit_code); }

	}
	return (0);
}
