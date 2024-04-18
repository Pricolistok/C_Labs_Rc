#include "process.h"
// Проверка числа на простоту
int is_simple(long long int num)
{
    long long int i = 2;
    if (num < 0)
        return 1;
    if (num == 1)
        return 1;
    while (i <= num - 1)
    {
        if (num % i == 0)
            return 1;
        i++;
    }
    return 0;
}

// Создание нового массива
size_t create_new_arr(long long int arr[][M], size_t len_n, size_t len_m, long long int save_arr[])
{
    size_t iter = 0;
    for (size_t i = 0; i < len_n; i++)
    {
        for (size_t j = 0; j < len_m; j++)
        {
            if (is_simple(arr[i][j]) == 0 && arr[i][j] > 1)
            {
                save_arr[iter] = arr[i][j];
                iter++;
            }
        }
    }
    if (iter == 0)
        return 0;
    return iter; 
}

// Разворот массива
void reverse_arr(long long int save_arr[], size_t len_k)
{
    long long int saver;
    int len_int = len_k;
    for (int i = 0; i < len_int / 2; i++)
    {
        saver = save_arr[i];
        save_arr[i] = save_arr[len_k - 1 - i];
        save_arr[len_k - 1 - i] = saver;
    }
}

// Вставка новых элементов
void insert_nums(long long int arr[][M], size_t len_n, size_t len_m, long long int save_arr[], size_t len_k)
{
    size_t iter = 0;
    int flag = 0;
    for (size_t i = 0; i < len_n; i++)
    {
        for (size_t j = 0; j < len_m; j++)
        {
            if (arr[i][j] == save_arr[len_k - 1 - iter])
            {
                arr[i][j] = save_arr[iter];
                iter++;
                if (iter >= len_k)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
            break;
    }
}

// Обработчик массива
int process_arr(long long int arr[][M], size_t len_n, size_t len_m)
{
    long long int save_arr[K];
    size_t len_k;
    len_k = create_new_arr(arr, len_n, len_m, save_arr);
    if (len_k == 0)
        return 1;
    reverse_arr(save_arr, len_k);
    insert_nums(arr, len_n, len_m, save_arr, len_k);
    return 0;
}
