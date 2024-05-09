#include <stdio.h>
#include <string.h>
#include "functions.h"


void my_strpbrk(char *str_scan, char *str_find, char *str_my_res)
{
    int flag = 0;
    size_t len_str_scan = sizeof(str_scan), len_str_find = sizeof(str_find);
    for (size_t i = 0; i < len_str_scan; i++)
    {
        for (size_t j = 0; j < len_str_find; j++)
        {
            if (str_scan[i] == str_find[j])
            {
                str_my_res[0] = str_scan[i];
                flag = 1;
                break;
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
            break;
    }
}

size_t my_strspn(char *str_scan, char *str_find)
{
    int flag;
    size_t len_substring = 0;
    size_t len_str_scan = sizeof(str_scan), len_str_find = sizeof(str_find);
    for (size_t i = 0; i < len_str_scan; i++)
    {
        flag = 0;
        for (size_t j = 0; j < len_str_find; j++)
        {
            if (str_scan[i] == str_find[j])
            {
                flag = 1;
                len_substring += 1;
                break;
            }
        }
        if (flag == 0)
            return len_substring;
    }
    return len_substring;
}

size_t my_strcspn(char *str_scan, char *str_find)
{
    size_t len_before_finder = 0;
    size_t len_str_scan = sizeof(str_scan), len_str_find = sizeof(str_find);
    printf("%s %s \n", str_scan, str_find);
    for (size_t i = 0; i < len_str_scan; i++)
    {
        for (size_t j = 0; j < len_str_find - 1; j++)
        {
            printf("s: %c %lu f: %c %lu \n", str_scan[i], i, str_find[j], j);
            if (str_scan[i] == str_find[j])
            {
                return len_before_finder;
            }
        }
        len_before_finder++;
    }
    return len_before_finder;
}