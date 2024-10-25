#include <string.h>
#include <stdio.h>
#include "process.h"
#include <ctype.h>
#include <stdlib.h>

// Создание массива
int create_arr(char str[], char arr[][LEN_MONTH + 1], size_t *len_arr)
{
    for (char *i = str; *i != '\0'; i++)
    {
        if (strchr("+-.,!$#*();:", *i) != NULL)
            return ANOTHER_SYMBOL;
    }
    char *pword = strtok(str, " \t\n\v\f\r");
    size_t iter = 0;
    while (pword)
    {
        strcpy(arr[iter], pword);
        iter++;
        pword = strtok(NULL,  " \t\n\v\f\r");
        if (iter > 3)
            return ERROR_LEN_ARR;
    }
    if (iter < 3)
        return NOT_ENOUGH_ELEMENTS;
    *len_arr = iter;
    return OK;
}

// Функция обработки слов
void mod_word(char *word)
{
    for (char *i = word; *i != '\0'; i++)
        *i = tolower(*i);
}

// Проверка значений дня, месяца, года
int check_day_month_year(int day, char month[LEN_MONTH + 1], int year, char months[][LEN_MONTH + 1], int days_month[])
{
    int flag = 0;
    char month_mod[LEN_MONTH + 1];
    strncpy(month_mod, month, LEN_MONTH + 1);
    mod_word(month_mod);
    for (size_t i = 0; i < LEN_ARR_MONTHS; i++)
    {
        if (strncmp(month_mod, months[i], LEN_MONTH) == 0)
        {
            flag = 1;
            if (strncmp(month_mod, "february", LEN_MONTH) == 0)
            {
                if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                {
                    if (day > 29)
                        return ERROR_DAY;
                }
                else
                {
                    if (day > 28)
                        return ERROR_DAY;
                }
            }
            else
            {
                if (day > days_month[i])
                    return ERROR_DAY;
            }
            break;
        }
    }
    if (flag == 1)
        return OK;
    return ERROR_MONTH;
}

// Обработка массива
int check_arr(char arr[][LEN_MONTH + 1])
{
    char arr_months[LEN_ARR_MONTHS][LEN_MONTH + 1] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
    int days[LEN_ARR_MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, rc;
    int date_day = atoi(arr[0]);
    if (date_day <= 0 || date_day > 31)
    {
        return ERROR_DAY;
    }
    char date_month[LEN_MONTH + 1];
    strncpy(date_month, arr[1], LEN_MONTH + 1);
    int date_year = atoi(arr[2]);
    if (date_year <= 0 || date_year > 9999)
        return ERROR_YEAR;
    rc = check_day_month_year(date_day, date_month, date_year, arr_months, days);
    return rc;
}
