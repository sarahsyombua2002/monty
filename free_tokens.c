#include "monty.h"

/**
 * free_tokens - Frees the tokens created by strtok in the global op_toks array.
 */
void free_tokens(void)
{
	size_t i;

    	if (op_toks == NULL)
        return;

    for ( i = 0; op_toks[i] != NULL; i++)
        free(op_toks[i]);

    free(op_toks);
    op_toks = NULL;
}

