// Файла для создания нового одномерного массива
#include "process.h"

// Проверка суммы каждого числа
int check_num(int num)
{
    int cnt = 0;
    if (num < 0)
        num *= -1;
    while (num > 0)
    {
        cnt += (num % 10);
        num /= 10;
    }
    if (cnt % 2 != 0)
    {
        return 0;
    }
    return 1;
}

// Проверка какждой строки на количсетво элементов, сумма цифр, которых нечетна
int check_row(long long int arr_row[], size_t len_m)
{
    int cnt = 0;
    for (size_t j = 0; j < len_m; j++)
    {
        if (check_num(arr_row[j]) == 0)
        {
            cnt++;
        }
        if (cnt >= 2)
        {
            return 0;
        }
    }
    return 1;
}

// Добавление новой строки перед строкой, где хотябы два числа с нечетной суммой цифр
void add_new_row(long long int arr[][M], size_t len_m, size_t index)
{
    for (size_t i = N - 1; i > index; i--)
    {
        for (size_t k = 0; k < len_m; k++)
        {
            arr[i][k] = arr[i - 1][k];
        }
    }
    for (size_t j = 0; j < len_m; j++)
    {
        arr[index][j] = -1;
    }
}

// Обработка массива
size_t processing_arr(long long int arr[][M], size_t len_n, size_t len_m)
{
    size_t saver = len_n;
    size_t i = 0;
    while (i < len_n)
    {
        if (check_row(arr[i], len_m) == 0)
        {
            add_new_row(arr, len_m, i);
            i++;
            saver++;
            len_n++;
        }
        i++;
    }
    return saver;
}
