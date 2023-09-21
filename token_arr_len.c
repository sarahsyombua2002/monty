#include "monty.h"

/**
 * token_arr_len - Counts the number of tokens in the global op_toks array.
 *
 * Return: Number of tokens in the array.
 */
size_t token_arr_len(void)
{
    size_t count = 0;
    while (op_toks != NULL && op_toks[count] != NULL)
        count++;
    return count;
}

