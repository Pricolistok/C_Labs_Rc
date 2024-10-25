// Заголовочный файл для process.c
#ifndef PROCESS_H__

#include <stdio.h>
#include "const.h"

int is_simple(long long int num);
size_t create_new_arr(long long int arr[][M], size_t len_n, size_t len_m, long long int save_arr[]);
void reverse_arr(long long int save_arr[], size_t len_k);
void insert_nums(long long int arr[][M], size_t len_n, size_t len_m, long long int save_arr[], size_t len_k);
int process_arr(long long int arr[][M], size_t len_n, size_t len_m);

#endif
#ifndef ERRORS_H__

#include "errors.h"

#endif
