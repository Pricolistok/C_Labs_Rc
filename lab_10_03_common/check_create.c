#include "check_create.h"


START_TEST(test_create_simple)
{
    assoc_array_t arr = NULL;
    arr = assoc_array_create();
    ck_assert_ptr_nonnull(arr);
    assoc_array_destroy(&arr);
}
END_TEST

Suite* test_create(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("test create");

    tc_pos = tcase_create("positive");
    // Тест, когда создается массив
    tcase_add_test(tc_pos, test_create_simple);

    suite_add_tcase(s, tc_pos);

    return s;
}