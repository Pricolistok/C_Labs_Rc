// Доколин Георгий ИУ7-22Б
#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 10
// Вывод результата
void print_res_arr(int arr[], size_t len_arr)
{
    for (size_t i = 0; i < len_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Сортировка массива вставками
int sort_mas(int arr[], size_t len_arr)
{
    int temp, flag = 0;
    size_t j;
    // Проверка условия и обозначение кода выхода
    if (len_arr > N)
    {
        flag = 100;
        len_arr--;
        len_arr = N;
    }
    // Сортировка втсавками
    for (size_t i = 1; i < len_arr; i++)
    {
        temp = arr[i];
        j = i;
        while (j > 0 && arr[j - 1] > temp)
        {
            arr[j] = arr[j - 1];
            j -= 1;
        }
        arr[j] = temp;
    }
    return flag;
}

// Функция ввода массива
int input_arr(int arr[])
{
    int rc = 1, elem;
    size_t iter = 0;
    while (rc == 1)
    {
        // Проверка ввода
        rc = scanf("%d", &elem);
        if (rc != 1)
        {
            break;
        }
        // Проверка количества
        if (iter < 10)
        {
            arr[iter] = elem;
        }
        iter++;
        if (iter > 10)
        {
            break;
        }
    }
    if (iter == 0)
    {
        return -1;
    }
    return iter;
}

int main()
{
    int arr[N], res_len, flag;
    res_len = input_arr(arr);
    // Проверка ввода длинны
    if (res_len == -1)
    {
        printf("Error");
        return 1;
    }
    // Проверка ввода
    flag = sort_mas(arr, res_len);
    if (flag == 100)
    {
        res_len --;
    }
    // Вывод массива
    print_res_arr(arr, res_len);
    return flag;
}
