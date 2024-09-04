#ifndef INPUT_OUTPUT_H__

#include <stdio.h>
#include "errors.h"

int find_size(FILE *f, size_t *size);
int cnt_summ(FILE *f, int *summ_result);
int replace_elem(FILE *f, int summ_result, int code);

#endif