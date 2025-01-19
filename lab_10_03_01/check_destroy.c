#include "check_destroy.h"

START_TEST(test_destroy_null_arr)
{
    assoc_array_error_t rc = assoc_array_clear(NULL);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
}
END_TEST

START_TEST(test_destroy_no_create_arr)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc = assoc_array_clear(arr);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    ck_assert_ptr_null(arr);
}
END_TEST

START_TEST(test_destroy_free_arr)
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

START_TEST(test_destroy_arr_with_one_elem)
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

START_TEST(test_destroy_arr_with_two_elems)
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

START_TEST(test_destroy_arr_with_more_elems)
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

Suite* test_destroy(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("test destroy");

    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, test_destroy_no_create_arr);
    tcase_add_test(tc_neg, test_destroy_null_arr);


    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, test_destroy_free_arr);
    tcase_add_test(tc_pos, test_destroy_arr_with_one_elem);
    tcase_add_test(tc_pos, test_destroy_arr_with_two_elems);
    tcase_add_test(tc_pos, test_destroy_arr_with_more_elems);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);


    return s;
}