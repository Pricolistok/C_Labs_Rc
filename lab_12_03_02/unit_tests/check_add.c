#include <stdlib.h>
#include <check.h>
#include "process.h"
#include "errors.h"


START_TEST(test_one_elem)
{
    int rc = OK;
    int *arr = NULL;
    int arr_check[] = {2};
    size_t len = 1;

    arr = malloc(sizeof(int) * len);
    if (!arr)
        rc = ERROR;
    if (rc == OK)
        add_simple_nums_to_arr(arr, len);
    if (rc == OK)
        ck_assert_mem_eq(arr, arr_check, len * sizeof(int));
    else
        ck_assert_int_eq(rc, OK);
    free(arr);
}
END_TEST

START_TEST(test_two_elems)
{
    int rc = OK;
    int *arr = NULL;
    int arr_check[] = {2, 3};
    size_t len = 2;

    arr = malloc(sizeof(int) * len);
    if (!arr)
        rc = ERROR;
    if (rc == OK)
        add_simple_nums_to_arr(arr, len);
    if (rc == OK)
        ck_assert_mem_eq(arr, arr_check, len * sizeof(int));
    else
        ck_assert_int_eq(rc, OK);
    free(arr);
}
END_TEST

START_TEST(test_more_elems)
{
    int rc = OK;
    int *arr = NULL;
    int arr_check[] = {2, 3, 5, 7, 11};
    size_t len = 5;

    arr = malloc(sizeof(int) * len);
    if (!arr)
        rc = ERROR;
    if (rc == OK)
        add_simple_nums_to_arr(arr, len);
    if (rc == OK)
        ck_assert_mem_eq(arr, arr_check, len * sizeof(int));
    else
        ck_assert_int_eq(rc, OK);
    free(arr);
}
END_TEST


Suite* add_test(void)
{
    Suite *s;
    //TCase *tc_neg;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции calc_avg
    s = suite_create("add");
    
    tc_pos = tcase_create("positive");

    // Тест, когда нужен один элемент
    tcase_add_test(tc_pos, test_one_elem);
    // Тест, когда нужно два элемента
    tcase_add_test(tc_pos, test_two_elems);
    // Тест, когда нужно много элементов
    tcase_add_test(tc_pos, test_more_elems);


    suite_add_tcase(s, tc_pos);

    return s;
}
