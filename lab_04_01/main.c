#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "errors.h"
#include "const.h"

// Тестирование входных данных для функции strpbrk
int run_cmp_strbrk(char *str_scan, char *str_find)
{
    char *result;
    result = my_strpbrk(str_scan, str_find);
    if (result != strpbrk(str_scan, str_find))
        return 1;
    return 0;
}

// Данные и подсчет результата для функции strpbrk
int test_strpbrk()
{
    int cnt_error = 0;
    char str_scan_1[] = "Hello world!", str_find_1[] = "Hled";
    char str_scan_2[] = "gukjbbnm", str_find_2[] = "bgdrhgk"; 
    char str_scan_3[] = "gukjbbnm", str_find_3[] = "p"; 
    char str_scan_4[] = "gukjbbnm", str_find_4[] = "pm"; 
    char str_scan_5[] = "", str_find_5[] = "pm"; 
    char str_scan_6[] = "uikjhuk", str_find_6[] = ""; 
    cnt_error += run_cmp_strbrk(str_scan_1, str_find_1);
    cnt_error += run_cmp_strbrk(str_scan_2, str_find_2);
    cnt_error += run_cmp_strbrk(str_scan_3, str_find_3);
    cnt_error += run_cmp_strbrk(str_scan_4, str_find_4);
    cnt_error += run_cmp_strbrk(str_scan_5, str_find_5);
    cnt_error += run_cmp_strbrk(str_scan_6, str_find_6);
    return cnt_error;
}

// Тестирование входных данных для функции strspn
int run_cmp_strspn(char *str_scan, char *str_find)
{
    if (my_strspn(str_scan, str_find) != strspn(str_scan, str_find))
        return 1;
    return 0;
}

// Данные и подсчет результата для функции strspn
int test_strspn()
{
    int cnt_error = 0;
    char str_scan_1[] = "aaababbb", str_find_1[] = "accc";
    char str_scan_2[] = "uuuabcdef", str_find_2[] = "ab"; 
    char str_scan_3[] = "ttututa", str_find_3[] = "aaaba";
    char str_scan_4[] = "abcdef", str_find_4[] = "p"; 
    char str_scan_5[] = "", str_find_5[] = ""; 
    cnt_error += run_cmp_strspn(str_scan_1, str_find_1);
    cnt_error += run_cmp_strspn(str_scan_2, str_find_2);
    cnt_error += run_cmp_strspn(str_scan_3, str_find_3);
    cnt_error += run_cmp_strspn(str_scan_4, str_find_4);
    cnt_error += run_cmp_strspn(str_scan_5, str_find_5);
    return cnt_error;
}

// Тестирование входных данных для функции strcspn
int run_cmp_strcspn(char *str_scan, char *str_find)
{
    if (my_strcspn(str_scan, str_find) != strcspn(str_scan, str_find))
        return 1;
    return 0;
}

// Данные и подсчет результата для функции strcspn
int test_strcspn()
{
    int cnt_error = 0;
    char str_scan_1[] = "aaaabcde", str_find_1[] = "ahb";
    char str_scan_2[] = "abcdef", str_find_2[] = "cyba"; 
    char str_scan_3[] = "aaaabcde", str_find_3[] = "chjfj";
    char str_scan_4[] = "abcdef", str_find_4[] = "bartyujh"; 
    char str_scan_5[] = "abcdef", str_find_5[] = "ummmuy"; 
    char str_scan_6[] = "", str_find_6[] = ""; 
    cnt_error += run_cmp_strcspn(str_scan_1, str_find_1);
    cnt_error += run_cmp_strcspn(str_scan_2, str_find_2);
    cnt_error += run_cmp_strcspn(str_scan_3, str_find_3);
    cnt_error += run_cmp_strcspn(str_scan_4, str_find_4);
    cnt_error += run_cmp_strcspn(str_scan_5, str_find_5);
    cnt_error += run_cmp_strcspn(str_scan_6, str_find_6);
    return cnt_error;
}

// Тестирование входных данных для функции strchr
int run_cmp_strchr(char *str_scan, char str_find)
{
    if (my_strchr(str_scan, str_find) != strchr(str_scan, str_find))
        return 1;
    return 0;
}

// Данные и подсчет результата для функции strchr
int test_strchr()
{
    int cnt_error = 0;
    char str_scan_1[] = "acaabcde";
    int str_find_1 = 'a';
    char str_scan_2[] = "abedef";
    int str_find_2 = 'b'; 
    char str_scan_3[] = "";
    int str_find_3 = '\0'; 
    char str_scan_4[] = "abedef";
    int str_find_4 = 'e'; 
    char str_scan_5[] = "abedef";
    int str_find_5 = 'u'; 
    char str_scan_6[] = "\0";
    int str_find_6 = ' '; 
    cnt_error += run_cmp_strchr(str_scan_1, str_find_1);
    cnt_error += run_cmp_strchr(str_scan_2, str_find_2);
    cnt_error += run_cmp_strchr(str_scan_3, str_find_3);
    cnt_error += run_cmp_strchr(str_scan_4, str_find_4);
    cnt_error += run_cmp_strchr(str_scan_5, str_find_5);
    cnt_error += run_cmp_strchr(str_scan_6, str_find_6);
    return cnt_error;
}

// Тестирование входных данных для функции strrchr
int run_cmp_strrchr(char *str_scan, char str_find)
{
    if (my_strrchr(str_scan, str_find) != strrchr(str_scan, str_find))
    {
        return 1;
    }
    return 0;
}

// Данные и подсчет результата для функции strrchr
int test_strrchr()
{
    int cnt_error = 0;
    char str_scan_1[] = "acaabcde";
    int str_find_1 = 'e';
    char str_scan_2[] = "abedef";
    int str_find_2 = 'e'; 
    char str_scan_3[] = "";
    int str_find_3 = '\0'; 
    char str_scan_4[] = "abedef";
    int str_find_4 = 'b'; 
    char str_scan_5[] = "abedef";
    int str_find_5 = 'u'; 
    char str_scan_6[] = "\0";
    int str_find_6 = ' '; 
    cnt_error += run_cmp_strrchr(str_scan_1, str_find_1);
    cnt_error += run_cmp_strrchr(str_scan_2, str_find_2);
    cnt_error += run_cmp_strrchr(str_scan_3, str_find_3);
    cnt_error += run_cmp_strrchr(str_scan_4, str_find_4);
    cnt_error += run_cmp_strrchr(str_scan_5, str_find_5);
    cnt_error += run_cmp_strrchr(str_scan_6, str_find_6);
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
