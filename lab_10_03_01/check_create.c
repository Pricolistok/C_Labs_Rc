#include "check_clear.h"


START_TEST(test_create_simple)
{
    assoc_array_t arr = NULL;
    assoc_array_error_t rc = assoc_array_clear(arr);
    ck_assert_int_eq(rc, ASSOC_ARRAY_INVALID_PARAM);
    ck_assert_ptr_null(arr);
}
END_TEST

Suite* test_create(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("test create");

    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, test_create_simple);

    suite_add_tcase(s, tc_pos);


    return s;
}