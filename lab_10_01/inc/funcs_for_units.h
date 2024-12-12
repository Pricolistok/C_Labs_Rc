#ifndef FUNCS_FOR_UNITS_H__

#define FUNCS_FOR_UNITS_H__

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <process.h>
#include "struct.h"

int compare_lists(node_t *head, node_t *result);
node_t *input_to_list(product list_products[], size_t len_arr);
node_t *create_elem_list(char *name, int price, size_t len_name);
node_t *add_elem_to_list(node_t *head, node_t *elem);
void print_list(node_t *head);
void free_all_data_for_test(node_t *head);


#endif //FUNCS_FOR_UNITS_H
