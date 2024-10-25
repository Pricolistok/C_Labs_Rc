#include <stdlib.h>
#include <check.h>
#include "errors.h"
#include "process.h"
#include "errors.h"


START_TEST(test_row_in_senter)
{
    int **arr = NULL;
    
    int arr1[] = {10, 20, 30};
    int arr2[] = {50, 60, 70};
    int arr3[] = {50, -1, 70};
    int arr4[] = {90, 60, 98};

    int arr_result_1[] = {10, 30, 40};
    int arr_result_2[] = {50, 70, 80};
    int arr_result_3[] = {90, 98, 78};
    int **arr = {&arr1[0], &arr2[0], &arr3[0]};
    int **arr_result[] = {&arr_result_1[0], &arr_result_2[0], &arr_result_3[0]};
    size_t n = 4, m = 3;
    remove_columns(arr, &n, m, 1);
    ck_assert_mem_eq(arr1, arr_result, m * sizeof(int));
}
END_TEST


Suite* rm_rows(void)
{
    Suite *s;
    //TCase *tc_neg;
    TCase *tc;

    // Создадим тестовый набор для тестирования функции calc_avg
    s = suite_create("rm_rows");
    
    tc = tcase_create("test");

    tcase_add_test(tc, test_row_in_senter);

    suite_add_tcase(s, tc);

    return s;
}
