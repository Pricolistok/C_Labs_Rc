#include "process.h"
// Запись в новый массив
void write_new_arr(long long int arr[][M], size_t len_n, size_t len_m, long long save_arr[])
{
    int flag = -1, iter = 0;
    int len_n_int = len_n;
    for (int j = len_m - 1; j >= 0; j--)
    {
        if (flag == 1)
        {
            for (int i = 0; i < len_n_int; i++)
            {
                arr[i][j] = save_arr[iter];
                iter++;
            } 
            flag *= -1;
        }
        else
        {
            for (int i = len_n_int - 1; i >= 0; i--)
            {
                arr[i][j] = save_arr[iter];
                iter++;
            } 
            flag *= -1;
        }
    }
}

// Создание массива с значениями двумерного массива
void create_save_arr(long long int arr[][M], size_t len_n, size_t len_m, long long int save_arr[])
{
    size_t iter = 0;
    for (size_t i = 0; i < len_n; i++)
    {
        for (size_t j = 0; j < len_m; j++)
        {
            save_arr[iter] = arr[i][j];
            iter++;
        }
    }
}

// Обработка массива
void process_arr(long long int arr[][M], size_t len_n, size_t len_m)
{
    long long int save_arr[K];
    create_save_arr(arr, len_n, len_m, save_arr);
    write_new_arr(arr, len_n, len_m, save_arr);
}
