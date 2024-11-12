#include <stdlib.h>
#include <check.h>
#include "errors.h"
#include "process.h"
#include "errors.h"
#include "funcs_for_unit.h"
#include "consts_for_unit.h"

// Функция для удаления строки в начале
START_TEST(test_row_in_start)
{
    int **arr_a = NULL, rc;
    int arr_data_in[LEN_DATA_3 * LEN_DATA_4] = {-100, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr_data_out[LEN_DATA_3 * LEN_DATA_3] = {4, 5, 6, 7, 8, 9, 10, 11, 12};
    int rm_rows = 1;
    size_t n_a = LEN_DATA_4, m_a = LEN_DATA_3;
    arr_a = add_memory(n_a, m_a);
    if (arr_a)
    {
        input_data_to_mtrix(arr_a, arr_data_in, n_a, m_a);
        arr_a = remove_rows(arr_a, &n_a, m_a, rm_rows);
        rc = check_result(arr_a, arr_data_out, n_a);
    }
    else
    {
        rc = ERROR;
    }
    if (arr_a)
    {
        for (size_t i = 0; i < n_a; i++)
            free(arr_a[i]);
        free(arr_a);
    }
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Функция для удаления строки в середине
START_TEST(test_row_in_center)
{
    int **arr_a = NULL, rc;
    int arr_data_in[LEN_DATA_3 * LEN_DATA_4] = {1, 2, 3, 4, 5, -100, 7, 8, 9, 10, 11, 12};
    int arr_data_out[LEN_DATA_3 * LEN_DATA_3] = {1, 2, 3, 7, 8, 9, 10, 11, 12};
    int rm_rows = 1;
    size_t n_a = LEN_DATA_4, m_a = LEN_DATA_3;
    arr_a = add_memory(n_a, m_a);
    if (arr_a)
    {
        input_data_to_mtrix(arr_a, arr_data_in, n_a, m_a);
        arr_a = remove_rows(arr_a, &n_a, m_a, rm_rows);
        rc = check_result(arr_a, arr_data_out, n_a);
    }
    else
    {
        rc = ERROR;
    }
    if (arr_a)
    {
        for (size_t i = 0; i < n_a; i++)
            free(arr_a[i]);
        free(arr_a);
    }
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Функция для удаления строки в конце
START_TEST(test_row_in_finish)
{
    int **arr_a = NULL, rc;
    int arr_data_in[LEN_DATA_3 * LEN_DATA_4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, -100};
    int arr_data_out[LEN_DATA_3 * LEN_DATA_3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int rm_rows = 1;
    size_t n_a = LEN_DATA_4, m_a = LEN_DATA_3;
    arr_a = add_memory(n_a, m_a);
    if (arr_a)
    {
        input_data_to_mtrix(arr_a, arr_data_in, n_a, m_a);
        arr_a = remove_rows(arr_a, &n_a, m_a, rm_rows);
        rc = check_result(arr_a, arr_data_out, n_a);
    }
    else
    {
        rc = ERROR;
    }
    if (arr_a)
    {
        for (size_t i = 0; i < n_a; i++)
            free(arr_a[i]);
        free(arr_a);
    }
    ck_assert_int_eq(rc, OK);
}
END_TEST


Suite* rm_rows(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("remove_rows");
    
    tc = tcase_create("test");

    tcase_add_test(tc, test_row_in_start);
    tcase_add_test(tc, test_row_in_center);
    tcase_add_test(tc, test_row_in_finish);

    suite_add_tcase(s, tc);

    return s;
}
