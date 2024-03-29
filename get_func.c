#include "main.h"
/**
 * get_func - decides which function goes with the character.
 * @c: the character.
 *
 * Return: a pointer to the function, NULL on faliure.
 **/
int (*get_func(char c))(va_list, char *, unsigned int)
{
	type_t type[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'u', print_ui},
		{'o', print_octal},
		{'x', print_hex},
		{'X', printHEX},
		{'S', print_S},
		{'p', print_p},
		{'\0', NULL}
	};
	int i;

	for (i = 0; type[i].c != '\0'; i++)
		if (type[i].c == c)
			return (type[i].func);
	return (NULL);
}
