#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_number(long int n, const char **format, int fc);
int print_str(char *str);
int print_binary(unsigned int n, const char **format, int fc);
int flag_count(const char *str);
int print_unsigned_int(long unsigned int n, const char **format, int fc);
int print_octal(long unsigned int n, const char **format, int fc);
int print_hex_lower(long unsigned int n, const char **format, int fc);
int print_hex_upper(long unsigned int n, const char **format, int fc);
int print_S_string(char *str);
int print_pointer(void *p, const char **format, int fc);

int flag(const char **format, int fc, char flag);
int print_rev(char *s);
int print_rot(char *str);
int print_padding(int width, int digit, char s);
int width_check(const char **format, int fc);
int digit_count(int n, int b);

#endif
