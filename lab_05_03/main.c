/*
Программа умеет создавать бинарный файл, который будет заполнен не отсортированными числами. Так же программа 
сортирует и выводит данные из бинарного файла.
Программа использует метод сортировки пузырьком, сортируя по возрастанию.
Типом данных выбран int.
*/
// Подключение библиотек и заголовочных файлов
#include <stdio.h>
#include "input_output.h"
#include "errors.h"
#include "process.h"

int main(int argc, char **argv)
{
    // Инициализация перменных
    FILE *f_in = NULL, *f_out = NULL, *f_work = NULL;
    int rc, digit;
    // Обработка и открытие файлов
    rc = input_file(&f_work, &f_in, &f_out, argc, argv, &digit);
    // Обработка ошибок
    if (rc == MISSING_ARG)
        return MISSING_ARG;
    if (rc == ERROR_OPEN_FILE)
        return ERROR_OPEN_FILE;
    // Обработка вывода данных
    if (rc == PRINT_FILE)
    {
        rc = print_bin_file(f_work);
        fclose(f_work);
        if (rc != OK)
            return rc;
    }
    // Обработка ошибок
    if (rc == NO_DIGIT)
        return NO_DIGIT;
    // Обработка создания файла
    if (rc == CREATE_FILE)
    {
        create_bin_file(f_work, digit);
        fclose(f_work);
    }
    // Обработка сортировки массива
    if (rc == SORT_FILE)
    {
        rc = sort_file(f_work);
        if (rc != OK)
            return rc;
        rc = print_bin_file(f_work);
        fclose(f_work);
        if (rc != OK)
            return rc;
    }
    // Обработка функции конвертации файлов
    if (rc == IMPORT)
    {
        rc = import(f_in, f_out);
        fclose(f_in);
        fclose(f_out);
        if (rc == INCORRECT_FILE)
            return INCORRECT_FILE;
        return OK;
    }
    // Обработка функции конвертации файлов
    if (rc == EXPORT)
    {
        export(f_in, f_out);
        fclose(f_in);
        fclose(f_out);
        return OK;
    }
    return OK;
}
