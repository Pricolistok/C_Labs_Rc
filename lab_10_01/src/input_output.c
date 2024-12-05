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

int open_file(FILE **file, int argc, char **argv)
{
    int rc;
    if (argc != 2)
        return ERROR_ARGUMENTS;
    *file = fopen(argv[1], "r");
    if (*file == NULL)
        return ERROR_OPEN_FILE;
    rc = check_len_file(*file);
    if (rc == ERROR_LEN_FILE)
        return ERROR_LEN_FILE;
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
        fgetc(file);
        elem = create_elem(name, price, len_name);
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
    product *elem_data = malloc(sizeof(product));
    elem_data->name = name;
    elem_data->price = price;
    elem_data->len_name = len_name;
    if (elem) {
        elem->data = elem_data;
        elem->next = NULL;
    }
    return elem;
}

void print_list(node_t *head) {
    for (; head != NULL; head = head->next) {
        product *elem = (product*)head->data;
        for (size_t i = 0; i < elem->len_name; i++) {
            printf("%c", elem->name[i]);
        }
        printf("\n%d\n", elem->price);
    }
}
