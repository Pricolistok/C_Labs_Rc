#include <stdlib.h>
#include <check.h>
#include <errors.h>

#include "errors_tests.h"
#include "process.h"

START_TEST(test_one_elem_ch)
{
    int rc = OK;
    int arr[1] = {2};
    int *arr_res = malloc(2 * sizeof(int));
    int arr_exp[2] = {2, 11};
    size_t len_arr = 1;
    size_t len_res = 2;
    rc = filter_nums(arr, len_arr, arr_res, &len_res, 11);
    if (rc == ERROR_ADD_MEMORY)
        ck_assert_int_eq(rc, OK);
    else
        ck_assert_mem_eq(arr_exp, arr_res, len_res * sizeof(int));
    free(arr_res);
}
END_TEST

START_TEST(test_one_elem_nch)
{
    int rc = OK;
    int arr[1] = {3};
    int *arr_res = malloc(1 * sizeof(int));
    int arr_exp[1] = {3};
    size_t len_arr = 1;
    size_t len_res = 1;
    rc = filter_nums(arr, len_arr, arr_res, &len_res, 11);
    if (rc == ERROR_ADD_MEMORY)
        ck_assert_int_eq(rc, OK);
    else
        ck_assert_mem_eq(arr_exp, arr_res, len_res * sizeof(int));
    free(arr_res);
}
END_TEST

START_TEST(test_two_elems_ch)
{
    int rc = OK;
    int arr[2] = {2, 4};
    int *arr_res = malloc(4 * sizeof(int));
    int arr_exp[4] = {2, 11, 4, 11};
    size_t len_arr = 2;
    size_t len_res = 4;
    rc = filter_nums(arr, len_arr, arr_res, &len_res, 11);
    if (rc == ERROR_ADD_MEMORY)
        ck_assert_int_eq(rc, OK);
    else
        ck_assert_mem_eq(arr_exp, arr_res, len_res * sizeof(int));
    free(arr_res);
}
END_TEST

START_TEST(test_two_elems_nch)
{
    int rc = OK;
    int arr[2] = {3, 5};
    int *arr_res = malloc(2 * sizeof(int));
    int arr_exp[2] = {3, 5};
    size_t len_arr = 2;
    size_t len_res = 2;
    rc = filter_nums(arr, len_arr, arr_res, &len_res, 11);
    if (rc == ERROR_ADD_MEMORY)
        ck_assert_int_eq(rc, OK);
    else
        ck_assert_mem_eq(arr_exp, arr_res, len_res * sizeof(int));
    free(arr_res);
}
END_TEST

START_TEST(test_more_elems_ch)
{
    int rc = OK;
    int arr[7] = {2, 4, 6, 8, 10, 12, 14};
    int *arr_res = malloc(14 * sizeof(int));
    int arr_exp[14] = {2, 11, 4, 11, 6, 11, 8, 11, 10, 11, 12, 11, 14, 11};
    size_t len_arr = 7;
    size_t len_res = 14;
    rc = filter_nums(arr, len_arr, arr_res, &len_res, 11);
    if (rc == ERROR_ADD_MEMORY)
        ck_assert_int_eq(rc, OK);
    else
        ck_assert_mem_eq(arr_exp, arr_res, len_res * sizeof(int));
    free(arr_res);
}
END_TEST

START_TEST(test_more_elems_nch)
{
    int rc = OK;
    int arr[7] = {3, 5, 7, 7, 9, 11, 13};
    int *arr_res = malloc(7 * sizeof(int));
    int arr_exp[7] = {3, 5, 7, 7, 9, 11, 13};
    size_t len_arr = 7;
    size_t len_res = 7;
    rc = filter_nums(arr, len_arr, arr_res, &len_res, 11);
    if (rc == ERROR_ADD_MEMORY)
        ck_assert_int_eq(rc, OK);
    else
        ck_assert_mem_eq(arr_exp, arr_res, len_res * sizeof(int));
    free(arr_res);
}
END_TEST

START_TEST(test_more_elems_random)
{
    int rc = OK;
    int arr[7] = {3, 5, 2, 2, 9, 2, 13};
    int *arr_res = malloc(10 * sizeof(int));
    int arr_exp[10] = {3, 5, 2, 11, 2, 11, 9, 2, 11, 13};
    size_t len_arr = 7;
    size_t len_res = 10;
    rc = filter_nums(arr, len_arr, arr_res, &len_res, 11);
    if (rc == ERROR_ADD_MEMORY)
        ck_assert_int_eq(rc, OK);
    else
        ck_assert_mem_eq(arr_exp, arr_res, len_res * sizeof(int));
    free(arr_res);
}
END_TEST

