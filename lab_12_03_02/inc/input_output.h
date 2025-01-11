#ifndef INPUT_OUTPUT_H__

#define INPUT_OUTPUT_H__

#include "stdio.h"

int get_len_from_file(FILE **file_in, size_t *len_arr, int *flag_filter, int argc, char **argv, int *mode_mem, int *write_num);
int open_files(FILE **file_in, FILE **file_out, char **argv);
void input_arr_from_file(FILE *file_in, int *arr, size_t len_arr);
void close_files(FILE *file_in, FILE *file_out);
void write_to_file(FILE *file_out, int *arr, size_t len_arr);

#endif
