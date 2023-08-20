#ifndef _MAIN_H
#define _MAIN_H

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
int check_format(const char *format);
int itob(int);
char *itos(unsigned long);
int print_ui(va_list);
int print_octal(va_list);
int printHEX(va_list args);
int print_hex(va_list args);

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
