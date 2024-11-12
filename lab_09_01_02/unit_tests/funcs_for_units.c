#include "funcs_for_unit.h"

int check_arr(item arr_a[], item arr_b[], size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (strcmp(arr_a[i].name, arr_b[i].name) != OK)
            return ERROR;
        if (arr_a[i].weight - arr_b[i].weight >= 1e-6)
            return ERROR;
        if (arr_a[i].volume - arr_b[i].volume >= 1e-6)
            return ERROR;        
    }
    return OK;
}

int check_arr_for_print(int arr_a[], int arr_b[], size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (arr_a[i] != arr_b[i])
            return ERROR;
    }
    return OK;
}

