#include "main.h"

/**
 * check_file_exist - Checks if a file exists and displays an error message to stderr if not.
 *
 * @shellname: Name of the invoking shell
 * @fname: Pointer to the filename string
 * @err_msg: Error message to display if the file is not found
 * @count: Count associated with the current operation
 *
 * Return: 1 if the file exists, 0 if it does not.
 */
int check_file_exist(char *shellname, char *fname, char *err_msg, int count) {
    int len;
    struct stat f_stat;

    if ((stat(fname, &f_stat) == 0) && (fname[0] == '.' || fname[0] == '/'))
        return 1;

    len = _slen(shellname);

    _puts_len(2, shellname, len);
    write(2, ": ", 2);
    print_number(2, count);
    write(2, ": ", 2);
    _puts_len(2, fname, _slen(fname));
    write(2, ": ", 2);
    _puts_len(2, err_msg, _slen(err_msg));
    write(2, "\n", 1);

    return 0;
}

/**
 * check_file_perm - Checks if a file is executable and displays an error message to stderr if not.
 *
 * @shellname: Name of the invoking shell
 * @filename: Pointer to the filename string
 * @err_msg: Error message to display
 * @count: Count associated with the current operation
 *
 * Return: 1 if the file is executable, 0 if it is not.
 */
int check_file_perm(char *shellname, char *filename, char *err_msg, int count) {
    int len;
    struct stat f_stat;

    if ((stat(filename, &f_stat) == 0))
        if (f_stat.st_mode & S_IXUSR)
            return 1;

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

    return 0;
}

/**
 * check_file - Checks the existence and permissions of a file.
 *
 * @shellname: Name of the invoking shell
 * @fname: Pointer to the filename associated with the error
 * @args: Array of arguments
 * @count: Count associated with the current operation
 *
 * Return: 0 on success, 126 if permission is denied, 127 if the file is not found
 */
int check_file(char *shellname, char *fname, char **args, int count) {
    struct stat f_stat;

    if (!((stat(fname, &f_stat) == 0) && (fname[0] == '.' || fname[0] == '/'))) {
        print_err_file(shellname, fname, "not found", count);
        free(args);
        return 127;
    }

    if (!(f_stat.st_mode & S_IXUSR)) {
        print_err_file(shellname, fname, "permission denied", count);
        free(args);
        return 126;
    }

    return 0;
}

/**
 * print_err_file - Prints an error message related to a file.
 *
 * @shellname: Name of the invoking shell
 * @filename: The file associated with the error
 * @err_msg: Error message to be displayed
 * @count: Count associated with the current operation
 */
void print_err_file(char *shellname, char *filename, char *err_msg, int count) {
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
 * _putchar_err - Writes the character c to stdout.
 *
 * @c: The character to print
 * @std: File descriptors / standard I/O streams
 *
 * Return: 1 on success, -1 if an error occurs (and errno is set).
 */
int _putchar_err(int std, char c) {
    return write(std, &c, 1);
}
