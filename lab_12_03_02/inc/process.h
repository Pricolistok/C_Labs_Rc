#ifndef PROCESS_H__

#define PROCESS_H__

#include <stdlib.h>

int check_simple_num(int num);
void add_simple_nums_to_arr(int *arr, size_t cnt_elems);
void cnt_ch_nums(int *arr, size_t len_arr, size_t *cnt);
int filter_nums(int *arr, size_t len_arr, int *result_arr, size_t *len_result_arr, int new_elem);


#endif
