#include <stdlib.h>
#include <check.h>
#include "funcs_for_units.h"

START_TEST(test_one_elem)
{
    int rc = OK;
    int coefficients_1[1] = {1}, cnt_coeficients_1 = 1;
    int coefficients_2[1] = {2}, cnt_coeficients_2 = 1;
    int coeficients_result[1] = {3}, cnt_coeficients = 1;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_two_elems)
{
    int rc = OK;
    int coefficients_1[2] = {1, 2}, cnt_coeficients_1 = 2;
    int coefficients_2[2] = {3, 4}, cnt_coeficients_2 = 2;
    int coeficients_result[2] = {4, 6}, cnt_coeficients = 2;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_more_elems_with_eq_cnt)
{
    int rc = OK;
    int coefficients_1[5] = {1, 2, 3, 4, 5}, cnt_coeficients_1 = 5;
    int coefficients_2[5] = {1, 2, 3, 4, 5}, cnt_coeficients_2 = 5;
    int coeficients_result[5] = {2, 4, 6, 8, 10}, cnt_coeficients = 5;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_sum_one_elem_and_more_elems)
{
    int rc = OK;
    int coefficients_1[1] = {1}, cnt_coeficients_1 = 1;
    int coefficients_2[5] = {1, 2, 3, 4, 5}, cnt_coeficients_2 = 5;
    int coeficients_result[5] = {1, 2, 3, 4, 6}, cnt_coeficients = 5;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_sum_more_elems_and_one_elem)
{
    int rc = OK;
    int coefficients_1[5] = {1, 2, 3, 4, 5}, cnt_coeficients_1 = 5;
    int coefficients_2[1] = {1}, cnt_coeficients_2 = 1;
    int coeficients_result[5] = {1, 2, 3, 4, 6}, cnt_coeficients = 5;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_more_elems_with_no_eq_cnt_first)
{
    int rc = OK;
    int coefficients_1[5] = {1, 2, 3, 4, 5}, cnt_coeficients_1 = 5;
    int coefficients_2[3] = {1, 2, 3}, cnt_coeficients_2 = 3;
    int coeficients_result[5] = {1, 2, 4, 6, 8}, cnt_coeficients = 5;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_more_elems_with_no_eq_cnt_second)
{
    int rc = OK;
    int coefficients_1[3] = {1, 2, 3}, cnt_coeficients_1 = 3;
    int coefficients_2[5] = {1, 2, 3, 4, 5}, cnt_coeficients_2 = 5;
    int coeficients_result[5] = {1, 2, 4, 6, 8}, cnt_coeficients = 5;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_more_elems_with_one_negative_num)
{
    int rc = OK;
    int coefficients_1[5] = {1, -1, 3, 4, 5}, cnt_coeficients_1 = 5;
    int coefficients_2[5] = {1, 2, 3, 4, 5}, cnt_coeficients_2 = 5;
    int coeficients_result[5] = {2, 1, 6, 8, 10}, cnt_coeficients = 5;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_more_elems_with_two_negative_nums)
{
    int rc = OK;
    int coefficients_1[5] = {1, -1, 3, -3, 5}, cnt_coeficients_1 = 5;
    int coefficients_2[5] = {1, 2, 3, 4, 5}, cnt_coeficients_2 = 5;
    int coeficients_result[5] = {2, 1, 6, 1, 10}, cnt_coeficients = 5;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_more_elems_with_more_negative_nums)
{
    int rc = OK;
    int coefficients_1[5] = {1, -1, -3, -3, 5}, cnt_coeficients_1 = 5;
    int coefficients_2[5] = {1, 2, 3, 4, 5}, cnt_coeficients_2 = 5;
    int coeficients_result[5] = {2, 1, -0, 1, 10}, cnt_coeficients = 5;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_more_elems_with_all_negative_nums)
{
    int rc = OK;
    int coefficients_1[5] = {-1, -1, -1, -1, -1}, cnt_coeficients_1 = 5;
    int coefficients_2[5] = {1, 2, 3, 4, 5}, cnt_coeficients_2 = 5;
    int coeficients_result[5] = {0, 1, 2, 3, 4}, cnt_coeficients = 5;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_more_elems_with_all_opposite_negative_nums)
{
    int rc = OK;
    int coefficients_1[5] = {-1, -2, -3, -4, -5}, cnt_coeficients_1 = 5;
    int coefficients_2[5] = {1, 2, 3, 4, 5}, cnt_coeficients_2 = 5;
    int coeficients_result[5] = {0, 0, 0, 0, 0}, cnt_coeficients = 5;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_more_elems_with_all_zero_nums_first)
{
    int rc = OK;
    int coefficients_1[5] = {0, 0, 0, 0, 0}, cnt_coeficients_1 = 5;
    int coefficients_2[5] = {1, 2, 3, 4, 5}, cnt_coeficients_2 = 5;
    int coeficients_result[5] = {1, 2, 3, 4, 5}, cnt_coeficients = 5;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_more_elems_with_all_zero_nums_second)
{
    int rc = OK;
    int coefficients_1[5] = {1, 2, 3, 4, 5}, cnt_coeficients_1 = 5;
    int coefficients_2[5] = {0, 0, 0, 0, 0}, cnt_coeficients_2 = 5;
    int coeficients_result[5] = {1, 2, 3, 4, 5}, cnt_coeficients = 5;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

START_TEST(test_more_elems_with_all_zero_nums)
{
    int rc = OK;
    int coefficients_1[5] = {0, 0, 0, 0, 0}, cnt_coeficients_1 = 5;
    int coefficients_2[5] = {0, 0, 0, 0, 0}, cnt_coeficients_2 = 5;
    int coeficients_result[5] = {0, 0, 0, 0}, cnt_coeficients = 5;
    ck_assert_int_eq(rc, check_func_cnt_sum(coefficients_1, cnt_coeficients_1, coefficients_2, cnt_coeficients_2, coeficients_result, cnt_coeficients));
}
END_TEST

Suite* test_sum(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sum");
    tc_pos = tcase_create("positive");

    // Тест, когда коэффициентов всего по одному
    tcase_add_test(tc_pos, test_one_elem);
    // Тест, когда коэффициентов всего по два
    tcase_add_test(tc_pos, test_two_elems);
    // Тест, когда коэффициентов много и их количество равно
    tcase_add_test(tc_pos, test_more_elems_with_eq_cnt);
    // Тест, когда коэффициентов в первом один коэффициент, а во втором много
    tcase_add_test(tc_pos, test_sum_one_elem_and_more_elems);
    // Тест, когда коэффициентов в первом много коэффициентов, а во втором один
    tcase_add_test(tc_pos, test_sum_more_elems_and_one_elem);
    // Тест, когда коэффициентов в первом и втором много коэфициентов, но в первом их больше
    tcase_add_test(tc_pos, test_more_elems_with_no_eq_cnt_first);
    // Тест, когда коэффициентов в первом и втором много коэфициентов, но во втором их больше
    tcase_add_test(tc_pos, test_more_elems_with_no_eq_cnt_second);
    // Тест, когда коэффициентов в первом и втором много коэфициентов, но во втором их больше
    tcase_add_test(tc_pos, test_more_elems_with_no_eq_cnt_second);
	// Тест, когда коэффициентов в первом и втором много коэфициентов, но есть один отрицательный
    tcase_add_test(tc_pos, test_more_elems_with_one_negative_num);
    // Тест, когда коэффициентов в первом и втором много коэфициентов, но есть два отрицательных
    tcase_add_test(tc_pos, test_more_elems_with_two_negative_nums);
    // Тест, когда коэффициентов в первом и втором много коэфициентов, но есть несколько отрицательных
    tcase_add_test(tc_pos, test_more_elems_with_more_negative_nums);
    // Тест, когда коэффициентов в первом и втором много коэфициентов, но все они отрицательные
    tcase_add_test(tc_pos, test_more_elems_with_all_negative_nums);
    // Тест, когда коэффициентов в первом и втором много коэфициентов, но все противоположны
    tcase_add_test(tc_pos, test_more_elems_with_all_opposite_negative_nums);
    // Тест, когда коэффициентов в первом и втором много коэфициентов, но в первом все равны 0
    tcase_add_test(tc_pos, test_more_elems_with_all_zero_nums_first);
    // Тест, когда коэффициентов в первом и втором много коэфициентов, но во втором все равны 0
    tcase_add_test(tc_pos, test_more_elems_with_all_zero_nums_second);
    // Тест, когда коэффициентов в первом и втором много коэфициентов, но все равны 0
    tcase_add_test(tc_pos, test_more_elems_with_all_zero_nums);

    suite_add_tcase(s, tc_pos);

    return s;
}
