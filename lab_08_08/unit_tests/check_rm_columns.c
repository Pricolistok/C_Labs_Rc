#include <stdlib.h>
#include <check.h>
#include "errors.h"
#include "process.h"

START_TEST(test_column_in_senter)
{
    int arr1[] = {10, 20, 30, 40};
    int arr2[] = {50, 60, 70, 80};
    int arr3[] = {90, -1, 98, 78};

    int arr_result_1[] = {10, 30, 40};
    int arr_result_2[] = {50, 70, 80};
    int arr_result_3[] = {90, 98, 78};
    int **arr[] = {arr1, arr2, arr3};
    size_t n = 3, m = 4;
    remove_columns(arr, &n, m, 1);
    ck_assert_mem_eq(arr1, arr_result_1, n * sizeof(int));
    ck_assert_mem_eq(arr2, arr_result_2, n * sizeof(int));
    ck_assert_mem_eq(arr3, arr_result_3, n * sizeof(int));
}
END_TEST


Suite* rm_columns(void)
{
    Suite *s;
    //TCase *tc_neg;
    TCase *tc;

    s = suite_create("rm_columns");
    tc = tcase_create("test");

    tcase_add_test(tc, test_column_in_senter);

    suite_add_tcase(s, tc);
    

    return s;
}
