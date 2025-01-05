#include "funcs_for_units.h"

node_t *create_list(int coefficients[], size_t cnt_coefficients)
{
    node_t *head = NULL, *elem = NULL;
    for (size_t i = 0; i < cnt_coefficients; i++)
    {
        elem = create_elem(coefficients[i]);
        head = add_elem_to_end_list(head, elem);
    }
    return head;
}

int check_func_cnt_val(int coefficients[], int cnt_coefficients, double expected_sum, double val)
{
    node_t *head = create_list(coefficients, cnt_coefficients);
    double result_sum = cnt_val(head, val, cnt_coefficients);
    free_list(head);
    if ((result_sum - expected_sum) > 1e-6)
        return ERROR_TEST;
    return OK;
}