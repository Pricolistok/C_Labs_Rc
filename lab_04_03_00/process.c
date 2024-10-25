#include <string.h>
#include <stdio.h>
#include "process.h"

// Функция создания массива
int create_arr(char str[], char arr[][LEN_WORD + 1], size_t *len_arr)
{
    char *pword = strtok(str, " ,:;?!-.@#'^&*()$\n");
    size_t iter = 0;
    while (pword)
    {
        if (strlen(pword) > LEN_WORD)
            return ERROR_LEN_WORD;
        strcpy(arr[iter], pword);
        iter++;
        pword = strtok(NULL, " ,:;?!-.@#'^&*()$\n");
    }
    if (iter == 0)
        return ZERO_WORDS;
    if (iter == 1)
        return ONE_WORD;
    *len_arr = iter;
    return OK;
}

// Функция обработки слов
size_t mode_word(char word[LEN_WORD + 1], char new_word[LEN_WORD + 1])
{
    new_word[0] = word[0];
    size_t iter = 0;
    for (size_t i = 1; i < strlen(word); i++)
    {
        if (word[i] != word[0])
        {
            iter++;
            new_word[iter] = word[i];
        }
    }
    new_word[iter + 1] = '\0';
    return iter + 1;
}

// Функция для создания новой строки
int created_new_str(char arr[][LEN_WORD + 1], size_t len_arr_1, char new_str[LEN_STR + 1])
{
    // printf("%lu", len_arr_1);
    size_t iter = 0, len_new_word;
    char new_word[LEN_WORD + 1];
    for (int i = len_arr_1 - 2; i >= 0; i--)
    {
        if (strncmp(arr[i], arr[len_arr_1 - 1], LEN_WORD) != 0)
        {
            len_new_word = mode_word(arr[i], new_word);
            for (size_t j = 0; j < len_new_word; j++)
            {
                new_str[iter] = new_word[j];
                iter++;
            }
            if (i != 0)
                new_str[iter] = ' ';
            iter++;
        }
    }
    if (iter == 0)
        return NEW_STR_EMPTY;
    iter--;
    new_str[iter] = '\0';
    return OK;
}
