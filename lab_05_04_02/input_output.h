// ЗАголовочный файл для файла ввода
#ifndef INPUT_OUTPUT_H__
#define INPUT_OUTPUT_H__

#include <stdio.h>
#include "errors.h"
#include "struct.h"

int input_file(FILE **f_in, FILE **f_out, char str[NAME_LEN + 2], int args, char **argv);
int create_arr(FILE *f, product products_arr[], size_t *len_arr);
int check_len_file(FILE *f);

#endif
