#ifndef _MAIN_
#define _MAIN_

/* Standard Libraries */
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


/* Prototypes */
int _printf(const char *format, ...);
int (*get_func(char c))(va_list);
unsigned int _strlen(char *);
int print_char(va_list);
int print_string(va_list);
int print_int(va_list);
int print_binary(va_list);

/* Structures */
/**
 * struct type - attacghin each character to its function.
 * @c: the character.
 * @func: the function.
 **/
typedef struct type
{
	char c;
	int (*func)(va_list);
} type_t;

#endif /* _MAIN_ */
