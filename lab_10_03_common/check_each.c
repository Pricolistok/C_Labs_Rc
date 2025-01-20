#include "check_each.h"


void action(const char *key, int *num, void *param)
{
    (void)key;
    if (!num)
        return;
    if (param != NULL)
        *num = *num - 100;
    else
        *num = *num + 100;
}

START_TEST(test_each_null_action)
{
    assoc_array_t arr = NULL;
    void *param = NULL;
    assoc_array_error_t rc;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    rc = assoc_array_each(arr, NULL, param);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_each_no_created_arr)
{
    assoc_array_t arr = NULL;
    void *param = NULL;
    assoc_array_error_t rc;
    rc = assoc_array_each(arr, NULL, param);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_each_one_elem_param_null)
{
    assoc_array_t arr = NULL;
    void *param = NULL;
    assoc_array_error_t rc;
    int *num;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    rc = assoc_array_each(arr, action, param);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_find(arr, "price", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 243);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_each_two_elems_param_null)
{
    assoc_array_t arr = NULL;
    void *param = NULL;
    assoc_array_error_t rc;
    int *num;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price1", 143);
    assoc_array_insert(arr, "price2", 144);
    rc = assoc_array_each(arr, action, param);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_find(arr, "price1", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 243);
    rc = assoc_array_find(arr, "price2", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 244);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_each_more_elems_param_null)
{
    assoc_array_t arr = NULL;
    void *param = NULL;
    assoc_array_error_t rc;
    int *num;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price1", 143);
    assoc_array_insert(arr, "price2", 144);
    assoc_array_insert(arr, "price3", 145);
    assoc_array_insert(arr, "price4", 146);
    assoc_array_insert(arr, "price5", 147);
    assoc_array_insert(arr, "price6", 148);
    assoc_array_insert(arr, "price7", 149);
    assoc_array_insert(arr, "price8", 150);
    rc = assoc_array_each(arr, action, param);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_find(arr, "price1", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 243);
    rc = assoc_array_find(arr, "price2", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 244);
    rc = assoc_array_find(arr, "price3", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 245);
    rc = assoc_array_find(arr, "price4", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 246);
    rc = assoc_array_find(arr, "price5", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 247);
    rc = assoc_array_find(arr, "price6", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 248);
    rc = assoc_array_find(arr, "price7", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 249);
    rc = assoc_array_find(arr, "price8", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 250);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_each_one_elem_param_not_null)
{
    assoc_array_t arr = NULL;
    void *param = "n";
    assoc_array_error_t rc;
    int *num;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price", 143);
    rc = assoc_array_each(arr, action, param);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_find(arr, "price", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 43);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_each_two_elems_param_not_null)
{
    assoc_array_t arr = NULL;
    void *param = "n";
    assoc_array_error_t rc;
    int *num;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price1", 143);
    assoc_array_insert(arr, "price2", 144);
    rc = assoc_array_each(arr, action, param);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_find(arr, "price1", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 43);
    rc = assoc_array_find(arr, "price2", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 44);
    assoc_array_destroy(&arr);
}
END_TEST

START_TEST(test_each_more_elems_param_not_null)
{
    assoc_array_t arr = NULL;
    void *param = "n";
    assoc_array_error_t rc;
    int *num;

    arr = assoc_array_create();
    assoc_array_insert(arr, "price1", 143);
    assoc_array_insert(arr, "price2", 144);
    assoc_array_insert(arr, "price3", 145);
    assoc_array_insert(arr, "price4", 146);
    assoc_array_insert(arr, "price5", 147);
    assoc_array_insert(arr, "price6", 148);
    assoc_array_insert(arr, "price7", 149);
    assoc_array_insert(arr, "price8", 150);
    rc = assoc_array_each(arr, action, param);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    rc = assoc_array_find(arr, "price1", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 43);
    rc = assoc_array_find(arr, "price2", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 44);
    rc = assoc_array_find(arr, "price3", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 45);
    rc = assoc_array_find(arr, "price4", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 46);
    rc = assoc_array_find(arr, "price5", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 47);
    rc = assoc_array_find(arr, "price6", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 48);
    rc = assoc_array_find(arr, "price7", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 49);
    rc = assoc_array_find(arr, "price8", &num);
    ck_assert_int_eq(rc, ASSOC_ARRAY_OK);
    ck_assert_int_eq(*num, 50);
    assoc_array_destroy(&arr);
}
END_TEST

Suite* test_each(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

     s = suite_create("test each");

    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, test_each_null_action);
    tcase_add_test(tc_neg, test_each_no_created_arr);


    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, test_each_one_elem_param_null);
    tcase_add_test(tc_pos, test_each_two_elems_param_null);
    tcase_add_test(tc_pos, test_each_more_elems_param_null);
    tcase_add_test(tc_pos, test_each_one_elem_param_not_null);
    tcase_add_test(tc_pos, test_each_two_elems_param_not_null);
    tcase_add_test(tc_pos, test_each_more_elems_param_not_null);

    suite_add_tcase(s, tc_neg);
    suite_add_tcase(s, tc_pos);


    return s;
}