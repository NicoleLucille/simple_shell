#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strlen - Determines the string length.
 * @str: String input.
 *
 * Return: The string length.
 */
int _strlen(char *str)
{
	int len = 0;

	if (str != NULL)
	{
		while (*(str + len))
		{
			len++;
		}
	}

	return (len);
}

/**
 * _strcpy - Duplicates a string from the source to the destination.
 * @dest: The string destination.
 * @src: The string source.
 *
 * Return: An address pointing to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;
	int y;

	if (src == NULL)
	{
		return (dest);
	}

	while (*(src + x) != '\0')
	{
		x++;
	}

	for (y = 0; y < x; y++)
	{
		dest[y] = src[y];
	}

	dest[x] = '\0';

	return (dest);
}

/**
 * _strcmp - Contrasts two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: Either 0, a negative value, or a positive value
 */
int _strcmp(char *string1, char *string2)
{
	if (str1 == NULL || str2 == NULL)
	{
		return (-1);
	}

	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}

/**
 * _strchr - Locates the initial occurrence of a char within a given string.
 * @str: The string input.
 * @c: The character to be located.
 *
 * Return:  NULL or a pointer to the first instance
 */
char *_strchr(char *str, char c)
{
	if (str == NULL)
	{
		return (NULL);
	}

	while ((*str != c) && (*str != '\0'))
	{
		str++;
	}

	if (*str == c)
	{
		return (str);
	}

	return (NULL);
}

/**
 * _strcat - Merges two strings together.
 * @dest: The string destination.
 * @src: The string source.
 *
 * Return: A address pointer to the destination string.
 */
char *_strcat(char *dest, char *src)
{
	int x = 0;
	int y = 0;

	if ((src == NULL && dest == NULL) || dest == NULL)
	{
		return (NULL);
	}

	if (src == NULL)
	{
		return (dest);
	}

	while (dest[x] != '\0')
	{
		x++;
	}

	while (src[y] != '\0')
	{
		dest[x] = src[y];
		x++;
		y++;
	}

	dest[x] = '\0';

	return (dest);
}
