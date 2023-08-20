#include "main.h"

/**
 * print_char - prints a character from va_list.
 * @args: the va_list contains the arguments to print from.
 *
 * Return: the length of the printed text.
 **/

int print_char(va_list args)
{
	char out = va_arg(args, int);

	write(1, &out, 1);

	return (1);
}

/**
 * print_string - prints a string from va_list.
 * @args: the va_list contains the arguments to print from.
 *
 * Return: the length of the printed text.
 **/

int print_string(va_list args)
{
	char *out = va_arg(args, char*);
	unsigned int out_len;

	if (out)
	{
		out_len = _strlen(out);
		if (out_len)
		{
			write(1, out, out_len);
			return (out_len);
		}
	}

	return (0);
}
