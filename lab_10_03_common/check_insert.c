#include "check_insert.h"


START_TEST(test_insert_null_key)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;

    arr = assoc_array_create();
    rc = assoc_array_insert(arr, NULL, 143);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_insert_zero_len_key)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;

    arr = assoc_array_create();
    rc = assoc_array_insert(arr, "\0", 143);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_insert_no_created_arr)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;

    rc = assoc_array_insert(arr, "price", 143);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_insert_exist_elem)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    rc = assoc_array_insert(arr, "price", 144);
    ck_assert_int_eq(rc, ASSOC_ARRAY_KEY_EXISTS);
    assoc_array_destroy(&arr);
}
END_TEST


START_TEST(test_insert_one_elem)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;

    arr = assoc_array_create();
    rc = assoc_array_insert(arr, "price", 143);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_insert_two_elems)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;

    arr = assoc_array_create();
    rc = assoc_array_insert(arr, "price", 143);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(arr, "price2", 144);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_insert_more_elems)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;

    arr = assoc_array_create();
    rc = assoc_array_insert(arr, "price", 143);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(arr, "price2", 144);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(arr, "price3", 145);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(arr, "price4", 146);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_insert(arr, "price5", 147);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    assoc_array_destroy(&arr);
}
END_TEST

Suite* test_insert(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

     s = suite_create("test insert");

    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, test_insert_null_key);
    tcase_add_test(tc_neg, test_insert_zero_len_key);
    tcase_add_test(tc_neg, test_insert_no_created_arr);
    tcase_add_test(tc_neg, test_insert_exist_elem);


    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, test_insert_one_elem);
    tcase_add_test(tc_pos, test_insert_two_elems);
    tcase_add_test(tc_pos, test_insert_more_elems);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);


    return s;
}