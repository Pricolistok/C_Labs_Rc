#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "associative_array.h"

typedef struct node
{
    char *key;
    int value;
    struct node *next;
} node_t;


struct assoc_array_type
{
    node_t *list;
};


assoc_array_t assoc_array_create(void)
{
    assoc_array_t arr = malloc(sizeof(struct assoc_array_type));
    if (!arr)
        return NULL;
    arr->list = NULL;
    return arr;
}


void free_list(node_t *node)
{
    node_t *next;
    for (; node != NULL; node = next)
    {
        next = node->next;
        free(node->key);
        free(node);
    }
}


void assoc_array_destroy(assoc_array_t *arr)
{
    if (!arr || !*arr)
    {
        free(*arr);
        return;
    }
    free_list((*arr)->list);
    free(*arr);
    *arr = NULL;
}


void insert_to_list(node_t **node, const char *key, int num, assoc_array_error_t *error_code)
{
    node_t *next = *node;
    if (*node != NULL)
    {

        for (; next->next != NULL; next = next->next)
        {
            if (strcmp(next->key, key) == 0)
            {
                *error_code = ASSOC_ARRAY_KEY_EXISTS;
                return;
            }
        }
        if (strcmp(next->key, key) == 0)
        {
            *error_code = ASSOC_ARRAY_KEY_EXISTS;
            return;
        }
        next->next = malloc(sizeof(node_t));
        if (!next->next)
        {
            *error_code = ASSOC_ARRAY_MEM;
            return;
        }

        next->next->key = malloc(strlen(key) + 1);
        if (!next->next->key)
        {
            free(next->next);
            *error_code = ASSOC_ARRAY_MEM;
            return;
        }
        strcpy(next->next->key, key);
        next->next->value = num;
        next->next->next = NULL;
    }
    else
    {
        *node = malloc(sizeof(node_t));
        if (!*node)
        {
            *error_code = ASSOC_ARRAY_MEM;
            return;
        }
        (*node)->key = malloc(strlen(key) + 1);
        if (!(*node)->key)
        {
            free(*node);
            *error_code = ASSOC_ARRAY_MEM;
            return;
        }

        strcpy((*node)->key, key);
        (*node)->value = num;
        (*node)->next = NULL;
    }
}



assoc_array_error_t assoc_array_insert(assoc_array_t arr, const char *key, int num)
{
    assoc_array_error_t error_code = ASSOC_ARRAY_OK;
    if (arr == NULL || key == NULL || strlen(key) == 0)
        return ASSOC_ARRAY_INVALID_PARAM;
    insert_to_list(&arr->list, key, num, &error_code);
    return error_code;
}

void find_in_arr(node_t *node, const char *key, int **num, assoc_array_error_t *error_code)
{
    for (; node != NULL; node = node->next)
    {
        if (strcmp(node->key, key) == 0)
        {
            *num = &node->value;
            *error_code = ASSOC_ARRAY_OK;
            return;
        }
    }
    *error_code = ASSOC_ARRAY_NOT_FOUND;
}


assoc_array_error_t assoc_array_find(const assoc_array_t arr, const char *key, int **num)
{
    if (arr == NULL || key == NULL || strlen(key) == 0 || num == NULL)
        return ASSOC_ARRAY_INVALID_PARAM;

    assoc_array_error_t error_code = ASSOC_ARRAY_NOT_FOUND;
    find_in_arr(arr->list, key, num, &error_code);
    return error_code;
}


node_t *remove_node(node_t *node, const char *key, assoc_array_error_t *error_code)
{
    node_t *next = node;
    node_t *tmp = node;
    if (strcmp(next->key, key) == 0)
    {
        node = node->next;
        free(next->key);
        free(next);
        *error_code = ASSOC_ARRAY_OK;
        return node;
    }
    for (; next != NULL; next = next->next)
    {
        if (strcmp(next->key, key) == 0)
        {
            tmp->next = next->next;
            free(next->key);
            free(next);
            *error_code = ASSOC_ARRAY_OK;
            return node;
        }
        tmp = next;
    }
    *error_code = ASSOC_ARRAY_NOT_FOUND;
    return node;
}


assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    if (arr == NULL || key == NULL || strlen(key) == 0)
        return ASSOC_ARRAY_INVALID_PARAM;

    if (arr->list == NULL)
        return ASSOC_ARRAY_NOT_FOUND;

    assoc_array_error_t error = ASSOC_ARRAY_OK;
    arr->list = remove_node(arr->list, key, &error);

    return error;
}


assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    if (!arr)
        return ASSOC_ARRAY_INVALID_PARAM;
    free_list(arr->list);
    arr->list = NULL;
    return ASSOC_ARRAY_OK;
}


void pre_order_action(node_t *node, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (node == NULL)
        return;
    for (; node != NULL; node = node->next)
        action(node->key, &node->value, param);
}


assoc_array_error_t assoc_array_each(const assoc_array_t arr, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (arr == NULL || action == NULL)
        return ASSOC_ARRAY_INVALID_PARAM;
    pre_order_action(arr->list, action, param);
    return ASSOC_ARRAY_OK;
}


int *find_min_node(node_t *node)
{
    if (node == NULL)
        return NULL;
    char *mini = node->key;
    int *saver = &node->value;
    for (; node != NULL; node = node->next)
    {
        if (strcmp(node->key, mini) < 0)
        {
            mini = node->key;  // Теперь меняем указатель, а не содержимое строки
            saver = &node->value;
        }
    }
    return saver;
}


assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    if (arr == NULL || num == NULL)
        return ASSOC_ARRAY_INVALID_PARAM;
    *num = find_min_node(arr->list);
    if (*num == NULL)
        return ASSOC_ARRAY_NOT_FOUND;
    return ASSOC_ARRAY_OK;
}


int *find_max_node(node_t *node)
{
    if (node == NULL)
        return NULL;
    char *maxi = node->key;
    int *saver = &node->value;
    for (; node != NULL; node = node->next)
    {
        if (strcmp(node->key, maxi) > 0)
        {
            maxi = node->key;
            saver = &node->value;
        }
    }
    return saver;
}


assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    if (arr == NULL || num == NULL)
        return ASSOC_ARRAY_INVALID_PARAM;
    *num = find_max_node(arr->list);
    if (*num == NULL)
        return ASSOC_ARRAY_NOT_FOUND;
    return ASSOC_ARRAY_OK;
}
