#include "main.h"

/**
 * print_char - prints a character from va_list.
 * @args: the va_list contains the arguments to print from.
 * @buffer: buffer
 * @len: current length of buffer
 *
 * Return: the length of the printed text.
 **/

int print_char(va_list args, char *buffer, unsigned int len)
{
	char out = va_arg(args, int);

	len = update_buffer(buffer, len, out);

	return (len);
}

/**
 * print_string - prints a string from va_list.
 * @args: the va_list contains the arguments to print from.
 * @buffer: buffer
 * @len: current length of buffer
 *
 * Return: the length of the printed text.
 **/

int print_string(va_list args, char *buffer, unsigned int len)
{
	char *out = va_arg(args, char*);
	unsigned int i = 0;

	if (out == NULL)
		out = "(null)";
	for (i = 0; out[i] != '\0'; i++)
		len = update_buffer(buffer, len, out[i]);
	return (len);
}
