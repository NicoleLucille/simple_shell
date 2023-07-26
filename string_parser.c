#include "main.h"
#include <string.h>

/**
 * parse_data - Data parsing function for the input obtained from getline
 * @data_string: User input string
 * Return: An array of strings representing tokenized values
 */
char **parse_data(char *data_string)
{
	const char *delimiter = " \n\t\r";
	char *string_token;
	char **arguments;
	size_t num_token = 0;
	size_t len = 0;

	arguments = malloc(sizeof(char *) * (num_token + 5));
	if (arguments == NULL)
	{
		free_arguments(arguments);
		return (NULL);
	}
	string_token = strtok(data_string, delimiter);
	len = _strlen(string_token);
	while (string_token != NULL)
	{
		arguments[num_token] = malloc(len + 1);
		if (arguments[num_token] == NULL)
		{
			free_arguments(arguments);
			return (NULL);
		}
		_strcpy(arguments[num_token], string_token);
		string_token = strtok(NULL, delimiter);
		if (string_token != NULL)
		{
			len = _strlen(string_token);
		}
		num_token++;
	}
	arguments[num_token] = NULL;
	return (arguments);
}

/**
 * free_arguments - Token array deallocation function
 * @arguments: A pointer to a string array (tokens)
 * Return: Void
 */
void free_arguments(char **arguments)
{
	int i = 0;

	while (arguments[i] != NULL)
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}
