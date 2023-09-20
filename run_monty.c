#include "monty.h"

/**
 * run_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char line[MAX_LINE_LENGTH];
	size_t line_length;
	size_t exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (fgets(line, sizeof(line), script_fd) != NULL)
	{
		line_number++;

		line_length = strlen(line);
		if (line_length > 0 && line[line_length - 1] == '\n')
			line[line_length - 1] = '\0';

		op_toks = strtow(line, DELIMS);

		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			free_tokens();
			continue;
		}

		op_func = get_op_func(op_toks[0]);

		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_error(op_toks[0], line_number);
			free_tokens();
			break;
		}

		prev_tok_len = token_arr_len();
		op_func(&stack, line_number);

		if (token_arr_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}

		free_tokens();
	}

	free_stack(&stack);
	return (exit_status);
}

