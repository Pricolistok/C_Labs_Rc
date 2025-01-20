#include "check_remove.h"

#include "check_each.h"

START_TEST(test_remove_null_key)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    assoc_array_insert(arr, "price1", 144);
    assoc_array_insert(arr, "price2", 145);
    rc = assoc_array_remove(arr, NULL);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_remove_zero_len_key)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    assoc_array_insert(arr, "price1", 144);
    assoc_array_insert(arr, "price2", 145);
    rc = assoc_array_remove(arr, "\0");
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_remove_no_created_arr)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    rc = assoc_array_remove(arr, "price");
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_remove_free_arr)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    arr = assoc_array_create();
    rc = assoc_array_remove(arr, "price1234");
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_remove_not_found)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    rc = assoc_array_remove(arr, "price12342");
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
}
END_TEST


START_TEST(test_remove_one_elem)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price1", 143);

    rc = assoc_array_remove(arr, "price1");
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);

    rc = assoc_array_find(arr, "price1", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_remove_two_elems)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price1", 143);
    assoc_array_insert(arr, "price2", 144);

    rc = assoc_array_remove(arr, "price1");
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);

    rc = assoc_array_find(arr, "price1", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_remove_more_elems_start)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price1", 143);
    assoc_array_insert(arr, "price2", 144);
    assoc_array_insert(arr, "price3", 145);
    assoc_array_insert(arr, "price4", 146);

    rc = assoc_array_remove(arr, "price1");
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);

    rc = assoc_array_find(arr, "price1", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_remove_more_elems_center)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price1", 143);
    assoc_array_insert(arr, "price2", 144);
    assoc_array_insert(arr, "price1", 145);
    assoc_array_insert(arr, "price4", 146);

    rc = assoc_array_remove(arr, "price1");
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);

    rc = assoc_array_find(arr, "price1", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_remove_more_elems_end)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price1", 143);
    assoc_array_insert(arr, "price2", 144);
    assoc_array_insert(arr, "price3", 145);
    assoc_array_insert(arr, "price1", 146);

    rc = assoc_array_remove(arr, "price1");
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);

    rc = assoc_array_find(arr, "price1", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);

    assoc_array_destroy(&arr);
}
END_TEST


Suite* test_remove(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

     s = suite_create("test remove");

    tc_neg = tcase_create("negative");
    // Тест, когда ключ - нуль
    tcase_add_test(tc_neg, test_remove_null_key);
    // Тест, когда ключ нулевой длины
    tcase_add_test(tc_neg, test_remove_zero_len_key);
    // Тест, когда массив не создан
    tcase_add_test(tc_neg, test_remove_no_created_arr);
    // Тест, когда массив пуст
    tcase_add_test(tc_neg, test_remove_free_arr);
    // Тест, когда массив пуст
    tcase_add_test(tc_neg, test_remove_not_found);


    tc_pos = tcase_create("positive");
    // Тест, когда один элемент
    tcase_add_test(tc_pos, test_remove_one_elem);
    // Тест, когда два элемента
    tcase_add_test(tc_pos, test_remove_two_elems);
    // Тест, когда много и искомое в начале
    tcase_add_test(tc_pos, test_remove_more_elems_start);
    // Тест, когда много и искомое в середине
    tcase_add_test(tc_pos, test_remove_more_elems_center);
    // Тест, когда много и искомое в конце
    tcase_add_test(tc_pos, test_remove_more_elems_end);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);


    return s;
}
