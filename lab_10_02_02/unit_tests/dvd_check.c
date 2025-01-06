#include <stdlib.h>
#include <check.h>
#include "funcs_for_units.h"

START_TEST(test_one_elem)
{
    int rc = OK;
    int coefficients[1] = {1}, cnt_coefficients = 1;
    int coefficients_ch_expected[1] = {1}, cnt_coefficients_ch_expected = 1;
    int coefficients_nch_expected[1], cnt_coefficients_nch_expected = 0;
    ck_assert_int_eq(rc, check_func_sep(coefficients, cnt_coefficients, coefficients_ch_expected, cnt_coefficients_ch_expected, coefficients_nch_expected, cnt_coefficients_nch_expected));
}
END_TEST

START_TEST(test_two_elems)
{
    int rc = OK;
    int coefficients[2] = {1, 2}, cnt_coefficients = 2;
    int coefficients_ch_expected[1] = {2}, cnt_coefficients_ch_expected = 1;
    int coefficients_nch_expected[1] = {1}, cnt_coefficients_nch_expected = 1;
    ck_assert_int_eq(rc, check_func_sep(coefficients, cnt_coefficients, coefficients_ch_expected, cnt_coefficients_ch_expected, coefficients_nch_expected, cnt_coefficients_nch_expected));
}
END_TEST

START_TEST(test_more_elems_nch)
{
    int rc = OK;
    int coefficients[5] = {1, 2, 3, 4, 5}, cnt_coefficients = 5;
    int coefficients_ch_expected[3] = {1, 3, 5}, cnt_coefficients_ch_expected = 3;
    int coefficients_nch_expected[2] = {2, 4}, cnt_coefficients_nch_expected = 2;
    ck_assert_int_eq(rc, check_func_sep(coefficients, cnt_coefficients, coefficients_ch_expected, cnt_coefficients_ch_expected, coefficients_nch_expected, cnt_coefficients_nch_expected));
}
END_TEST

START_TEST(test_more_elems_ch)
{
    int rc = OK;
    int coefficients[4] = {1, 2, 3, 4}, cnt_coefficients = 4;
    int coefficients_ch_expected[2] = {2, 4}, cnt_coefficients_ch_expected = 2;
    int coefficients_nch_expected[2] = {1, 3}, cnt_coefficients_nch_expected = 2;
    ck_assert_int_eq(rc, check_func_sep(coefficients, cnt_coefficients, coefficients_ch_expected, cnt_coefficients_ch_expected, coefficients_nch_expected, cnt_coefficients_nch_expected));
}
END_TEST



Suite* test_dvd(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sep");
    tc_pos = tcase_create("positive");

    // Тест, когда коэффициент всего один
    tcase_add_test(tc_pos, test_one_elem);
    // Тест, когда коэффициентов два
    tcase_add_test(tc_pos, test_two_elems);
    // Тест, когда коэффициентов много и их нечетное количество
    tcase_add_test(tc_pos, test_more_elems_nch);
    // Тест, когда коэффициентов много и их четное количество
    tcase_add_test(tc_pos, test_more_elems_ch);

    suite_add_tcase(s, tc_pos);

    return s;
}
