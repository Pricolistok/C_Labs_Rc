#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "errors.h"
#include "const.h"

// Тестирование входных данных для функции strpbrk
int run_cmp_strbrk(char *str_scan, char *str_find, size_t len_str_scan, size_t len_str_find)
{
    char str_my_res[LEN_ELEM + 1];
    my_strpbrk(str_scan, str_find, str_my_res, len_str_scan, len_str_find);
    if (str_my_res[0] != *strpbrk(str_scan, str_find))
        return 1;
    return 0;
}

// Данные и подсчет результата для функции strpbrk
int test_strpbrk()
{
    int cnt_error = 0;
    char str_scan_1[] = "Hello world!", str_find_1[] = "aled";
    char str_scan_2[] = "gukjbbnm", str_find_2[] = "bgdrhgk"; 
    cnt_error += run_cmp_strbrk(str_scan_1, str_find_1, sizeof(str_scan_1), sizeof(str_find_1));
    cnt_error += run_cmp_strbrk(str_scan_2, str_find_2, sizeof(str_scan_1), sizeof(str_find_1));
    return cnt_error;
}

// Тестирование входных данных для функции strspn
int run_cmp_strspn(char *str_scan, char *str_find, size_t len_str_scan, size_t len_str_find)
{
    if (my_strspn(str_scan, str_find, len_str_scan, len_str_find) != strspn(str_scan, str_find))
        return 1;
    return 0;
}

// Данные и подсчет результата для функции strspn
int test_strspn()
{
    int cnt_error = 0;
    char str_scan_1[] = "aaababbb", str_find_1[] = "aba";
    char str_scan_2[] = "abcdef", str_find_2[] = "ba"; 
    cnt_error += run_cmp_strbrk(str_scan_1, str_find_1, sizeof(str_scan_1), sizeof(str_find_1));
    cnt_error += run_cmp_strbrk(str_scan_2, str_find_2, sizeof(str_scan_1), sizeof(str_find_1));
    return cnt_error;
}

// Тестирование входных данных для функции strcspn
int run_cmp_strcspn(char *str_scan, char *str_find, size_t len_str_scan, size_t len_str_find)
{
    if (my_strcspn(str_scan, str_find, len_str_scan, len_str_find) != strcspn(str_scan, str_find))
        return 1;
    return 0;
}

// Данные и подсчет результата для функции strcspn
int test_strcspn()
{
    int cnt_error = 0;
    char str_scan_1[] = "aaaabcde", str_find_1[] = "bgp";
    char str_scan_2[] = "abcdef", str_find_2[] = "ba"; 
    cnt_error += run_cmp_strcspn(str_scan_1, str_find_1, sizeof(str_scan_1), sizeof(str_find_1));
    cnt_error += run_cmp_strcspn(str_scan_2, str_find_2, sizeof(str_scan_1), sizeof(str_find_1));
    return cnt_error;
}

// Тестирование входных данных для функции strchr
int run_cmp_strchr(char *str_scan, char *str_find, size_t len_str_scan)
{
    if (my_strchr(str_scan, str_find, len_str_scan) != strchr(str_scan, str_find[0]))
        return 1;
    return 0;
}

// Данные и подсчет результата для функции strchr
int test_strchr()
{
    int cnt_error = 0;
    char str_scan_1[] = "acaabcde", str_find_1[] = "b";
    char str_scan_2[] = "abedef", str_find_2[] = "e"; 
    cnt_error += run_cmp_strchr(str_scan_1, str_find_1, sizeof(str_scan_1));
    cnt_error += run_cmp_strchr(str_scan_2, str_find_2, sizeof(str_scan_1));
    return cnt_error;
}

// Тестирование входных данных для функции strrchr
int run_cmp_strrchr(char *str_scan, char *str_find, size_t len_str_scan)
{
    if (my_strrchr(str_scan, str_find, len_str_scan) != strrchr(str_scan, str_find[0]))
        return 1;
    return 0;
}

// Данные и подсчет результата для функции strrchr
int test_strrchr()
{
    int cnt_error = 0;
    char str_scan_1[] = "acaabcde", str_find_1[] = "d";
    char str_scan_2[] = "abedef", str_find_2[] = "b"; 
    cnt_error += run_cmp_strrchr(str_scan_1, str_find_1, sizeof(str_scan_1));
    cnt_error += run_cmp_strrchr(str_scan_2, str_find_2, sizeof(str_scan_1));
    return cnt_error;
}


int main()
{
    if (test_strpbrk() != 0)
        return ERROR_STRPBRK;
    if (test_strspn() != 0)
        return ERROR_STRSPN;
    if (test_strcspn() != 0)
        return ERROR_STRCSPN;
    if (test_strchr() != 0)
        return ERROR_STRCHR;
    if (test_strrchr() != 0)
        return ERROR_STRRCHR;
    return 0;
}
