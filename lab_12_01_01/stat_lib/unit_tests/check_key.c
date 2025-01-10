#include <stdlib.h>
#include <check.h>
#include "errors_tests.h"
#include "process.h"
#include "errors.h"


START_TEST(test_simple_first_last)
{
    int rc = OK;
    int arr1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int arr_check[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *start_filter = NULL;
    size_t len_arr_1 = 11, len_res = 9;
    size_t new_len;
    int *start = arr1, *finish = start + len_arr_1, *min_adr, *max_adr;
    rc = pre_key(start, finish, &new_len, &min_adr, &max_adr);
    start_filter = malloc(sizeof(int) * new_len);
    if (!start_filter)
        rc = ERROR;
    if (len_res != new_len)
        rc = ERROR;
    if (rc == OK)
        key(start, finish, start_filter, min_adr, max_adr);
    if (rc == OK)
        ck_assert_mem_eq(arr_check, start_filter, len_res * sizeof(int));
    else
        ck_assert_int_eq(rc, OK);
    free(start_filter);
}
END_TEST

START_TEST(test_simple_first_min)
{
    int rc = OK;
    int arr1[] = {1, -100, 9, 8, 7, 6, 5, 4, 3, 2, 1, 100, 9, 8, 78};
    int arr_check[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *start_filter = NULL;
    size_t len_arr_1 = 15, len_res = 9;
    size_t new_len;
    int *start = arr1, *finish = start + len_arr_1, *min_adr, *max_adr;
    rc = pre_key(start, finish, &new_len, &min_adr, &max_adr);
    if (len_res != new_len)
        rc = ERROR;
    start_filter = malloc(sizeof(int) * new_len);
    if (!start_filter)
        rc = ERROR;
    if (rc == OK)
        key(start, finish, start_filter, min_adr, max_adr);
    if (rc == OK)
        ck_assert_mem_eq(arr_check, start_filter, len_res * sizeof(int));
    else
        ck_assert_int_eq(rc, OK);
    free(start_filter);
}
END_TEST

START_TEST(test_simple_first_max)
{
    int rc = OK;
    int arr1[] = {1, 100, 9, 8, 7, 6, 5, 4, 3, 2, 1, -100, 9, 8, 78};
    int arr_check[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *start_filter = NULL;
    size_t len_arr_1 = 15, len_res = 9;
    size_t new_len;
    int *start = arr1, *finish = start + len_arr_1, *min_adr, *max_adr;
    rc = pre_key(start, finish, &new_len, &min_adr, &max_adr);
    if (len_res != new_len)
        rc = ERROR;
    start_filter = malloc(sizeof(int) * new_len);
    if (!start_filter)
        rc = ERROR;
    if (rc == OK)
        key(start, finish, start_filter, min_adr, max_adr);
    if (rc == OK)
        ck_assert_mem_eq(arr_check, start_filter, len_res * sizeof(int));
    else
        ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_simple_double_max)
{
    int rc = OK;
    int arr1[] = {1, 100, 100, 9, 8, 7, 6, 5, 4, 3, 2, 1, -100, 9, 8, 78};
    int arr_check[] = {100, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *start_filter = NULL;
    size_t len_arr_1 = 16, len_res = 10;
    size_t new_len;
    int *start = arr1, *finish = start + len_arr_1, *min_adr, *max_adr;
    rc = pre_key(start, finish, &new_len, &min_adr, &max_adr);
    if (len_res != new_len)
        rc = ERROR;
    start_filter = malloc(sizeof(int) * new_len);
    if (!start_filter)
        rc = ERROR;
    if (rc == OK)
        key(start, finish, start_filter, min_adr, max_adr);
    if (rc == OK)
        ck_assert_mem_eq(arr_check, start_filter, len_res * sizeof(int));
    else
        ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_simple_double_min)
{
    int rc = OK;
    int arr1[] = {1, -100, -100, 9, 8, 7, 6, 5, 4, 3, 2, 1, 100, 9, 8, 78};
    int arr_check[] = {-100, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *start_filter = NULL;
    size_t len_arr_1 = 16, len_res = 10;
    size_t new_len;
    int *start = arr1, *finish = start + len_arr_1, *min_adr, *max_adr;
    rc = pre_key(start, finish, &new_len, &min_adr, &max_adr);
    if (len_res != new_len)
        rc = ERROR;
    start_filter = malloc(sizeof(int) * new_len);
    if (!start_filter)
        rc = ERROR;
    if (rc == OK)
        key(start, finish, start_filter, min_adr, max_adr);
    if (rc == OK)
        ck_assert_mem_eq(arr_check, start_filter, len_res * sizeof(int));
    else
        ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_elems)
{
    int rc = OK;
    int arr1[] = {100, -100};
    size_t len_arr_1 = 2;
    size_t new_len;
    int *start = arr1, *finish = start + len_arr_1, *min_adr, *max_adr;
    rc = pre_key(start, finish, &new_len, &min_adr, &max_adr);
    if (rc != OK)
        rc = OK;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_elems_near)
{
    int rc = OK;
    int arr1[] = {1, 2, 3, 100, -100, 8, 9};
    size_t len_arr_1 = 2;
    size_t new_len;
    int *start = arr1, *finish = start + len_arr_1, *min_adr, *max_adr;
    rc = pre_key(start, finish, &new_len, &min_adr, &max_adr);
    if (rc != OK)
        rc = OK;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_all_elems_eq)
{
    int rc = OK;
    int arr1[] = {9, 9, 9, 9, 9, 9, 9};
    size_t len_arr_1 = 7;
    size_t new_len;
    int *start = arr1, *finish = start + len_arr_1, *min_adr, *max_adr;
    rc = pre_key(start, finish, &new_len, &min_adr, &max_adr);
    if (rc != OK)
        rc = OK;
    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite* key_test(void)
{
    Suite *s;
    //TCase *tc_neg;
    TCase *tc_pos, *tc_neg;

    // Создадим тестовый набор для тестирования функции calc_avg
    s = suite_create("key");
    
    tc_pos = tcase_create("positive");

    tcase_add_test(tc_pos, test_simple_first_last);
    tcase_add_test(tc_pos, test_simple_first_min);
    tcase_add_test(tc_pos, test_simple_first_max);
    tcase_add_test(tc_pos, test_simple_double_max);
    tcase_add_test(tc_pos, test_simple_double_min);

    tc_neg = tcase_create("negative");

    tcase_add_test(tc_neg, test_two_elems);
    tcase_add_test(tc_neg, test_two_elems_near);
    tcase_add_test(tc_neg, test_all_elems_eq);


    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}
