#include "main.h"
/**
 * get_func - decides which function goes with the character.
 * @c: the character.
 *
 * Return: a pointer to the function, NULL on faliure.
 **/
int (*get_func(char c))(va_list)
{
	type_t type[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'\0', NULL}
	};
	int i;

	if (!c)
		return (NULL);

	for (i = 0; type[i].c; i++)
		if (type[i].c == c)
			return (type[i].func);
	return (NULL);
}
