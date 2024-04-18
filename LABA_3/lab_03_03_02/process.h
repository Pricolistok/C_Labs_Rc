// Заголовочный файл для process.c
#ifndef PROCESS_H__

#include <stdio.h>
#include "const.h"

void move_elements(long long int arr[][M], size_t index, size_t len_m);
void count_multiplication(long long int arr[][M], size_t len_n, size_t len_m, long long int res_arr[N]);
void sort_matrix(long long int arr[][M], size_t len_n, size_t len_m);

#endif
#ifndef ERRORS_H__

#include "errors.h"

#endif
