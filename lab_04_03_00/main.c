#include <string.h>
#include <stdio.h>
#include "errors.h"
#include "const.h"
#include "process.h"
#include "input_output.h"


int main()
{
    // Инициализация переменных
    char str_1[LEN_STR + 2], arr[MAX_LEN_ARR][LEN_WORD + 1], new_str[LEN_STR + 1];
    size_t len_arr_1;
    int rc = input_str(str_1);
    // Обработка ошибок при вводе строки
    if (rc == INPUT_STR_ERROR)
    {
        printf("Ошибка ввода строки \n");
        return rc;
    }
    if (rc == LEN_STR_ERROR)
    {
        printf("Ошибка длинны строки\n");
        return rc;
    }
    // Ввод массива
    rc = create_arr(str_1, arr, &len_arr_1);
    // Обработка ошибок при создании массива
    if (rc == ZERO_WORDS)
    {
        printf("Отсутствуют слова \n");
        return rc;
    }
    if (rc == ERROR_LEN_WORD)
    {
        printf("Ошибка длинны слова \n");
        return rc;
    }
    if (rc == ONE_WORD)
    {
        printf("Всего одно слово \n");
        return rc;
    }
    // Создание новой строки
    rc = created_new_str(arr, len_arr_1, new_str);
    // Обработка ошибок при создани новой строки
    if (rc == NEW_STR_EMPTY)
    {
        printf("Получилась пустая строка \n");
        return rc;
    }
    // Вывод дезультата
    printf("Result: %s", new_str);
    return OK;
}
