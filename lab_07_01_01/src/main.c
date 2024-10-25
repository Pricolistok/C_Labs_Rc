#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "input_output.h"
#include "process.h"



int main(int argc, char **argv)
{
    FILE *file_in, *file_out;
    int rc = 0, flag_filter = 0;
    int *arr = NULL, *start, *finish;
    int *arr_filter = NULL, *finish_filter = NULL;
    size_t len_arr;
    rc = get_len_from_file(&file_in, &len_arr, &flag_filter, argc, argv);
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
    rc = add_new_memory(&arr, len_arr);
    if (rc == ERROR_ADD_MEMORY)
    {
        // printf("Ошибка выделения памяти\n");
        return ERROR_ADD_MEMORY;
    }
    rc = open_files(&file_in, &file_out, argv);
    if (rc == ERROR_OPEN_FILE)
    {
        // printf("Ошибка открытия файла\n");
        free(arr);
        return ERROR_OPEN_FILE;
    }
    start = arr;

    finish = start + len_arr;
    input_arr_from_file(file_in, start, finish);
    if (flag_filter == 0)
    {
        mysort(start, finish - start, sizeof(int), compare);
        wite_to_file(file_out, start, finish);
    }
    else
    {
        rc = key(start, finish, &arr_filter, &finish_filter);
        // printf("%p %p %ld    %p %p %ld\n", (void*)start,  (void*)finish, start - finish, (void*)arr_filter, (void*)finish_filter, arr_filter - finish_filter);
        if (rc == ERROR_ADD_MEMORY)
        {
            // printf("Ошибка выделения памяти\n");
            free(arr);
            close_files(file_in, file_out);
            return ERROR_ADD_MEMORY;
        }
        else if (rc == ERROR_FILTER)
        {
            // printf("Ошибка фильтрации\n");
            free(arr);
            close_files(file_in, file_out);
            return ERROR_FILTER;
        }
        else if (rc == ERROR_ELEMS)
        {
            // printf("Ошибка количества элементов внутри\n");
            free(arr);
            close_files(file_in, file_out);
            return ERROR_ELEMS;
        }
        mysort(arr_filter, finish_filter - arr_filter, sizeof(int), compare);
        wite_to_file(file_out, arr_filter, finish_filter);
        free(arr_filter);
    }
        
    free(arr);
    return OK;
}
