// Доколин Георгий ИУ7-22Б
// Лабораторная работа номер 1
// Подсчет периметра треугольника
// Ввод библиотек
#include <stdio.h>
#include <math.h>

// Создание функции
int main(void)
{
    // Инициализация переменных
    double x_a, y_a, x_b, y_b, x_c, y_c;
    // Ввод переменных
    scanf("%lf %lf %lf %lf %lf %lf", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c);
    // Инициализация переменных
    double first_side, second_side, third_side, result;
    // Подсчет длинны каждой стороны
    first_side = sqrt((pow((x_a - x_b), 2)) + (pow((y_a - y_b), 2)));
    second_side = sqrt((pow((x_c - x_b), 2)) + (pow((y_c - y_b), 2)));
    third_side = sqrt((pow((x_c - x_a), 2)) + (pow((y_c - y_a), 2)));
    // Подсчет результата
    result = first_side + second_side + third_side;
    // Вывод результата
    printf("%lf \n", result);
    return 0;
}

