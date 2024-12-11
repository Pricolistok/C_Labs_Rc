#ifndef INPUT_OUTPUT_H__

#define INPUT_OUTPUT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include "struct.h"

int work_with_args(FILE **file_in, FILE **file_out, int argc, char **argv, int *choice_menu);
int check_len_file(FILE *file);
int read_from_file(FILE *file, node_t **head);
node_t* create_elem(char *name, int price, size_t len_name);
node_t *add_to_list_elem_end(node_t *head, node_t *elem);
void print_list_to_file(node_t *head, FILE *file_out);
int check_choice_menu(char **argv);
int open_file_in(FILE **file, char **argv);
int open_file_out(FILE **file, char **argv);

#endif
