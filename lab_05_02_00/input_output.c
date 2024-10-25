// Подключение заголовочных файлов
#include "input_output.h"

// Функция для открытия файла
int input_file(FILE **f, int argc, char **argv)
{
    if (argc != 2)
        return MISSING_ARG;
    if ((*f = fopen(argv[1], "r")) == NULL)
    {
        return ERROR_OPEN_FILE;
    }
    return OK;
}
