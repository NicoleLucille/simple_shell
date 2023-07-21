#include "main.h"

/**
 * main - The point of entry for the custom shell
 * This function serves as a fundamental shell that,
 * accepting user input, parsing it, executing commands.
 * presenting a shell prompt to interactively read input from the user
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char **arguments;
	char *shell_prompt = "$ ";
	char *user_input_value = NULL;
	size_t user_input_size = 0;
	int user_input_length = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, shell_prompt, _strlen(shell_prompt));
		}
		user_input_length = getline(&user_input_value, &user_input_size, stdin);
		if (user_input_length == -1)
		{
			free(user_input_value);
			exit(0);
		}
		if (user_input_value[user_input_length - 1] == '\n')
		{
			user_input_value[user_input_length - 1] = '\0';
		}
		arguments = parse_data(user_input_value);
		if (arguments != NULL)
		{
			process_command(arguments);
		}
		free_arguments(arguments);
	}
	free(user_input_value);
	return (0);
}
