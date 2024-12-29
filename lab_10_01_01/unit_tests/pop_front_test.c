#include <stdlib.h>
#include <check.h>
#include "process.h"
#include "struct.h"
#include "funcs_for_units.h"

// Тест, когда элемент всего 1
START_TEST(test_one_elem)
{
    int rc;
    char *name_head_1 = malloc(5 + 1);
    strcpy(name_head_1, "apple");
    product list_product[] = { { name_head_1, 5, 12}};
    // product list_result[] = {};
    node_t *head = NULL;
    node_t *result = NULL;
    head = input_to_list(list_product, 1);
    // result = input_to_list(list_result, 0);
    rc = test_pop_front(head, result);
    ck_assert_int_eq(rc, OK);
}
END_TEST



Suite* pop_front_test(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("pop_front");
    tc_pos = tcase_create("positive");

    tcase_add_test(tc_pos, test_one_elem);


    suite_add_tcase(s, tc_pos);

    return s;
}

