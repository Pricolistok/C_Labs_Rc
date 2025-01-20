#include "check_clear.h"


START_TEST(test_clear_no_create_arr)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc = assoc_array_clear(arr);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    ck_assert_ptr_null(arr);
}
END_TEST

START_TEST(test_clear_free_arr)
{
    assoc_array_error_t rc;
    assoc_array_t arr = NULL;

    arr = assoc_array_create();
    rc = assoc_array_clear(arr);
    ck_assert_ptr_nonnull(arr);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_clear_arr_with_one_elem)
{
    assoc_array_error_t rc;
    assoc_array_t arr = NULL;

    arr = assoc_array_create();

    assoc_array_insert(arr, "price", 143);
    rc = assoc_array_clear(arr);
    ck_assert_ptr_nonnull(arr);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_clear_arr_with_two_elems)
{
    assoc_array_error_t rc;
    assoc_array_t arr = NULL;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    assoc_array_insert(arr, "secondprice", 145);
    rc = assoc_array_clear(arr);
    ck_assert_ptr_nonnull(arr);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_clear_arr_with_more_elems)
{
    assoc_array_error_t rc;
    assoc_array_t arr = NULL;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    assoc_array_insert(arr, "secondprice", -11145);
    assoc_array_insert(arr, "secondprice1", 122145);
    assoc_array_insert(arr, "secondprice2", 1452222);
    assoc_array_insert(arr, "secondprice45678", 145456);
    rc = assoc_array_clear(arr);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
}
END_TEST

Suite* test_clear(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("test clear");

    tc_neg = tcase_create("negative");
    // Тест, когда очищается не созданный массив
    tcase_add_test(tc_neg, test_clear_no_create_arr);


    tc_pos = tcase_create("positive");
    // Тест, когда очищается пустой массив
    tcase_add_test(tc_pos, test_clear_free_arr);
    // Тест, когда очищается массив с одним элементом
    tcase_add_test(tc_pos, test_clear_arr_with_one_elem);
    // Тест, когда очищается массив с двумя элементами
    tcase_add_test(tc_pos, test_clear_arr_with_two_elems);
    // Тест, когда очищается массив с большим количеством элементов
    tcase_add_test(tc_pos, test_clear_arr_with_more_elems);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);


    return s;
}