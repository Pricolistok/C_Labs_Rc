// Подключение библиотек и заголовочных файлов
#include <stdio.h>
#include "input_output.h"
#include "errors.h"
#include "process.h"

int main(int argc, char **argv)
{
    // Инициализация переменных
    FILE *f;
    int rc;
    double middle, result_num;
    // Открытие файла
    rc = input_file(&f, argc, argv);
    // Обработка ошибок
    if (rc == MISSING_ARG)
    {
        printf("Missing argument \n");
        return MISSING_ARG;
    }
    if (rc == ERROR_OPEN_FILE)
    {
        printf("Error open file \n");
        return ERROR_OPEN_FILE;
    }
    // Подсчет среднего
    rc = cnt_middle(f, &middle);
    // Обработка ошибок
    if (rc == ERROR_READ_FILE)
    {
        printf("Error read file \n");
        return ERROR_READ_FILE;
    }
    if (rc == EMPTY_FILE)
    {
        printf("Empty file \n");
        return EMPTY_FILE;
    }
    if (rc == ERROR_SYMBOL)
    {
        printf("Error symbol \n");
        return ERROR_SYMBOL;
    }
    fseek(f, 0, SEEK_SET);
    // Поиск числа
    find_num(f, middle, &result_num);
    // Вывод результата
    printf("Result: %lf \n", result_num);
    return OK;
}
