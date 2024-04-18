// Доколин Георгий ИУ7-22Б
// Вывести среднее арифметическое отридцательных чисел в массиве
// Подключаем библиотеки
#include <stdio.h>
#include <math.h>

// Константы
#define N 10

// Функция ввода списка с проверкой каждого элмента
int input_arr(size_t len, int arr[])
{
    int rc, elem;
    for (size_t i = 0; i < len; i++)
    {
        rc = scanf("%d", &elem);
        if (rc == 1)
        {
            arr[i] = elem;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

// Подсчет среднего арифметиеского
float midle_value(size_t len, int arr[])
{
    float summ = 0;
    int cnt = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] < 0)
        {
            summ += arr[i];
            cnt++;
        }
    }
    if (cnt == 0)
    {
        return 1;
    }
    return summ / cnt;
}

// Основная функция
int main(void)
{
    // Объявляем переменные 
    size_t len_arr;
    int arr[N], rc;
    double temp;
    rc = scanf("%lu", &len_arr);
    // Проверка ввода длинны массива
    if (rc != 1 || len_arr > 10 || len_arr < 1)
    {
        printf("Error \n");
        return 1;
    }
    // Провека ввода массива
    if (input_arr(len_arr, arr) == 1)
    {
        printf("Error \n");
        return 1;
    }
    // Проверка наличия отридцательных чисел
    temp = midle_value(len_arr, arr);
    if (temp + 1 > 1e-8)
    {
        printf("Error \n");
        return 1;
    }
    // Вывод результата
    printf("%lf \n", temp);
    return 0;
}
