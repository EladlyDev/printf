#include "main.h"

/**
 * _printf - formatting function that is used to print a string to stdout.
 * @format: the string and the format of the output.
 *
 * Return: the number of printed characters, negative value on falure.
 **/
int _printf(const char *format, ...)
{
	int i, len, total_len = 0;
	va_list args;
	int (*func)(va_list);

	if (!format)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && get_func(format[i + 1]))
		{
			i++;
			func = get_func(format[i]);
			len = func(args);
			total_len += len;
			continue;
		}
		total_len++;
		write(STDOUT_FILENO, &format[i], 1);
	}
	va_end(args);
	return (total_len);
}
