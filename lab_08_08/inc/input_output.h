#ifndef INPUT_OUTPUT_H__

#define INPUT_OUTPUT_H__

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

int input_sizes(size_t *n, size_t *m);
int input_matrix(int **arr, size_t n, size_t m);
void print_matrix(int **arr, size_t n, size_t m);

#endif