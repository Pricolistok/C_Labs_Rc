#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "input_output.h"
#include "process.h"


int main(int argc, char **argv)
{
    // Инициализация переменных
    int rc;
    FILE *file_in;
    FILE *file_out;
    size_t n = 0, m = 0;
    double **arr = NULL;

    // Открытие файла
    rc = open_file_in(&file_in, argc, argv);
    // Обработка ошибок по работе с файлом
    switch (rc)
    {
    case ERROR_ARGS:
        printf("Ошибка аргументов!\n");
        return ERROR_ARGS;
    case ERROR_OPEN_FILE:
        printf("Ошибка открытия файла!\n");
        return ERROR_OPEN_FILE;
    case ERROR_LEN_FILE:
        printf("Файл - пуст!\n");
        return ERROR_LEN_FILE;
    }

    // Подсчет количества элементов
    cnt_elem_matrix(file_in, &n, &m);

    // Выделение памяти для матрицы
    arr = add_memory(n, m);
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        fclose(file_in);
        return ERROR_ADD_MEMORY;
    }

    // Ввод из файла в матрицу
    input_from_file(file_in, arr, m);

    // Открытие файла для вывода
    rc = open_file_out(&file_out, argc, argv);
    // Обработка ошибок связанных с открытием файла
    switch (rc)
    {
    case ERROR_ARGS:
        printf("Ошибка аргументов!\n");
        fclose(file_in);
        free_memory(arr, n);
        return ERROR_ARGS;
    case ERROR_OPEN_FILE:
        printf("Ошибка открытия файла!\n");
        fclose(file_in);
        free_memory(arr, n);
        return ERROR_OPEN_FILE;
    }

    // Вывод матрицы в файл
    print_matrix_to_file(arr, n, m, file_out);

    // Освобождение выделенной памяти
    free_memory(arr, n);
    // ЗАкрытие файлов
    fclose(file_in);
    fclose(file_out);
    return OK;
}
