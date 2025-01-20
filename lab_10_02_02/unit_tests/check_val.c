#include <stdlib.h>
#include <check.h>
#include "process.h"
#include "struct.h"
#include "funcs_for_units.h"

START_TEST(test_one_elem)
{
    int rc = OK;
    int coefficients[1] = {1}, cnt_coefficients = 1, val = 3;
    int expected_sum = 1;
    ck_assert_int_eq(rc, check_func_cnt_val(coefficients, cnt_coefficients, expected_sum, val));
}
END_TEST

START_TEST(test_two_elems)
{
    int rc = OK;
    int coefficients[2] = {3, 4}, cnt_coefficients = 2, val = 3;
    int expected_sum = 13;
    ck_assert_int_eq(rc, check_func_cnt_val(coefficients, cnt_coefficients, expected_sum, val));
}
END_TEST

START_TEST(test_more_elems)
{
    int rc = OK;
    int coefficients[5] = {3, 4, 10, 45, 2}, cnt_coefficients = 5, val = 3;
    int expected_sum = 578;
    ck_assert_int_eq(rc, check_func_cnt_val(coefficients, cnt_coefficients, expected_sum, val));
}
END_TEST

START_TEST(test_one_elem_is_zero)
{
    int rc = OK;
    int coefficients[1] = {0}, cnt_coefficients = 1, val = 3;
    int expected_sum = 0;
    ck_assert_int_eq(rc, check_func_cnt_val(coefficients, cnt_coefficients, expected_sum, val));
}
END_TEST

START_TEST(test_more_elems_is_zero)
{
    int rc = OK;
    int coefficients[6] = {0, 0, 0, 0, 0, 0}, cnt_coefficients = 6, val = 3;
    int expected_sum = 0;
    ck_assert_int_eq(rc, check_func_cnt_val(coefficients, cnt_coefficients, expected_sum, val));
}
END_TEST

START_TEST(test_one_elem_with_negative_number)
{
    int rc = OK;
    int coefficients[1] = {-3}, cnt_coefficients = 1, val = 3;
    int expected_sum = -3;
    ck_assert_int_eq(rc, check_func_cnt_val(coefficients, cnt_coefficients, expected_sum, val));
}
END_TEST

START_TEST(test_more_elems_with_one_negative_number)
{
    int rc = OK;
    int coefficients[4] = {1, 2, 4, -3}, cnt_coefficients = 4, val = 3;
    int expected_sum = 54;
    ck_assert_int_eq(rc, check_func_cnt_val(coefficients, cnt_coefficients, expected_sum, val));
}
END_TEST

START_TEST(test_more_elems_with_more_negative_numbers)
{
    int rc = OK;
    int coefficients[4] = {1, -2, -4, -3}, cnt_coefficients = 4, val = 3;
    int expected_sum = -6;
    ck_assert_int_eq(rc, check_func_cnt_val(coefficients, cnt_coefficients, expected_sum, val));
}
END_TEST

START_TEST(test_more_elems_with_all_negative_numbers)
{
    int rc = OK;
    int coefficients[4] = {-1, -2, -4, -3}, cnt_coefficients = 4, val = 3;
    int expected_sum = -60;
    ck_assert_int_eq(rc, check_func_cnt_val(coefficients, cnt_coefficients, expected_sum, val));
}
END_TEST


Suite* test_val(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("val");
    tc_pos = tcase_create("positive");

    // Тест, когда коэффициент всего 1
    tcase_add_test(tc_pos, test_one_elem);
    // Тест, когда коэффициентов всего 2
    tcase_add_test(tc_pos, test_two_elems);
    // Тест, когда коэффициентов много
    tcase_add_test(tc_pos, test_more_elems);
    // Тест, когда коэффициент всего один и он равен нулю
    tcase_add_test(tc_pos, test_one_elem_is_zero);
    // Тест, когда коэффициентов много и они равны нулю
    tcase_add_test(tc_pos, test_more_elems_is_zero);
    // Тест, когда коэффициент один и он является отрицательным числом
    tcase_add_test(tc_pos, test_one_elem_with_negative_number);
    // Тест, когда коэффициентов много и один из них это отрицательное число
    tcase_add_test(tc_pos, test_more_elems_with_one_negative_number);
    // Тест, когда коэффициентов много и несколько из них это отрицательные числа
    tcase_add_test(tc_pos, test_more_elems_with_more_negative_numbers);
    // Тест, когда коэффициентов много и все из них это отрицательные числа
    tcase_add_test(tc_pos, test_more_elems_with_all_negative_numbers);

    suite_add_tcase(s, tc_pos);

    return s;
}
