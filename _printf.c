#include "main.h"

/**
 * istype - checks if a charcter is a
 * conversion specifier
 * @c: char
 *
 * Return: 1 if true, 0 otherwise
 **/
int istype(char c)
{
	char *types = "csdi";
	int i;

	for (i = 0; types[i] != '\0'; i++)
		if (types[i] == c)
			return (1);
	return (0);
}
/**
 * _printf - formatting function that is used to print a string to stdout.
 * @format: the string and the format of the output.
 *
 * Return: the number of printed characters, negative value on falure.
 **/
int _printf(const char *format, ...)
{
	unsigned int i, j, len = 0, total_len = 0;
	va_list args;
	int (*func)(va_list);

	if (!format || *format = '\0')
		return (-1);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			char c = '%';

			write(1, &c, 1);
			i++, total_len++;
			continue;
		}
		if (format[i] == '%')
		{
			for (j = i + 1; format[j] != '\0'; j++)
			{
				if (istype(format[j]))
				{
					func = get_func(format[j]);
					len = func(args);
					total_len += len;
					break;
				}
			}
			if (format[j] == '\0')
				return (-1);
			i = j;
			continue;
		}
		write(1, &format[i], 1);
		total_len++;
	}
	va_end(args);
	return (total_len);
}
