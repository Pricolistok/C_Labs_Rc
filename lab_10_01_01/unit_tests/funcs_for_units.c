#include "funcs_for_units.h"

node_t *add_elem_to_list(node_t *head, node_t *elem)
{
    node_t *cur = head;
    if (!cur) {
        return elem;
    }
    for ( ; cur->next; cur = cur->next)
        ;
    cur->next = elem;
    return head;
}

node_t *create_elem_list(char *name, int price, size_t len_name)
{
    node_t *elem = malloc(sizeof(node_t));
    if (!elem)
        return elem;
    product *product_elem = malloc(sizeof(product));
    if (!product_elem)
        return NULL;
    product_elem->name = name;
    product_elem->price = price;
    product_elem->len_name = len_name;
    elem->data = product_elem;
    elem->next = NULL;
    return elem;
}


node_t *input_to_list(product list_products[], size_t len_arr)
{
    node_t *head = NULL, *elem;
    for (size_t i = 0; i < len_arr; i++)
    {
        elem = create_elem_list(list_products[i].name, list_products[i].price, list_products[i].len_name);
        head = add_elem_to_list(head, elem);
    }
    return head;
}

int compare_lists(node_t *head, node_t *result)
{
    node_t *next_elem;
    product *head_data, *result_data;
    for ( ; head; head = next_elem)
    {
        head_data = head->data;
        result_data = result->data;
        if (head_data->price != result_data->price)
            return ERROR;
        if (head_data->len_name != result_data->len_name)
            return ERROR;
        if (strcmp(head_data->name, result_data->name) != 0)
            return ERROR;
        if ((head->next == NULL && result->next != NULL) || (head->next != NULL && result->next == NULL))
            return ERROR;
        next_elem = head->next;
        result = result->next;
    }
    return OK;
}

void print_list(node_t *head)
{
    node_t *next_elem;
    product *head_data;
    for ( ; head; head = next_elem)
    {
        head_data = head->data;
        for (size_t i = 0; i < head_data->len_name; i++)
            printf("%c", head_data->name[i]);
        printf(" %d\n", head_data->price);
        next_elem = head->next;
    }
}

void free_all_data_for_test(node_t *head)
{
    node_t *next;
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        free(head->data);
        free(head);
        return;
    }
    for ( ; head; head = next)
    {
        next = head->next;
        free(head->data);
        free(head);
    }
}
