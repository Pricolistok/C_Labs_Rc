// Файдля для хранения заголовков функций ввода и вывода
#ifndef INPUT_OUTPUT_H__

#define INPUT_OUTPUT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "errors.h"
#include "consts.h"

int open_file_in(FILE **file, int argc, char **argv);
void cnt_elem_matrix(FILE *file_in, size_t *n, size_t *m);
void input_from_file(FILE *file, double **arr, size_t m);
void print_matrix_to_file(double **arr, size_t n, size_t m, FILE *file_out);
int open_file_out(FILE **file, int argc, char **argv);
int check_len_file(FILE *file);

#endif
