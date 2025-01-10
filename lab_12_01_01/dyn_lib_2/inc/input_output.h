#ifndef INPUT_OUTPUT_H__

#define INPUT_OUTPUT_H__

#include "stdio.h"

int get_len_from_file(FILE **file_in, size_t *len_arr, int *flag_filter, int argc, char **argv);
int open_files(FILE **file_in, FILE **file_out, char **argv);
void input_arr_from_file(FILE *file_in, int *start, int *finish);
void close_files(FILE *file_in, FILE *file_out);
void wite_to_file(FILE *file_out, int *start, int *finish);

#endif
