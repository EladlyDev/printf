#ifndef _MAIN_
#define _MAIN_

/* Standard Libraries */
#include <stdarg.h>


/* Prototypes */
int _printf(const char *format, ...);
int (*get_func(char c))(va_list);


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
