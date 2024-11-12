#include <stdlib.h>
#include <check.h>
#include "errors.h"
#include "process.h"
#include "errors.h"
#include "funcs_for_unit.h"
#include "consts_for_unit.h"

// Тест для проверки добавления одной строки и одного столбца
START_TEST(test_add_one_row_and_column)
{
    int **arr_a = NULL, rc;
    int flag = 0;
    int arr_data_in[LEN_DATA_2 * LEN_DATA_2] = {1, 2, 3, 4};
    int arr_data_result[LEN_DATA_3 * LEN_DATA_3] = {1, 2, 1, 3, 4, 3, 1, 2, 1};
    size_t n_a = LEN_DATA_2, m_a = LEN_DATA_2, add_size = 1;
    arr_a = add_memory(n_a, m_a);
    if (arr_a)
    {
        input_data_to_mtrix(arr_a, arr_data_in, n_a, m_a);
        rc = create_new_memory_for_rows(&arr_a, n_a, m_a, add_size);
        if (rc != OK)
            flag = 1;
        rc = add_row_to_arr(arr_a, n_a, m_a, add_size);
        if (rc != OK)
            flag = 1;
        n_a += add_size;
        rc = create_new_memory_for_columns(&arr_a, n_a, m_a, add_size);
        if (rc != OK)
            flag = 1;
        add_column_to_arr(arr_a, n_a, m_a, add_size);
        m_a += add_size;
        rc = check_result(arr_a, arr_data_result, n_a);
        if (rc != OK)
            flag = 1;
    }
    else
    {
        rc = ERROR;
    }
    if (flag == 1)
        rc = ERROR;
    if (arr_a)
    {
        for (size_t i = 0; i < n_a; i++)
            free(arr_a[i]);
        free(arr_a);
    }
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест для проверки добавления нескольких строк и нескольких столбцов
START_TEST(test_add_several_row_and_column)
{
    int **arr_a = NULL, rc;
    int flag = 0;
    int arr_data_in[LEN_DATA_2 * LEN_DATA_2] = {1, 2, 3, 4};
    int arr_data_result[LEN_DATA_4 * LEN_DATA_4] = {1, 2, 1, 1, 3, 4, 3, 3, 1, 2, 1, 1, 1, 2, 1, 1};
    size_t n_a = LEN_DATA_2, m_a = LEN_DATA_2, add_size = 2;
    arr_a = add_memory(n_a, m_a);
    if (arr_a)
    {
        input_data_to_mtrix(arr_a, arr_data_in, n_a, m_a);
        rc = create_new_memory_for_rows(&arr_a, n_a, m_a, add_size);
        if (rc != OK)
            flag = 1;
        rc = add_row_to_arr(arr_a, n_a, m_a, add_size);
        if (rc != OK)
            flag = 1;
        n_a += add_size;
        rc = create_new_memory_for_columns(&arr_a, n_a, m_a, add_size);
        if (rc != OK)
            flag = 1;
        add_column_to_arr(arr_a, n_a, m_a, add_size);
        m_a += add_size;
        rc = check_result(arr_a, arr_data_result, n_a);
        if (rc != OK)
            flag = 1;
    }
    else
    {
        rc = ERROR;
    }
    if (flag == 1)
        rc = ERROR;
    if (arr_a)
    {
        for (size_t i = 0; i < n_a; i++)
            free(arr_a[i]);
        free(arr_a);
    }
    ck_assert_int_eq(rc, OK);
}
END_TEST


Suite* add_elems(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("add_elems");
    
    tc = tcase_create("test");

    tcase_add_test(tc, test_add_one_row_and_column);
    tcase_add_test(tc, test_add_several_row_and_column);

    suite_add_tcase(s, tc);

    return s;
}
