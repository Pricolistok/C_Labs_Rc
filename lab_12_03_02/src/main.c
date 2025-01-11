#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "input_output.h"
#include "process.h"



int main(int argc, char **argv)
{
    FILE *file_in, *file_out;
    int rc = 0, flag_filter = 0, mode_mem, new_elem_filter;
    int *arr = NULL;
    int *result_arr;
    size_t len_arr, len_result_arr;
    rc = get_len_from_file(&file_in, &len_arr, &flag_filter, argc, argv, &mode_mem, &new_elem_filter);
    switch (rc)
    {
        case ERROR_ARGUMENTS:
            // printf("Ошибка количества аргументов\n");
            return ERROR_ARGUMENTS;
        case ERROR_OPEN_FILE:
            // printf("Ошибка открытия файла\n");
            return ERROR_OPEN_FILE;
        case ERROR_ELEM_IN_FILE:
            // printf("Ошибка элемента внутри файла\n");
            return ERROR_ELEM_IN_FILE;
        case ERROR_LEN_FILE:
            // printf("Ошибка длинны файла\n");
            return ERROR_LEN_FILE;
        case ERROR_FLAG_FILTER:
            // printf("Ошибка ключа фильтрации\n");
            return ERROR_FLAG_FILTER;
    }
    arr = malloc(len_arr * sizeof(int));
    if (!arr)
    {
        // printf("Ошибка выделения памяти!\n");
        return ERROR_ADD_MEMORY;
    }
    rc = open_files(&file_in, &file_out, argv);
    if (rc == ERROR_OPEN_FILE)
    {
        // printf("Ошибка открытия файла\n");
        free(arr);
        return ERROR_OPEN_FILE;
    }
    if (flag_filter == 0)
    {
        add_simple_nums_to_arr(arr, len_arr);
        write_to_file(file_out, arr, len_arr);
    }
    else if (flag_filter == 1)
    {
        if (mode_mem == 0)
        {
            input_arr_from_file(file_in, arr, len_arr);
            len_result_arr = len_arr / 3;
            result_arr = malloc(len_result_arr * sizeof(int));
            if (!result_arr)
            {
                // printf("Ошибка выделения памяти!\n");
                return ERROR_ADD_MEMORY;
            }
            rc = filter_nums(arr, len_arr, result_arr, &len_result_arr, new_elem_filter);
            if (rc == ERROR_ADD_MEMORY)
            {
                free(result_arr);
                result_arr = malloc(len_result_arr * sizeof(int));
                if (!result_arr)
                {
                    // printf("Ошибка выделения памяти!\n");
                    return ERROR_ADD_MEMORY;
                }
                filter_nums(arr, len_arr, result_arr, &len_result_arr, new_elem_filter);
            }
            write_to_file(file_out, result_arr, len_result_arr);
            free(result_arr);
        }
        else if (mode_mem == 1)
        {
            len_result_arr = 0;
            input_arr_from_file(file_in, arr, len_arr);
            cnt_ch_nums(arr, len_arr, &len_result_arr);
            len_result_arr += len_arr;
            result_arr = malloc(len_result_arr * sizeof(int));
            if (!result_arr)
            {
                // printf("Ошибка выделения памяти!\n");
                return ERROR_ADD_MEMORY;
            }
            filter_nums(arr, len_arr, result_arr, &len_result_arr, new_elem_filter);
            write_to_file(file_out, result_arr, len_result_arr);
            free(result_arr);
        }
    }
    free(arr);
    return OK;
}
