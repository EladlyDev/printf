#include "main.h"

/**
 * print_hex - prints a number in print a number
 * in hexidecimal (base 16) using abcdef
 * @args: va_list arguments
 *
 * Return: legth of the printed characters.
 *
 */
int print_hex(va_list args)
{
	unsigned int num;
	char hexNum[100], i = 0, j;

	num = va_arg(args, unsigned int);

	while (num > 0)
	{
		int rem = num % 16;

		hexNum[i] = rem < 10 ? rem + '0' : rem - 10 + 'a';
		num /= 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		_printf("%c", hexNum[j]);
	return (i + 1);
}

/**
 * printHEX - prints a number in print a number
 * in hexidecimal (base 16) using ABCDEF
 * @args: va_list arguments
 *
 * Return: legth of the printed characters.
 *
 */
int printHEX(va_list args)
{
	unsigned int num;
	char hexNum[100], i = 0, j;

	num = va_arg(args, unsigned int);

	while (num > 0)
	{
		int rem = num % 16;

		hexNum[i] = rem < 10 ? rem + '0' : rem - 10 + 'A';
		num /= 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		_printf("%c", hexNum[j]);
	return (i + 1);
}
