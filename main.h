#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_number(int n);
int print_str(char *str);
int print_binary(unsigned int n);
int flag_count(const char *str);
int print_unsigned_int(unsigned int n);
int print_octal(unsigned int n);
int print_hex_lower(unsigned int n);
int print_hex_upper(unsigned int n);
int print_S_string(char *str);
int print_pointer(void *p);

#endif
