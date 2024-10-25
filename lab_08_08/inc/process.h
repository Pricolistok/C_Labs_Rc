#ifndef PROCESS_H__

#define PROCESS_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "errors.h"

int** add_memory(size_t n, size_t m);
void free_memory(int **arr, size_t n);
void change_rows(int **arr, size_t index_1, size_t index_2);
void change_columns(int **arr, size_t index_1, size_t index_2, size_t n);
void remove_rows(int **arr, size_t *n, size_t m, int cnt_rm_rows);
void remove_columns(int **arr, size_t n, size_t *m, int cnt_rm_columns);
void cnt_remove(size_t n, size_t m, int *rm_rows,int *rm_columns);
void add_row_to_arr(int **arr, size_t n, size_t m, size_t add_size);

int create_new_memory_for_rows(int ***arr, size_t n, size_t m, size_t add_size);

void add_column_to_arr(int **arr, size_t n, size_t m, size_t add_size);
int create_new_memory_for_columns(int ***arr, size_t n, size_t m, size_t add_size);

#endif