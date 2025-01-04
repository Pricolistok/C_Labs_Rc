#include <check.h>
#include <stdlib.h>
#include <stdio.h>

extern Suite *pop_duplicates_test(void);
extern Suite *pop_front_test(void);
extern Suite *pop_end_test(void);
extern Suite *sort_test(void);

int main(void)
{
    int cnt_failed = 0;

    SRunner *runner = srunner_create(pop_duplicates_test());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    runner = srunner_create(pop_front_test());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    runner = srunner_create(pop_end_test());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    runner = srunner_create(sort_test());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (cnt_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
