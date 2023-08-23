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
