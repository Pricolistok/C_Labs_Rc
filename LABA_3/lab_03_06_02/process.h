// Заголовочный файл для process.c
#ifndef PROCESS_H__

#include <stdio.h>
#include "const.h"

void write_new_arr(long long int arr[][M], size_t len_n, size_t len_m, long long save_arr[]);
void sort_arr(long long int save_arr[], size_t len_k);
void create_save_arr(long long int arr[][M], size_t len_n, size_t len_m, long long int save_arr[]);
void process_arr(long long int arr[][M], size_t len_n, size_t len_m);

#endif
#ifndef ERRORS_H__

#include "errors.h"

#endif
