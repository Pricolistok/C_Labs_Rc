// Добавить перед каждой строкой, где есть нечетная сумма сумма цифр строку с элементами -1
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
    // Работа со строками массива
    len_n = processing_arr(arr, len_n, len_m);
    // Вывод массива
    print_arr(arr, len_n, len_m);

    return rc;
}
