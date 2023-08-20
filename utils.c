#include "main.h"

/**
 * _strlen - gets the length of a string, without the null terminator.
 * @str: the string
 *
 * Return: the length of @str.
 **/
unsigned int _strlen(char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * check_format - to handle the edge cases in _printf.
 * @format: the format passed to _printf.
 *
 * Return: 0 if there's any issues, 1 on succeed.
 **/
int check_format(const char *format)
{
	int i;

	if (!format || *format == '\0')
		return (0);


	for (i = 0; format[i];)
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			i += 2;
			continue;
		}
		if (format[i] == '%' && !get_func(format[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
