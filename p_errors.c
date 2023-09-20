#include "main.h"

/**
 * p_err_getline - Handle errors when the getline function fails.
 * Return: Exit status.
 */
int p_err_getline(void) {
    if (errno == 0) {
        exit(0);
    }

    if (errno != 0 && errno == EOF) {
        exit(0);
    }

    write(1, "\n", 1);

    if (errno != 0 && errno != EOF) {
        exit(1);
    }

    exit(0);
}

/**
 * p_err_write - Handle errors when the write system call fails.
 * @w: Return value of the write system call.
 */
void p_err_write(int w) {
    if (w == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
}
