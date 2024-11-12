#include <check.h>
#include <stdlib.h>
#include <stdio.h>

extern Suite *sort_array(void);
extern Suite *key_array(void);

int main(void)
{
    int cnt_failed = 0;

    SRunner *runner;

    // Запуск модульных тестов, длв проверки сортировки
    runner = srunner_create(sort_array());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    // Запуск модульных тестов для проверки поиска элементов в массиве
    runner = srunner_create(key_array());
    srunner_run_all(runner, CK_VERBOSE);
    cnt_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (cnt_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
