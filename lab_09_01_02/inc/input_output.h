// Файл хранящий функции файла input_output.c
#ifndef INPUT_OUTPUT_H__

#define INPUT_OUTPUT_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "errors.h"

// Функции файла
int input_file(FILE **file_in, char **str_option, int argc, char **argv, size_t *len_arg);
int create_arr(FILE *file, item *items_arr, size_t len_arr);
void print_arr(item *items_arr, size_t len_arr);
void print_item(item *items_arr, size_t index_item);
int read_item(FILE *file, item *items_arr, size_t cnt_struct);
int cnt_item(FILE *file);
int cnt_structs(FILE *file, size_t *len_arr);
int add_memory_for_name(char **name, size_t len);
int open_file(FILE **file_in, char **argv);

#endif
