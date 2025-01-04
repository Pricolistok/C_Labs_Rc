#include <stdlib.h>
#include <check.h>
#include "process.h"
#include "struct.h"
#include "funcs_for_units.h"

// Тест, когда элементов нет
START_TEST(test_zero_elems)
{
    int rc;
    node_t *head = NULL;
    node_t *result = NULL;
    head = sort(head, comparator_prices);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST


// Тест, когда элементов всего 1
START_TEST(test_one_elem)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_result_1 = malloc(5 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_result_1, "apple");
    product list_product[] = { { name_head_1, 5, 12 } };
    product list_result[] = { { name_result_1, 5, 12 } };
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 1);
    result = input_to_list(list_result, 1);
    head = sort(head, comparator_prices);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест, когда элементов всего 2 и они отсортированы
START_TEST(test_two_sorted_elems)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(4 + 1);
    char *name_result_1 = malloc(5 + 1);
    char *name_result_2 = malloc(4 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "pear");
    strcpy(name_result_1, "apple");
    strcpy(name_result_2, "pear");
    product list_product[] = { { name_head_1, 5, 12 }, { name_head_2, 4, 13 } };
    product list_result[] = { { name_result_1, 5, 12 }, {name_result_2, 4, 13} };
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 2);
    result = input_to_list(list_result, 2);
    head = sort(head, comparator_prices);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест, когда элементов всего 2 и они не отсортированы
START_TEST(test_two_no_sorted_elems)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(4 + 1);
    char *name_result_1 = malloc(5 + 1);
    char *name_result_2 = malloc(4 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "pear");
    strcpy(name_result_1, "apple");
    strcpy(name_result_2, "pear");
    product list_product[] = { { name_head_2, 4, 15 }, { name_head_1, 5, 9 } };
    product list_result[] = { { name_result_1, 5, 9 }, {name_result_2, 4, 15} };
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 2);
    result = input_to_list(list_result, 2);
    head = sort(head, comparator_prices);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест, когда элементов много и они отсортированы
START_TEST(test_more_sorted_elems)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(4 + 1);
    char *name_head_3 = malloc(6 + 1);
    char *name_head_4 = malloc(5 + 1);
    char *name_result_1 = malloc(5 + 1);
    char *name_result_2 = malloc(4 + 1);
    char *name_result_3 = malloc(6 + 1);
    char *name_result_4 = malloc(5 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "pear");
    strcpy(name_head_3, "orange");
    strcpy(name_head_4, "lemon");
    strcpy(name_result_1, "apple");
    strcpy(name_result_2, "pear");
    strcpy(name_result_3, "orange");
    strcpy(name_result_4, "lemon");
    product list_product[] =
    {
        { name_head_1, 5, 1 },
        { name_head_2, 4, 11 },
        { name_head_3, 6, 100 },
        { name_head_4, 5, 509 }
    };
    product list_result[] =
    {
        { name_result_1, 5, 1 },
        { name_result_2, 4, 11 },
        { name_result_3, 6, 100 },
        { name_result_4, 5, 509 }
    };
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 4);
    result = input_to_list(list_result, 4);
    head = sort(head, comparator_prices);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST


// Тест, когда элементов много и они не отсортированы
START_TEST(test_more_no_sorted_elems)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(4 + 1);
    char *name_head_3 = malloc(6 + 1);
    char *name_head_4 = malloc(5 + 1);
    char *name_result_1 = malloc(5 + 1);
    char *name_result_2 = malloc(4 + 1);
    char *name_result_3 = malloc(6 + 1);
    char *name_result_4 = malloc(5 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "pear");
    strcpy(name_head_3, "orange");
    strcpy(name_head_4, "lemon");
    strcpy(name_result_1, "apple");
    strcpy(name_result_2, "pear");
    strcpy(name_result_3, "orange");
    strcpy(name_result_4, "lemon");
    product list_product[] =
    {
        { name_head_4, 5, 509 },
        { name_head_1, 5, 1 },
        { name_head_3, 6, 100 },
        { name_head_2, 4, 11 },
    };
    product list_result[] =
    {
        { name_result_1, 5, 1 },
        { name_result_2, 4, 11 },
        { name_result_3, 6, 100 },
        { name_result_4, 5, 509 }
    };
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 4);
    result = input_to_list(list_result, 4);
    head = sort(head, comparator_prices);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST


// Тест, когда элементов много и они отсортированы в обратном порядке
START_TEST(test_more_back_sorted_elems)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(4 + 1);
    char *name_head_3 = malloc(6 + 1);
    char *name_head_4 = malloc(5 + 1);
    char *name_result_1 = malloc(5 + 1);
    char *name_result_2 = malloc(4 + 1);
    char *name_result_3 = malloc(6 + 1);
    char *name_result_4 = malloc(5 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "pear");
    strcpy(name_head_3, "orange");
    strcpy(name_head_4, "lemon");
    strcpy(name_result_1, "apple");
    strcpy(name_result_2, "pear");
    strcpy(name_result_3, "orange");
    strcpy(name_result_4, "lemon");
    product list_product[] =
    {
        { name_head_4, 5, 509 },
        { name_head_3, 6, 100 },
        { name_head_2, 4, 11 },
        { name_head_1, 5, 1 },
    };
    product list_result[] =
    {
        { name_result_1, 5, 1 },
        { name_result_2, 4, 11 },
        { name_result_3, 6, 100 },
        { name_result_4, 5, 509 }
    };
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 4);
    result = input_to_list(list_result, 4);
    head = sort(head, comparator_prices);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест, когда элементов много и они все равны
START_TEST(test_more_elems_eq)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(5 + 1);
    char *name_head_3 = malloc(5 + 1);
    char *name_head_4 = malloc(5 + 1);
    char *name_result_1 = malloc(5 + 1);
    char *name_result_2 = malloc(5 + 1);
    char *name_result_3 = malloc(5 + 1);
    char *name_result_4 = malloc(5 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "apple");
    strcpy(name_head_3, "apple");
    strcpy(name_head_4, "apple");
    strcpy(name_result_1, "apple");
    strcpy(name_result_2, "apple");
    strcpy(name_result_3, "apple");
    strcpy(name_result_4, "apple");
    product list_product[] =
    {
        { name_head_4, 5, 10 },
        { name_head_3, 5, 10 },
        { name_head_2, 5, 10 },
        { name_head_1, 5, 10 },
    };
    product list_result[] =
    {
        { name_result_1, 5, 10 },
        { name_result_2, 5, 10 },
        { name_result_3, 5, 10 },
        { name_result_4, 5, 10 }
    };
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 4);
    result = input_to_list(list_result, 4);
    head = sort(head, comparator_prices);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST



Suite* sort_test(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sort");
    tc_pos = tcase_create("positive");

    tcase_add_test(tc_pos, test_zero_elems);
    tcase_add_test(tc_pos, test_one_elem);
    tcase_add_test(tc_pos, test_two_sorted_elems);
    tcase_add_test(tc_pos, test_two_no_sorted_elems);
    tcase_add_test(tc_pos, test_more_sorted_elems);
    tcase_add_test(tc_pos, test_more_no_sorted_elems);
    tcase_add_test(tc_pos, test_more_back_sorted_elems);
    tcase_add_test(tc_pos, test_more_elems_eq);

    suite_add_tcase(s, tc_pos);

    return s;
}
