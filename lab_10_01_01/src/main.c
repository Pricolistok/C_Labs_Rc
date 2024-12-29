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
    node_t *head = NULL;
    node_t *head_saver = NULL, *elem = NULL, *next = NULL, *save = NULL, *saver = NULL;
    node_t *cur_saver = NULL;
    product *saver_product;

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
            saver_product = head->data;
            pop_front(&head);
            free(saver_product);
            print_list_to_file(head, file_out);
            break;
        case MODE_POP_END:
            head_saver = head;
            for (; head_saver->next != NULL; head_saver = head_saver->next);
            saver_product = head_saver->data;
            pop_end(&head);
            free(saver_product->name);
            print_list_to_file(head, file_out);
            break;
        case MODE_SORT:
            head = sort(head, comparator_prices);
            print_list_to_file(head, file_out);
            break;
        case MODE_SORT_POP_FRONT_END:
            saver_product = head->data;
            pop_front(&head);
            free(saver_product);
            if (head == NULL)
                break;
            head_saver = head;
            for (; head_saver->next != NULL; head_saver = head_saver->next);
            saver_product = head_saver->data;
            pop_end(&head);
            free(saver_product->name);
            head = sort(head, comparator_prices);
            print_list_to_file(head, file_out);
            break;
        case MODE_POP_DUPLICATES:
            for (node_t *cur = head; cur != NULL; cur = cur->next)
            {
                elem = malloc(sizeof(node_t));
                elem->data = cur->data;
                elem->next = NULL;
                head_saver = add_to_list_elem_end(head_saver, elem);
            }
            save = head_saver;
            remove_duplicates(&head, comparator_products);
            cur_saver = head_saver;
            for (node_t *cur = head; cur != NULL; cur = cur->next) {
                if (cur_saver == NULL)
                    break;
                if (cur->data != cur_saver->data)
                {
                    next = cur_saver->next;
                    saver->next = next;
                    free(cur_saver);
                    cur_saver = next;
                } else
                {
                    saver = cur_saver;
                    cur_saver = cur_saver->next;
                }
            }
            head_saver = save;
            while (head_saver != NULL)
            {
                next = head_saver->next;
                free(head_saver);
                head_saver = next;
            }
            print_list_to_file(head, file_out);
            break;
        case MODE_POP_DUPLICATES_SORT:
            for (node_t *cur = head; cur != NULL; cur = cur->next)
            {
                elem = malloc(sizeof(node_t));
                elem->data = cur->data;
                elem->next = NULL;
                head_saver = add_to_list_elem_end(head_saver, elem);
            }
            save = head_saver;
            remove_duplicates(&head, comparator_products);
            cur_saver = head_saver;
            for (node_t *cur = head; cur != NULL; cur = cur->next) {
                if (cur_saver == NULL)
                    break;
                if (cur->data != cur_saver->data)
                {
                    next = cur_saver->next;
                    saver->next = next;
                    free(cur_saver);
                    cur_saver = next;
                }
                else
                {
                    saver = cur_saver;
                    cur_saver = cur_saver->next;
                }
            }
            head = sort(head, comparator_prices);
            head_saver = save;
            while (head_saver != NULL) {
                next = head_saver->next;
                free(head_saver);
                head_saver = next;
            }
            print_list_to_file(head, file_out);
            break;
    }
    free_all_data(head);
    fclose(file_in);
    fclose(file_out);
    return OK;
}
