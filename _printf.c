#include "main.h"

/**
 * _printf - formatting function that is used to print a string to stdout.
 * @format: the string and the format of the output.
 *
 * Return: the number of printed characters, negative value on falure.
 **/
int _printf(const char *format, ...)
{
	unsigned int i, len = 0;
	va_list args;
	int (*func)(va_list, char *, unsigned int);
	char buffer[1024];

	if (!check_format(format))
		return (-1);
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				buffer[len] = '%';
				len++;
			}
			else if (get_func(format[i]) != NULL)
			{
				func = get_func(format[i]);
				len += func(args, buffer, len);
			}
			else
				return (-1);
		}
		else
		{
			buffer[len] = format[i];
			len++;
		}
	}
	va_end(args);
	buffer[len] = '\0';
	write(1, buffer, len);
	return (len);
}
