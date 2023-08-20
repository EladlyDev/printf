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
	int binary;
	unsigned int num;

	num = va_arg(args, unsigned int);

	binary = itob(num);
	return (_printf("%d", binary));
}
