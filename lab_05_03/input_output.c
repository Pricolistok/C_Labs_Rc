// Подключениие библиотек и заголовочных файлов
#include "input_output.h"
#include <string.h>
#include "process.h"
#include <ctype.h> 
#include <stdlib.h>

// Функция для открытия файлов и обработки аргументов
int input_file(FILE **f_work, FILE **f_in, FILE **f_out, int args, char **argv, int *digit)
{
    int flag = 0;
    // Проверка количества аргументов
    if (args != 3 && args != 4)
    {
        return MISSING_ARG;
    }
    // Обработка создания нового файла
    else if (strcmp(argv[1], "c") == 0 && args == 4)
    {
        if ((*f_work = fopen(argv[3], "wb")) == NULL)
        {
            return ERROR_OPEN_FILE;
        }
        for (size_t i = 0; i < strlen(argv[2]); i++)
        {
            if (isdigit(argv[2][i]) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            return NO_DIGIT;
        }
        *digit = atoi(argv[2]);
        return CREATE_FILE;
    }
    // Обработка вывода данных
    else if (strcmp(argv[1], "p") == 0 && args == 3)
    {
        if ((*f_work = fopen(argv[2], "rb")) == NULL)
        {
            return ERROR_OPEN_FILE;
        }
        return PRINT_FILE;
    }
    // Обработка сортировки
    else if (strcmp(argv[1], "s") == 0 && args == 3)
    {
        if ((*f_work = fopen(argv[2], "r+b")) == NULL)
        {
            return ERROR_OPEN_FILE;
        }
        return SORT_FILE;
    }
    // Обработка функции import
    else if (strcmp(argv[1], "import") == 0 && args == 4)
    {
        *f_in = fopen(argv[2], "r");
        *f_out = fopen(argv[3], "wb");
        if (*f_in == NULL || *f_out == NULL)
        {
            return ERROR_OPEN_FILE;
        }
        return IMPORT;
    }
    // Обработка функции export
    else if (strcmp(argv[1], "export") == 0 && args == 4)
    {
        *f_in = fopen(argv[2], "rb");
        *f_out = fopen(argv[3], "w");
        if (*f_in == NULL || *f_out == NULL)
        {
            return ERROR_OPEN_FILE;
        }
        if (check_file(*f_in) != OK)
        {
            return ERROR_TYPE_FILE;
        }
        return EXPORT;
    }
    else
    {
        return ERROR_OPEN_FILE;
    }
    return OK;
}
