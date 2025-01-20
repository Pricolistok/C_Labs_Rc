#include "funcs_for_units.h"


node_t *input_to_list(product list_products[], size_t len_arr)
{
    node_t *head = NULL, *elem = NULL;
    for (size_t i = 0; i < len_arr; i++)
    {
        elem = create_elem(list_products[i].name, list_products[i].price, list_products[i].len_name);
        head = add_to_list_elem_end(head, elem);
    }
    return head;
}


int compare_lists(node_t *head, node_t *result)
{
    node_t *next_elem;
    product *head_data, *result_data;
    for (; head; head = next_elem)
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
    for (; head; head = next_elem)
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
    for (; head; head = next)
    {
        next = head->next;
        free(head->data);
        free(head);
    }
}


int test_rm_duplicates(node_t **head, node_t **result)
{
    int rc;
    node_t *elem = NULL, *saver = NULL, *next = NULL;
    node_t *head_saver = NULL;

    for (node_t *cur = *head; cur != NULL; cur = cur->next)
    {
        elem = malloc(sizeof(node_t));
        if (elem == NULL)
            return -1;
        elem->data = cur->data;
        elem->next = NULL;
        head_saver = add_to_list_elem_end(head_saver, elem);
    }
    remove_duplicates(head, comparator_products);
    saver = *head;
    rc = compare_lists(*head, *result);
    while (saver != NULL)
    {
        next = saver->next;
        free(saver);
        saver = next;
    }
    free_all_data(head_saver);
    free_all_data(*result);

    return rc;
}





int test_pop_front(node_t **head, node_t *result)
{
    int rc;
    product *saver_product = NULL;
    if (*head != NULL)
    {
        saver_product = (*head)->data;
        pop_front(head);
    }
    if (saver_product != NULL)
    {
        free(saver_product->name);
        free(saver_product);
    }
    rc = compare_lists(*head, result);
    return rc;
}




int test_pop_end(node_t **head, node_t *result)
{
    int rc;
    node_t *head_saver = *head;
    product *saver_product = NULL;
    void *data;

    if (*head == NULL)
    {
        if (result == NULL)
            return OK;
        return ERROR;
    }

    for (; head_saver->next != NULL; head_saver = head_saver->next);
    saver_product = head_saver->data;

    data = pop_back(head);
    free(((product*)data)->name);
    free(data);
    if (saver_product != data)
        return ERROR;
    rc = compare_lists(*head, result);
    return rc;
}


