#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "input_output.h"
#include "errors.h"
#include "struct.h"

int main(int argc, char **argv)
{
    int rc, chice_menu;
    FILE *file_in, *file_out;
    node_t * head = NULL;

    rc = work_with_args(&file_in, &file_out, argc, argv, &chice_menu);
    switch (rc)
    {
        case ERROR_OPEN_FILE_IN:
            // printf("Ошибка открытия входного файла!\n");
            return ERROR_OPEN_FILE_IN;
        case ERROR_OPEN_FILE_OUT:
            // printf("Ошибка открытия выходного файла!\n");
            return ERROR_OPEN_FILE_OUT;
        case ERROR_LEN_FILE:
            // printf("Файл пуст!\n");
            return ERROR_LEN_FILE;
        case ERROR_ARGUMENTS:
            // printf("Ошибка количества аргументов!\n");
            return ERROR_ARGUMENTS;
        case ERROR_CHOICE_MENU:
            // printf("Ошибка выбора пункта меню!\n");
            return ERROR_CHOICE_MENU;
    }

    rc = read_from_file(file_in, &head);
    if (rc == ERROR_READ_PRICE)
    {
        fclose(file_in);
        fclose(file_out);
        // printf("Ошибка чтения цены!\n");
        return ERROR_READ_PRICE;
    }
    else if (rc == ERROR_ADD_MEMORY)
    {
        fclose(file_in);
        fclose(file_out);
        // printf("Ошибка выделения памяти!\n");
        return ERROR_ADD_MEMORY;
    }
    else if (rc == ERROR_PRICE)
    {
        fclose(file_in);
        fclose(file_out);
        // printf("Ошибка значения цены!\n");
        return ERROR_PRICE;
    }
    else if (rc == ERROR_LEN_NAME)
    {
        fclose(file_in);
        fclose(file_out);
        // printf("Ошибка длины имени!\n");
        return ERROR_LEN_NAME;
    }

    switch (chice_menu)
    {
        case MODE_POP_FRONT:
            pop_front(&head);
            print_list_to_file(head, file_out);
            break;
        case MODE_POP_END:
            pop_end(&head);
            print_list_to_file(head, file_out);
            break;
        case MODE_SORT:
            head = sort(head, comparator_prices);
            print_list_to_file(head, file_out);
            break;
        case MODE_SORT_POP_FRONT_END:
            pop_front(&head);
            pop_end(&head);
            head = sort(head, comparator_prices);
            print_list_to_file(head, file_out);
            break;
        case MODE_POP_DUPLICATES:
            remove_duplicates(&head, comparator_products);
            print_list_to_file(head, file_out);
            break;
        case MODE_POP_DUPLICATES_SORT:
            remove_duplicates(&head, comparator_products);
            head = sort(head, comparator_prices);
            print_list_to_file(head, file_out);
            break;
    }

    free_all_data(head);
    fclose(file_in);
    fclose(file_out);
    return OK;
}
