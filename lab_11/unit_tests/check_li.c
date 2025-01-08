#include <stdlib.h>
#include <check.h>
#include <limits.h>
#include <string.h>
#include "process.h"
#include "funcs_for_units.h"

START_TEST(test_one_li_short_len)
{
    int rc = OK;
    char *format = "Name: %li\0";
    size_t n = 8;
    char result_my[8], result_func[8];
    long int arg_1 = 1;
    int result_len_func = snprintf(result_func, n, format, arg_1);
    int result_len_my = my_snprintf(result_my, n, format, arg_1);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_one_li_long_len)
{
    int rc = OK;
    char *format = "Name: %li\0";
    size_t n = 14;
    char result_my[14], result_func[14];
    long int arg_1 = 1234567;
    int result_len_func = snprintf(result_func, n, format, arg_1);
    int result_len_my = my_snprintf(result_my, n, format, arg_1);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_one_li_long_int_len)
{
    int rc = OK;
    char *format = "Name: %li\0";
    size_t n = 26;
    char result_my[26], result_func[26];
    long int arg_1 = 9223372036854775807;
    int result_len_func = snprintf(result_func, n, format, arg_1);
    int result_len_my = my_snprintf(result_my, n, format, arg_1);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST


START_TEST(test_two_li_short_len_no_space)
{
    int rc = OK;
    char *format = "Name: %li%li\0";
    size_t n = 9;
    char result_my[9], result_func[9];
    long int arg_1 = 1;
    long int arg_2 = 2;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_li_short_len_one_space)
{
    int rc = OK;
    char *format = "Name: %li %li\0";
    size_t n = 10;
    char result_my[10], result_func[10];
    long int arg_1 = 1;
    long int arg_2 = 2;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_li_short_len_more_spaces)
{
    int rc = OK;
    char *format = "N  ame:    %li      %li\0";
    size_t n = 20;
    char result_my[20], result_func[20];
    long int arg_1 = 1;
    long int arg_2 = 2;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_li_long_len_no_space)
{
    int rc = OK;
    char *format = "Name: %li%li\0";
    size_t n = 21;
    char result_my[21], result_func[21];
    long int arg_1 = 1234567;
    long int arg_2 = 7654321;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_li_long_len_one_space)
{
    int rc = OK;
    char *format = "Name: %li %li\0";
    size_t n = 22;
    char result_my[22], result_func[22];
    long int arg_1 = 1234567;
    long int arg_2 = 7654321;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_li_long_len_more_spaces)
{
    int rc = OK;
    char *format = "Na m e:  %li      %li\0";
    size_t n = 30;
    char result_my[30], result_func[30];
    long int arg_1 = 1234567;
    long int arg_2 = 7654321;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_li_long_int_len_no_space)
{
    int rc = OK;
    char *format = "Name: %li%li\0";
    size_t n = 45;
    char result_my[45], result_func[45];
    long int arg_1 = LONG_MAX;
    long int arg_2 = LONG_MAX;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_li_long_int_len_with_one_space)
{
    int rc = OK;
    char *format = "Name: %li %li\0";
    size_t n = 46;
    char result_my[46], result_func[46];
    long int arg_1 = LONG_MAX;
    long int arg_2 = LONG_MAX;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_li_long_int_len_with_more_spaces)
{
    int rc = OK;
    char *format = "    N   a m e: %li    %li  \0";
    size_t n = 60;
    char result_my[60], result_func[60];
    long int arg_1 = LONG_MAX;
    long int arg_2 = LONG_MAX;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_one_li_short_len_negative)
{
    int rc = OK;
    char *format = "Name: %li\0";
    size_t n = 9;
    char result_my[9], result_func[9];
    long int arg_1 = -1;
    int result_len_func = snprintf(result_func, n, format, arg_1);
    int result_len_my = my_snprintf(result_my, n, format, arg_1);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_li_short_len_negative_no_space)
{
    int rc = OK;
    char *format = "Name: %li%li\0";
    size_t n = 11;
    char result_my[11], result_func[11];
    long int arg_1 = -1;
    long int arg_2 = -2;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_li_short_len_negative_one_space)
{
    int rc = OK;
    char *format = "Name: %li %li\0";
    size_t n = 12;
    char result_my[12], result_func[12];
    long int arg_1 = -1;
    long int arg_2 = -2;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_li_short_len_negative_more_spaces)
{
    int rc = OK;
    char *format = "N am e: %li    %li   \0";
    size_t n = 20;
    char result_my[20], result_func[20];
    long int arg_1 = -1;
    long int arg_2 = -2;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST


START_TEST(test_two_li_long_len_negative_more_spaces)
{
    int rc = OK;
    char *format = "N am e: %li    %li   \0";
    size_t n = 35;
    char result_my[35], result_func[35];
    long int arg_1 = -12345;
    long int arg_2 = -345678987654;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST


START_TEST(test_two_li_long_int_len_negative_more_spaces)
{
    int rc = OK;
    char *format = "N am e: %li    %li   \0";
    size_t n = 56;
    char result_my[56], result_func[56];
    long int arg_1 = LONG_MIN;
    long int arg_2 = LONG_MIN;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_more_li_long_int_len_negative_more_spaces)
{
    int rc = OK;
    char *format = "N %li%liam e: %li%li%li    %li   \0";
    size_t n = 136;
    char result_my[136], result_func[136];
    long int arg_1 = LONG_MIN;
    long int arg_2 = LONG_MIN;
    long int arg_3 = LONG_MIN;
    long int arg_4 = LONG_MIN;
    long int arg_5 = LONG_MIN;
    long int arg_6 = LONG_MIN;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_more_li_long_int_len_negative_more_spaces_and_percents)
{
    int rc = OK;
    char *format = "N %li%liam e: %%li%%li%li    %li   \0";
    size_t n = 102;
    char result_my[102], result_func[102];
    long int arg_1 = LONG_MIN;
    long int arg_2 = LONG_MIN;
    long int arg_3 = LONG_MIN;
    long int arg_4 = LONG_MIN;
    long int arg_5 = LONG_MIN;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2, arg_3, arg_4, arg_5);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2, arg_3, arg_4, arg_5);
    // printf("f %s\nm %s\n", result_func, result_my);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST


START_TEST(test_more_li_long_int_len_negative_more_spaces_and_percents_overflow_small)
{
    int rc = OK;
    char *format = "N %li%liam e: %%li%%li%li    %li   \0";
    size_t n = 10;
    char result_my[10], result_func[10];
    long int arg_1 = LONG_MIN;
    long int arg_2 = LONG_MIN;
    long int arg_3 = LONG_MIN;
    long int arg_4 = LONG_MIN;
    long int arg_5 = LONG_MIN;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2, arg_3, arg_4, arg_5);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2, arg_3, arg_4, arg_5);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST


START_TEST(test_more_li_long_int_len_negative_more_spaces_and_percents_overflow_mid)
{
    int rc = OK;
    char *format = "N %li%liam e: %%li%%li%li    %li   \0";
    size_t n = 50;
    char result_my[50], result_func[50];
    long int arg_1 = LONG_MIN;
    long int arg_2 = LONG_MIN;
    long int arg_3 = LONG_MIN;
    long int arg_4 = LONG_MIN;
    long int arg_5 = LONG_MIN;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2, arg_3, arg_4, arg_5);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2, arg_3, arg_4, arg_5);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST


