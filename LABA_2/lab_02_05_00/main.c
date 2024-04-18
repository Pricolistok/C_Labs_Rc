// Доколин Георгий ИУ7-22Б
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 10

// Функция ввода массива
int input_arr(int *pa, int *finish)
{
    for (int *i = pa; i < finish; i++)
    {
        if (scanf("%d", i) != 1)
        {
            return 1;
        }
    }
    return 0;
}

// Функция подсчета максимального значения
int count_max(int *pa, int *finish)
{
    int max = *(pa) + *(finish), temp1;
    int iter_step = 1;
    int iter = 0;
    finish++;

    // Определение количества
    for (int *i = pa; i < finish; i++)
    {
        iter += 1;
    }
    if (iter == 1)
    {
        return *pa;
    }
    // Определение середины
    iter = iter / 2;
    for (int *i = pa; i < finish; i++)
    {
        temp1 = *i + *(finish - iter_step);
        if (max < temp1)
        {
            max = temp1;
        }
        if (iter_step == iter)
        {
            break;
        }
        iter_step += 1;
    }
    finish--;
    // Проверка элементов по центру
    if (max < *(finish - iter) * 2)
    {
        max = *(finish - iter) * 2;
    }
    
    return max;
}

int main()
{
    int arr[N];
    int rc, res;
    int *start = arr;
    int len_arr;
    rc = scanf("%d", &len_arr);
    // Проверка корректности ввода длинны массива
    if (rc != 1 || len_arr < 1 || len_arr > 10)
    {
        printf("Error len_elem");
        return 1;
    }
    int *finish = (start + len_arr);
    res = input_arr(start, finish);
    // Проверка вводимых значений
    if (res == 1)
    {
        printf("Error input_value");
        return 1;
    }
    // Вывод результата
    finish--;
    res = count_max(start, finish);
    printf("%d \n", res);
    return 0; 
}
