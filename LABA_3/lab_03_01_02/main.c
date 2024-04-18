// Вывести одномерный массив, где 1 это столбец в котором чередуются положительные и отридцательные числа, а 0, где не чередуются.
#include <stdio.h>
#include "input_output.h"
#include "process.h"

int main(void)
{
    // Инициализация перменных
    long long int arr[N][N], result_arr[N];
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
    // Работа со столбцами массива
    create_new_arr(arr, len_n, len_m, result_arr);
    // Вывод массива
    print_arr(result_arr, len_m);

    return rc;
}
