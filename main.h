#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>

int _printf(const char *format, ...);

int _putchar(char c);
int _print_str(char *s);
int _print_rev(char *s);
int _print_rot(char *s);
long int _pow(long int a, int b);
int _isdigit(char c);

/* Non-Custom conversion */
int print_char(va_list *ap, const char *format, int fc);
int print_string(va_list *ap, const char *format, int fc);
int print_int(va_list *ap, const char *format, int fc);
int print_unsigned_int(va_list *ap, const char *format, int fc);
int print_octal(va_list *ap, const char *format, int fc);
int print_hex_lower(va_list *ap, const char *format, int fc);
int print_hex_upper(va_list *ap, const char *format, int fc);
int print_pointer(va_list *ap, const char *format, int fc);

/* Custom conversion */
int print_binary(va_list *ap, const char *format, int fc);
int print_S_string(va_list *ap, const char *format, int fc);
int print_rev_string(va_list *ap, const char *format, int fc);
int print_rot_string(va_list *ap, const char *format, int fc);

int flag_count(const char *str);

int flag(const char *format, int fc, char flag);
int print_padding(int width, int digit, char s);
int char_counter(char *str);
int digit_count_signed(long int n, int b);
int digit_count_unsigned(unsigned long int n, int b);

int get_width(va_list *ap, const char *format, int fc);
int get_size(const char *format, int fc);

#endif
