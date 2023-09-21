#include "monty.h"

/**
 * get_int - Converts a string to an integer.
 * @str: The string to convert.
 *
 * Return: The integer representation of the string.
 */
int get_int(char *str)
{
    int num;
    if (str == NULL)
        return 0;

    num = atoi(str);
    return num;
}

