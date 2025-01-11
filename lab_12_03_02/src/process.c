#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "process.h"

int check_simple_num(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return ERROR;
    }
    return OK;
}


void add_simple_nums_to_arr(int *arr, size_t cnt_elems)
{
    size_t cnt = 0;
    int num = 2;
    while (cnt < cnt_elems)
    {
        if (check_simple_num(num) == OK)
        {
            arr[cnt] = num;
            cnt++;
        }
        num++;
    }
}

void cnt_ch_nums(int *arr, size_t len_arr, size_t *cnt)
{
    for (size_t i = 0; i < len_arr; i++)
    {
        if (arr[i] % 2 == 0)
            *cnt = *cnt + 1;
    }
}


int filter_nums(int *arr, size_t len_arr, int *result_arr, size_t *len_result_arr, int new_elem)
{
    size_t cnt_nums = 0;
    size_t cur_new_arr = 0;
    cnt_ch_nums(arr, len_arr, &cnt_nums);
    if (len_arr + cnt_nums > *len_result_arr)
    {
        *len_result_arr = cnt_nums + len_arr;
        return ERROR_ADD_MEMORY;
    }
    for (size_t i = 0; i < len_arr; i++)
    {
        result_arr[cur_new_arr] = arr[i];
        cur_new_arr++;
        if (abs(arr[i]) % 2 == 0)
        {
            result_arr[cur_new_arr] = new_elem;
            cur_new_arr++;
        }
    }
    return OK;
}
