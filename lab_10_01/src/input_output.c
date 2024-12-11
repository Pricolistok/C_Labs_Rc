#include "input_output.h"

int check_len_file(FILE *file)
{
    long int saver_position = ftell(file);
    fseek(file, 0, SEEK_END);
    if (saver_position == ftell(file))
        return ERROR_LEN_FILE;
    fseek(file, 0, SEEK_SET);
    return OK;
}

int check_choice_menu(char **argv) {
    if (strcmp(argv[3], "POP_FRONT") == 0)
        return MODE_POP_FRONT;
    else if (strcmp(argv[3], "POP_END") == 0)
        return MODE_POP_END;
    else if (strcmp(argv[3], "SORT") == 0)
        return MODE_SORT;
    else if (strcmp(argv[3], "SORT_POP_FRONT_END") == 0)
        return MODE_SORT_POP_FRONT_END;
    else if (strcmp(argv[3], "POP_DUPL") == 0)
        return MODE_POP_DUPLICATES;
    else if (strcmp(argv[3], "POP_SORT_DUPL") == 0)
        return MODE_POP_DUPLICATES_SORT;
    return ERROR_CHOICE_MENU;
}


int open_file_in(FILE **file, char **argv) {
    *file = fopen(argv[1], "r");
    if (*file == NULL)
        return ERROR_OPEN_FILE_IN;
    if (check_len_file(*file))
        return ERROR_LEN_FILE;
    return OK;
}

int open_file_out(FILE **file, char **argv) {
    *file = fopen(argv[2], "w");
    if (*file == NULL)
        return ERROR_OPEN_FILE_OUT;
    return OK;
}


int work_with_args(FILE **file_in, FILE **file_out, int argc, char **argv, int *choice_menu)
{
    int rc;
    if (argc != 4)
        return ERROR_ARGUMENTS;
    *choice_menu = check_choice_menu(argv);
    if (*choice_menu == ERROR_CHOICE_MENU)
        return ERROR_CHOICE_MENU;
    rc = open_file_in(file_in, argv);
    if (rc != OK)
        return rc;
    rc = open_file_out(file_out, argv);
    if (rc != OK) {
        fclose(*file_in);
        return rc;
    }
    return OK;

}


int read_from_file(FILE *file, node_t **head)
{
    long int saver_pos;
    int rc, price;
    size_t len_name = 0;
    char *name, ch;
    node_t *elem;

    while (!feof(file)) {
        saver_pos = ftell(file);
        while ((ch = fgetc(file)) != '\n' && ch != EOF)
            len_name++;
        if (len_name == 0)
            return ERROR_LEN_NAME;
        name = malloc(len_name + 1);
        if (!name)
            return ERROR_ADD_MEMORY;
        fseek(file, saver_pos, SEEK_SET);
        for (size_t i = 0; i < len_name; i++)
            name[i] = fgetc(file);
        name[len_name] = 0;

        rc = fscanf(file, "%d", &price);
        if (rc != 1)
            return ERROR_READ_PRICE;
        if (price <= 0)
            return ERROR_PRICE;
        fgetc(file);

        elem = create_elem(name, price, len_name);
        if (elem == NULL)
            return ERROR_ADD_MEMORY;
        *head = add_to_list_elem_end(*head, elem);
        if (elem == NULL)
            return ERROR_ADD_MEMORY;

        len_name = 0;
    }
    return OK;
}


node_t *add_to_list_elem_end(node_t *head, node_t *elem) {
    node_t *cur = head;
    if (!head)
        return elem;
    for ( ; cur->next; cur = cur->next)
        ;
    cur->next = elem;
    return head;
}


node_t* create_elem(char *name, int price, size_t len_name) {
    node_t *elem = malloc(sizeof(node_t));
    if (!elem)
        return elem;
    product *elem_data = malloc(sizeof(product));
    if (!elem_data)
        return NULL;
    elem_data->name = name;
    elem_data->price = price;
    elem_data->len_name = len_name;
    if (elem) {
        elem->data = elem_data;
        elem->next = NULL;
    }
    return elem;
}


void print_list_to_file(node_t *head, FILE *file_out) {
    if (head == NULL)
        return;
    for (; head != NULL; head = head->next) {
        product *elem = head->data;
        for (size_t i = 0; i < elem->len_name; i++) {
            fprintf(file_out, "%c", elem->name[i]);
        }
        fprintf(file_out, "\n%d\n", elem->price);
    }
}


