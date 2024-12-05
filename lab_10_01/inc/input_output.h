#ifndef INPUT_OUTPUT_H__

#define INPUT_OUTPUT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include "struct.h"

int open_file(FILE **file, int argc, char **argv);
int check_len_file(FILE *file);
int read_from_file(FILE *file, node_t **head);
node_t* create_elem(char *name, int price, size_t len_name);
node_t *add_to_list_elem_end(node_t *head, node_t *elem);
void print_list(node_t *head);

#endif
