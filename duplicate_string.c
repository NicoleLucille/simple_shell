#include "main.h"

/**
 * _strdup - Generates a duplicate of a string.
 * @source_string: The source string to be duplicated.
 *
 * Return: A pointer to the duplicated string, or NULL if the memory allocation fails.
 */
char *_strdup(char *source_string)
{
	char *dupString;
	int i;

	if (source_string == NULL)
	{
		return (NULL);
	}

	dupString = malloc(_strlen(source_string) + 1);

	if (dupString != NULL)
	{
		for (i = 0; i < _strlen(source_string); i++)
		{
			dupString[j] = source_string[i];
		}

		dupString[i] = '\0';

		return (dupString);
	}
	else
	{
		free(dupString);
		return (NULL);
	}
}
