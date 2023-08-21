#include "main.h"

/**
 * print_int - prints an integer to stdout.
 * @args: integer
 * @buffer: buffer
 * @len: current length  of buffer
 *
 * Return: 0 (Success)
 */
int print_int(va_list args, char *buffer, unsigned int len)
{
	char *str;
	unsigned int n;
	int num, i;

	num = va_arg(args, int);

	/*Hangle negative numbers & INT_MIN*/
	n = num < 0 ? num * -1 : num;

	str = itos(n);

	if (str)
	{
		if (num < 0)
		{
			buffer[len] = '-';
			len++;
		}
		for (i = 0; str[i] != '\0'; i++)
		{
			buffer[len] = str[i];
			len++;
		}
		if (num < 0)
			i++;
		free(str);
		return (i);
	}
	return (0);
}

/**
 * print_binary - This function prints unsigned int as a binary.
 * @args: the list of arguments where the number comes from.
 * @buffer: buffer
 * @len: current length  of buffer
 *
 * Return: the length of the printed number, 0 on faliure.
 **/
int print_binary(va_list args, char *buffer, unsigned int len)
{
	int arr[32], i = 0, j;
	unsigned int num;

	num = va_arg(args, unsigned int);

	for (i = 0; num > 0; i++)
	{
		arr[i] = num % 2;
		num = num / 2;
	}
	if (i == 0)
	{
		buffer[len] = '0';
		return (1);
	}
	for (j = i - 1; j >= 0; j--)
	{
		buffer[len] = arr[j] + '0';
		len++;
	}
	return (i);
}

/**
 * print_ui - prints an unsigned int.
 * @args: va_list of arguments
 * @buffer: buffer
 * @len: current length  of buffer
 *
 * Return: legth of the printed characters
 **/
int print_ui(va_list args, char *buffer, unsigned int len)
{
	char *str;
	unsigned int i = 0, num;

	num = va_arg(args, unsigned int);

	str = itos(num);

	if (str)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			buffer[len] = str[i];
			len++;
		}
		free(str);
		return (i);
	}
	return (0);

}
/**
 * print_octal - print a number in octal (base 8).
 * @args: va_list arguments
 * @buffer: buffer
 * @len: current length  of buffer
 *
 *Return: length of the printed characters
 **/
int print_octal(va_list args, char *buffer, unsigned int len)
{
	unsigned int num;
	int oNum[100], i = 0, j;

	num = va_arg(args, unsigned int);

	while (num > 0)
	{
		oNum[i] = num % 8;
		num /= 8;
		i++;
	}
	if (i == 0)
	{
		buffer[len] = '0';
		return (1);
	}
	for (j = i - 1; j >= 0; j--)
	{
		buffer[len] = oNum[j] + '0';
		len++;
	}
	return (i);
}
