#include "main.h"

/**
 * _printf - formatting function that is used to print a string to stdout.
 * @format: the string and the format of the output.
 *
 * Return: the number of printed characters, negative value on falure.
 **/
int _printf(const char *format, ...)
{
	unsigned int i, total_len = 0;
	va_list args;
	char *buffer;
	int (*func)(va_list, *buffer);

	if (!format)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				char c = '%';

				write(1, &c, 1);
				total_len++;
			}
			else
			{
				get_func(format[i]);
				func(args);
			}
			continue;
		}
	}
	total_len = strlen(buffer);
	write(STDOUT_FILENO, buffer, total_len);

	free(buffer);
	va_end(args);
	return (total_len);
}
