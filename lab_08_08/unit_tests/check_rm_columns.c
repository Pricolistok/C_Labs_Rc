#include <stdlib.h>
#include <check.h>
#include "errors.h"
#include "process.h"
#include "errors.h"
#include "funcs_for_unit.h"
#include "consts_for_unit.h"

// Тест для проверки удаления столбца в начале
START_TEST(test_column_in_start)
{
    int **arr_a = NULL, rc;
    int arr_data_in[LEN_DATA_3 * LEN_DATA_4] = {-100, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr_data_out[LEN_DATA_3 * LEN_DATA_3] = {2, 3, 4, 6, 7, 8, 10, 11, 12};
    int rm_rows = 1;
    size_t n_a = LEN_DATA_3, m_a = LEN_DATA_4;
    arr_a = add_memory(n_a, m_a);
    if (arr_a)
    {
        input_data_to_mtrix(arr_a, arr_data_in, n_a, m_a);
        arr_a = remove_columns(arr_a, n_a, &m_a, rm_rows);
        if (arr_a != NULL)
            rc = check_result(arr_a, arr_data_out, n_a);
        else
            rc = ERROR;
    }
    else
    {
        rc = ERROR;
    }
    ck_assert_int_eq(rc, OK);
    free_memory(arr_a, n_a);
}
END_TEST

// Тест для проверки удаления столбца в середине
START_TEST(test_column_in_center)
{
    int **arr_a = NULL, rc;
    int arr_data_in[LEN_DATA_3 * LEN_DATA_4] = {1, 2, 3, 4, 5, -100, 7, 8, 9, 10, 11, 12};
    int arr_data_out[LEN_DATA_3 * LEN_DATA_3] = {1, 3, 4, 5, 7, 8, 9, 11, 12};
    int rm_rows = 1;
    size_t n_a = LEN_DATA_3, m_a = LEN_DATA_4;
    arr_a = add_memory(n_a, m_a);
    if (arr_a)
    {
        input_data_to_mtrix(arr_a, arr_data_in, n_a, m_a);
        arr_a = remove_columns(arr_a, n_a, &m_a, rm_rows);
        if (arr_a != NULL)
            rc = check_result(arr_a, arr_data_out, n_a);
        else
            rc = ERROR;
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

// Тест для проверки удаления столбца в конце
START_TEST(test_column_in_finish)
{
    int **arr_a = NULL, rc;
    int arr_data_in[LEN_DATA_3 * LEN_DATA_4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, -100};
    int arr_data_out[LEN_DATA_3 * LEN_DATA_3] = {1, 2, 3, 5, 6, 7, 9, 10, 11};
    int rm_rows = 1;
    size_t n_a = LEN_DATA_3, m_a = LEN_DATA_4;
    arr_a = add_memory(n_a, m_a);
    if (arr_a)
    {
        input_data_to_mtrix(arr_a, arr_data_in, n_a, m_a);
        arr_a = remove_columns(arr_a, n_a, &m_a, rm_rows);
        if (arr_a != NULL)
            rc = check_result(arr_a, arr_data_out, n_a);
        else
            rc = ERROR;
    }
    else
    {
        rc = ERROR;
    }
    ck_assert_int_eq(rc, OK);
    free_memory(arr_a, n_a);
}
END_TEST


Suite* rm_columns(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("remove_columns");
    
    tc = tcase_create("test");

    tcase_add_test(tc, test_column_in_start);
    tcase_add_test(tc, test_column_in_center);
    tcase_add_test(tc, test_column_in_finish);

    suite_add_tcase(s, tc);

    return s;
}
