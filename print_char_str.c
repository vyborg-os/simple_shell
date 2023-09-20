#include "main.h"

/**
 * print_number - Write an integer number to the specified file descriptor.
 * @std: File descriptor to which the number is printed.
 * @n: The number to print.
 */
void print_number(int std, int n) {
    if (n / 10 == 0) {
        _putchar_err(std, n + 48);
        return;
    }

    if (n / 10 > 0) {
        print_number(std, n / 10);
        _putchar_err(std, (n % 10) + 48);
    }
}

/**
 * _slen - Calculate the length of a string.
 * @s: Pointer to the string.
 * Return: The length of the string.
 */
int _slen(char *s) {
    int i = 0;
    while (s[i]) {
        i++;
    }
    return (i);
}

/**
 * _puts - Write the characters of a string to stdout.
 * @c: Pointer to the string.
 * Return: The number of characters printed.
 */
int _puts(char *c) {
    return (write(1, c, _slen(c)));
}

/**
 * __putchar - Write a character to stdout.
 * @c: The character to print.
 * Return: 1 on success, -1 on error.
 */
int __putchar(char c) {
    return (write(1, &c, 1));
}

/**
 * _puts_len - Write a specified number of characters to stdout.
 * @std: File descriptors / standard I/O streams.
 * @str: Pointer to the string.
 * @len: Number of characters to write.
 * Return: The number of characters printed.
 */
int _puts_len(int std, char *str, int len) {
    return (write(std, str, len));
}
