#ifndef FUNCS_FOR_UNITS_H
#define FUNCS_FOR_UNITS_H

#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "input_output.h"
#include "errors.h"

node_t *create_list(int coefficients[], size_t cnt_coefficients);
int check_func_cnt_val(int coefficients[], int cnt_coefficients, double expected_sum, double val);
int compare_lists(node_t *head_1, node_t *head_2);
int check_func_cnt_sum(int coefficients_1[], int cnt_coefficients_1, int coefficients_2[], int cnt_coefficients_2, int expected_sum[], int len_expected_sum);
int check_func_cnt_ddx(int coefficients[], int cnt_coefficients, int expected[], int len_expected);

#endif
