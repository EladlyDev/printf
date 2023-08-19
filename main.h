#ifndef _MAIN_
#define _MAIN_

/* Standard Libraries */
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


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

/**
 * struct buffer - keeps the buffer to be printed and its length
 * @str: string to be printed
 * @len: length of string
 */
typedef struct buffer
{
	char *str;
	unsigned int len;
} buffer_t;


/* Prototypes */
int _printf(const char *format, ...);
void *(*get_func(char c))(va_list, buffer_t *);
void *expand_int(va_list, buffer_t *);
int print_int(va_list);
void *expand_string(va_list, buffer_t *);
unsigned int _strlen(char *);

#endif /* _MAIN_ */
