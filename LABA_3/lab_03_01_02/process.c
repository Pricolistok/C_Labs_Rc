// Файла для создания нового одномерного массива
#include "process.h"

// Проверка столбца на чередование
int checking_column(long long int arr[][N], size_t len_n, size_t column)
{   
    if (len_n == 1)
    {
        return 0;
    }
    for (size_t i = 0; i < len_n - 1; i++)
    {
        if (arr[i][column] * arr[i + 1][column] >= 0)
        {
            return 0;
        }
    }   
    return 1;
}
// Создание нового массива
void create_new_arr(long long int arr[][N], size_t len_n, size_t len_m, long long int result_arr[])
{
    for (size_t j = 0; j < len_m; j++)
    {
        result_arr[j] = checking_column(arr, len_n, j);
    }
}
