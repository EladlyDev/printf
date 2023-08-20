#include "main.h"

/**
 * itos - convert an int to a string
 * @n: unsigned integer
 *
 * Return: string rep of integer
 */
char *itos(unsigned int n)
{
	int dig_count = 0;
	int idx, num = n;
	char *str;

	/* Count the digits of n*/
	do {
		dig_count++;
		num /= 10;
	} while (num != 0);

	/* Allocate space for all digits + null byte*/
	str = malloc(dig_count + 1);
	if (!str)
		return (NULL);
	/*Fill the string strating from the last character*/
	idx = dig_count - 1;
	do {
		str[idx] = '0' + (n % 10);
		n /= 10;
		idx--;
	} while (n != 0);
	str[dig_count] = '\0';

	return (str);
}

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
