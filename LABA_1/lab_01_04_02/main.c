// Доколин Георгий ИУ7-22Б
// Лабораторная рабта номер 1
// Перевод времени

// Ввод библитек
#include <stdio.h>

// Создание функции
int main(void)
{
    // Инициализация переменных
    int input_value, minutes, hours;
    // Ввод значения
    scanf("%d", &input_value);
    // Подсчет значений
    hours = (input_value / 3600);
    input_value = input_value % 3600;
    minutes = (input_value / 60);
    input_value = input_value % 60;
    // Вывод результата
    printf("%d %d %d \n", hours, minutes, input_value);
    return 0;
}

