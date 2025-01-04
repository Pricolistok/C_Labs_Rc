#include "input_output.h"

#include <ctype.h>

int input_mode(int *mode)
{
    char mode_char[LEN_MODE];

    fgets(mode_char, LEN_MODE, stdin);
    mode_char[strlen(mode_char) - 1] = 0;

    if (strlen(mode_char) != 3)
        return ERROR_LEN_MODE;

    if (strcmp(mode_char, "val") == 0)
        *mode = 1;
    else if (strcmp(mode_char, "ddx") == 0)
        *mode = 2;
    else if (strcmp(mode_char, "sum") == 0)
        *mode = 3;
    else if (strcmp(mode_char, "dvd") == 0)
        *mode = 4;
    else
        return ERROR_VALUE_MODE;
    return OK;
}

int read_coefficients(node_t **head, int *cnt_coefficients)
{
    int rc, coefficient;
    node_t *elem = NULL;
    char checker;

    rc = scanf("%d", cnt_coefficients);
    if (rc != 1 || *cnt_coefficients <= 0)
        return ERROR_CNT_COEFFICIENTS;

    for (size_t cnt = 0; cnt < (size_t)*cnt_coefficients; cnt++)
    {
        rc = scanf("%d", &coefficient);
        if (rc != 1)
            return ERROR_INPUT_COEFFICIENT;
        elem = create_elem(coefficient);
        *head = add_elem_to_end_list(*head, elem);
    }
    if ((checker = getchar()) != EOF && checker != '\n')
        return ERROR_INPUT_MORE_COEFFICIENT;

    return OK;
}

node_t *create_elem(const int coefficient)
{
    node_t *elem = malloc(sizeof(node_t));
    if (!elem)
        return NULL;
    elem->coefficient = coefficient;
    elem->flag = 0;
    elem->next = NULL;
    return elem;
}

node_t *add_elem_to_end_list(node_t *head, node_t *elem)
{
    node_t *cur = head;
    if (!head)
        return elem;
    for (; cur->next != NULL; cur = cur->next);
    cur->next = elem;
    return head;
}

void print_list(node_t *head)
{
    for (; head != NULL; head = head->next)
    {
        if (head->flag == 1)
            continue;
        printf("%d ", head->coefficient);
    }
    printf("L\n");
}

int input_val(double *val)
{
    if (scanf("%lf", val) != 1)
        return ERROR_INPUT_VAL;
    return OK;
}
