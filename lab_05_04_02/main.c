// Инициализация библиотек и заголовчных файлов
#include <stdio.h>
#include "input_output.h"
#include "errors.h"
#include "process.h"
#include "const.h"
#include <string.h>
#include "struct.h"

int main(int argc, char **argv)
{
    // Инициализация переменных
    FILE *f_in, *f_out;
    char substr[NAME_LEN + 2];
    int rc;
    size_t len_arr;
    product products_arr[200];
    // Обработка аргументов и файла
    rc = input_file(&f_in, &f_out, substr, argc, argv);
    // Обработка ошибок при открытии
    if (rc == MISSING_ARG)
    {
        printf("Missing argument \n");
        return ERROR_COMMAND;
    }
    if (rc == ERROR_OPEN_FILE)
    {
        printf("Error open file \n");
        return ERROR_OPEN_FILE;
    }
    if (rc == ERROR_ARG_STR)
    {
        printf("Error str \n");
        return ERROR_COMMAND;
    }
    // Обрабока поиска элементов
    if (rc == FT)
    {
        // Создание массива
        rc = create_arr(f_in, products_arr, &len_arr);
        // Обработка ошибок
        if (rc == ERROR_READ_FILE)
        {
            printf("Error read file \n");
            return ERROR_READ_FILE;
        }
        if (rc == INPUT_STR_ERROR)
        {
            printf("Error str \n");
            return INPUT_STR_ERROR;
        }
        if (rc == INPUT_NUM_ERROR)
        {
            printf("Error num \n");
            return INPUT_NUM_ERROR;
        }
        if (rc == ERROR_LEN_FILE)
        {
            printf("Error len file \n");
            return ERROR_LEN_FILE;
        }
        // Поиск элементов
        rc = find_elems(products_arr, len_arr, substr);
        fclose(f_in);
        if (rc == HAVENT_CMP_RESULT)
        {
            printf("Error havent elems \n");
            return HAVENT_CMP_RESULT;
        }
    }
    // Обработка команды сортировки
    if (rc == ST)
    {
        // Создание массива
        rc = create_arr(f_in, products_arr, &len_arr);
        // Обработка ошибок
        if (rc == ERROR_READ_FILE)
        {
            printf("Error read file \n");
            return ERROR_COMMAND;
        }
        if (rc == INPUT_STR_ERROR)
        {
            printf("Error str \n");
            return INPUT_STR_ERROR;
        }
        if (rc == INPUT_NUM_ERROR)
        {
            printf("Error num \n");
            return INPUT_NUM_ERROR;
        }
        if (rc == ERROR_LEN_FILE)
        {
            printf("Error len file \n");
            return ERROR_LEN_FILE;
        }
        // Сортировка массива
        rc = sort_arr(products_arr, len_arr);
        fclose(f_in);
        if (rc == ERROR_LEN_FILE)
        {
            printf("Error len file \n");
            return ERROR_LEN_FILE;
        }
        // Запись результата в файл
        write_to_file(f_out, products_arr, len_arr);
    }
    return OK;
}
