// Файл хранящий функции файла process.c
#ifndef PROCESS_H__

#define PROCESS_H__

// Подключенные файлы и библиотеки
#include "stdio.h"
#include "input_output.h"
#include "errors.h"
#include "struct.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Функции
void sort_arr(item *items_arr, size_t len_arr);
int find_item(item *items_arr, size_t len_arr, char *name_find, int *arr);
int check_name(char *name_find, char *name_item, size_t len_name);
void change_elems(item *items_arr, size_t index_1, size_t index_2);
int add_memory(item **arr, size_t len_arr);
int add_memory_for_print(int **arr, size_t len_arr);

#endif
