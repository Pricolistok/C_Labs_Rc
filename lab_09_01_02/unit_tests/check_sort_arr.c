#include <stdlib.h>
#include <check.h>
#include "errors.h"
#include "process.h"
#include "struct.h"
#include "funcs_for_unit.h"
#include "consts_for_unit.h"


// Тест для проверки сортировки, когда элементы расположены в обратном порядке
START_TEST(simple_back_sort)
{
    int rc;
    item arr_data_result[LEN_DATA_8] = {{"name1", 121, 2, 5}, {"name2", 122, 2, 5}, {"name3", 123, 2, 5}, {"name4", 124, 2, 5}, {"name5", 125, 2, 5}, {"name6", 126, 2, 5}, {"name7", 127, 2, 5}, {"name8", 128, 2, 5}};
    item arr_data_in[LEN_DATA_8] = {{"name8", 128, 2, 5}, {"name7", 127, 2, 5}, {"name6", 126, 2, 5}, {"name5", 125, 2, 5}, {"name4", 124, 2, 5}, {"name3", 123, 2, 5}, {"name2", 122, 2, 5}, {"name1", 121, 2, 5}};
    sort_arr(arr_data_in, LEN_DATA_8);
    rc = check_arr(arr_data_in, arr_data_result, LEN_DATA_8);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест для проверки сортировки, когда элементы расположены в упорядоченном виде
START_TEST(simple_straight_sort)
{
    int rc;
    item arr_data_result[LEN_DATA_8] = {{"name1", 121, 2, 5}, {"name2", 122, 2, 5}, {"name3", 123, 2, 5}, {"name4", 124, 2, 5}, {"name5", 125, 2, 5}, {"name6", 126, 2, 5}, {"name7", 127, 2, 5}, {"name8", 128, 2, 5}};
    item arr_data_in[LEN_DATA_8] = {{"name1", 121, 2, 5}, {"name2", 122, 2, 5}, {"name3", 123, 2, 5}, {"name4", 124, 2, 5}, {"name5", 125, 2, 5}, {"name6", 126, 2, 5}, {"name7", 127, 2, 5}, {"name8", 128, 2, 5}};
    sort_arr(arr_data_in, LEN_DATA_8);
    rc = check_arr(arr_data_in, arr_data_result, LEN_DATA_8);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест для проверки сортировки, когда элементы расположены в случайном порядке
START_TEST(simple_sort)
{
    int rc;
    item arr_data_in[LEN_DATA_8] = {{"name3", 123, 2, 5}, {"name4", 124, 2, 5}, {"name1", 121, 2, 5}, {"name2", 122, 2, 5}, {"name5", 125, 2, 5}, {"name6", 126, 2, 5}, {"name8", 128, 2, 5}, {"name7", 127, 2, 5}};
    item arr_data_result[LEN_DATA_8] = {{"name1", 121, 2, 5}, {"name2", 122, 2, 5}, {"name3", 123, 2, 5}, {"name4", 124, 2, 5}, {"name5", 125, 2, 5}, {"name6", 126, 2, 5}, {"name7", 127, 2, 5}, {"name8", 128, 2, 5}};
    sort_arr(arr_data_in, LEN_DATA_8);
    rc = check_arr(arr_data_in, arr_data_result, LEN_DATA_8);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест для проверки сортировки, когда элемент всего один
START_TEST(simple_sort_with_one_elem)
{
    int rc;
    item arr_data_in[LEN_DATA_8] = {{"name3", 123, 2, 5}};
    item arr_data_result[LEN_DATA_8] = {{"name3", 123, 2, 5}};
    sort_arr(arr_data_in, LEN_DATA_8);
    rc = check_arr(arr_data_in, arr_data_result, LEN_DATA_1);
    ck_assert_int_eq(rc, OK);
}
END_TEST

// Тест для проверки сортировки, когда элементов очень много
START_TEST(simple_sort_with_more_structs)
{
    int rc;
    item arr_data_in[LEN_DATA_100] = {{"name0", 100, 2, 5}, {"name1", 99, 2, 5}, {"name2", 98, 2, 5}, {"name3", 97, 2, 5}, {"name4", 96, 2, 5}, {"name5", 95, 2, 5}, {"name6", 94, 2, 5}, {"name7", 93, 2, 5}, {"name8", 92, 2, 5}, {"name9", 91, 2, 5}, {"name10", 90, 2, 6}, {"name11", 89, 2, 6}, {"name12", 88, 2, 6}, {"name13", 87, 2, 6}, {"name14", 86, 2, 6}, {"name15", 85, 2, 6}, {"name16", 84, 2, 6}, {"name17", 83, 2, 6}, {"name18", 82, 2, 6}, {"name19", 81, 2, 6}, {"name20", 80, 2, 6}, {"name21", 79, 2, 6}, {"name22", 78, 2, 6}, {"name23", 77, 2, 6}, {"name24", 76, 2, 6}, {"name25", 75, 2, 6}, {"name26", 74, 2, 6}, {"name27", 73, 2, 6}, {"name28", 72, 2, 6}, {"name29", 71, 2, 6}, {"name30", 70, 2, 6}, {"name31", 69, 2, 6}, {"name32", 68, 2, 6}, {"name33", 67, 2, 6}, {"name34", 66, 2, 6}, {"name35", 65, 2, 6}, {"name36", 64, 2, 6}, {"name37", 63, 2, 6}, {"name38", 62, 2, 6}, {"name39", 61, 2, 6}, {"name40", 60, 2, 6}, {"name41", 59, 2, 6}, {"name42", 58, 2, 6}, {"name43", 57, 2, 6}, {"name44", 56, 2, 6}, {"name45", 55, 2, 6}, {"name46", 54, 2, 6}, {"name47", 53, 2, 6}, {"name48", 52, 2, 6}, {"name49", 51, 2, 6}, {"name50", 50, 2, 6}, {"name51", 49, 2, 6}, {"name52", 48, 2, 6}, {"name53", 47, 2, 6}, {"name54", 46, 2, 6}, {"name55", 45, 2, 6}, {"name56", 44, 2, 6}, {"name57", 43, 2, 6}, {"name58", 42, 2, 6}, {"name59", 41, 2, 6}, {"name60", 40, 2, 6}, {"name61", 39, 2, 6}, {"name62", 38, 2, 6}, {"name63", 37, 2, 6}, {"name64", 36, 2, 6}, {"name65", 35, 2, 6}, {"name66", 34, 2, 6}, {"name67", 33, 2, 6}, {"name68", 32, 2, 6}, {"name69", 31, 2, 6}, {"name70", 30, 2, 6}, {"name71", 29, 2, 6}, {"name72", 28, 2, 6}, {"name73", 27, 2, 6}, {"name74", 26, 2, 6}, {"name75", 25, 2, 6}, {"name76", 24, 2, 6}, {"name77", 23, 2, 6}, {"name78", 22, 2, 6}, {"name79", 21, 2, 6}, {"name80", 20, 2, 6}, {"name81", 19, 2, 6}, {"name82", 18, 2, 6}, {"name83", 17, 2, 6}, {"name84", 16, 2, 6}, {"name85", 15, 2, 6}, {"name86", 14, 2, 6}, {"name87", 13, 2, 6}, {"name88", 12, 2, 6}, {"name89", 11, 2, 6}, {"name90", 10, 2, 6}, {"name91", 9, 2, 6}, {"name92", 8, 2, 6}, {"name93", 7, 2, 6}, {"name94", 6, 2, 6}, {"name95", 5, 2, 6}, {"name96", 4, 2, 6}, {"name97", 3, 2, 6}, {"name98", 2, 2, 6}, {"name99", 1, 2, 6}};
    item arr_data_result[LEN_DATA_100] = {{"name99", 1, 2, 6}, {"name98", 2, 2, 6}, {"name97", 3, 2, 6}, {"name96", 4, 2, 6}, {"name95", 5, 2, 6}, {"name94", 6, 2, 6}, {"name93", 7, 2, 6}, {"name92", 8, 2, 6}, {"name91", 9, 2, 6}, {"name90", 10, 2, 6}, {"name89", 11, 2, 6}, {"name88", 12, 2, 6}, {"name87", 13, 2, 6}, {"name86", 14, 2, 6}, {"name85", 15, 2, 6}, {"name84", 16, 2, 6}, {"name83", 17, 2, 6}, {"name82", 18, 2, 6}, {"name81", 19, 2, 6}, {"name80", 20, 2, 6}, {"name79", 21, 2, 6}, {"name78", 22, 2, 6}, {"name77", 23, 2, 6}, {"name76", 24, 2, 6}, {"name75", 25, 2, 6}, {"name74", 26, 2, 6}, {"name73", 27, 2, 6}, {"name72", 28, 2, 6}, {"name71", 29, 2, 6}, {"name70", 30, 2, 6}, {"name69", 31, 2, 6}, {"name68", 32, 2, 6}, {"name67", 33, 2, 6}, {"name66", 34, 2, 6}, {"name65", 35, 2, 6}, {"name64", 36, 2, 6}, {"name63", 37, 2, 6}, {"name62", 38, 2, 6}, {"name61", 39, 2, 6}, {"name60", 40, 2, 6}, {"name59", 41, 2, 6}, {"name58", 42, 2, 6}, {"name57", 43, 2, 6}, {"name56", 44, 2, 6}, {"name55", 45, 2, 6}, {"name54", 46, 2, 6}, {"name53", 47, 2, 6}, {"name52", 48, 2, 6}, {"name51", 49, 2, 6}, {"name50", 50, 2, 6}, {"name49", 51, 2, 6}, {"name48", 52, 2, 6}, {"name47", 53, 2, 6}, {"name46", 54, 2, 6}, {"name45", 55, 2, 6}, {"name44", 56, 2, 6}, {"name43", 57, 2, 6}, {"name42", 58, 2, 6}, {"name41", 59, 2, 6}, {"name40", 60, 2, 6}, {"name39", 61, 2, 6}, {"name38", 62, 2, 6}, {"name37", 63, 2, 6}, {"name36", 64, 2, 6}, {"name35", 65, 2, 6}, {"name34", 66, 2, 6}, {"name33", 67, 2, 6}, {"name32", 68, 2, 6}, {"name31", 69, 2, 6}, {"name30", 70, 2, 6}, {"name29", 71, 2, 6}, {"name28", 72, 2, 6}, {"name27", 73, 2, 6}, {"name26", 74, 2, 6}, {"name25", 75, 2, 6}, {"name24", 76, 2, 6}, {"name23", 77, 2, 6}, {"name22", 78, 2, 6}, {"name21", 79, 2, 6}, {"name20", 80, 2, 6}, {"name19", 81, 2, 6}, {"name18", 82, 2, 6}, {"name17", 83, 2, 6}, {"name16", 84, 2, 6}, {"name15", 85, 2, 6}, {"name14", 86, 2, 6}, {"name13", 87, 2, 6}, {"name12", 88, 2, 6}, {"name11", 89, 2, 6}, {"name10", 90, 2, 6}, {"name9", 91, 2, 5}, {"name8", 92, 2, 5}, {"name7", 93, 2, 5}, {"name6", 94, 2, 5}, {"name5", 95, 2, 5}, {"name4", 96, 2, 5}, {"name3", 97, 2, 5}, {"name2", 98, 2, 5}, {"name1", 99, 2, 5}, {"name0", 100, 2, 5}};
    sort_arr(arr_data_in, LEN_DATA_100);
    rc = check_arr(arr_data_in, arr_data_result, LEN_DATA_100);
    ck_assert_int_eq(rc, OK);
}
END_TEST


Suite* sort_array(void)
{
    Suite *s;
    TCase *tc;
    
    s = suite_create("sort array");
    
    tc = tcase_create("test");

    tcase_add_test(tc, simple_back_sort);
    tcase_add_test(tc, simple_straight_sort);
    tcase_add_test(tc, simple_sort);
    tcase_add_test(tc, simple_sort_with_one_elem);
    tcase_add_test(tc, simple_sort_with_more_structs);

    suite_add_tcase(s, tc);

    return s;
}
