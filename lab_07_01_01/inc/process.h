#ifndef PROCESS_H__

#define PROCESS_H__

#include <stdlib.h>

int add_new_memory(int **arr, size_t len_arr);
void mysort(void *start, size_t len, size_t size, int (*func)(const void *, const void *));
int compare(const void *a, const void *b);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
int compare_char(const void *a, const void *b);
int compare_float(const void *a, const void *b);
void change_elems(char *mini, char *i, size_t size);


#endif
