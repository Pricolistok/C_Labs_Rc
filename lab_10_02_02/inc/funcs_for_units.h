#ifndef FUNCS_FOR_UNITS_H
#define FUNCS_FOR_UNITS_H

#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "input_output.h"
#include "errors.h"

node_t *create_list(int coefficients[], size_t cnt_coefficients);
int check_func_cnt_val(int coefficients[], int cnt_coefficients, double expected_sum, double val);

#endif
