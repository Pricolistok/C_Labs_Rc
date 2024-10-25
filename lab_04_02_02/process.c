#include <string.h>
#include <stdio.h>
#include "process.h"

// Функция для определения длинны строки
size_t check_len_str(const char str[])
{
    size_t len_str = 0;
    while (str[len_str] != '\0')
        len_str++;
    return len_str;
}

// Функция для проверки разделителей внутри строки
int check_separator(char elem)
{
    for (size_t i = 0; i < strlen(SEPARATORS); i++)
    {
        if (SEPARATORS[i] == elem)
            return OK;
    }
    return NO_ELEM;
}

// Функция для создания массива из слов
int create_arr(const char str[], char arr[][LEN_WORD + 1], size_t *len_arr)
{
    size_t cnt_words = 0, len_word = 0, len_str = check_len_str(str);
    for (size_t i = 0; i < len_str; i++)
    {
        if (check_separator(str[i]) == NO_ELEM) 
        {
            if (len_word > LEN_WORD - 1)
                return ERROR_LEN_WORD;
            arr[cnt_words][len_word] = str[i];
            arr[cnt_words][len_word + 1] = '\0';
            len_word++;
        }
        else
        {
            if (len_word != 0)
            {
                len_word = 0;
                cnt_words++;
            }
        }
    }
    if (cnt_words == 0)
        return ZERO_WORDS;
    *len_arr = cnt_words;
    return OK;
}

// Функция для удаления повторяющихся слов
void delete_repeated_words(char arr[][LEN_WORD + 1], size_t len_arr, char arr_result[][LEN_WORD + 1], size_t *len_arr_result)
{
    size_t iter = 0;
    int flag = 0;
    for (size_t i = 0; i < len_arr; i++)
    {
        for (size_t j = 0; j < iter; j++)
        {
            if (strncmp(arr[i], arr_result[j], strlen(arr[i])) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            strncpy(arr_result[iter], arr[i], strlen(arr[i]) + 1);
            iter++;
        }
        flag = 0;  
    }
    *len_arr_result = iter;
}