START_TEST(test_more_li_long_int_len_negative_more_spaces_and_percents_memory_over)
{
    int rc = OK;
    char *format = "N %li%liam e: %%li%%li%li    %li   \0";
    size_t n = 200;
    char result_my[200], result_func[200];
    long int arg_1 = LONG_MIN;
    long int arg_2 = LONG_MIN;
    long int arg_3 = LONG_MIN;
    long int arg_4 = LONG_MIN;
    long int arg_5 = LONG_MIN;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2, arg_3, arg_4, arg_5);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2, arg_3, arg_4, arg_5);
    // printf("f %s\nm %s\n", result_func, result_my);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite* test_li(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("spec: li");
    tc_pos = tcase_create("positive");

    // Тест, когда есть одно число маленькой длины
    tcase_add_test(tc_pos, test_one_li_short_len);
    // Тест, когда есть одно число большой длины
    tcase_add_test(tc_pos, test_one_li_long_len);
    // Тест, когда есть одно число граничного значения
    tcase_add_test(tc_pos, test_one_li_long_int_len);
    // Тест, когда есть два числа маленькой длины без пробелов
    tcase_add_test(tc_pos, test_two_li_short_len_no_space);
    // Тест, когда есть два числа маленькой длины с пробелом
    tcase_add_test(tc_pos, test_two_li_short_len_one_space);
    // Тест, когда есть два числа маленькой длины с большим количеством пробелов
    tcase_add_test(tc_pos, test_two_li_short_len_more_spaces);
    // Тест, когда есть два числа маленького размера без пробелов
    tcase_add_test(tc_pos, test_two_li_long_len_no_space);
    // Тест, когда есть два числа большого размера с одним пробелом
    tcase_add_test(tc_pos, test_two_li_long_len_one_space);
    // Тест, когда есть два числа большого размера c несколькими пробелами
    tcase_add_test(tc_pos, test_two_li_long_len_more_spaces);
    // Тест, когда есть два числа граничного значение без пробелов
    tcase_add_test(tc_pos, test_two_li_long_int_len_no_space);
    // Тест, когда есть два числа граничного значение c одним пробелом
    tcase_add_test(tc_pos, test_two_li_long_int_len_with_one_space);
    // Тест, когда есть два числа граничного значение c несколькими пробелами
    tcase_add_test(tc_pos, test_two_li_long_int_len_with_more_spaces);
    // Тест, когда есть одно отрицательное число маленького размера
    tcase_add_test(tc_pos, test_one_li_short_len_negative);
    // Тест, когда есть два отрицательных числа маленького размера без пробела
    tcase_add_test(tc_pos, test_two_li_short_len_negative_no_space);
    // Тест, когда есть два отрицательных числа маленького размера с пробелом
    tcase_add_test(tc_pos, test_two_li_short_len_negative_one_space);
    // Тест, когда есть два отрицательных числа маленького размера с несколькими пробелами
    tcase_add_test(tc_pos, test_two_li_short_len_negative_more_spaces);
    // Тест, когда есть два отрицательных числа большого размера с несколькими пробелами
    tcase_add_test(tc_pos, test_two_li_long_len_negative_more_spaces);
    // Тест, когда есть два отрицательных числа граничного значения с несколькими пробелами
    tcase_add_test(tc_pos, test_two_li_long_int_len_negative_more_spaces);
    // Тест, когда есть несколько отрицательных числа граничного значения с несколькими пробелами
    tcase_add_test(tc_pos, test_more_li_long_int_len_negative_more_spaces);
    // Тест, когда есть несколько отрицательных числа граничного значения с несколькими пробелами и процентами
    tcase_add_test(tc_pos, test_more_li_long_int_len_negative_more_spaces_and_percents);
    // Тест, когда есть несколько отрицательных числа граничного значения с несколькими пробелами и процентами и длиной строки, значительно меньшей, нежели необходимо
    tcase_add_test(tc_pos, test_more_li_long_int_len_negative_more_spaces_and_percents_overflow_small);
    // Тест, когда есть несколько отрицательных числа граничного значения с несколькими пробелами и процентами и длиной строки, в половину меньше, нежели необходимо
    tcase_add_test(tc_pos, test_more_li_long_int_len_negative_more_spaces_and_percents_overflow_mid);
    // Тест, когда есть несколько отрицательных числа граничного значения с несколькими пробелами и процентами и длиной строки, которая значительно больше необходимой
    tcase_add_test(tc_pos, test_more_li_long_int_len_negative_more_spaces_and_percents_memory_over);


    suite_add_tcase(s, tc_pos);

    return s;
}
