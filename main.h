#ifndef _MAIN_H
#define _MAIN_H

/* Standard Libraries */
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


/* Prototypes */
int _printf(const char *format, ...);
int (*get_func(char c))(va_list, char *, unsigned int);
unsigned int _strlen(char *);
int print_char(va_list, char *, unsigned int);
int print_string(va_list, char *, unsigned int);
int print_int(va_list, char *, unsigned int);
int print_binary(va_list, char *, unsigned int);
int init_check(const char *format, char *buffer);
int itob(int);
char *itos(unsigned long);
int print_ui(va_list, char *, unsigned int);
int print_octal(va_list, char *, unsigned int);
int printHEX(va_list args, char *, unsigned int);
int print_hex(va_list args, char *, unsigned int);
void print_buffer(char *, unsigned int);
unsigned int update_buffer(char *, unsigned int, char);
char *itox(unsigned int, int);

/* Structures */
/**
 * struct type - attacghin each character to its function.
 * @c: the character.
 * @func: the function.
 **/
typedef struct type
{
	char c;
	int (*func)(va_list, char *, unsigned int);
} type_t;

#endif /* _MAIN_ */
