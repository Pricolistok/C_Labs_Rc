// Заголовочный файл для файла с основными функциями программы
#ifndef PROCESS_H__
#define PROCESS_H__

#include <stdio.h>
#include "errors.h"
#include "struct.h"

void create_bin_file(FILE *f);
int find_size(FILE *f, size_t *size);
int sort_arr(product products_arr[], size_t len_arr);
int find_elems(product products_arr[], size_t len_arr, char str[]);
void write_to_file(FILE *f, product products_arr[], size_t len_arr);

#endif
