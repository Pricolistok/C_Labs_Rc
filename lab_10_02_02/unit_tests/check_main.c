#include <check.h>
#include <stdlib.h>
#include <stdio.h>

extern Suite *test_val(void);
extern Suite *test_sum(void);
extern Suite *test_ddx(void);

int main(void)
{
    int cnt_failed = 0;

    SRunner *runner = srunner_create(test_val());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    runner = srunner_create(test_sum());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    runner = srunner_create(test_ddx());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (cnt_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
