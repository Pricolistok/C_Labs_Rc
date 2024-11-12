#include <stdlib.h>
#include <check.h>
#include "errors.h"
#include "process.h"
#include "errors.h"
#include "funcs_for_unit.h"
#include "consts_for_unit.h"

// Тест для проверки функции усножения
START_TEST(test_simple_multiplication)
{
    int **arr_a = NULL, **arr_b = NULL, rc;
    int arr_a_data_in[LEN_DATA_3 * LEN_DATA_3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr_b_data_in[LEN_DATA_3 * LEN_DATA_3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr_data_out[LEN_DATA_3 * LEN_DATA_3] = {30, 36, 42, 66, 81, 96, 102, 126, 150};
    size_t n = LEN_DATA_3;
    arr_a = add_memory(n, n);
    arr_b = add_memory(n, n);
    if (arr_a && arr_b)
    {
        input_data_to_mtrix(arr_a, arr_a_data_in, n, n);
        input_data_to_mtrix(arr_b, arr_b_data_in, n, n);
        matrix_multiplication(arr_a, arr_b, n);
        rc = check_result(arr_a, arr_data_out, n);
    }
    else
    {
        rc = ERROR;
    }
    ck_assert_int_eq(rc, OK);
    free_memory(arr_a, n);
    free_memory(arr_b, n);
}
END_TEST

// Тест для проверки умножения с несколькими отрицательными числами
START_TEST(test_multiplication_with_negatives)
{
    int **arr_a = NULL, **arr_b = NULL, rc;
    int arr_a_data_in[LEN_DATA_3 * LEN_DATA_3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr_b_data_in[LEN_DATA_3 * LEN_DATA_3] = {1, 2, -3, 4, 5, -6, 7, 8, -9};
    int arr_data_out[LEN_DATA_3 * LEN_DATA_3] = {30, 36, -42, 66, 81, -96, 102, 126, -150};
    size_t n = LEN_DATA_3;
    arr_a = add_memory(n, n);
    arr_b = add_memory(n, n);
    if (arr_a && arr_b)
    {
        input_data_to_mtrix(arr_a, arr_a_data_in, n, n);
        input_data_to_mtrix(arr_b, arr_b_data_in, n, n);
        matrix_multiplication(arr_a, arr_b, n);
        rc = check_result(arr_a, arr_data_out, n);
    }
    else
    {
        rc = ERROR;
    }
    ck_assert_int_eq(rc, OK);
    free_memory(arr_a, n);
    free_memory(arr_b, n);
}
END_TEST

// Тест для проверки умножения со всеми отрицательными числами
START_TEST(test_multiplication_with_all_negatives)
{
    int **arr_a = NULL, **arr_b = NULL, rc;
    int arr_a_data_in[LEN_DATA_3 * LEN_DATA_3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr_b_data_in[LEN_DATA_3 * LEN_DATA_3] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
    int arr_data_out[LEN_DATA_3 * LEN_DATA_3] = {-30, -36, -42, -66, -81, -96, -102, -126, -150};
    size_t n = LEN_DATA_3;
    arr_a = add_memory(n, n);
    arr_b = add_memory(n, n);
    if (arr_a != NULL && arr_b != NULL)
    {
        input_data_to_mtrix(arr_a, arr_a_data_in, n, n);
        input_data_to_mtrix(arr_b, arr_b_data_in, n, n);
        matrix_multiplication(arr_a, arr_b, n);
        rc = check_result(arr_a, arr_data_out, n);
    }
    else
    {
        rc = ERROR;
    }
    ck_assert_int_eq(rc, OK);
    free_memory(arr_a, n);
    free_memory(arr_b, n);
}
END_TEST

Suite* multiplication_matrix(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("multiplication matrix");
    
    tc = tcase_create("test");

    tcase_add_test(tc, test_simple_multiplication);
    tcase_add_test(tc, test_multiplication_with_negatives);
    tcase_add_test(tc, test_multiplication_with_all_negatives);

    suite_add_tcase(s, tc);

    return s;
}
