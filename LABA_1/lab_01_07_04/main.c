// Доклин Георгий ИУ7-22Б
// Ввод библиотек
#include <stdio.h>
#include <math.h>

// Инициализация функции для подсчета знаенчия функции
double count_fx(double x)
{
    double f_x = (1 / pow((1 + x), 3));
    return f_x;
}
// Инициализация функции для подсчета ряда
double count_sx(double x, double eps)
{
    double s_x = 1, new_elem = 2, num = 2;
    int flag = -1;
    while (fabs(new_elem) >= eps)
    {
        // Обновление значений
        new_elem = (num * (num + 1) * pow(x, num - 1)) / 2;;
        s_x = s_x + flag * new_elem;
        num += 1;
        flag *= -1;
    }
    return s_x;
}
//  Функция для подсчета абсолютной погрешности
double count_abs_err(double f_x, double s_x)
{
    double abs_error = fabs(f_x - s_x);
    return abs_error;
}
// Функция для подсчета относительной погрешности
double count_rel_err(double f_x, double s_x)
{
    double rel_error = fabs(f_x - s_x) / fabs(f_x);
    return rel_error;
}


int main()
{
    // Инициализация переменных
    double x, eps, s_x, f_x, absolute_error, relative_error;
    int rc;
    // Перемнная отвечающая за знак
    // Проверка данных при вводе
    rc = scanf("%lf%lf", &x, &eps);
    if (rc != 2 || fabs(x) >= 1 || eps <= 0 || eps > 1)
    {
        printf("Error ");
        return 1;
    }
    // Значения для начала подсчета
    s_x = 1;
    // Подсчет s_x
    s_x = count_sx(x, eps);
    // Присваивание значений
    f_x = count_fx(x);
    absolute_error = count_abs_err(f_x, s_x);
    relative_error = count_rel_err(f_x, s_x);
    // Вывод
    printf("%lf %lf %lf %lf", s_x, f_x, absolute_error, relative_error);
    return 0;
}