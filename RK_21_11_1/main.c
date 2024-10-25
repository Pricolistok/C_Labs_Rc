#include <stdio.h>
#include <math.h>

int new_num_cnt(int num)
{
    int iter = 0, new_num = 0;
    while (num > 0)
    {
        if ((num % 10) % 2 != 0)
        {
            new_num += 2 * (int)pow(10, iter);
        }
        else
        {
            new_num += (num % 10) * (int)pow(10, iter);
        }
        num /= 10;
        iter += 1;
    }
    return new_num;
}

// Основная функция
int main()
{
    // Инициазация переменных
    int num, rc, new_num = 0;
    printf("Введите число: ");
    rc = scanf("%d", &num);
    // Проверка ввода
    if (rc != 1)
    {
        printf("Ошибка ввода, возможно введена строка");
        return 100;
    }
    // Проверка на натуральное
    if (num < 1)
    {
        printf("Число не является натуральным");
        return 200;
    }
    // Алгоритм
    new_num = new_num_cnt(num);
    // Вывод
    printf("Новое число: %d \n", new_num);
    return 0;
}