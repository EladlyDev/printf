#include "main.h"

/**
 * print_buffer - prints n bytes of buffer to STDOUT
 * @buffer: buffer
 * @n: number of bytes to print
 *
 **/
void print_buffer(char *buffer, unsigned int n)
{
	n = n == 1024 ? 1024 : n % 1024;
	write(1, buffer, n);
}
/**
 * update_buffer - updates the buffer with a new char
 * @buffer: buffer
 * @len: number of elements in buffer
 * @c: char
 *
 * Return: number of elements in the buffer.
 */
unsigned int update_buffer(char *buffer, unsigned int len, char c)
{
	unsigned int i = len % 1024;

	if (len > 0 && i == 0)
		print_buffer(buffer, 1024);
	buffer[i] = c;

	return (len + 1);
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
	if (!format || !buffer || (format[0] == '%' && !format[1]))
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

/**
 * itox - converts an integer into hexdecimal.
 * @n: the number to be convirted.
 * @upper: true for upper, false for lower cased ouptut.
 *
 * Return: hex value of n as string
 **/
char *itox(unsigned long n, int upper)
{
	int i = 0, j, k;
	char hexNum[100], *str;
	long num = n;


	while (num > 0)
	{
		int rem = num % 16;

		if (upper)
			hexNum[i] = rem < 10 ? rem + '0' : rem - 10 + 'A';
		else
			hexNum[i] = rem < 10 ? rem + '0' : rem - 10 + 'a';
		num /= 16;
		i++;
	}
	if (i == 0)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * i + 1);
	for (j = i - 1, k = 0; j >= 0; j--, k++)
		str[k] = hexNum[j];
	str[k] = '\0';
	return (str);
}
