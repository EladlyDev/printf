#include "main.h"

/*testing purposes*/
#include <string.h>

/**
 * itos - convert an int to a string
 * @n: integer
 * 
 * Return: string rep of integer
 */
char *itos(int n)
{
	int dig_count = 0;
	int idx, num = n;
	char *str;

	/* Get the nymber of digits*/
	do {
		dig_count ++;
		num /= 10;
		
	} while (num != 0);

	str = malloc(dig_count + 1);
	if (!str)
		return (NULL);
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
 * expand_int - converts an integer to a string
 * and appends to buffer struct
 * @num: integer
 * @buffer: pointer to buffer structure
 * 
 */
void print_int(va_list args)
{
	char *str = itos(va_arg(args, int));
	unsigned int len = 0;

	if (str)
	{
		len = _strlen(str);
		return (write(1, str, len));
	}
	free(str);
	return (0);
}
