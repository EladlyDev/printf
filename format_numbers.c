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
void *expand_int(va_list args, buffer_t *buffer)
{
	char *str = itos(va_arg(args, int));

	memcpy(buffer->str, str);
	buffer->len += _strlen(str) - 1;
	free(str);
}
