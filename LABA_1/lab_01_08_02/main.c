// Доколин Георгий ИУ7-22Б
// Импортируем библиотеки
#include <stdio.h>
#include <math.h>

// Инициализируем функцию для перевод числа
void convertation_to_bin(unsigned int num)
{
    // Длинна
    int iter = 31;
    printf("Result: ");
    while (iter >= 0)
    {
        printf("%d", (num >> iter) % 2);
        iter -= 1;
    }
}

// Инициализируем функцию 
int main(void)
{
    // Инициализируем переменные
    unsigned int a;
    int n, rc;
    // Проверка ввода
    rc = scanf("%u %d", &a, &n);
    if (rc != 2)
    {
        printf("Error: number of data entered or type of a");
        return 1;
    }
    // Проверка значений
    if (n < 0)
    {
        printf("Error: value n");
        return 1;
    }
    // Делаем так, чтобы число было всегда меньшк 32
    n %= 32;
    // Сдвиги
    a = (a << n) | (a >> (32 - n));
    // Вывод результата
    convertation_to_bin(a);
    return 0;
}
