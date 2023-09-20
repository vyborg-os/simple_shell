#ifndef MAIN_H
#define MAIN_H
#define __getline getline
#define _GNU_SOURCE
#include <sys/types.h>
#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
extern char **environ;

/** print_char_str.c **/
void print_number(int std, int n);
int _slen(char *s);
int _puts(char *c);
int __putchar(char c);
int _puts_len(int std, char *str, int len);

/** check_file.c **/
int _putchar_err(int std, char c);
int check_file_exist(char *shellname, char *filename, char *er_msg, int count);
int check_file_perm(char *shellname, char *filename, char *err_msg, int count);
void print_err_file(char *shellname, char *filename, char *err_msg, int count);
int check_file(char *shellname, char *filename, char **args, int count);

/** str_func.c **/
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _atoi(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

/** env.c **/
char *_getenv(char *var);
void _env(void);
int _setenv(char *name, const char *value, int count);
int _unsetenv(char *name, int count);
void free_env(char **old_env);

/** check_is_command.c **/
int check_is_env_cd(char **args, char *shellname, int count, int ex_code);
int _cd(char *dest_dir, char *shellname, int count, int check);
void print_err_cd(char *shellname, char *dir_name, int count);
void print_err_oldpwd(char *current_dir);
int check_if_exit(char **args, char *shname, int count, int ex_code, char **a);
/** check_is_env - exit_func.c **/


/** p_errors.c **/
int p_err_getline(void);
void p_err_write(int w);

/** strtok_alloc.c **/
char **strtok_alloc(char *line, ssize_t read);
char **strtok_alloc_semi_colom(char *line, ssize_t read);
int _puts_std(int std, char *c);


/** file_input_shell.c **/
void input_file_shell(char *argv[]);
int check_file_exist_argv(char *argv[]);

/** echo_variables.c **/
int _echo(char **args, int exit_code);
int _echo_get_var(char **args, int indice);

/** echo_variables.c **/
int _echo(char **args, int exit_code);
int _echo_get_var(char **args, int indice);


/** exec_command.c **/
int exec_cmd(char *cmd, char *args[]);

/** get_cmd_path.c **/
char *check_command_path(char *cmd);

/** free.c **/
void _free(char *, char *);
void _free_with_null(char **, char **);

/** str_func2.c **/
char *_strdup(const char *str);

/** check_is_comment.c **/
int check_is_comment(char **args);

/** shell.c **/
void non_interactive_shell(char *argv[]);


ssize_t _getline(char **line, size_t *size, FILE *stream);

#endif /*  MAIN_H  */

