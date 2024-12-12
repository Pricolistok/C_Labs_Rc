#include <stdlib.h>
#include <check.h>
#include "process.h"
#include "struct.h"
#include "funcs_for_units.h"

// Тест, когда элемент всего 1
START_TEST(test_one_elem)
{
    int rc;
    product list_product[] = {{"apple", 5, 12}};
    product list_result[] = {{"apple", 5, 12}};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 1);
    result = input_to_list(list_result, 1);
    rc = compare_lists(head, result);
    free_all_data_for_test(head);
    free_all_data_for_test(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест, когда элементов всего 2 и они не дубликаты
START_TEST(test_two_elems)
{
    int rc;
    product list_product[] = {{"apple", 5, 12}, {"pear", 4, 16}};
    product list_result[] = {{"apple", 5, 12}, {"pear", 4, 16}};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 1);
    result = input_to_list(list_result, 1);
    rc = compare_lists(head, result);
    free_all_data_for_test(head);
    free_all_data_for_test(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST


// Тест, когда элементов всего 2 и они дубликаты
START_TEST(test_two_elems_dupl)
{
    int rc;
    product list_product[] = {{"apple", 5, 12}, {"pear", 4, 16}};
    product list_result[] = {{"apple", 5, 12}, {"pear", 4, 16}};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 1);
    result = input_to_list(list_result, 1);
    rc = compare_lists(head, result);
    free_all_data_for_test(head);
    free_all_data_for_test(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite* pop_duplicates_test(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("pop_duplicates");
    tc_pos = tcase_create("positive");

    tcase_add_test(tc_pos, test_one_elem);
    tcase_add_test(tc_pos, test_two_elems);
    tcase_add_test(tc_pos, test_two_elems_dupl);

    suite_add_tcase(s, tc_pos);

    return s;
}
