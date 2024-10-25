// Доклин Георгий ИУ7-22Б
// Ввод библиотек
#include <stdio.h>
#include <math.h>
// Инициализация функции для подсчета результата
double count_result(double x)
{
    double n = 1, result = 0;\
    int rc;
    // Цикл для сложения, пока вводятся неотридцательные числа
    while (x >= 0)
    {
        result = result + sqrt(n + x);
        rc = scanf("%lf", &x);
        if (rc != 1)
        {
            return -1;
        }
        n += 1;
    }
    n -= 1;
    result = (1 / n) * result;
    return result;
}
// Инициализация функции
int main(void)
{
    double x, res;
    int rc;
    rc = scanf("%lf", &x);
    // Проверка корректности ввода
    if (rc != 1 || x < 0)
    {
        printf("Error");
        return 1;
    }
    // Вывод
    res = count_result(x);
    if (res + 1 < 1e-6)
    {
        printf("Error");
        return 1;
    }
    else
    {
        printf("%lf", res);
        return 0;
    }
}

