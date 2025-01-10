#include <stdlib.h>
#include <check.h>
#include <string.h>
#include "process.h"
#include "funcs_for_units.h"

START_TEST(test_one_str)
{
    int rc = OK;
    char *format = "Name: %s\0";
    size_t n = 12;
    char result_my[12], result_func[12];
    char *arg_1 = "Alina\0";
    int result_len_my = snprintf(result_func, n, format, arg_1);
    int result_len_func = my_snprintf(result_my, n, format, arg_1);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_strs_no_space)
{
    int rc = OK;
    char *format = "Names: %s%s\0";
    size_t n = 17;
    char result_my[17], result_func[17];
    char *arg_1 = "Alina\0";
    char *arg_2 = "Anna\0";
    int result_len_my = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_func = my_snprintf(result_my, n, format, arg_1, arg_2);

    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_strs_with_space)
{
    int rc = OK;
    char *format = "Names: %s %s\0";
    size_t n = 18;
    char result_my[18], result_func[18];
    char *arg_1 = "Alina\0";
    char *arg_2 = "Anna\0";
    int result_len_my = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_func = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_strs_with_more_spaces)
{
    int rc = OK;
    char *format = "Names:    %s     %s\0";
    size_t n = 25;
    char result_my[25], result_func[25];
    char *arg_1 = "Alina\0";
    char *arg_2 = "Anna\0";
    int result_len_my = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_func = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_strs_with_enter)
{
    int rc = OK;
    char *format = "Names: %s\n%s\0";
    size_t n = 18;
    char result_my[18], result_func[18];
    char *arg_1 = "Alina\0";
    char *arg_2 = "Anna\0";
    int result_len_my = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_func = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_strs_with_more_enters)
{
    int rc = OK;
    char *format = "Names\n: \n%s\n\n%s\n\0";
    size_t n = 22;
    char result_my[22], result_func[22];
    char *arg_1 = "Alina\0";
    char *arg_2 = "Anna\0";
    int result_len_my = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_func = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_strs_with_percent)
{
    int rc = OK;
    char *format = "Names: %s%%s\0";
    size_t n = 18;
    char result_my[18], result_func[18];
    char *arg_1 = "Alina\0";
    char *arg_2 = "Anna\0";
    int result_len_my = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_func = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_strs_with_more_percents_near)
{
    int rc = OK;
    char *format = "Names: %s%%%%s\0";
    size_t n = 20;
    char result_my[20], result_func[20];
    char *arg_1 = "Alina\0";
    char *arg_2 = "Anna\0";
    int result_len_my = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_func = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_strs_with_more_strs)
{
    int rc = OK;
    char *format = "Names: %s%s %s    %s\0";
    size_t n = 33;
    char result_my[33], result_func[33];
    char *arg_1 = "Alina\0";
    char *arg_2 = "Anna\0";
    char *arg_3 = "Nina\0";
    char *arg_4 = "Alla\0";
    int result_len_my = snprintf(result_func, n, format, arg_1, arg_2, arg_3, arg_4);
    int result_len_func = my_snprintf(result_my, n, format, arg_1, arg_2, arg_3, arg_4);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_strs_with_more_strs_overflow_small)
{
    int rc = OK;
    char *format = "Names: %s%s %s    %s\0";
    size_t n = 10;
    char result_my[10], result_func[10];
    char *arg_1 = "Alina\0";
    char *arg_2 = "Anna\0";
    char *arg_3 = "Nina\0";
    char *arg_4 = "Alla\0";
    int result_len_my = snprintf(result_func, n, format, arg_1, arg_2, arg_3, arg_4);
    int result_len_func = my_snprintf(result_my, n, format, arg_1, arg_2, arg_3, arg_4);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_strs_with_more_strs_overflow_mid)
{
    int rc = OK;
    char *format = "Names: %s%s %s    %s\0";
    size_t n = 20;
    char result_my[20], result_func[20];
    char *arg_1 = "Alina\0";
    char *arg_2 = "Anna\0";
    char *arg_3 = "Nina\0";
    char *arg_4 = "Alla\0";
    int result_len_my = snprintf(result_func, n, format, arg_1, arg_2, arg_3, arg_4);
    int result_len_func = my_snprintf(result_my, n, format, arg_1, arg_2, arg_3, arg_4);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST


START_TEST(test_two_strs_with_more_strs_memory_over)
{
    int rc = OK;
    char *format = "Names: %s%s %s    %s\0";
    size_t n = 100;
    char result_my[100], result_func[100];
    char *arg_1 = "Alina\0";
    char *arg_2 = "Anna\0";
    char *arg_3 = "Nina\0";
    char *arg_4 = "Alla\0";
    int result_len_my = snprintf(result_func, n, format, arg_1, arg_2, arg_3, arg_4);
    int result_len_func = my_snprintf(result_my, n, format, arg_1, arg_2, arg_3, arg_4);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite* test_s(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("spec: s");
    tc_pos = tcase_create("positive");

    // Тест, когда есть одна строка
    tcase_add_test(tc_pos, test_one_str);
    // Тест, когда есть две строки без пробелов
    tcase_add_test(tc_pos, test_two_strs_no_space);
    // Тест, когда есть две строки с пробелом
    tcase_add_test(tc_pos, test_two_strs_with_space);
    // Тест, когда есть две строки с несколькими пробелами
    tcase_add_test(tc_pos, test_two_strs_with_more_spaces);
    // Тест, когда есть две строки с переносом строки
    tcase_add_test(tc_pos, test_two_strs_with_enter);
    // Тест, когда есть две строки с несколькими переносами строки
    tcase_add_test(tc_pos, test_two_strs_with_more_enters);
    // Тест, когда есть две строки с дополнительным процентом
    tcase_add_test(tc_pos, test_two_strs_with_percent);
    // Тест, когда есть две строки с дополнительными процентами
    tcase_add_test(tc_pos, test_two_strs_with_more_percents_near);
    // Тест, когда есть много строк
    tcase_add_test(tc_pos, test_two_strs_with_more_strs);
    // Тест, когда есть много строк и длина строки значительно меньше необходимого
    tcase_add_test(tc_pos, test_two_strs_with_more_strs_overflow_small);
    // Тест, когда есть много строк и длина строки в половину меньше необходимого
    tcase_add_test(tc_pos, test_two_strs_with_more_strs_overflow_mid);
    // есть много строк и длина строки значительно больше необходимого
    tcase_add_test(tc_pos, test_two_strs_with_more_strs_memory_over);

    suite_add_tcase(s, tc_pos);

    return s;
}
