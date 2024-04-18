// Файл хранящий в себе функции ввода и выводв
#include <stdio.h>
#include "input_output.h"

// Функция Ввода
int input_arr(long long int arr[][M], size_t *len_n, size_t *len_m)
{
    int rc;
    long long int iter = 1;
    printf("Input len arr: ");
    rc = scanf("%zu %zu", len_n, len_m);
    if (rc != 2)
    {
        return ERROR_INPUT_LEN;
    }
    if (*len_n > 10 || *len_n < 1 || *len_m > 10 || *len_m < 1)
    {
        return ERROR_VALUE_LEN;
    }
    for (size_t i = 0; i < *len_n; i++)
    {
        for (size_t j = 0; j < *len_m; j++)
        {
            arr[i][j] = iter;
            iter++;
        }
    }
    return OK;
}

// Функция вывода
void print_arr(long long int arr[][M], size_t len_n, size_t len_m)
{
    printf("Array: \n");
    for (size_t i = 0; i < len_n; i++)
    {
        for (size_t j = 0; j < len_m; j++)
        {
            printf("%lld ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
