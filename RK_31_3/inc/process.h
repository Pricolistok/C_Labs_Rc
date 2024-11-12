// Файл для хранения заголовков функций по работе с памятью
#ifndef PROCESS_H__

#define PROCESS_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "errors.h"

double **add_memory(size_t n, size_t m);
void free_memory(double **arr, size_t n);

#endif
