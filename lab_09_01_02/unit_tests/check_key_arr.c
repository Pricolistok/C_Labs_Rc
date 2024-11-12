#include <stdlib.h>
#include <check.h>
#include "errors.h"
#include "process.h"
#include "struct.h"
#include "funcs_for_unit.h"
#include "consts_for_unit.h"

// Тест для обработки случая, когда в массиве есть всего один искомый элемент и он находится в конце
START_TEST(find_one_elem_in_finish)
{
    int rc, rc_res;
    int arr_for_print[LEN_DATA_8];
    int arr_for_print_result[LEN_DATA_8] = {7};
    item arr_data_in[LEN_DATA_8] = {{"name8", 128, 2, 5}, {"name7", 127, 2, 5}, {"name6", 126, 2, 5}, {"name5", 125, 2, 5}, {"name4", 124, 2, 5}, {"name3", 123, 2, 5}, {"name2", 122, 2, 5}, {"name1", 121, 2, 5}};
    char *name = "name1\0";
    rc = find_item(arr_data_in, strlen(name), name, arr_for_print);
    rc_res = check_arr_for_print(arr_for_print, arr_for_print_result, rc);
    ck_assert_int_eq(rc_res, OK);
}
END_TEST

// Тест для обработки случая, когда в массиве есть всего один искомый элемент и он находится в центре
START_TEST(find_one_elem_in_center)
{
    int rc, rc_res;
    int arr_for_print[LEN_DATA_8];
    int arr_for_print_result[LEN_DATA_8] = {3};
    item arr_data_in[LEN_DATA_8] = {{"name8", 128, 2, 5}, {"name7", 127, 2, 5}, {"name6", 126, 2, 5}, {"name1", 125, 2, 5}, {"name4", 124, 2, 5}, {"name3", 123, 2, 5}, {"name2", 122, 2, 5}, {"name3", 121, 2, 5}};
    char *name = "name1\0";
    rc = find_item(arr_data_in, LEN_DATA_8, name, arr_for_print);
    rc_res = check_arr_for_print(arr_for_print, arr_for_print_result, rc);
    ck_assert_int_eq(rc_res, OK);
}
END_TEST

// Тест для обработки случая, когда в массиве есть всего один искомый элемент и он находится в начале
START_TEST(find_one_elem_in_start)
{
    int rc, rc_res;
    int arr_for_print[LEN_DATA_8];
    int arr_for_print_result[LEN_DATA_8] = {0};
    item arr_data_in[LEN_DATA_8] = {{"name1", 128, 2, 5}, {"name7", 127, 2, 5}, {"name6", 126, 2, 5}, {"name9", 125, 2, 5}, {"name4", 124, 2, 5}, {"name3", 123, 2, 5}, {"name2", 122, 2, 5}, {"name3", 121, 2, 5}};
    char *name = "name1\0";
    rc = find_item(arr_data_in, LEN_DATA_8, name, arr_for_print);
    rc_res = check_arr_for_print(arr_for_print, arr_for_print_result, rc);
    ck_assert_int_eq(rc_res, OK);
}
END_TEST

// Тест для обработки случая, когда в массиве есть несколько искомых элементов
START_TEST(find_several_elems)
{
    int rc, rc_res;
    int arr_for_print[LEN_DATA_8];
    int arr_for_print_result[LEN_DATA_8] = {0, 1, 7};
    item arr_data_in[LEN_DATA_8] = {{"name1", 128, 2, 5}, {"name1", 127, 2, 5}, {"name6", 126, 2, 5}, {"name5", 125, 2, 5}, {"name4", 124, 2, 5}, {"name3", 123, 2, 5}, {"name2", 122, 2, 5}, {"name1", 121, 2, 5}};
    char *name = "name1\0";
    rc = find_item(arr_data_in, LEN_DATA_8, name, arr_for_print);
    rc_res = check_arr_for_print(arr_for_print, arr_for_print_result, rc);
    ck_assert_int_eq(rc_res, OK);
}
END_TEST

// Тест для обработки случая, когда в массиве все элементы являются искомыми
START_TEST(find_all_elems)
{
    int rc, rc_res;
    int arr_for_print[LEN_DATA_8];
    int arr_for_print_result[LEN_DATA_8] = {0, 1, 2, 3, 4, 5, 6, 7};
    item arr_data_in[LEN_DATA_8] = {{"name1", 128, 2, 5}, {"name1", 127, 2, 5}, {"name1", 126, 2, 5}, {"name1", 125, 2, 5}, {"name1", 124, 2, 5}, {"name1", 123, 2, 5}, {"name1", 122, 2, 5}, {"name1", 121, 2, 5}};
    char *name = "name1\0";
    rc = find_item(arr_data_in, LEN_DATA_8, name, arr_for_print);
    rc_res = check_arr_for_print(arr_for_print, arr_for_print_result, rc);
    ck_assert_int_eq(rc_res, OK);
}
END_TEST

// Тест для обработки случая, когда в массиве нет искомых элементов
START_TEST(find_zero_elems)
{
    int rc, rc_res;
    int arr_for_print[LEN_DATA_8];
    int arr_for_print_result[LEN_DATA_8];
    item arr_data_in[LEN_DATA_8] = {{"name8", 128, 2, 5}, {"name7", 127, 2, 5}, {"name6", 126, 2, 5}, {"name5", 125, 2, 5}, {"name4", 124, 2, 5}, {"name3", 123, 2, 5}, {"name2", 122, 2, 5}, {"name1", 121, 2, 5}};
    char *name = "name123\0";
    rc = find_item(arr_data_in, LEN_DATA_8, name, arr_for_print);
    rc_res = check_arr_for_print(arr_for_print, arr_for_print_result, rc);
    ck_assert_int_eq(rc_res, 0);
}
END_TEST

// Тест для обработки случая, когда в массиве есть длинное имя
START_TEST(find_long_name)
{
    int rc, rc_res;
    int arr_for_print[LEN_DATA_8];
    int arr_for_print_result[LEN_DATA_8] = {0};
    item arr_data_in[LEN_DATA_8] = {{"name8nnnnnnmmmmmmyyyy", 128, 2, 21}, {"name7", 127, 2, 5}, {"name6", 126, 2, 5}, {"name5", 125, 2, 5}, {"name4", 124, 2, 5}, {"name3", 123, 2, 5}, {"name2", 122, 2, 5}, {"name1", 121, 2, 5}};
    char *name = "name8nnnnnnmmmmmm\0";
    rc = find_item(arr_data_in, LEN_DATA_8, name, arr_for_print);
    rc_res = check_arr_for_print(arr_for_print, arr_for_print_result, rc);
    ck_assert_int_eq(rc_res, 0);
}
END_TEST




Suite* key_array(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("sort array");
    
    // Похитивные тесты
    tc = tcase_create("positives");

    tcase_add_test(tc, find_one_elem_in_start);
    tcase_add_test(tc, find_one_elem_in_center);
    tcase_add_test(tc, find_one_elem_in_finish);
    tcase_add_test(tc, find_several_elems);
    tcase_add_test(tc, find_all_elems);
    tcase_add_test(tc, find_long_name);
    suite_add_tcase(s, tc);

    // Негативные тесты
    tc = tcase_create("negatives");

    tcase_add_test(tc, find_zero_elems);

    suite_add_tcase(s, tc);

    return s;
}
