#ifndef FUNCS_FOR_UNITS_H__

#define FUNCS_FOR_UNITS_H__

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "process.h"
#include "input_output.h"
#include "struct.h"

int compare_lists(node_t *head, node_t *result);
node_t *input_to_list(product list_products[], size_t len_arr);
void print_list(node_t *head);
void free_all_data_for_test(node_t *head);
int test_rm_duplicates(node_t **head, node_t **result);
int test_pop_front(node_t **head, node_t *result);
int test_pop_end(node_t **head, node_t *result);


#endif //FUNCS_FOR_UNITS_H
