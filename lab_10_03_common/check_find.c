#include "check_find.h"


START_TEST(test_find_null_key)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    rc = assoc_array_find(arr, NULL, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_null_arr)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    rc = assoc_array_find(NULL, "price", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_null_num)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    rc = assoc_array_find(arr, "price", NULL);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_zero_len_key)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;

    arr = assoc_array_create();
    assoc_array_insert(NULL, "price", 143);
    rc = assoc_array_find(arr, "", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_no_created_arr)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;

    assoc_array_insert(arr, "price", 143);
    rc = assoc_array_find(arr, "price", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_free_arr)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    rc = assoc_array_find(arr, "price", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_no_elem)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    rc = assoc_array_find(arr, "price1", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_one_elem)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    rc = assoc_array_find(arr, "price", &num);
    ck_assert_int_eq(*num, 143);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_two_elems)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    assoc_array_insert(arr, "price2", 144);
    rc = assoc_array_find(arr, "price", &num);
    ck_assert_int_eq(*num, 143);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_more_elems_in_start)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    assoc_array_insert(arr, "price2", 144);
    assoc_array_insert(arr, "price3", 145);
    assoc_array_insert(arr, "price4", 146);
    assoc_array_insert(arr, "price5", 147);
    rc = assoc_array_find(arr, "price", &num);
    ck_assert_int_eq(*num, 143);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_more_elems_in_center)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    assoc_array_insert(arr, "price2", 144);
    assoc_array_insert(arr, "price3", 145);
    assoc_array_insert(arr, "price4", 146);
    assoc_array_insert(arr, "price5", 147);
    rc = assoc_array_find(arr, "price3", &num);
    ck_assert_int_eq(*num, 145);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_more_elems_in_end)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    assoc_array_insert(arr, "price2", 144);
    assoc_array_insert(arr, "price3", 145);
    assoc_array_insert(arr, "price4", 146);
    assoc_array_insert(arr, "price5", 147);
    rc = assoc_array_find(arr, "price5", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 147);
    assoc_array_destroy(&arr);
}
END_TEST


Suite* test_find(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

     s = suite_create("test find");

    tc_neg = tcase_create("negative");
    // Тест, когда ключ нуль
    tcase_add_test(tc_neg, test_find_null_key);
    // Тест, когда массив нуль
    tcase_add_test(tc_neg, test_find_null_arr);
    // Тест, когда число нуль
    tcase_add_test(tc_neg, test_find_null_num);
    // Тетс, когда длина ключа нуль
    tcase_add_test(tc_neg, test_find_zero_len_key);
    // Тест, когда массив не создан
    tcase_add_test(tc_neg, test_find_no_created_arr);
    // Тест, когда массив пуст
    tcase_add_test(tc_neg, test_find_free_arr);
    // Тест, когда элементов не найдено
    tcase_add_test(tc_neg, test_find_no_elem);


    tc_pos = tcase_create("positive");
    // Тест, когда олин элемент
    tcase_add_test(tc_pos, test_find_one_elem);
    // Тест, когда два элемента
    tcase_add_test(tc_pos, test_find_two_elems);
    // Тест, когда много элеентов и искомый в начале
    tcase_add_test(tc_pos, test_find_more_elems_in_start);
    // Тест, когда много элеентов и искомый в середине
    tcase_add_test(tc_pos, test_find_more_elems_in_center);
    // Тест, когда много элеентов и искомый в конце
    tcase_add_test(tc_pos, test_find_more_elems_in_end);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);


    return s;
}