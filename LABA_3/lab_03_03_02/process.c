// Файла для создания нового одномерного массива
#include "process.h"
// Перестановка строк матрицы
void move_elements(long long int arr[][M], size_t index, size_t len_m)
{
    long long int saver;
    for (size_t j = 0; j < len_m; j++)
    {
        saver = arr[index][j];
        arr[index][j] = arr[index + 1][j];
        arr[index + 1][j] = saver;
    }
}

// Подсчет умножения в строке
void count_multiplication(long long int arr[][M], size_t len_n, size_t len_m, long long int res_arr[N])
{
    long long int cnt = 1;
    for (size_t i = 0; i < len_n; i++)
    {
        for (size_t j = 0; j < len_m; j++)
        {
            cnt *= arr[i][j];
        }
        res_arr[i] = cnt;
        cnt = 1;
    }
}

// Сортировка матрицы
void sort_matrix(long long int arr[][M], size_t len_n, size_t len_m)
{
    long long int res_arr[N], saver;
    count_multiplication(arr, len_n, len_m, res_arr);
    for (size_t i = 0; i < len_n; i++)
    {
        for (size_t j = 0; j < len_n - 1; j++)
        {
            if (res_arr[j] > res_arr[j + 1])
            {
                move_elements(arr, j, len_m);
                saver = res_arr[j];
                res_arr[j] = res_arr[j + 1];
                res_arr[j + 1] = saver;
            }
        }
    }
}
