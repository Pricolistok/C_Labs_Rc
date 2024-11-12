#include <check.h>
#include <stdlib.h>
#include <stdio.h>

extern Suite *rm_rows(void);
extern Suite *rm_columns(void);
extern Suite *multiplication_matrix(void);
extern Suite *add_elems(void);

int main(void)
{
    int cnt_failed = 0;

    SRunner *runner = srunner_create(rm_rows());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    runner = srunner_create(rm_columns());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    runner = srunner_create(multiplication_matrix());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    runner = srunner_create(add_elems());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (cnt_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
