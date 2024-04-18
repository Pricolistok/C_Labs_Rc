#include "process.h"
// Модуль числа
int abs_num(long long int elem)
{
    if (elem < 0)
        elem *= -1;
    return elem;
}


// Проверка элементов под побочной диагональю
int process_arr(long long int arr[][M], size_t len_n)
{
    long long int maxi = 3;
    for (size_t i = 1; i < len_n; i++)
    {
        for (size_t j = len_n - 1; j > len_n - i - 1; j--)
        {
            if (maxi == 3 && abs_num(arr[i][j]) % 10 == 5)
            {
                maxi = arr[i][j];
            }
            if (maxi < arr[i][j] && abs_num(arr[i][j]) % 10 == 5)
            {
                maxi = arr[i][j];
            }
        }
    }
    return maxi;
}
