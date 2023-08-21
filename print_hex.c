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
	int i = 0, j;
	char hexNum[100];

	num = va_arg(args, unsigned int);

	while (num > 0)
	{
		int rem = num % 16;

		hexNum[i] = rem < 10 ? rem + '0' : rem - 10 + 'a';
		num /= 16;
		i++;
	}
	if (i == 0)
	{
		buffer[len] = '0';
		buffer[len + 1] = '\0';
		return (1);
	}
	for (j = i - 1; j >= 0; j--)
	{
		buffer[len] = hexNum[j];
		len++;
	}
	buffer[len + 1] = '\0';
	return (i);
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
	int i = 0, j;
	char hexNum[100];

	num = va_arg(args, unsigned int);

	while (num > 0)
	{
		int rem = num % 16;

		hexNum[i] = rem < 10 ? rem + '0' : rem - 10 + 'A';
		num /= 16;
		i++;
	}
	if (i == 0)
	{
		buffer[len] = '0';
		buffer[len + 1] = '\0';
		return (1);
	}
	for (j = i - 1; j >= 0; j--)
	{
		buffer[len] = hexNum[j];
		len++;
	}
	buffer[len + 1] = '\0';
	return (i);
}
