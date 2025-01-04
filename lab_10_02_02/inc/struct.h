#ifndef STRUCT_H__
#define STRUCT_H__

typedef struct node_t node_t;

struct node_t
{
    int coefficient;
    int flag;
    node_t *next;
};

#endif
