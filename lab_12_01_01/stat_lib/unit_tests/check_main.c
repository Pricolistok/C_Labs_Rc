#include <check.h>
#include <stdlib.h>
#include <stdio.h>

extern Suite *my_sort_test(void);
extern Suite *key_test(void);

int main(void)
{
    int cnt_failed = 0;

    SRunner *runner = srunner_create(my_sort_test());

    srunner_run_all(runner, CK_VERBOSE);

    cnt_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    runner = srunner_create(key_test());

    srunner_run_all(runner, CK_VERBOSE);

    cnt_failed += srunner_ntests_failed(runner);

    srunner_free(runner);

    return (cnt_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
