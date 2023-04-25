#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_str(char *str, const char **format, int fc);
int print_number(long int n, const char **format, int fc);
int print_binary(unsigned int n, const char **format, int fc);
int flag_count(const char *str);
int print_unsigned_int(unsigned int n, const char **format, int fc);
int print_octal(unsigned int n, const char **format, int fc);
int print_hex_lower(unsigned int n, const char **format, int fc);
int print_hex_upper(unsigned int n, const char **format, int fc);
int print_S_string(char *str, const char **format, int fc);
int print_pointer(void *p, const char **format, int fc);

int flag(const char **format, int fc, char flag);
int print_rev(char *s);
int print_rot(char *str);
int print_padding(int width, int digit, char s);
int width_check(const char **format, int fc);
int char_counter(char *str);
int digit_count(long int n, int b);

#endif
