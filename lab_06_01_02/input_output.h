// Файл хранящий функции файла input_output.c
#ifndef INPUT_OUTPUT_H__

#define INPUT_OUTPUT_H__

#include "struct.h"
#include "const.h"
#include "errors.h"

// Функции файла
int input_file(FILE **file_in, char str_option[LEN_NAME + 2], int argc, char **argv);
int create_arr(FILE *file, item items_arr[], size_t *len_arr);
void print_arr(item items_arr[], size_t len_arr);
void prin_item(item items_arr[], size_t index_item);
int read_item(FILE *file, item items_arr[], size_t cnt_struct);


#endif
