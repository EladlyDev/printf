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
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	i = init_check(format, buffer);
	if (i != 1)
		return (i);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{	i++;
			if (format[i] == '\0')
			{	print_buffer(buffer, len), va_end(args);
				return (-1);
			}
			else if (format[i] == '%')
				buffer[len++] = '%';
			else if (format[i] == ' ' && !format[i + 1])
			{	print_buffer(buffer, len), va_end(args);
				return (-1);
			}
			else if (get_func(format[i]) != NULL)
			{	func = get_func(format[i]);
				len += func(args, buffer, len);
			}
			else
			{	buffer[len++] = '%';
				buffer[len++] = format[i];
			}
		}
		else
			buffer[len++] = format[i];
	}
	va_end(args);
	buffer[len] = '\0';
	print_buffer(buffer, len);
	return (len);
}
