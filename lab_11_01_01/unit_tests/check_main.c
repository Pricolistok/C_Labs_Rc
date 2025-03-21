#include <check.h>
#include <stdlib.h>
#include <stdio.h>

extern Suite *test_s(void);
extern Suite *test_li(void);
extern Suite *test_all(void);


int main(void)
{
    int cnt_failed = 0;

    SRunner *runner;

    runner = srunner_create(test_s());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    runner = srunner_create(test_li());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    runner = srunner_create(test_all());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (cnt_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
