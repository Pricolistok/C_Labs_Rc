// Подключение библиотек и заголовочных файлов
#include <stdio.h>
#include "process.h"

// Функция поиска максимумов
int process(FILE *f, int *max_1, int *max_2)
{
    int num;
    // Чтение чиел
    fscanf(f, "%d", max_1);
    fscanf(f, "%d", max_2);
    // Сравнение чисел
    if (*max_2 > *max_1)
    {
        num = *max_1;
        *max_1 = * max_2;
        *max_2 = num;
    }
    // Обработка оствшихся
    while (fscanf(f, "%d", &num) == 1)
        if (num > *max_1)
        {
            *max_2 = *max_1;
            *max_1 = num;
        }
        else if (num <= *max_1 && num > *max_2)
            *max_2 = num;

    return OK;
}
