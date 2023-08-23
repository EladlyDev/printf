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

/**
 * print_S - prints the string.
 * non printable characters are printed this way: \x
 * followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters)
 * @args: the va_list contains the arguments to print from.
 * @buffer: buffer
 * @len: current length of buffer
 *
 * Return: length of the buffer
 **/

int print_S(va_list args, char *buffer, unsigned int len)
{
	char *str = va_arg(args, char*);
	unsigned int i = 0;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		if (str[i] >= 32 && str[i] < 127)
			len = update_buffer(buffer, len, str[i]);
		else
		{
			int c = str[i];
			char *hex = itox(c, 1);

			len = update_buffer(buffer, len, '\\');
			len = update_buffer(buffer, len, 'x');
			if (c < 16)
			{
				len = update_buffer(buffer, len, '0');
				len = update_buffer(buffer, len, hex[0]);
			}
			else
			{
				len = update_buffer(buffer, len, hex[0]);
				len = update_buffer(buffer, len, hex[1]);
			}
			free(hex);
		}
	return (len);
}
