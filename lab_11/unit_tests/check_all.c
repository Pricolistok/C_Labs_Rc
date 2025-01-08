#include <stdlib.h>
#include <check.h>
#include <string.h>
#include "process.h"
#include "funcs_for_units.h"

START_TEST(test_one_str_one_num)
{
    int rc = OK;
    char *format = "Name: %s %li\0";
    size_t n = 14;
    char result_my[14], result_func[14];
    char *arg_1_str = "Alina\0";
    long int arg_1_num = 1;
    int result_len_my = snprintf(result_func, n, format, arg_1_str, arg_1_num);
    int result_len_func = my_snprintf(result_my, n, format, arg_1_str, arg_1_num);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_strs_one_num)
{
    int rc = OK;
    char *format = "Name: %s%s %li\0";
    size_t n = 19;
    char result_my[19], result_func[19];
    char *arg_1_str = "Alina\0";
    char *arg_2_str = "Alina\0";
    long int arg_1_num = 1;
    int result_len_my = snprintf(result_func, n, format, arg_1_str, arg_2_str, arg_1_num);
    int result_len_func = my_snprintf(result_my, n, format, arg_1_str, arg_2_str, arg_1_num);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_one_str_two_nums)
{
    int rc = OK;
    char *format = "Name: %s %li%li\0";
    size_t n = 15;
    char result_my[15], result_func[15];
    char *arg_1_str = "Alina\0";
    long int arg_1_num = 1;
    long int arg_2_num = 2;
    int result_len_my = snprintf(result_func, n, format, arg_1_str, arg_1_num, arg_2_num);
    int result_len_func = my_snprintf(result_my, n, format, arg_1_str, arg_1_num, arg_2_num);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_str_two_nums)
{
    int rc = OK;
    char *format = "Name: %s%s %li%li\0";
    size_t n = 20;
    char result_my[20], result_func[20];
    char *arg_1_str = "Alina\0";
    char *arg_2_str = "Alina\0";
    long int arg_1_num = 1;
    long int arg_2_num = 2;
    int result_len_my = snprintf(result_func, n, format, arg_1_str, arg_2_str, arg_1_num, arg_2_num);
    int result_len_func = my_snprintf(result_my, n, format, arg_1_str, arg_2_str, arg_1_num, arg_2_num);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_str_two_nums_mix_with_space)
{
    int rc = OK;
    char *format = "Name: %s%li %s%li\0";
    size_t n = 20;
    char result_my[20], result_func[20];
    char *arg_1_str = "Alina\0";
    char *arg_2_str = "Alina\0";
    long int arg_1_num = 1;
    long int arg_2_num = 2;
    int result_len_my = snprintf(result_func, n, format, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    int result_len_func = my_snprintf(result_my, n, format, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_str_two_nums_mix_with_no_space)
{
    int rc = OK;
    char *format = "Name: %s%li%s%li\0";
    size_t n = 19;
    char result_my[19], result_func[19];
    char *arg_1_str = "Alina\0";
    char *arg_2_str = "Alina\0";
    long int arg_1_num = 1;
    long int arg_2_num = 2;
    int result_len_my = snprintf(result_func, n, format, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    int result_len_func = my_snprintf(result_my, n, format, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_two_str_two_long_int_nums_mix_with_space)
{
    int rc = OK;
    char *format = "Name: %s%li%s%li\0";
    size_t n = 55;
    char result_my[55], result_func[55];
    char *arg_1_str = "Alina\0";
    char *arg_2_str = "Alina\0";
    long int arg_1_num = 9223372036854775807;
    long int arg_2_num = 9223372036854775807;
    int result_len_my = snprintf(result_func, n, format, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    int result_len_func = my_snprintf(result_my, n, format, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_more_str_more_long_int_nums_mix_with_space)
{
    int rc = OK;
    char *format = "%liN%lia%s%sme: %s%li%s%li\0";
    size_t n = 103;
    char result_my[103], result_func[103];
    char *arg_1_str = "Alina\0";
    char *arg_2_str = "Alina\0";
    char *arg_3_str = "Alina\0";
    char *arg_4_str = "Alina\0";
    long int arg_1_num = 9223372036854775807;
    long int arg_2_num = 9223372036854775807;
    long int arg_3_num = 9223372036854775807;
    long int arg_4_num = 9223372036854775807;
    int result_len_my = snprintf(result_func, n, format, arg_3_num, arg_4_num, arg_3_str, arg_4_str, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    int result_len_func = my_snprintf(result_my, n, format, arg_3_num, arg_4_num, arg_3_str, arg_4_str, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_more_str_more_long_int_nums_mix_with_space_overflow_small)
{
    int rc = OK;
    char *format = "%liN%lia%s%sme: %s%li%s%li\0";
    size_t n = 25;
    char result_my[25], result_func[25];
    char *arg_1_str = "Alina\0";
    char *arg_2_str = "Alina\0";
    char *arg_3_str = "Alina\0";
    char *arg_4_str = "Alina\0";
    long int arg_1_num = 9223372036854775807;
    long int arg_2_num = 9223372036854775807;
    long int arg_3_num = 9223372036854775807;
    long int arg_4_num = 9223372036854775807;
    int result_len_my = snprintf(result_func, n, format, arg_3_num, arg_4_num, arg_3_str, arg_4_str, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    int result_len_func = my_snprintf(result_my, n, format, arg_3_num, arg_4_num, arg_3_str, arg_4_str, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    // printf("%d %d\n", result_len_func, result_len_my);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_more_str_more_long_int_nums_mix_with_space_overflow_mid)
{
    int rc = OK;
    char *format = "%liN%lia%s%sme: %s%li%s%li\0";
    size_t n = 50;
    char result_my[50], result_func[50];
    char *arg_1_str = "Alina\0";
    char *arg_2_str = "Alina\0";
    char *arg_3_str = "Alina\0";
    char *arg_4_str = "Alina\0";
    long int arg_1_num = 9223372036854775807;
    long int arg_2_num = 9223372036854775807;
    long int arg_3_num = 9223372036854775807;
    long int arg_4_num = 9223372036854775807;
    int result_len_my = snprintf(result_func, n, format, arg_3_num, arg_4_num, arg_3_str, arg_4_str, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    int result_len_func = my_snprintf(result_my, n, format, arg_3_num, arg_4_num, arg_3_str, arg_4_str, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    // printf("%d %d\n", result_len_func, result_len_my);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_more_str_more_long_int_nums_mix_with_space_overflow_maxi)
{
    int rc = OK;
    char *format = "%liN%lia%s%sme: %s%li%s%li\0";
    size_t n = 99;
    char result_my[99], result_func[99];
    char *arg_1_str = "Alina\0";
    char *arg_2_str = "Alina\0";
    char *arg_3_str = "Alina\0";
    char *arg_4_str = "Alina\0";
    long int arg_1_num = 9223372036854775807;
    long int arg_2_num = 9223372036854775807;
    long int arg_3_num = 9223372036854775807;
    long int arg_4_num = 9223372036854775807;
    int result_len_my = snprintf(result_func, n, format, arg_3_num, arg_4_num, arg_3_str, arg_4_str, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    int result_len_func = my_snprintf(result_my, n, format, arg_3_num, arg_4_num, arg_3_str, arg_4_str, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    // printf("%d %d\n", result_len_func, result_len_my);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    // printf("%s\n%s\n", result_func, result_my);
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_more_str_more_long_int_nums_mix_with_space_more_memory)
{
    int rc = OK;
    char *format = "%liN%lia%s%sme: %s%li%s%li\0";
    size_t n = 200;
    char result_my[200], result_func[200];
    char *arg_1_str = "Alina\0";
    char *arg_2_str = "Alina\0";
    char *arg_3_str = "Alina\0";
    char *arg_4_str = "Alina\0";
    long int arg_1_num = 9223372036854775807;
    long int arg_2_num = 9223372036854775807;
    long int arg_3_num = 9223372036854775807;
    long int arg_4_num = 9223372036854775807;
    int result_len_my = snprintf(result_func, n, format, arg_3_num, arg_4_num, arg_3_str, arg_4_str, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    int result_len_func = my_snprintf(result_my, n, format, arg_3_num, arg_4_num, arg_3_str, arg_4_str, arg_1_str, arg_1_num, arg_2_str, arg_2_num);
    // printf("%d %d\n", result_len_func, result_len_my);
    if (result_len_func != result_len_my || strcmp(result_func, result_my) != 0)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_len_str_is_zero)
{
    int rc = OK;
    char *format = "Name: %s %li\0";
    size_t n = 0;
    char result_my[14], result_func[14];
    char *arg_1_str = "Alina\0";
    long int arg_1_num = 1;
    int result_len_func = snprintf(result_func, n, format, arg_1_str, arg_1_num);
    int result_len_my = my_snprintf(result_my, n, format, arg_1_str, arg_1_num);
    if (result_len_func != result_len_my)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_null_str_and_len_no_zero)
{
    int rc = OK;
    char *format = "Name: %s %li\0";
    size_t n = 0;
    char *result_my = NULL, *result_func = NULL;
    char *arg_1_str = "Alina\0";
    long int arg_1_num = 1;
    int result_len_func = snprintf(result_func, n, format, arg_1_str, arg_1_num);
    int result_len_my = my_snprintf(result_my, n, format, arg_1_str, arg_1_num);
    if (result_len_func != result_len_my)
        rc = ERROR;
    ck_assert_int_eq(rc, OK);
}
END_TEST


Suite* test_all(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("spec: all");
    tc_pos = tcase_create("positive");

    // Тест, когда есть одна строка и одно число
    tcase_add_test(tc_pos, test_one_str_one_num);
    // Тест, когда есть две строки и одно число
    tcase_add_test(tc_pos, test_two_strs_one_num);
    // Тест, когда есть одна строка и два числа
    tcase_add_test(tc_pos, test_one_str_two_nums);
    // Тест, когда есть две строки и два числа
    tcase_add_test(tc_pos, test_two_str_two_nums);
    // Тест, когда есть две строки и два числа, которые перемешаны с пробелами
    tcase_add_test(tc_pos, test_two_str_two_nums_mix_with_space);
    // Тест, когда есть две строки и два числа, которые перемешаны без пробелов
    tcase_add_test(tc_pos, test_two_str_two_nums_mix_with_no_space);
    // Тест, когда есть две строки и два граничных числа, которые перемешаны с пробелами
    tcase_add_test(tc_pos, test_two_str_two_long_int_nums_mix_with_space);
    // Тест, когда есть много строк и много чисел, которые перемешаны с пробелами
    tcase_add_test(tc_pos, test_more_str_more_long_int_nums_mix_with_space);
    // Тест, когда есть много строк и много чисел, которые перемешаны с пробелами
    tcase_add_test(tc_pos, test_more_str_more_long_int_nums_mix_with_space_overflow_small);
    // Тест, когда есть много строк и много чисел, которые перемешаны с пробелами, а также длина строки указана сильно меньше
    tcase_add_test(tc_pos, test_more_str_more_long_int_nums_mix_with_space_overflow_mid);
    // Тест, когда есть много строк и много чисел, которые перемешаны с пробелами, а также длина строки указана в половину меньше от реального
    tcase_add_test(tc_pos, test_more_str_more_long_int_nums_mix_with_space_overflow_maxi);
    // Тест, когда есть много строк и много чисел, которые перемешаны с пробелами, а также длина строки указана сильно больше чем необходима
    tcase_add_test(tc_pos, test_more_str_more_long_int_nums_mix_with_space_more_memory);
    // Тест, когда есть много строк и много чисел, которые перемешаны с пробелами, а также длина строки равна нулю
    tcase_add_test(tc_pos, test_len_str_is_zero);
    // Тест, когда есть много строк и много чисел, которые перемешаны с пробелами, а также длина строки равна нулю и указатель на строку NULL
    tcase_add_test(tc_pos, test_null_str_and_len_no_zero);

    suite_add_tcase(s, tc_pos);

    return s;
}
