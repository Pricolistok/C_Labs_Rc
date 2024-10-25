#include <string.h>
#include <stdio.h>
#include "errors.h"
#include "const.h"
#include "process.h"
#include "input_output.h"


int main()
{
    // Инициализация перменных
    char str_1[LEN_STR + 2], arr[MAX_LEN_ARR][LEN_MONTH + 1];
    size_t len_arr;
    // Ввод строки
    int rc = input_str(str_1);
    // Проверка ввода строки
    if (rc == LEN_STR_ERROR)
    {
        return rc;
    }
    // Проверка ошибки значений внутри строки
    if (rc == STR_ERROR)
    {
        printf("NO\n");
        return OK;
    }
    // Проверка на иные символы внутри строки
    rc = create_arr(str_1, arr, &len_arr);
    if (rc == ANOTHER_SYMBOL)
    {
        printf("NO\n");
        return OK;
    }
    // Проверка на количество слов строки
    if (rc == NOT_ENOUGH_ELEMENTS)
    {
        printf("NO\n");
        return OK;
    }
    // Проверка на количество слов строки
    if (rc == ERROR_LEN_ARR)
    {
        printf("NO\n");
        return OK;
    }
    // Проверка массива
    rc = check_arr(arr);
    // Ошибка значения дня
    if (rc == ERROR_DAY)
    {
        printf("NO\n");
        return OK;
    }
    // Ошибка значения года
    if (rc == ERROR_YEAR)
    {
        printf("NO\n");
        return OK;
    }
    // Ошибка значения месяца
    if (rc == ERROR_MONTH)
    {
        printf("NO\n");
        return OK;
    }
    // Вывод результата
    printf("YES\n");
    return OK;
}
