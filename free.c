#include "main.h"

/**
 * _free - Release memory occupied by character pointers.
 * @a: Pointer to a character array.
 * @b: Another character array.
 */
void _free(char *a, char *b) {
    if (a)
        free(a);

    if (b)
        free(b);
}

/**
 * _free_with_null - Release memory occupied by character pointers
 * and set them to NULL.
 * @a: Pointer to a character array.
 * @b: Another character array.
 */
void _free_with_null(char **a, char **b) {
    if (a && *a) {
        free(*a);
        *a = NULL;
    }

    if (b && *b) {
        free(*b);
        *b = NULL;
    }
}
