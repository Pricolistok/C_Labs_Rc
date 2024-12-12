#include <check.h>
#include <stdlib.h>
#include <stdio.h>

extern Suite *pop_duplicates_test(void);

int main(void)
{
    int cnt_failed = 0;

    SRunner *runner = srunner_create(pop_duplicates_test());

    srunner_run_all(runner, CK_VERBOSE);

    cnt_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (cnt_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
