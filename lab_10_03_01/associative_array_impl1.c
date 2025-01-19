#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "associative_array.h"

typedef struct node
{
    char *key;
    int value;
    struct node *left;
    struct node *right;
} node_t;


struct assoc_array_type
{
    node_t *tree;
};


assoc_array_t assoc_array_create(void)
{
    assoc_array_t arr = malloc(sizeof(assoc_array_t));
    if (!arr)
        return NULL;
    arr->tree = NULL;
    return arr;
}


void free_bin_tree(node_t *node)
{
    if (node != NULL)
    {
        free(node->key);
        free_bin_tree(node->left);
        free_bin_tree(node->right);
        free(node);
    }
}


void assoc_array_destroy(assoc_array_t *arr)
{
    if (!arr || !*arr)
        return;
    free_bin_tree((*arr)->tree);
    *arr = NULL;
}


node_t *insert_to_tree(node_t *node, const char *key, int num, assoc_array_t *error_code)
{
    int cmp;

    if (node == NULL)
    {
        node = malloc(sizeof(node_t));
        if (!node)
        {
            *error_code =  ASSOC_ARRAY_MEM;
            return NULL;
        }
        node->key = malloc(strlen(key) + 1);
        if (!node->key)
        {
            *error_code =  ASSOC_ARRAY_MEM;
            return NULL;
        }
        node->left = NULL;
        node->right = NULL;
        node->value = num;
        strcpy(node->key, key);
        return node;
    }

    cmp = strcmp(key, node->key);
    if (cmp == 0)
        *error_code = ASSOC_ARRAY_KEY_EXISTS;
    if (cmp < 0)
        node->left = insert_to_tree(node->left, key, num, error_code);
    else if (cmp > 0)
        node->right = insert_to_tree(node->right, key, num, error_code);

    return node;
}


assoc_array_error_t assoc_array_insert(assoc_array_t arr, const char *key, int num)
{
    assoc_array_error_t error_code = ASSOC_ARRAY_OK;
    if (arr == NULL || key == NULL || strlen(key) == 0)
        return ASSOC_ARRAY_INVALID_PARAM;
    arr->tree = insert_to_tree(arr->tree, key, num, &error_code);
    return error_code;
}


void find_in_arr(node_t *node, const char *key, int **num, assoc_array_error_t *error_code)
{
    if (!node)
        return;
    if (*error_code == ASSOC_ARRAY_OK)
        return;

    if (strcmp(node->key, key) == 0)
    {
        *num = &node->value;
        *error_code = ASSOC_ARRAY_OK;
    }
    else
    {
        find_in_arr(node->left, key, num, error_code);
        if (*error_code == ASSOC_ARRAY_OK)
            return;
        find_in_arr(node->right, key, num, error_code);
    }
}


assoc_array_error_t assoc_array_find(const assoc_array_t arr, const char *key, int **num)
{
    if (arr == NULL || key == NULL || strlen(key) == 0)
        return ASSOC_ARRAY_INVALID_PARAM;

    assoc_array_error_t error_code = ASSOC_ARRAY_NOT_FOUND;
    find_in_arr(arr->tree, key, num, &error_code);
    return error_code;
}


static node_t* find_minimum_elem(node_t *node)
{
    while (node && node->left != NULL)
        node = node->left;
    return node;
}


node_t* remove_node(node_t *node, const char *key, assoc_array_error_t *error)
{
    node_t *tmp;
    node_t *mini_elem;

    if (node == NULL)
    {
        *error = ASSOC_ARRAY_NOT_FOUND;
        return node;
    }
    int cmp = strcmp(key, node->key);

    if (cmp < 0)
        node->left = remove_node(node->left, key, error);
    else if (cmp > 0)
        node->right = remove_node(node->right, key, error);
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            free(node->key);
            free(node);
            return NULL;
        }
        if (node->left == NULL)
        {
            tmp = node->right;
            free(node->key);
            free(node);
            return tmp;
        }
        else if (node->right == NULL)
        {
            tmp = node->left;
            free(node->key);
            free(node);
            return tmp;
        }

        mini_elem = find_minimum_elem(node->right);
        free(node->key);
        node->key = mini_elem->key;
        node->value = mini_elem->value;
        node->right = remove_node(node->right, mini_elem->key, error);
    }

    return node;
}


assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    if (arr == NULL || key == NULL || strlen(key) == 0)
        return ASSOC_ARRAY_INVALID_PARAM;

    assoc_array_error_t error = ASSOC_ARRAY_OK;
    arr->tree = remove_node(arr->tree, key, &error);

    return error;
}


assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    if (!arr)
        return ASSOC_ARRAY_INVALID_PARAM;
    free_bin_tree(arr->tree);
    arr->tree = NULL;
    return ASSOC_ARRAY_OK;
}


void pre_order_action(node_t *node, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (node == NULL)
        return;
    action(node->key, &node->value, param);
    pre_order_action(node->left, action, param);
    pre_order_action(node->right, action, param);
}


assoc_array_error_t assoc_array_each(const assoc_array_t arr, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (arr == NULL || action == NULL)
        return ASSOC_ARRAY_INVALID_PARAM;
    pre_order_action(arr->tree, action, param);
    return ASSOC_ARRAY_OK;
}


node_t* find_min_node(const node_t *node)
{
    if (node == NULL)
        return NULL;
    while (node->left != NULL)
        node = node->left;
    return (node_t*)node;
}


assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    if (arr == NULL || num == NULL)
        return ASSOC_ARRAY_INVALID_PARAM;
    node_t *min_node = find_min_node(arr->tree);
    if (min_node == NULL)
        return ASSOC_ARRAY_NOT_FOUND;
    *num = &min_node->value;
    return ASSOC_ARRAY_OK;
}


node_t* find_max_node(const node_t *node)
{
    if (node == NULL)
        return NULL;
    while (node->right != NULL)
        node = node->right;
    return (node_t*)node;
}


assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    if (arr == NULL || num == NULL)
        return ASSOC_ARRAY_INVALID_PARAM;
    node_t *max_node = find_max_node(arr->tree);
    if (max_node == NULL)
        return ASSOC_ARRAY_NOT_FOUND;
    *num = &max_node->value;
    return ASSOC_ARRAY_OK;
}
