#include "monty.h"

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{	
	int i;
	int j;

	if (line == NULL || delims == NULL)
        return 0;

    for (i = 0; line[i] != '\0'; i++)
    {
        int is_delim = 0;

        for (j = 0; delims[j] != '\0'; j++)
        {
            if (line[i] == delims[j])
            {
                is_delim = 1;
                break;
            }
        }

        if (!is_delim)
        {
            return 0;
        }
    }

    return 1;
}
