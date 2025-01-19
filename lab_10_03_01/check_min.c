#include "check_min.h"

START_TEST(test_find_min_null_arr)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price11", 143);
    rc = assoc_array_min(NULL, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_min_null_num)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price11", 143);
    rc = assoc_array_min(arr, NULL);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_min_no_created_arr)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;

    assoc_array_insert(arr, "price11", 143);
    rc = assoc_array_min(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_min_free_arr)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    rc = assoc_array_min(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_min_no_elem)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    rc = assoc_array_min(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_NOT_FOUND);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_min_one_elem)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    assoc_array_insert(arr, "price11", 143);
    rc = assoc_array_min(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 143);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_min_two_elems)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    assoc_array_insert(arr, "price11", 143);
    assoc_array_insert(arr, "price", 159);
    rc = assoc_array_min(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 159);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_min_more_elems_in_start)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 159);
    assoc_array_insert(arr, "price2", 144);
    assoc_array_insert(arr, "price3", 145);
    assoc_array_insert(arr, "price4", 146);
    assoc_array_insert(arr, "price11", 147);
    rc = assoc_array_min(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 159);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_min_more_elems_in_center)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    assoc_array_insert(arr, "price11", 143);
    assoc_array_insert(arr, "price2", 144);
    assoc_array_insert(arr, "price", 159);
    assoc_array_insert(arr, "price4", 146);
    assoc_array_insert(arr, "price3", 147);
    rc = assoc_array_min(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 159);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_find_min_more_elems_in_end)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc;
    int *num = NULL;
    arr = assoc_array_create();
    assoc_array_insert(arr, "price11", 143);
    assoc_array_insert(arr, "price2", 144);
    assoc_array_insert(arr, "price3", 145);
    assoc_array_insert(arr, "price4", 146);
    assoc_array_insert(arr, "price", 159);
    rc = assoc_array_min(arr, &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 159);
    assoc_array_destroy(&arr);
}
END_TEST


Suite* test_min(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

     s = suite_create("test min");

    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, test_find_min_null_arr);
    tcase_add_test(tc_neg, test_find_min_null_num);
    tcase_add_test(tc_neg, test_find_min_no_created_arr);
    tcase_add_test(tc_neg, test_find_min_free_arr);
    tcase_add_test(tc_neg, test_find_min_no_elem);


    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, test_find_min_one_elem);
    tcase_add_test(tc_pos, test_find_min_two_elems);
    tcase_add_test(tc_pos, test_find_min_more_elems_in_start);
    tcase_add_test(tc_pos, test_find_min_more_elems_in_center);
    tcase_add_test(tc_pos, test_find_min_more_elems_in_end);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);


    return s;
}

