#include <string.h>
#include <stdio.h>
#include "input_output.h"

// Функция ввода строки
int input_str(char str[LEN_STR + 2])
{
    fgets(str, LEN_STR + 2, stdin);
    
    if (str[0] == '\n')
        return STR_ERROR;

    if (strlen(str) > LEN_STR)
        return LEN_STR_ERROR;
        
    return OK;
}
