#include "monty.h"

/**
 * main - Entry point for a Monty script interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of strings containing the arguments
 *
 * Description: This function serves as the entry point for a Monty script
 * interpreter. It takes one command-line argument, the Monty script file,
 * and checks the argument count before attempting to open the file. If
 * successful, it calls parsefile() to execute the script.
 *
 * Return: EXIT_SUCCESS on script success, EXIT_FAILURE on errors (e.g.,
 * invalid args or file not found).
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	parsefile(file);
	return (EXIT_SUCCESS);
}
