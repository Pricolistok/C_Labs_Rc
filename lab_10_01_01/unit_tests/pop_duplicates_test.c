#include <stdlib.h>
#include <check.h>
#include "process.h"
#include "struct.h"
#include "funcs_for_units.h"

// Тест, когда элемент всего 1
START_TEST(test_one_elem)
{
    int rc;
    char *name_1 = malloc(5 + 1);
    char *name_2 = malloc(5 + 1);
    strcpy(name_1, "apple");
    strcpy(name_2, "apple");
    product list_product[] = {{name_1, 5, 12}};
    product list_result[] = {{name_2, 5, 12}};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 1);
    result = input_to_list(list_result, 1);
    remove_duplicates(&head, comparator_products);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест, когда элементов всего 2 и они не дубликаты
START_TEST(test_two_elems)
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
    product list_product[] = {{name_head_1, 5, 12}, {name_head_2, 4, 16}};
    product list_result[] = {{name_result_1, 5, 12}, {name_result_2, 4, 16}};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 2);
    result = input_to_list(list_result, 2);
    remove_duplicates(&head, comparator_products);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST


// Тест, когда элементов всего 2 и они дубликаты
START_TEST(test_two_elems_dupl)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(5 + 1);
    char *name_result_1 = malloc(5 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "apple");
    strcpy(name_result_1, "apple");
    product list_product[] = {{name_head_1, 5, 12}, {name_head_2, 5, 12}};
    product list_result[] = {{name_result_1, 5, 12}};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 2);
    result = input_to_list(list_result, 1);
    remove_duplicates(&head, comparator_products);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест, когда элементов всего 3 и есть дубликаты и они не рядом
START_TEST(test_two_elems_one_dupl)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(4 + 1);
    char *name_head_3 = malloc(5 + 1);
    char *name_result_1 = malloc(5 + 1);
    char *name_result_2 = malloc(4 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "pear");
    strcpy(name_head_3, "apple");
    strcpy(name_result_1, "apple");
    strcpy(name_result_2, "pear");
    product list_product[] = {{name_head_1, 5, 12}, {name_head_2, 4, 12},{name_head_3, 5, 12}};
    product list_result[] = {{name_result_1, 5, 12}, {name_result_2, 4, 12}};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 3);
    result = input_to_list(list_result, 2);
    remove_duplicates(&head, comparator_products);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест, когда элементов всего 4 и есть дубликаты и дубликаты расположены подряд
START_TEST(test_two_elems_two_dupl_with_elem_ord)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(5 + 1);
    char *name_head_3 = malloc(4 + 1);
    char *name_head_4 = malloc(4 + 1);
    char *name_result_1 = malloc(5 + 1);
    char *name_result_2 = malloc(4 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "apple");
    strcpy(name_head_3, "pear");
    strcpy(name_head_4, "pear");
    strcpy(name_result_1, "apple");
    strcpy(name_result_2, "pear");
    product list_product[] = {{name_head_1, 5, 12}, {name_head_2, 5, 12},{name_head_3, 4, 12}, {name_head_4, 4, 12}};
    product list_result[] = {{name_result_1, 5, 12}, {name_result_2, 4, 12}};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 4);
    result = input_to_list(list_result, 2);
    remove_duplicates(&head, comparator_products);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST


// Тест, когда элементов всего 4 и есть дубликаты и дубликаты расположены не подряд
START_TEST(test_two_elems_two_dupl_with_elem_no_ord)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(4 + 1);
    char *name_head_3 = malloc(5 + 1);
    char *name_head_4 = malloc(4 + 1);
    char *name_result_1 = malloc(5 + 1);
    char *name_result_2 = malloc(4 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "pear");
    strcpy(name_head_3, "apple");
    strcpy(name_head_4, "pear");
    strcpy(name_result_1, "apple");
    strcpy(name_result_2, "pear");
    product list_product[] = {{name_head_1, 5, 12}, {name_head_2, 4, 12},{name_head_3, 5, 12}, {name_head_4, 4, 12}};
    product list_result[] = {{name_result_1, 5, 12}, {name_result_2, 4, 12}};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 4);
    result = input_to_list(list_result, 2);
    remove_duplicates(&head, comparator_products);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест, когда элементов всего 6 и есть всего два элемента повторяются по 3 раза и дубликаты расположены не подряд
