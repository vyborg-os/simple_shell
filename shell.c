#include "main.h"

/**
 * non_interactive_shell - Execute commands in non-interactive mode.
 * @argv: An array of pointers that contains the command-line arguments.
 */
void non_interactive_shell(char *argv[]) {
    char *line = NULL, **args, **args_c = NULL, *cmd, *cmd1;
    size_t len = 0;
    ssize_t r = 0;
    int count = 0, ch_ex_c = 0, c_exit = 0, env = 0, f = 0, i = 0;
    
    while ((r = __getline(&line, &len, stdin)) != -1) {
        args_c = strtok_alloc_semi_colon(line, r);
        
        if (args_c == NULL)
            continue;
        
        for (i = 0; args_c[i]; i++) {
            count++;
            args = strtok_alloc(args_c[i], 1);
            
            if (args == NULL)
                continue;
            
            env = check_is_env_cd(args, argv[0], count, ch_ex_c);
            
            if (env) {
                if (env == 2)
                    f = 2;
                ch_ex_c = 0;
                continue;
            }
            
            c_exit = check_if_exit(args, argv[0], count, ch_ex_c, args_c);
            
            if (c_exit == -2) {
                free(line);
                exit(2);
            }
            
            if (c_exit >= 0) {
                free(line);
                exit(c_exit);
            }
            
            cmd1 = check_command_path(args[0]);
            cmd = !cmd1 ? args[0] : cmd1;
            ch_ex_c = check_file(argv[0], cmd, args, count);
            
            if (ch_ex_c)
                continue;
            
            ch_ex_c = exec_cmd(cmd, args);
            _free(NULL, cmd1);
            free(args);
        } /* for */
        
        free(args_c);
    } /* while */
    
    free(line);
    
    if (f == 2)
        free_env(environ);
    
    exit(ch_ex_c);
}

/**
 * main - Main function of a simple shell.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of pointers that point to each argument passed to the program.
 * Return: Always 0 on success.
 */
int main(int argc __attribute__((unused)), char *argv[]) {
    char *line = NULL, **args, *cmd, *cmd1 = NULL, **args_c = NULL;
    size_t len = 0;
    ssize_t read = 0, w;
    int count = 0, c_exit = 0, env = 0, f = 0;
    
    if (argc == 2)
        input_file_shell(argv);
    
    if (!isatty(STDIN_FILENO))
        non_interactive_shell(argv);
    
    while (1) {
        w = write(1, "($) ", 4);
        p_err_write(w);
        count++;
        read = __getline(&line, &len, stdin);
        args = strtok_alloc(line, read);
        
        if (args == NULL)
            continue;
        
        c_exit = check_if_exit(args, argv[0], count, 0, args_c);
        
        if (c_exit == -2) {
            c_exit = 2;
            continue;
        }
        
        if (c_exit >= 0)
            break;
        
        env = check_is_env_cd(args, argv[0], count, c_exit);
        
        if (env) {
            if (env == 2)
                f = 2;
            continue;
        }
        
        cmd1 = check_command_path(args[0]);
        cmd = !cmd1 ? args[0] : cmd1;
        
        if (check_file(argv[0], cmd, args, count))
            continue;
        
        exec_cmd(cmd, args);
        _free_with_null(&line, &cmd1);
        free(args);
    }
    
    _free(line, cmd1);
    
    if (f == 2)
        free_env(environ);
    
    return (c_exit);
}
