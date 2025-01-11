#include <check.h>
#include <stdlib.h>
#include <stdio.h>

extern Suite *add_test(void);
extern Suite *filter_test(void);

int main(void)
{
    int cnt_failed = 0;

    SRunner *runner;

    runner = srunner_create(filter_test());

    srunner_run_all(runner, CK_VERBOSE);

    cnt_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    runner = srunner_create(add_test());

    srunner_run_all(runner, CK_VERBOSE);

    cnt_failed += srunner_ntests_failed(runner);

    srunner_free(runner);

    return (cnt_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
