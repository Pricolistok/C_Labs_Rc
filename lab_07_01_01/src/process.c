#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "process.h"
#include <string.h>

int compare(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

int compare_char(const void *a, const void *b) 
{
    return (*(char*)a - *(char*)b);
}

int compare_float(const void *a, const void *b) 
{
    double g = *(double*)a - *(double*)b;
    if (g < 0)
        return -1;
    else if (g > 0)
        return 1;
    return 0;
}

int add_new_memory(int **arr, size_t len_arr)
{
    // printf("size %ld len: %zu sizeof: %ld\n", len_arr * sizeof(int), len_arr, sizeof(int));
    *arr = malloc(len_arr * sizeof(int));
    if (!arr)
        return ERROR_ADD_MEMORY;
    return OK;
}

void change_elems(char *mini, char *i, size_t size)
{
    char tmp;
    for (size_t k = 0; k < size; ++k) 
    {
        tmp = mini[k];
        mini[k] = i[k];
        i[k] = tmp;
    }
}


void mysort(void *start, size_t len, size_t size, int (*func)(const void *, const void *))
{
    char *mini;
    char *finish = (char*)start + len * size;
    // printf("%p %p", start, (void*)finish);
    // printf("zz %zu\n", len);
    for (char *i = (char*)start; i < finish; i += size)
    {
        mini = i;
        for (char *j = i + size; j < finish; j += size)
        {
            if (func(mini, j) > 0)
                mini = j;
        }
        if (mini != i)
            change_elems(mini, i, size);
    }
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int *mini = (int*)pb_src, *maxi = (int*)pb_src, rc = 0;
    int *min_adr, *max_adr;
    int *cursor; 
    size_t cnt = 0;
    for (int *i = (int*)pb_src; i < (int*)pe_src; i++)
    {
        if (*i < *mini)
            mini = i;
        else if (*i > *maxi)
            maxi = i;
    }
    if (mini > maxi)
    {
        max_adr = mini;
        min_adr = maxi;
    }
    else
    {
        max_adr = maxi;
        min_adr = mini;
    }
    if (min_adr == max_adr)
        return ERROR_ELEMS;
    for (int *i = (int*)pb_src; i < pe_src; i++)
    {
        if ((i > min_adr) && (i < max_adr))
            cnt++;
    }
    if (cnt == 0)
        return ERROR_FILTER;
    rc = add_new_memory(pb_dst, cnt);
    if (rc == ERROR_ADD_MEMORY)
        return ERROR_ADD_MEMORY;
    cursor = *pb_dst;
    *pe_dst = *pb_dst + cnt;
    for (int *i = (int*)pb_src; i < pe_src; i++)
    {
        if ((i > min_adr) && (i < max_adr))
        {
            *cursor = *i;
            cursor++;
        }
    }
    
    // for (int *i = max_adr; i < *pe_dst; i++)
    // {
    //     *cursor = *i;
    //     cursor++;
    // }
    return OK;
}
