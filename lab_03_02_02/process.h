// Заголовочный файл для process.c
#ifndef PROCESS_H__

#include <stdio.h>
#include "const.h"

int check_num(int num);
int check_row(long long int arr_row[], size_t len_m);
void add_new_row(long long int arr[][M], size_t len_m, size_t index);
size_t processing_arr(long long int arr[][M], size_t len_n, size_t len_m);
#endif
#ifndef ERRORS_H__

#include "errors.h"

#endif
