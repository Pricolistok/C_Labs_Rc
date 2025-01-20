#include "process.h"

void *pop_front(node_t **head)
{
    void *saver_data;
    if (head == NULL || *head == NULL)
        return NULL;
    node_t *saver_point = *head;
    saver_data = (*head)->data;
    *head = (*head)->next;
    free(saver_point);
    return saver_data;
}


void *pop_back(node_t **head)
{
    node_t *next;
    void *data;
    if (head == NULL || *head == NULL)
        return NULL;
    if ((*head)->next == NULL)
    {
        data = (*head)->data;
        free(*head);
        *head = NULL;
        return data;
    }
    for (node_t *curr = *head; ; curr = next)
    {
        next = curr->next;
        if (!next->next)
        {
            data = next->data;
            curr->next = NULL;
            free(next);
            break;
        }
    }
    return data;
}

void product_free(node_t *head)
{
    if (head == NULL)
        return;
    product *elem_data = (product*)head->data;
    if (elem_data != NULL)
    {
        free(elem_data->name);
        free(elem_data);
        head->data = NULL; // Set data to NULL to avoid double free
    }
}

void free_all_data(node_t *head)
{
    node_t *next;
    while (head != NULL)
    {
        next = head->next;
        product_free(head);
        free(head); // Free the node itself
        head = next;
    }
}

int comparator_products(const void *compare_1, const void *compare_2)
{
    product *compare_data_1 = (product*)compare_1;
    product *compare_data_2 = (product*)compare_2;
    if (compare_data_1->len_name != compare_data_2->len_name)
        return -1;
    if (strcmp(compare_data_1->name, compare_data_2->name) != 0)
        return -1;
    if (compare_data_1->price != compare_data_2->price)
        return -1;
    return 0;
}

int is_in_list_before_elem(node_t *head, node_t *elem, int (*comparator)(const void*, const void*))
{
    node_t *cur = head;
    while (cur != elem)
    {
        if (comparator(elem->data, cur->data) == 0)
            return -1;
        cur = cur->next;
    }
    return 0;
}

void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*))
{
    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return;

    node_t *saver = *head;
    node_t *cur = (*head)->next, *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        if (is_in_list_before_elem(*head, cur, comparator) == -1)
        {
            saver->next = next;
            free(cur);
        }
        else
            saver = cur;
        cur = next;
    }
}

int comparator_prices(const void *price_1, const void *price_2)
{
    product *price_data_1 = (product*)price_1;
    product *price_data_2 = (product*)price_2;
    if (price_data_1->price > price_data_2->price)
        return 1;
    else if (price_data_1->price < price_data_2->price)
        return -1;
    return 0;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (head == NULL || element == NULL || comparator == NULL)
        return;
    if (*head == NULL || comparator((*head)->data, element->data) > 0)
    {
        element->next = *head;
        *head = element;
        return;
    }
    node_t *tmp = *head;
    while (tmp->next != NULL && comparator(tmp->next->data, element->data) <= 0)
        tmp = tmp->next;
    element->next = tmp->next;
    tmp->next = element;
}


node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *result = NULL;
    node_t *cur, *next;

    if (head == NULL || head->next == NULL)
        return head;

    cur = head;
    while (cur != NULL)
    {
        next = cur->next;
        if (result == NULL || comparator(result->data, cur->data) > 0)
        {
            cur->next = result;
            result = cur;
        }
        else if (comparator(result->data, cur->data) <= 0)
            sorted_insert(&result, cur, comparator);
        cur = next;
    }
    return result;
}
