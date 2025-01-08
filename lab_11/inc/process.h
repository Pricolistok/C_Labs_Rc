#ifndef PROCESS_H__
#define PROCESS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "errors.h"

int my_snprintf(char *str, size_t n, const char *format, ...);
void write_str(char *str, size_t len_str, size_t *position, char *str_arg);
size_t cnt_len_num(long int num);
void reverse_str_num(const char *str_num, char *new_str, size_t last_position);
void write_int_to_str(long int num, char *str_for_num, int flag_negative);
int int_to_str(char *str, long int num, size_t len_str, size_t *position, int flag_overflow);

#endif
