// Вывести одномерный массив, где 1 это столбец в котором чередуются положительные и отридцательные числа, а 0, где не чередуются.
#include <stdio.h>
#include "input_output.h"
#include "process.h"

int main(void)
{
    // Инициализация перменных
    long long int arr[N][M];
    int rc = 0;
    size_t len_n, len_m;
    // Проверка ввода массива
    rc = input_arr(arr, &len_n, &len_m);
    if (rc == ERROR_INPUT_LEN)
    {
        printf("Error input len \n");
        return ERROR_INPUT_LEN;
    }
    else if (rc == ERROR_VALUE_LEN)
    {
        printf("Error value len \n");
        return ERROR_VALUE_LEN;
    }
    else if (rc == ERROR_ARR_VALUE)
    {
        printf("Error array value \n");
        return ERROR_ARR_VALUE;
    }
    rc = process_arr(arr, len_n, len_m);
    if (rc == 1)
    {
        printf("Haven`t simple elements");
        return ERROR_SIMPLE_ELEM;
    }
    print_arr(arr, len_n, len_m);
    return rc;
}
