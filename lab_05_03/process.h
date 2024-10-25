// Заголовочный файл для основных функций программы
#ifndef PROCESS_H__
#define PROCESS_H__

#include <stdio.h>
#include "errors.h"

void create_bin_file(FILE *f, int digit);
int print_bin_file(FILE *f);
int get_number_by_pos(FILE *f, size_t position);
void put_number_by_pos(FILE *f, size_t position, int *number);
void export(FILE *bin_file, FILE *txt_file);
int import(FILE *txt_file, FILE *bin_file);
int find_size(FILE *f, size_t *size);
int sort_file(FILE *f);
int check_file(FILE *f);

#endif
