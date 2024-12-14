#ifndef STRUCT_H__

#define STRUCT_H__

#include "consts.h"

typedef struct node node_t;

struct node
{
    char *name;
    int year;
    char *group;
    node_t *next;
};

typedef struct product product;

#endif
