// Заголовочный файл для файла input_output.c
#ifndef INPUT_OUTPUT_H__

#define INPUT_OUTPUT_H__

#include "errors.h"
#include "const.h"

int input_arr(long long int arr[][M], size_t *len_n, size_t *len_m);
void print_arr(long long int arr[][M], size_t len_n, size_t len_m);

#endif
