#include <stdio.h>
#include <string.h>
#include "functions.h"

// Аналог функции strpbrk, которая ищет первое вхождение символа из второй строки
void my_strpbrk(char *str_scan, char *str_find, char *str_my_res, size_t len_str_scan, size_t len_str_find)
{
    int flag = 0;
    for (size_t i = 0; i < len_str_scan - 2; i++)
    {
        for (size_t j = 0; j < len_str_find - 2; j++)
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

// Аналог функции strspn, которая ищет длинну строки,. которая состоит из сиволов другой строки
size_t my_strspn(char *str_scan, char *str_find, size_t len_str_scan, size_t len_str_find)
{
    int flag;
    size_t len_substring = 0;
    for (size_t i = 0; i < len_str_scan - 2; i++)
    {
        flag = 0;
        for (size_t j = 0; j < len_str_find - 2; j++)
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

// Аналог функции strspn, которая ищет длинну до нахождения первого символа из подстроки
size_t my_strcspn(char *str_scan, char *str_find, size_t len_str_scan, size_t len_str_find)
{
    size_t len_before_finder = 0;
    for (size_t i = 0; i < len_str_scan - 2; i++)
    {
        for (size_t j = 0; j < len_str_find - 2; j++)
        {
            if (str_scan[i] == str_find[j])
            {
                return len_before_finder;
            }
        }
        len_before_finder++;
    }
    return len_before_finder;
}

// Аналог функции strchr, которая ищет адрес первого искомого символа в строке
char *my_strchr(char *str_scan, char *str_find, size_t len_str_scan)
{
    for (size_t i = 0; i < len_str_scan - 2; i++)
    {
        if (str_scan[i] == str_find[0])
        {
            return &str_scan[i];
        }
    }
    return NULL;
}

// Аналог функции strrchr, которая ищет адрес последнего искомого символа в строке
char *my_strrchr(char *str_scan, char *str_find, size_t len_str_scan)
{
    int flag = 0;
    char *saver;
    for (size_t i = 0; i < len_str_scan - 2; i++)
    {
        if (str_scan[i] == str_find[0])
        {
            flag = 1;
            saver = &str_scan[i];
        }
    }
    if (flag == 1)
        return saver;
    return NULL;
}
