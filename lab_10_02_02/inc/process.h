#ifndef PROCESS_H__
#define PROCESS_H__

#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "struct.h"
#include "errors.h"
#include "consts.h"
#include "input_output.h"

double cnt_val(node_t *head, double val, int cnt_coefficients);
void cnt_derivative(node_t *head, int cnt_coefficients);
void cnt_sum_of_polynomials(node_t *head, node_t *add_head, node_t **result, int cnt_coefficients, int cnt_coefficients_for_mode_sum);
void separator_coefficients(node_t *head, node_t **head_ch, node_t **head_nch, int diff);
void free_list(node_t *head);
void read_coefficients_for_leveling(node_t **result, node_t **head, int diff);

#endif
