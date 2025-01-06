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


int compare_lists(node_t *head_1, node_t *head_2)
{
    for (; head_1 != NULL; head_1 = head_1->next)
    {
        if (head_1->coefficient != head_2->coefficient)
            return ERROR_COMPARE;
        head_2 = head_2->next;
    }
    return OK;
}

int check_func_cnt_sum(int coefficients_1[], int cnt_coefficients_1, int coefficients_2[], int cnt_coefficients_2, int expected_sum[], int len_expected_sum)
{
 	int rc;
	node_t *head_1 = create_list(coefficients_1, cnt_coefficients_1);
	node_t *head_2 = create_list(coefficients_2, cnt_coefficients_2);
	node_t *head_expected_sum = create_list(expected_sum, len_expected_sum);
	node_t *result = NULL;
	cnt_sum_of_polynomials(head_1, head_2, &result, cnt_coefficients_1, cnt_coefficients_2);
	free_list(head_1);
	free_list(head_2);
	rc = compare_lists(result, head_expected_sum);
    free_list(head_expected_sum);
	free_list(result);
	return rc;
}


int check_func_cnt_ddx(int coefficients[], int cnt_coefficients, int expected[], int len_expected)
{
 	int rc;
	node_t *head = create_list(coefficients, cnt_coefficients);
	node_t *head_expected = NULL;
	if (len_expected != 0)
		head_expected = create_list(expected, len_expected);
	cnt_derivative(head, cnt_coefficients);
	rc = compare_lists(head, head_expected);
    free_list(head_expected);
	free_list(head);
	return rc;
}
