#ifndef PROCESS_H__

#define PROCESS_H__

#include <stdlib.h>

void mysort(void *start, size_t len, size_t size, int (*func)(const void *, const void *));
int compare(const void *a, const void *b);
int pre_key(const int *pb_src, const int *pe_src, size_t *new_len, int **min_adr, int **max_adr);
int compare_char(const void *a, const void *b);
int compare_float(const void *a, const void *b);
void change_elems(char *mini, char *i, size_t size);
int key(const int *pb_src, const int *pe_src, int *pb_dst, int *min_adr, int *max_adr);


#endif
