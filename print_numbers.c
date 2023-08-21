#include "main.h"

/**
 * print_int - prints an integer to stdout.
 * @args: integer
 *
 * Return: 0 (Success)
 */
int print_int(va_list args)
{
	char *str;
	unsigned int n, len = 0;
	int num;

	num = va_arg(args, int);

	/*Hangle negative numbers & INT_MIN*/
	n = num < 0 ? num * -1 : num;

	str = itos(n);

	if (str)
	{
		char c = '-';

		if (num < 0)
			write(1, &c, 1);
		len = _strlen(str);
		write(1, str, len);
		free(str);
		len = num < 0 ? len + 1 : len;
		return (len);
	}
	return (0);
}

/**
 * print_binary - This function prints unsigned int as a binary.
 * @args: the list of arguments where the number comes from.
 *
 * Return: the length of the printed number, 0 on faliure.
 **/
int print_binary(va_list args)
{
	int arr[32], i, len = 0;
	unsigned int num;

	num = va_arg(args, unsigned int);

	for (i = 0; num > 0; i++)
	{
		arr[i] = num % 2;
		num = num / 2;
	}
	for (i = i - 1; i >= 0; i--)
	{
		_printf("%d", arr[i]);
		len++;
	}
	return (len);
}

/**
 * print_ui - prints an unsigned int.
 * @args: va_list of arguments
 *
 * Return: legth of the printed characters
 **/
int print_ui(va_list args)
{
	char *str;
	unsigned int len = 0, num;

	num = va_arg(args, unsigned int);

	str = itos(num);

	if (str)
	{
		len = _strlen(str);
		write(1, str, len);
		free(str);
		return (len);
	}
	return (0);

}
/**
 * print_octal - print a number in octal (base 8).
 * @args: va_list arguments
 *
 *Return: length of the printed characters
 **/
int print_octal(va_list args)
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
	for (j = i - 1; j >= 0; j--)
		_printf("%d", oNum[j]);
	return (i);
}
