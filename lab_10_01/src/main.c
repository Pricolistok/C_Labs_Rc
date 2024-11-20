#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "input_output.h"
#include "errors.h"
#include "struct.h"

int main(int argc, char **argv)
{
    int rc;
    FILE *file_in;
    rc = open_file(&file_in, argc, argv);
    switch (rc)
    {
        case ERROR_OPEN_FILE:
            printf("Ошибка открытия файла!\n");
            return ERROR_OPEN_FILE;
        case ERROR_LEN_FILE:
            printf("Файл пуст!\n");
            return ERROR_LEN_FILE;
        case ERROR_ARGUMENTS:
            printf("Ошибка количества аргументов!\n");
            return ERROR_ARGUMENTS;
    }

    return OK;
}