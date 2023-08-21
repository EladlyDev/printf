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
	int *arr, i, len = 0;
	char *out;
	unsigned int num, binary;

	num = va_arg(args, unsigned int);

    /* convert to binary so I can get the length of the output */
	binary = itob(num);
	out = itos(binary);
	for (i = 0; out[i]; i++)
		len++;

    /* allocate memory for the output */
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (0);

    /* print the values */
	for (i = 0; num > 0; i++)
	{
		arr[i] = num % 2;
		num = num / 2;
	}
	for (i = i - 1, len = 0; i >= 0; i--)
	{
		_printf("%d", arr[i]);
		len++;
	}
	free(out);
	free(arr);
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
