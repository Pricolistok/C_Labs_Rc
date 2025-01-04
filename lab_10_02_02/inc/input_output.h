#ifndef INPUT_OUTPUT_H__
#define INPUT_OUTPUT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "errors.h"
#include "consts.h"

int input_mode(int *mode);
node_t *create_elem(const int coefficient);
node_t *add_elem_to_end_list(node_t *head, node_t *elem);
int read_coefficients(node_t **head, int *cnt_coefficients);
void print_list(node_t *head);
int input_val(double *val);

#endif
