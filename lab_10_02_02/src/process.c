#include "process.h"

double cnt_function(node_t *head, double val, int cnt_coefficients)
{
    double sum = 0;
    for (; head != NULL; head = head->next)
    {
        sum += head->coefficient * pow(val, cnt_coefficients - 1);
        cnt_coefficients--;
    }
    return sum;
}

void cnt_derivative(node_t *head, int cnt_coefficients)
{
    for (; head != NULL; head = head->next)
    {
        if (head->coefficient == 0)
            head->flag = 1;
        head->coefficient = head->coefficient * (cnt_coefficients - 1);
        cnt_coefficients--;
    }
}

size_t cnt_degree(node_t *head)
{
    size_t degree = 0;
    for (; head != NULL; head = head->next)
        degree++;
    return degree;
}

void cnt_sum_of_polynomials(node_t *head, node_t *add_head, int diff)
{
    for (int i = 0; i < diff; i++)
        head = head->next;

    for (; head != NULL; head = head->next)
    {
        head->coefficient = head->coefficient + add_head->coefficient;
        add_head = add_head->next;
    }
}

void separator_coefficients(node_t *head, node_t **head_ch, node_t **head_nch, int cnt_coefficients)
{
    node_t *elem = NULL;
    for (; head != NULL; head = head->next)
    {
        elem = create_elem(head->coefficient);
        if ((cnt_coefficients - 1) % 2 == 0)
            *head_ch = add_elem_to_end_list(*head_ch, elem);
        else
            *head_nch = add_elem_to_end_list(*head_nch, elem);
        cnt_coefficients--;
    }
}

void free_list(node_t *head)
{
    node_t *next = NULL;
    for (; head != NULL; head = next)
    {
        next = head->next;
        free(head);
    }
}

