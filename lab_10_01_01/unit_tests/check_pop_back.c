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
    pop_back(&head);
    rc = compare_lists(head, result);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест, когда элемент всего 1
START_TEST(test_one_elem)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    strcpy(name_head_1, "apple");
    product list_product[] = { { name_head_1, 5, 12}};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 1);
    result = NULL;
    rc = test_pop_end(&head, result);
    free_all_data(head);
    // free(name_head_1);
    ck_assert_int_eq(rc, OK);
}
END_TEST



// Тест, когда элемент всего 2

START_TEST(test_two_elems)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(4 + 1);
    char *name_result_1 = malloc(5 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "pear");
    strcpy(name_result_1, "apple");
    product list_product[] = { { name_head_1, 5, 12}, { name_head_2, 4, 13}};
    product list_result[] = {{ name_result_1, 5, 12}};
    node_t *head = NULL;
    node_t *result;
    head = input_to_list(list_product, 2);
    result = input_to_list(list_result, 1);
    rc = test_pop_end(&head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST


// Тест, когда элементов много
START_TEST(test_more_elems)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(4 + 1);
    char *name_head_3 = malloc(5 + 1);
    char *name_head_4 = malloc(6 + 1);
    char *name_result_1 = malloc(5 + 1);
    char *name_result_2 = malloc(4 + 1);
    char *name_result_3 = malloc(5 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "pear");
    strcpy(name_head_3, "apple");
    strcpy(name_head_4, "orange");
    strcpy(name_result_1, "apple");
    strcpy(name_result_2, "pear");
    strcpy(name_result_3, "apple");
    product list_product[] = { { name_head_1, 5, 12}, {name_head_2, 4, 12},{name_head_3, 5, 12 }, {name_head_4, 6, 42 } };
    product list_result[] = { {name_result_1, 5, 12},{name_result_2, 4, 12 }, {name_result_3, 5, 12 }};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 4);
    result = input_to_list(list_result, 3);
    rc = test_pop_end(&head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST




Suite* pop_end_test(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("pop_end");
    tc_pos = tcase_create("positive");

    tcase_add_test(tc_pos, test_zero_elems);
    tcase_add_test(tc_pos, test_one_elem);
    tcase_add_test(tc_pos, test_two_elems);
    tcase_add_test(tc_pos, test_more_elems);


    suite_add_tcase(s, tc_pos);

    return s;
}