START_TEST(test_more_elems_random_with_negatives)
{
    int rc = OK;
    int arr[7] = {3, 5, 2, -2, 9, -2, 13};
    int *arr_res = malloc(10 * sizeof(int));
    int arr_exp[10] = {3, 5, 2, 11, -2, 11, 9, -2, 11, 13};
    size_t len_arr = 7;
    size_t len_res = 10;
    rc = filter_nums(arr, len_arr, arr_res, &len_res, 11);
    if (rc == ERROR_ADD_MEMORY)
        ck_assert_int_eq(rc, OK);
    else
        ck_assert_mem_eq(arr_exp, arr_res, len_res * sizeof(int));
    free(arr_res);
}
END_TEST

START_TEST(test_more_elems_random_with_all_negatives)
{
    int rc = OK;
    int arr[7] = {3, 5, -2, -2, 9, -2, 13};
    int *arr_res = malloc(10 * sizeof(int));
    int arr_exp[10] = {3, 5, -2, 11, -2, 11, 9, -2, 11, 13};
    size_t len_arr = 7;
    size_t len_res = 10;
    rc = filter_nums(arr, len_arr, arr_res, &len_res, 11);
    if (rc == ERROR_ADD_MEMORY)
        ck_assert_int_eq(rc, OK);
    else
        ck_assert_mem_eq(arr_exp, arr_res, len_res * sizeof(int));
    free(arr_res);
}
END_TEST

START_TEST(test_more_memory)
{
    int rc = OK;
    int arr[7] = {3, 5, -2, -2, 9, -2, 13};
    int *arr_res = malloc(4 * sizeof(int));
    int arr_exp[10] = {3, 5, -2, 11, -2, 11, 9, -2, 11, 13};
    size_t len_arr = 7;
    size_t len_res = 4;
    rc = filter_nums(arr, len_arr, arr_res, &len_res, 11);
    if (rc == ERROR_ADD_MEMORY)
    {
        free(arr_res);
        arr_res = malloc(len_res * sizeof(int));
        filter_nums(arr, len_arr, arr_res, &len_res, 11);
    }
    else
        ck_assert_mem_eq(arr_exp, arr_res, len_res * sizeof(int));
    free(arr_res);
}
END_TEST

START_TEST(test_more_memory_zero)
{
    int rc = OK;
    int arr[7] = {3, 5, -2, -2, 9, -2, 13};
    int *arr_res = malloc(0 * sizeof(int));
    int arr_exp[10] = {3, 5, -2, 11, -2, 11, 9, -2, 11, 13};
    size_t len_arr = 7;
    size_t len_res = 0;
    rc = filter_nums(arr, len_arr, arr_res, &len_res, 11);
    if (rc == ERROR_ADD_MEMORY)
    {
        free(arr_res);
        arr_res = malloc(len_res * sizeof(int));
        filter_nums(arr, len_arr, arr_res, &len_res, 11);
    }
    else
        ck_assert_mem_eq(arr_exp, arr_res, len_res * sizeof(int));
    free(arr_res);
}
END_TEST

START_TEST(test_more_memory_over)
{
    int rc = OK;
    int arr[7] = {3, 5, -2, -2, 9, -2, 13};
    int *arr_res = malloc(100 * sizeof(int));
    size_t len_arr = 7;
    size_t len_res = 100;
    rc = filter_nums(arr, len_arr, arr_res, &len_res, 11);
    if (rc == ERROR_ADD_MEMORY)
    {
        arr_res = malloc(len_res * sizeof(int));
        filter_nums(arr, len_arr, arr_res, &len_res, 11);
    }
    else
        ck_assert_int_eq(rc, OK);
    free(arr_res);
}
END_TEST



Suite* filter_test(void)
{
    Suite *s;
    //TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("filter");
    tc_pos = tcase_create("positive");

    // Тест, когда один четный элемент
    tcase_add_test(tc_pos, test_one_elem_ch);
    // Тест, когда один нечетный элемент
    tcase_add_test(tc_pos, test_one_elem_nch);
    // Тест, когда два четных элемента
    tcase_add_test(tc_pos, test_two_elems_ch);
    // Тест, когда два нечетных элемента
    tcase_add_test(tc_pos, test_two_elems_nch);
    // Тест, когда много четных элементов
    tcase_add_test(tc_pos, test_more_elems_ch);
    // Тест, когда много нечетных элементов
    tcase_add_test(tc_pos, test_more_elems_nch);
    // Тест, когда много разных элементов
    tcase_add_test(tc_pos, test_more_elems_random);
    // Тест, когда много разных элементов, также среди них есть четные отрицательные
    tcase_add_test(tc_pos, test_more_elems_random_with_negatives);
    // Тест, когда много разных элементов, также среди них все четные отрицательные
    tcase_add_test(tc_pos, test_more_elems_random_with_all_negatives);
    // Тест, когда добавление памяти с запасом, но сначала ее мало
    tcase_add_test(tc_pos, test_more_memory);
    // Тест, когда добавление памяти с запасом, но сначала ее нет
    tcase_add_test(tc_pos, test_more_memory_zero);
    // Тест, когда добавление памяти с запасом, но сначала ее очень много
    tcase_add_test(tc_pos, test_more_memory_over);


    suite_add_tcase(s, tc_pos);

    return s;
}
