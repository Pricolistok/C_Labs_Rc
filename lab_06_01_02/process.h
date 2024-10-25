// Файл хранящий функции файла process.c
#ifndef PROCESS_H__

#define PROCESS_H__

// Подключенные файлы и библиотеки
#include "stdio.h"
#include "input_output.h"
#include "const.h"
#include "errors.h"

// Функции
void sort_arr(item items_arr[], size_t len_arr);
int find_item(item items_arr[], size_t len_arr, char name_find[LEN_NAME + 2]);
int check_name(char name_find[], char name_item[]);

#endif
