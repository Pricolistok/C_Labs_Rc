#ifndef STRUCT_H__

#define STRUCT_H__

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

#endif
