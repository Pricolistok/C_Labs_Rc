#include <stdlib.h>
#include <check.h>
#include <dlfcn.h>
#include "errors_tests.h"


START_TEST(test_back_arr)
{
    void *hlib = dlopen("./dynlib_2.so", RTLD_NOW);
    void (*mysort)(void *, size_t, size_t, int (*)(const void *, const void *)) = dlsym(hlib, "mysort");
    int (*compare)(const void *, const void *) = dlsym(hlib, "compare");
    int arr1[] = {3, 2, 1, 0};
    int arr2[] = {0, 1, 2, 3};
    size_t len_arr_1 = 4;
    mysort(arr1, len_arr_1, sizeof(int), compare);
    ck_assert_mem_eq(arr1, arr2, len_arr_1 * sizeof(int));
    dlclose(hlib);
}
END_TEST

START_TEST(test_alt_arr)
{
    void *hlib = dlopen("./dynlib_2.so", RTLD_NOW);
    void (*mysort)(void *, size_t, size_t, int (*)(const void *, const void *)) = dlsym(hlib, "mysort");
    int (*compare)(const void *, const void *) = dlsym(hlib, "compare");
    int arr1[] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
    int arr2[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
    size_t len_arr_1 = 10;
    mysort(arr1, len_arr_1, sizeof(int), compare);
    ck_assert_mem_eq(arr1, arr2, len_arr_1 * sizeof(int));
    dlclose(hlib);
}
END_TEST

START_TEST(test_all_eq_arr)
{
    void *hlib = dlopen("./dynlib_2.so", RTLD_NOW);
    void (*mysort)(void *, size_t, size_t, int (*)(const void *, const void *)) = dlsym(hlib, "mysort");
    int (*compare)(const void *, const void *) = dlsym(hlib, "compare");
    int arr1[] = {1, 1, 1, 1, 1, 1};
    int arr2[] = {1, 1, 1, 1, 1, 1};
    size_t len_arr_1 = 6;
    mysort(arr1, len_arr_1, sizeof(int), compare);
    ck_assert_mem_eq(arr1, arr2, len_arr_1 * sizeof(int));
    dlclose(hlib);
}
END_TEST

START_TEST(test_simple_arr)
{
    void *hlib = dlopen("./dynlib_2.so", RTLD_NOW);
    void (*mysort)(void *, size_t, size_t, int (*)(const void *, const void *)) = dlsym(hlib, "mysort");
    int (*compare)(const void *, const void *) = dlsym(hlib, "compare");
    int arr1[] = {10, 100, -78, 8, 9, 10001, 0, -9, 10};
    int arr2[] = {-78, -9, 0, 8, 9, 10, 10, 100, 10001};
    size_t len_arr_1 = 9;
    mysort(arr1, len_arr_1, sizeof(int), compare);
    ck_assert_mem_eq(arr1, arr2, len_arr_1 * sizeof(int));
    dlclose(hlib);
}
END_TEST

START_TEST(test_simple_double_arr)
{
    void *hlib = dlopen("./dynlib_2.so", RTLD_NOW);
    void (*mysort)(void *, size_t, size_t, int (*)(const void *, const void *)) = dlsym(hlib, "mysort");
    int (*compare_float)(const void *, const void *) = dlsym(hlib, "compare_float");
    double arr1[] = {2, -2.4, -4.5, 1, 0, 9, -100};
    double arr2[] = {-100, -4.5, -2.4, 0, 1, 2, 9};
    size_t len_arr_1 = 7;
    mysort(arr1, len_arr_1, sizeof(double), compare_float);
    ck_assert_mem_eq(arr1, arr2, len_arr_1 * sizeof(double));
    dlclose(hlib);
}
END_TEST

START_TEST(test_simple_double_arr_back)
{
    void *hlib = dlopen("./dynlib_2.so", RTLD_NOW);
    void (*mysort)(void *, size_t, size_t, int (*)(const void *, const void *)) = dlsym(hlib, "mysort");
    int (*compare_float)(const void *, const void *) = dlsym(hlib, "compare_float");
    double arr1[] = {100, 10.5, 8.6, 5.8, 2.1};
    double arr2[] = {2.1, 5.8, 8.6, 10.5, 100};
    size_t len_arr_1 = 5;
    mysort(arr1, len_arr_1, sizeof(double), compare_float);
    ck_assert_mem_eq(arr1, arr2, len_arr_1 * sizeof(double));
    dlclose(hlib);
}
END_TEST

START_TEST(test_simple_char_arr)
{
    void *hlib = dlopen("./dynlib_2.so", RTLD_NOW);
    void (*mysort)(void *, size_t, size_t, int (*)(const void *, const void *)) = dlsym(hlib, "mysort");
    int (*compare_char)(const void *, const void *) = dlsym(hlib, "compare_char");
    char arr1[] = {'c', 'a', 'z', 'b'};
    char arr2[] = {'a', 'b', 'c', 'z'};
    size_t len_arr_1 = 4;
    mysort(arr1, len_arr_1, sizeof(char), compare_char);
    ck_assert_mem_eq(arr1, arr2, len_arr_1 * sizeof(char));
    dlclose(hlib);
}
END_TEST

START_TEST(test_simple_char_arr_back)
{
    void *hlib = dlopen("./dynlib_2.so", RTLD_NOW);
    void (*mysort)(void *, size_t, size_t, int (*)(const void *, const void *)) = dlsym(hlib, "mysort");
    int (*compare_char)(const void *, const void *) = dlsym(hlib, "compare_char");
    char arr1[] = {'d', 'c', 'b', 'a'};
    char arr2[] = {'a', 'b', 'c', 'd'};
    size_t len_arr_1 = 4;
    mysort(arr1, len_arr_1, sizeof(char), compare_char);
    ck_assert_mem_eq(arr1, arr2, len_arr_1 * sizeof(char));
    dlclose(hlib);
}
END_TEST

Suite* my_sort_test(void)
{
    Suite *s;
    //TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("my_sort");
    tc_pos = tcase_create("positive");

    // Тест, когда массив отсортирован в обратном порядке
    tcase_add_test(tc_pos, test_back_arr);
    // Тест, когда элементов в массиве много, но значения всего два и они чередуются
    tcase_add_test(tc_pos, test_alt_arr);
    // Тест, когда элементов в массиве много, но они все равны
    tcase_add_test(tc_pos, test_all_eq_arr);
    // Тест, когда элементов в массиве много и они расположены в случайном порядке
    tcase_add_test(tc_pos, test_simple_arr);
    // Тест, когда элементов в массиве много и они расположены в случайном порядке, но все элементы вещественные числа
    tcase_add_test(tc_pos, test_simple_double_arr);
    // Тест, когда элементов в массиве много и они расположены в обратном порядке, но все элементы вещественные числа
    tcase_add_test(tc_pos, test_simple_double_arr_back);
    // Тест, когда элементов в массиве много и они расположены в случайном порядке, но все элементы символы
    tcase_add_test(tc_pos, test_simple_char_arr);
    // Тест, когда элементов в массиве много и они расположены в обратном порядке, но все элементы символы
    tcase_add_test(tc_pos, test_simple_char_arr_back);

    suite_add_tcase(s, tc_pos);

    return s;
}
