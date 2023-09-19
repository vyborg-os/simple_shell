#include "shell.h"

/**
 * bfree - Frees a pointer and sets it to NULL
 * @ptr: Address of the pointer to free
 *
 * This function frees the memory pointed to by 'ptr' and sets 'ptr' to NULL.
 *
 * Returns:
 *   - 1 if the memory was successfully freed.
 *   - 0 if 'ptr' was already NULL or if an error occurred during freeing.
 */
int bfree(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
        return 1;
    }
    return 0;
}
