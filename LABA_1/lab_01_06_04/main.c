// Доколин Георйгий ИУ7-22Б
// Ввод библиотек
#include <stdio.h>
#include <math.h>
// Инициализация функции, которая проверяет условия нахождения точки на отрезке
int counter(double x_q, double y_q, double x_r, double y_r, double x_p, double y_p)
{
    if ((fabs((x_p - x_q) * (y_r - y_q) - (x_r - x_q) * (y_p - y_q)) < 1e-8) \
        && (0 <= (x_p - x_q) * (x_r - x_p)) && ((x_p - x_q) * (x_r - x_p) <= pow((x_q - x_r), 2)) \
        && (0 <= (y_p - y_q) * (y_r - y_p)) && ((y_p - y_q) * (y_r - y_p) <= pow((y_q - y_r), 2)))
    {
        printf("1 \n");
    }    
    else
    {
        printf("0 \n");
    }
    return 0;
}
// Инициализация функции
int main()
{
    // Инициализация переменных
    double x_q, y_q, x_r, y_r, x_p, y_p;
    int rc;
    // Проверка ввода
    rc = scanf("%lf%lf%lf%lf%lf%lf", &x_q, &y_q, &x_r, &y_r, &x_p, &y_p);
    if (rc != 6 || (fabs(x_q - x_r) < 1e-8 && fabs(y_q - y_r) < 1e-8))
    {
        printf("Error");
        return 1;
    }
    // Вызов функции
    counter(x_q, y_q, x_r, y_r, x_p, y_p);
    return 0;
}