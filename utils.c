#include "main.h"

/**
 * _strlen - gets the length of a string, without the null terminator.
 * @str: the string
 *
 * Return: the length of @str.
 **/
unsigned int _strlen(char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * print_buffer - prints n bytes of buffer to STDOUT
 * @buffer: buffer
 * @n: number of bytes to print
 *
 **/
void print_buffer(char *buffer, unsigned int n)
{
	write(1, buffer, n);
	free(buffer);
}

/**
 * itob - converts an integer into binary.
 * @num: the integer.
 *
 * Return: the binary representation of @num.
 **/
int itob(int num)
{
	if (num < 2)
		return (num);

	return (itob(num / 2) * 10 + num % 2);
}

/**
 * itos - convert a number to a string
 * @n: number
 *
 * Return: string rep of integer
 */
char *itos(unsigned long n)
{
	int dig_count = 0, idx;
	long num = n;
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
 * init_check - Checks for initial errors
 * @format: _printf string
 * @buffer: buffer
 *
 * Return: -1 or 0 if error, 1 otherwise.
 */
int init_check(const char *format, char *buffer)
{
	if (!format || !buffer || (format[0] == '%' && format[1]))
	{
		free(buffer);
		return (-1);
	}
	if (format[0] == '\0')
	{
		free(buffer);
		return (0);
	}
	return (1);
}
