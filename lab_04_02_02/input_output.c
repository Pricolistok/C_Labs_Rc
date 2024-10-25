#include <string.h>
#include <stdio.h>
#include "input_output.h"

// Функция ввода строки
int input_str(char str[LEN_STR + 2])
{
    printf("Input row: ");
    if (fgets(str, LEN_STR + 2, stdin) == NULL)
        return INPUT_STR_ERROR;
        
    if (strlen(str) <= 1)
        return INPUT_STR_ERROR;
    
    if (strlen(str) > LEN_STR)
        return LEN_STR_ERROR;
        
    return OK;
}

// Вывод результата
void print_result(char arr_result_1[][LEN_WORD + 1], size_t len_arr_result_1, char arr_result_2[][LEN_WORD + 1], size_t len_arr_result_2)
{
    int flag = 0, maxi;
    printf("Result: ");
    for (size_t i = 0; i < len_arr_result_1; i++)
    {
        for (size_t j = 0; j < len_arr_result_2; j++)
        {
            if (strlen(arr_result_1[i]) >= strlen(arr_result_2[j]))
                maxi = strlen(arr_result_1[i]);
            else
                maxi = strlen(arr_result_2[j]);
            if (strncmp(arr_result_1[i], arr_result_2[j], maxi) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            printf("%s yes\n", arr_result_1[i]);
        else
            printf("%s no\n", arr_result_1[i]);
        flag = 0;
    }
}
