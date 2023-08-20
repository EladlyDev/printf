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
 * check_format - to handle the edge cases in _printf.
 * @format: the format passed to _printf.
 *
 * Return: 0 if there's any issues, 1 on succeed.
 **/
int check_format(const char *format)
{
	int i;

	if (!format)
		return (0);


	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				i++;
				continue;
			}
			if (!get_func(format[i]))
				return (0);
		}
	}
	return (1);
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
