#include "main.h"

/**
 * _printf - formatting function that is used to print a string to stdout.
 * @format: the string and the format of the output.
 *
 * Return: the number of printed characters, negative value on falure.
 **/
int _printf(const char *format, ...)
{
	unsigned int i, len = 0, mod_len = 0;
	va_list args;
	int (*func)(va_list);

	if (!format || *format == '\0')
		return (-1);

	va_start(args, format);

	for (i = 0; format[i];)
	{
		/* hello %% %s % */
		if (format[i] == '%' && format[i + 1] == '%')
		{
			i += 2;
			continue;
		}
		if (format[i] == '%' && !get_func(format[i + 1]))
			return (-1);
		i++;
	}

	for (i = 0; format[i];)
	{
		/* hello %% %b % */
		if (format[i] == '%' && format[i + 1] == '%')
		{
			write(STDOUT_FILENO, &format[i], 1);
			mod_len++;
			i += 2;
			continue;
		}
		if (format[i] == '%' && get_func(format[i + 1]))
		{
			func = get_func(format[i + 1]);
			len += func(args);
			i += 2;
			continue;
		}
		write(STDOUT_FILENO, &format[i], 1);
		len++;
		i++;
		continue;
	}
	len += mod_len;
	va_end(args);
	return (len);
}
