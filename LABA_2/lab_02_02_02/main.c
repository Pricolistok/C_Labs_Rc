// Доколин Георгий ИУ7-22Б
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 10

// Функция ввода массива
int input_arr(long long int arr[], size_t len_arr)
{
    int rc;
    long long int elem;
    for (size_t i = 0; i < len_arr; i++)
    {
        rc = scanf("%lld", &elem);
        if (rc != 1)
        {
            return 1;
        }
        arr[i] = elem;
    }
    return 0;
}


// Вывод результата
void print_res_arr(long long int res_arr[], size_t cnt)
{
    for (size_t i = 0; i < cnt; i++)
    {
        printf("%lld ", res_arr[i]);
    }
    printf("\n");
}

// Подсчет количества разрядов числа
long long int cnt_first(long long int num)
{
    long long int saver = num;
    long long int cnt = 1;
    if (num == 0)
    {
        num = 1;
    }
    while (num != 0)
    {
        num /= 10;
        cnt *= 10;
    }
    return saver / (cnt / 10);
}

// Функция для определения элементов, которые подходят по условию
int check_values(long long int arr[], size_t len_arr)
{
    size_t cnt = 0;
    
    for (size_t i = 0; i < len_arr; i++)
    {
        long long int elem = llabs(arr[i]);
        if (elem % 10 == cnt_first(elem))
        {
            cnt++;
        }
    }
    if (cnt == 0)
    {
        return 100;
    }
    return cnt;
}

// Создание нового массива
void create_arr(long long int arr[], size_t len_arr, long long int res_arr[])
{
    int res_index = 0;
    for (size_t i = 0; i < len_arr; i++)
    {
        long long int elem = llabs(arr[i]);
        if (elem % 10 == cnt_first(elem))
        {        
            res_arr[res_index] = arr[i];
            res_index++;
        }
    }
}

int main()
{
    long long int arr[N], res_arr[N];
    int rc, res;
    size_t len_arr, cnt;
    rc = scanf("%lu", &len_arr);
    // Проверка корректности ввода длинны массива
    if (rc != 1 || len_arr < 1 || len_arr > 10)
    {
        printf("Error len_elem\n");
        return 1;
    }
    res = input_arr(arr, len_arr);
    // Проверка вводимых значений
    if (res == 1)
    {
        printf("Error input_value\n");
        return 1;
    }
    // Проверка на наличие искомых элементов массива
    cnt = check_values(arr, len_arr);
    if (cnt == 100)
    {
        printf("Error haven`t simetric elements\n");
        return 1;
    }
    create_arr(arr, len_arr, res_arr);
    // Вывод нового массива
    print_res_arr(res_arr, cnt);
    return 0;
}
