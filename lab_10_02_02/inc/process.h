#ifndef PROCESS_H__
#define PROCESS_H__

#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "struct.h"
#include "errors.h"
#include "consts.h"
#include "input_output.h"

double cnt_function(node_t *head, double val, int cnt_coefficients);
void cnt_derivative(node_t *head, int cnt_coefficients);
void cnt_sum_of_polynomials(node_t *head, node_t *add_head, int diff);
size_t cnt_degree(node_t *head);
void separator_coefficients(node_t *head, node_t **head_ch, node_t **head_nch, int cnt_coefficients);
void free_list(node_t *head);

#endif
