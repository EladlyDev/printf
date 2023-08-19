#include "main.h"

/**
 * _strlen - gets the length of a string, without the null terminator.
 * @str: the string
 *
 * Return: the length of @str.
 **/
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}
