#include "main.h"

/**
 * print_hex - prints a number in print a number
 * in hexidecimal (base 16) using abcdef
 * @args: va_list arguments
 * @buffer: buffer
 * @len:current length of buffer
 *
 * Return: legth of the printed characters.
 *
 */
int print_hex(va_list args, char *buffer, unsigned int len)
{
	unsigned int num;
	int i = 0;
	char *hexNum;

	num = va_arg(args, unsigned int);

	hexNum = itox(num, 0);

	for (i = 0; hexNum[i] != '\0'; i++)
		len = update_buffer(buffer, len, hexNum[i]);
	free(hexNum);
	return (len);
}

/**
 * printHEX - prints a number in print a number
 * in hexidecimal (base 16) using ABCDEF
 * @args: va_list arguments
 * @buffer: buffer
 * @len:current length of buffer
 *
 * Return: legth of the printed characters.
 *
 */
int printHEX(va_list args, char *buffer, unsigned int len)
{
	unsigned int num;
	int i = 0;
	char *hexNum;

	num = va_arg(args, unsigned int);

	hexNum = itox(num, 1);

	for (i = 0; hexNum[i] != '\0'; i++)
		len = update_buffer(buffer, len, hexNum[i]);
	free(hexNum);
	return (len);
}

/**
 * print_p: for handling %p in _printf.
 * @args: va_list to get the address from.
 * @buffer: the buffer to append to.
 * @len: the current length of the buffer.
 *
 * Return: the new length of the buffer.
 **/
int print_p(va_list args, char *buffer, unsigned int len)
{
	long out = (long)va_arg(args, void *);
	char *hex;
	int i;

	if (out != 0)
	{
		hex = itox(out, 0);
		len = update_buffer(buffer, len, '0');
		len = update_buffer(buffer, len, 'x');
	}
	else
		hex = "(nil)";

	for (i = 0; hex[i]; i++)
		len = update_buffer(buffer, len, hex[i]);

	if (hex[0] != '(')
		free(hex);
	return (len);
}
