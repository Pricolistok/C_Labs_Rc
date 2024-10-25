// Доколин Георгий ИУ7-22Б
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 10

// Функция ввода массива
int input_arr(int arr[], size_t len_arr)
{
    int rc, elem;
    for (size_t i = 0; i < len_arr; i++)
    {
        rc = scanf("%d", &elem);
        if (rc != 1)
        {
            return 1;
        }
        arr[i] = elem;
    }
    return 0;
}

int check_elem(int num)
{
    for (int i = 0; i < sqrt(num) + 1; i++)
    {
        if (fabs(i - sqrt(num)) < 1e-6)
        {
            return 0;
        }
    }
    return 1;
}

// Вывод результата
void print_res_arr(int res_arr[], size_t cnt)
{ 
    for (size_t i = 0; i < cnt; i++)
    {
        printf("%d ", res_arr[i]);
    }
    printf("\n");
}

int del_elems(int arr[], size_t len_arr)
{
    size_t cnt = len_arr, iter = 0;
    while (iter < cnt)
    {
        if (check_elem(arr[iter]) == 0)
        {
            for (size_t j = iter; j < len_arr - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            cnt--;
        }
        else
        {
            iter++;
        }
    }
    if (cnt == 0)
    {
        return -1;
    }
    return cnt;
}

int main()
{
    int arr[N];
    int rc, res;
    size_t len_arr;
    rc = scanf("%lu", &len_arr);
    // Проверка корректности ввода длинны массива
    if (rc != 1 || len_arr < 1 || len_arr > 10)
    {
        printf("Error len_elem");
        return 1;
    }
    res = input_arr(arr, len_arr);
    // Проверка вводимых значений
    if (res == 1)
    {
        printf("Error input_value");
        return 1;
    }
    // Вывод итогового массива
    res = del_elems(arr, len_arr);
    if (res == -1)
    {
        printf("Error");
        return 1;
    }
    print_res_arr(arr, res);
    return 0;
}
