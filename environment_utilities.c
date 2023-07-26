#include "main.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * _getenv - finds the value associated with an environment variable
 * @name: environment variable name
 * Return: environment variable value
 */
char *_getenv(char *name)
{
	int index = 0;
	char *env_var_value;
	char *env_var_entry;

	if (name == NULL)
		return (NULL);

	env_var_entry = environ[index];
	while (env_var_entry != NULL)
	{
		if (_strcmp(env_var_entry, name) == 0)
		{
			env_var_value = _strchr(env_var_entry, '=');
			if (env_var_value == NULL)
				return (NULL);
			return (env_var_value + 1);
		}
		index++;
	}

	return (NULL);
}

/**
 * real_path - gets the path of the executable file, thereby resolving
 * @command: the name of the command
 * Return: File path containing the executable code
 */
char *real_path(char *command)
{
	char *path = NULL;
	char *new_path = NULL;
	char *path_token = NULL;
	char *find_path = NULL;
	const char *delim = ":";
	struct stat buffer;

	if (command == NULL)
		return (NULL);
	if (_strchr(command, '/') != NULL || _strchr(command, '.') != NULL)
	{
		if ((stat(command, &buffer) == 0) && (access(command, X_OK) == 0))
		{
			return (_strdup(command));
		}
		return (NULL);
	}
	path = getenv("PATH");
	new_path = _strdup(path);
	if (path == NULL)
		return (NULL);
	path_token = strtok(new_path, delim);
	while (path_token != NULL)
	{
		find_path = malloc(_strlen(path_token) + _strlen(command) + 2);
		if (find_path == NULL)
			return (NULL);
		strcpy(find_path, path_token);
		strcat(find_path, "/");
		strcat(find_path, command);
		if ((access(find_path, X_OK) == 0) && (stat(find_path, &buffer) == 0))
		{
			free(new_path);
			return (find_path);
		}
		free(find_path);
		path_token = strtok(NULL, delim);
	}
	free(new_path);
	return (NULL);
}
/**
 * process_command - replaces the running child process with a new executable
 * @arguments: command line arguments of an array
 * Return: void
 */
void process_command(char **arguments)
{
	pid_t child_pid;
	int status = 0;
	char *executable_path = NULL;
	char *error_msg = "Command not found: ";

	if (arguments == NULL)
		return;

	executable_path = real_path(arguments[0]);
	if (executable_path == NULL)
	{
		write(STDERR_FILENO, error_msg, _strlen(error_msg));
		write(STDERR_FILENO, arguments[0], _strlen(arguments[0]));
		write(STDERR_FILENO, "\n", 1);
		return;
	}
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("child");
		exit(0);
	}
	else if (child_pid == 0)
	{
		if (execve(executable_path, arguments, environ) == -1)
		{
			perror("execve");
			exit(0);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(0);
		}
	}
	free(executable_path);
}
