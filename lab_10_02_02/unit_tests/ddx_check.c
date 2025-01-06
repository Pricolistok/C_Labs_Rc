#include <stdlib.h>
#include <check.h>
#include "funcs_for_units.h"

START_TEST(test_one_elem)
{
    int rc = OK;
    int coefficients[1] = {1}, cnt_coefficients = 1;
    int coefficients_result[1] = {0}, cnt_coefficients_result = 1;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST

START_TEST(test_two_elems)
{
    int rc = OK;
    int coefficients[2] = {1, 2}, cnt_coefficients = 2;
    int coefficients_result[2] = {1, 0}, cnt_coefficients_result = 2;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST

START_TEST(test_more_elems)
{
    int rc = OK;
    int coefficients[5] = {1, 2, 3, 4, 5}, cnt_coefficients = 5;
    int coefficients_result[5] = {4, 6, 6, 4, 0}, cnt_coefficients_result = 5;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST

START_TEST(test_one_zero_elem)
{
    int rc = OK;
    int coefficients[1] = {0}, cnt_coefficients = 1;
    int coefficients_result[1] = {0}, cnt_coefficients_result = 1;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST

START_TEST(test_two_elems_with_one_zero)
{
    int rc = OK;
    int coefficients[2] = {0, 1}, cnt_coefficients = 2;
    int coefficients_result[2] = {0, 0}, cnt_coefficients_result = 2;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST

START_TEST(test_two_elems_with_two_zeros)
{
    int rc = OK;
    int coefficients[2] = {0, 0}, cnt_coefficients = 2;
    int coefficients_result[2] = {0, 0}, cnt_coefficients_result = 2;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST

START_TEST(test_more_elems_with_one_zero)
{
    int rc = OK;
    int coefficients[5] = {1, 2, 0, 4, 5}, cnt_coefficients = 5;
    int coefficients_result[5] = {4, 6, 0, 4, 0}, cnt_coefficients_result = 5;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST

START_TEST(test_more_elems_with_two_zeros)
{
    int rc = OK;
    int coefficients[5] = {0, 2, 0, 4, 5}, cnt_coefficients = 5;
    int coefficients_result[5] = {0, 6, 0, 4, 0}, cnt_coefficients_result = 5;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST

START_TEST(test_more_elems_with_more_zeros)
{
    int rc = OK;
    int coefficients[5] = {0, 2, 0, 0, 5}, cnt_coefficients = 5;
    int coefficients_result[5] = {0, 6, 0, 0, 0}, cnt_coefficients_result = 5;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST

START_TEST(test_more_elems_with_all_zeros)
{
    int rc = OK;
    int coefficients[5] = {0, 0, 0, 0, 0}, cnt_coefficients = 5;
    int coefficients_result[5] = {0, 0, 0, 0, 0}, cnt_coefficients_result = 5;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST

START_TEST(test_more_elems_with_one_negative)
{
    int rc = OK;
    int coefficients[5] = {1, 2, -3, 4, 5}, cnt_coefficients = 5;
    int coefficients_result[5] = {4, 6, -6, 4, 0}, cnt_coefficients_result = 5;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST

START_TEST(test_more_elems_with_two_negatives)
{
    int rc = OK;
    int coefficients[5] = {1, -2, -3, 4, 5}, cnt_coefficients = 5;
    int coefficients_result[5] = {4, -6, -6, 4, 0}, cnt_coefficients_result = 5;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST

START_TEST(test_more_elems_with_more_negatives)
{
    int rc = OK;
    int coefficients[5] = {-1, -2, -3, 4, 5}, cnt_coefficients = 5;
    int coefficients_result[5] = {-4, -6, -6, 4, 0}, cnt_coefficients_result = 5;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST

START_TEST(test_more_elems_with_all_negatives)
{
    int rc = OK;
    int coefficients[5] = {-1, -2, -3, -4, -5}, cnt_coefficients = 5;
    int coefficients_result[5] = {-4, -6, -6, -4, 0}, cnt_coefficients_result = 5;
    ck_assert_int_eq(rc, check_func_cnt_ddx(coefficients, cnt_coefficients, coefficients_result, cnt_coefficients_result));
}
END_TEST


Suite* test_ddx(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("ddx");
    tc_pos = tcase_create("positive");

    // Тест, когда коэффициент всего один
    tcase_add_test(tc_pos, test_one_elem);
    // Тест, когда коэффициентов всего два
    tcase_add_test(tc_pos, test_two_elems);
    // Тест, когда коэффициентов много
    tcase_add_test(tc_pos, test_more_elems);
    // Тест, когда коэффициент один и он равен 0
    tcase_add_test(tc_pos, test_one_zero_elem);
    // Тест, когда коэффициентов всего два и один равен 0
    tcase_add_test(tc_pos, test_two_elems_with_one_zero);
    // Тест, когда коэффициентов всего два и оба равны 0
    tcase_add_test(tc_pos, test_two_elems_with_two_zeros);
    // Тест, когда коэффициентов много и один равен 0
    tcase_add_test(tc_pos, test_more_elems_with_one_zero);
    // Тест, когда коэффициентов много и два из них равны 0
    tcase_add_test(tc_pos, test_more_elems_with_two_zeros);
    // Тест, когда коэффициентов много и несколько из них равны 0
    tcase_add_test(tc_pos, test_more_elems_with_more_zeros);
    // Тест, когда коэффициентов много и все равны 0
    tcase_add_test(tc_pos, test_more_elems_with_all_zeros);
    // Тест, когда коэффициентов много и есть один отрицательный
    tcase_add_test(tc_pos, test_more_elems_with_one_negative);
    // Тест, когда коэффициентов много и есть два отрицательных коэффициента
    tcase_add_test(tc_pos, test_more_elems_with_two_negatives);
    // Тест, когда коэффициентов много и есть несколько отрицательных
    tcase_add_test(tc_pos, test_more_elems_with_more_negatives);
    // Тест, когда коэффициентов много и есть все отрицательные
    tcase_add_test(tc_pos, test_more_elems_with_all_negatives);
    suite_add_tcase(s, tc_pos);

    return s;
}
