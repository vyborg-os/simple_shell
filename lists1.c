#include "shell.h"

/**
 * Determines the length of a linked list.
 *
 * @param h: Pointer to the first node.
 *
 * @return: Size of the list.
 */
size_t list_len(const list_t *h) {
    size_t i = 0;

    while (h) {
        h = h->next;
        i++;
    }

    return (i);
}

/**
 * Converts a linked list of strings to an array of strings.
 *
 * @param head: Pointer to the first node.
 *
 * @return: Array of strings.
 */
char **list_to_strings(list_t *head) {
    list_t *node = head;
    size_t i = list_len(head), j;
    char **strs;
    char *str;

    if (!head || !i) {
        return (NULL);
    }

    strs = malloc(sizeof(char *) * (i + 1));
    if (!strs) {
        return (NULL);
    }

    for (i = 0; node; node = node->next, i++) {
        str = malloc(_strlen(node->str) + 1);
        if (!str) {
            for (j = 0; j < i; j++) {
                free(strs[j]);
            }
            free(strs);
            return (NULL);
        }

        str = _strcpy(str, node->str);
        strs[i] = str;
    }

    strs[i] = NULL;
    return (strs);
}

/**
 * Prints all elements of a list_t linked list.
 *
 * @param h: Pointer to the first node.
 *
 * @return: Size of the list.
 */
size_t print_list(const list_t *h) {
    size_t i = 0;

    while (h) {
        _puts(convert_number(h->num, 10, 0));
        _putchar(':');
        _putchar(' ');
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        i++;
    }

    return (i);
}

/**
 * Returns the node whose string starts with a prefix and matches a character.
 *
 * @param node: Pointer to the list head.
 * @param prefix: String to match.
 * @param c: The next character after the prefix to match.
 *
 * @return: Matching node or NULL.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c) {
    char *p = NULL;

    while (node) {
        p = starts_with(node->str, prefix);
        if (p && ((c == -1) || (*p == c))) {
            return (node);
        }
        node = node->next;
    }

    return (NULL);
}

/**
 * Gets the index of a node in a linked list.
 *
 * @param head: Pointer to the list head.
 * @param node: Pointer to the node.
 *
 * @return: Index of the node or -1.
 */
ssize_t get_node_index(list_t *head, list_t *node) {
    size_t i = 0;

    while (head) {
        if (head == node) {
            return (i);
        }
        head = head->next;
        i++;
    }

    return (-1);
}
