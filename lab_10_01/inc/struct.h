#ifndef STRUCT_H__

#define STRUCT_H__

#include "consts.h"

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

typedef struct product product;

struct product
{
    char *name;
    size_t len_name;
    int price;
};

#endif