START_TEST(test_two_elems_three_dupl_with_elem_ord)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(5 + 1);
    char *name_head_3 = malloc(5 + 1);
    char *name_head_4 = malloc(4 + 1);
    char *name_head_5 = malloc(4 + 1);
    char *name_head_6 = malloc(4 + 1);
    char *name_result_1 = malloc(5 + 1);
    char *name_result_2 = malloc(4 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "apple");
    strcpy(name_head_3, "apple");
    strcpy(name_head_4, "pear");
    strcpy(name_head_5, "pear");
    strcpy(name_head_6, "pear");
    strcpy(name_result_1, "apple");
    strcpy(name_result_2, "pear");
    product list_product[] =
    {
        {name_head_1, 5, 12},
        {name_head_2, 5, 12},
        {name_head_3, 5, 12},
        {name_head_4, 4, 12},
        {name_head_5, 4, 12},
        {name_head_6, 4, 12}
    };
    product list_result[] = {{name_result_1, 5, 12}, {name_result_2, 4, 12}};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 6);
    result = input_to_list(list_result, 2);
    remove_duplicates(&head, comparator_products);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест, когда много элементов и есть всего более двух элементов, которые повторяются по 2 раза и повторы идут подряд
START_TEST(test_two_elems_three_dupl_with_elem_no_ord)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(5 + 1);
    char *name_head_3 = malloc(5 + 1);
    char *name_head_4 = malloc(4 + 1);
    char *name_head_5 = malloc(4 + 1);
    char *name_head_6 = malloc(4 + 1);
    char *name_result_1 = malloc(5 + 1);
    char *name_result_2 = malloc(4 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "apple");
    strcpy(name_head_3, "apple");
    strcpy(name_head_4, "pear");
    strcpy(name_head_5, "pear");
    strcpy(name_head_6, "pear");
    strcpy(name_result_1, "apple");
    strcpy(name_result_2, "pear");
    product list_product[] =
    {
        {name_head_1, 5, 12},
        {name_head_4, 4, 12},
        {name_head_2, 5, 12},
        {name_head_5, 4, 12},
        {name_head_3, 5, 12},
        {name_head_6, 4, 12}
    };
    product list_result[] = {{name_result_1, 5, 12}, {name_result_2, 4, 12}};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 6);
    result = input_to_list(list_result, 2);
    remove_duplicates(&head, comparator_products);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест, когда элементов всего 6 и есть всего два элемента повторяются по 3 раза и дубликаты расположены подряд
START_TEST(test_more_elems_more_dupl_with_elem_ord)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    char *name_head_2 = malloc(5 + 1);
    char *name_head_3 = malloc(5 + 1);
    char *name_head_4 = malloc(4 + 1);
    char *name_head_5 = malloc(4 + 1);
    char *name_head_6 = malloc(4 + 1);
    char *name_head_7 = malloc(5 + 1);
    char *name_head_8 = malloc(5 + 1);
    char *name_head_9 = malloc(5 + 1);
    char *name_result_1 = malloc(5 + 1);
    char *name_result_2 = malloc(4 + 1);
    char *name_result_3 = malloc(5 + 1);
    strcpy(name_head_1, "apple");
    strcpy(name_head_2, "apple");
    strcpy(name_head_3, "apple");
    strcpy(name_head_4, "pear");
    strcpy(name_head_5, "pear");
    strcpy(name_head_6, "pear");
    strcpy(name_head_7, "peach");
    strcpy(name_head_8, "peach");
    strcpy(name_head_9, "peach");
    strcpy(name_result_1, "apple");
    strcpy(name_result_2, "pear");
    strcpy(name_result_3, "peach");
    product list_product[] =
    {
        {name_head_1, 5, 12},
        {name_head_2, 5, 12},
        {name_head_3, 5, 12},
        {name_head_4, 4, 12},
        {name_head_5, 4, 12},
        {name_head_6, 4, 12},
        {name_head_7, 5, 12},
        {name_head_8, 5, 12},
        {name_head_9, 5, 12}
    };
    product list_result[] = {{name_result_1, 5, 12}, {name_result_2, 4, 12}, {name_result_3, 5, 12}};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 9);
    result = input_to_list(list_result, 3);
    remove_duplicates(&head, comparator_products);
    rc = compare_lists(head, result);
    free_all_data(head);
    free_all_data(result);
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
    tcase_add_test(tc_pos, test_two_elems_one_dupl);
    tcase_add_test(tc_pos, test_two_elems_two_dupl_with_elem_ord);
    tcase_add_test(tc_pos, test_two_elems_two_dupl_with_elem_no_ord);
    tcase_add_test(tc_pos, test_two_elems_three_dupl_with_elem_ord);
    tcase_add_test(tc_pos, test_two_elems_three_dupl_with_elem_no_ord);
    tcase_add_test(tc_pos, test_more_elems_more_dupl_with_elem_ord);

    suite_add_tcase(s, tc_pos);

    return s;
}
