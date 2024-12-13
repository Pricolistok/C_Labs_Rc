#ifndef PROCESS_H__

#define PROCESS_H__

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "errors.h"
#include <string.h>

void *pop_front(node_t **head);
void product_free(node_t *head);
void free_all_data(node_t *head);
void *pop_end(node_t **head);
int comparator_products(const void *compare_1, const void *compare_2);
void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*));
int comparator_prices(const void *price_1, const void *price_2);
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

#endif
