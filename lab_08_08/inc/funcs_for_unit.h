// Файл хранящий заголовки функций модульных тестов
#ifndef FUNCS_FOR_UNIT_H__

#define FUNCS_FOR_UNIT_H__

#include "stdlib.h"
#include "stdio.h"

void input_data_to_mtrix(int **arr, int data[], size_t n, size_t m);
int check_result(int **arr, int data[], size_t n);
void print_matrix(int **arr, size_t n, size_t m);

#endif
