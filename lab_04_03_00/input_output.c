#include <string.h>
#include <stdio.h>
#include "input_output.h"

// Функция ввода строки
int input_str(char str[LEN_STR + 2])
{
    printf("input row: ");
    
    if (fgets(str, LEN_STR + 2, stdin) == NULL)
        return INPUT_STR_ERROR;
        
    if (strlen(str) <= 1)
        return INPUT_STR_ERROR;
    
    if (strlen(str) > LEN_STR)
        return LEN_STR_ERROR;
        
    return OK;
}
