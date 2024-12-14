#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "input_output.h"
#include "errors.h"
#include "struct.h"

int main(int argc, char **argv)
{
    int rc, chice_menu;
    char *finder = NULL;
    size_t len_finder;
    FILE *file_in;
    node_t *head = NULL;

    rc = work_with_args(&file_in, argc, argv, &chice_menu, &finder, &len_finder);
    switch (rc)
    {
        case ERROR_OPEN_FILE:
            printf("Ошибка открытия входного файла!\n");
            return ERROR_OPEN_FILE;
        case ERROR_LEN_FILE:
            printf("Файл пуст!\n");
            return ERROR_LEN_FILE;
        case ERROR_ARGUMENTS:
            printf("Ошибка аргументов!\n");
            return ERROR_ARGUMENTS;
    }

    rc = read_from_file(file_in, &head);
    switch (rc)
    {
        case ERROR_LEN_NAME:
            printf("Ошибка длины имени!\n");
            fclose(file_in);
            return ERROR_LEN_NAME;
        case ERROR_READ_YEAR:
            printf("Ошибка чтения года!\n");
            fclose(file_in);
            return ERROR_READ_YEAR;
        case ERROR_YEAR:
            printf("Ошибка значения года!\n");
            fclose(file_in);
            return ERROR_YEAR;
        case ERROR_LEN_GROUP:
            printf("Ошибка длины группы!\n");
            fclose(file_in);
            return ERROR_LEN_GROUP;
        case ERROR_ADD_MEMORY:
            printf("Ошибка выделения памяти!\n");
            fclose(file_in);
            return ERROR_ADD_MEMORY;
    }

    if (chice_menu == 1)
    {
        print_list(head);
    }
    if (chice_menu == 2)
    {
        printf("%s", finder);
        if (select_elems(head, finder) == 0)
        {
            printf("При поиске ничего не найдено!\n");
            free_all_data(head);
            return ERROR_FIND;
        }
    }
    free_all_data(head);
    fclose(file_in);
    return OK;
}
