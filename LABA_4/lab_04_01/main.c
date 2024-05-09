#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "errors.h"
#include "const.h"

int run_cmp_strbrk(char *str_scan, char *str_find)
{
    char str_my_res[LEN_ELEM + 1];
    my_strpbrk(str_scan, str_find, str_my_res);
    if (str_my_res[0] != *strpbrk(str_scan, str_find))
        return 1;
    return 0;
}

int test_strpbrk()
{
    int cnt_error = 0;
    char str_scan_1[] = "Hello world!", str_find_1[] = "aled";
    char str_scan_2[] = "gukjbbnm", str_find_2[] = "bgdrhgk"; 
    cnt_error += run_cmp_strbrk(str_scan_1, str_find_1);
    cnt_error += run_cmp_strbrk(str_scan_2, str_find_2);
    return cnt_error;
}

int run_cmp_strspn(char *str_scan, char *str_find)
{
    if (my_strspn(str_scan, str_find) != strspn(str_scan, str_find))
        return 1;
    return 0;
}

int test_strspn()
{
    int cnt_error = 0;
    char str_scan_1[] = "aaababbb", str_find_1[] = "aba";
    char str_scan_2[] = "abcdef", str_find_2[] = "ba"; 
    cnt_error += run_cmp_strspn(str_scan_1, str_find_1);
    cnt_error += run_cmp_strspn(str_scan_2, str_find_2);
    return cnt_error;
}

int run_cmp_strcspn(char *str_scan, char *str_find)
{
    printf("%lu %lu \n", my_strcspn(str_scan, str_find), strcspn(str_scan, str_find));
    if (my_strcspn(str_scan, str_find) != strcspn(str_scan, str_find))
        return 1;
    return 0;
}

int test_strcspn()
{
    int cnt_error = 0;
    char str_scan_1[] = "aaaabcde", str_find_1[] = "bgp";
    char str_scan_2[] = "abcdef", str_find_2[] = "ba"; 
    cnt_error += run_cmp_strcspn(str_scan_1, str_find_1);
    cnt_error += run_cmp_strcspn(str_scan_2, str_find_2);
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
    return 0;
}