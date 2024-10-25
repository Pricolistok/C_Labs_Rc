#include <stdio.h>
#include <string.h>
#include "functions.h"

// Аналог функции strpbrk, которая ищет первое вхождение символа из второй строки
char *my_strpbrk(char *str_scan, char *str_find)
{
    int flag = 0;
    char *result = NULL;
    for (char *i = str_scan; *i != '\0'; i++)
    {
        for (char *j = str_find; *j != '\0'; j++)
        {
            if (*i == *j)
            {
                result = i;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    return result;
}

// Аналог функции strspn, которая ищет длинну строки,. которая состоит из сиволов другой строки
size_t my_strspn(char *str_scan, char *str_find)
{
    int flag;
    size_t len_substring = 0;
    for (char *i = str_scan; *i != '\0'; i++)
    {
        flag = 0;
        for (char *j = str_find; *j != '\0'; j++)
        {
            if (*i == *j)
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
size_t my_strcspn(char *str_scan, char *str_find)
{
    size_t len_before_finder = 0;
    for (char *i = str_scan; *i != '\0'; i++)
    {
        for (char *j = str_find; *j != '\0'; j++)
        {
            if (*i == *j)
            {
                return len_before_finder;
            }
        }
        len_before_finder++;
    }
    return len_before_finder;
}

// Аналог функции strchr, которая ищет адрес первого искомого символа в строке
char *my_strchr(char *str_scan, int str_find)
{
    char *saver = NULL;
    for (char *i = str_scan; *i != '\0'; i++)
    {
        if (*i == str_find)
        {
            return i;
        }
        saver = i;
    }
    if (str_find == 0)
    {
        if (strlen(str_scan) == 0)
            return str_scan;
        return ++saver;
    }
    return NULL; 
}

// Аналог функции strrchr, которая ищет адрес последнего искомого символа в строке
char *my_strrchr(char *str_scan, int str_find)
{
    int flag = 0;
    char *saver = NULL, *saver_2;
    for (char *i = str_scan; *i != '\0'; i++)
    {
        if (*i == str_find)
        {
            flag = 1;
            saver_2 = i;
        }
        saver = i;
    }
    
    if (str_find == 0)
    {
        if (strlen(str_scan) == 0)
            return str_scan;
        return ++saver;
    }
    if (flag == 1)
        return saver_2;
    return NULL;
}
