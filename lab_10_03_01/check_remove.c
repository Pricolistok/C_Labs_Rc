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
    tcase_add_test(tc_neg, test_remove_null_key);
    tcase_add_test(tc_neg, test_remove_zero_len_key);
    tcase_add_test(tc_neg, test_remove_no_created_arr);
    tcase_add_test(tc_neg, test_remove_free_arr);
    tcase_add_test(tc_neg, test_remove_not_found);


    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, test_remove_one_elem);
    tcase_add_test(tc_pos, test_remove_two_elems);
    tcase_add_test(tc_pos, test_remove_more_elems_start);
    tcase_add_test(tc_pos, test_remove_more_elems_center);
    tcase_add_test(tc_pos, test_remove_more_elems_end);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);


    return s;
}
