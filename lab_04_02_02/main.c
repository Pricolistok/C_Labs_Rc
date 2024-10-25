#include <string.h>
#include <stdio.h>
#include "errors.h"
#include "const.h"
#include "process.h"
#include "input_output.h"

int main()
{
    // Инициалиация перменных
    char str_1[LEN_STR + 2], str_2[LEN_STR + 2], arr_1[MAX_LEN_ARR][LEN_WORD + 1], arr_2[MAX_LEN_ARR][LEN_WORD + 1];
    char result_arr_1[MAX_LEN_ARR][LEN_WORD + 1];
    size_t len_arr_1, len_arr_2, len_arr_result_1;
    int rc = input_str(str_1);
    // Проверка ввода строк
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
    rc = input_str(str_2);
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
    // Создание массивов слов
    rc = create_arr(str_1, arr_1, &len_arr_1);
    if (rc == ERROR_LEN_WORD)
    {
        printf("Ошибка в введении слова");
        return rc;
    }
    else if (rc == ZERO_WORDS)
    {
        printf("В строке отсутствуют слова");
        return rc;
    }
    rc = create_arr(str_2, arr_2, &len_arr_2);
    if (rc == ERROR_LEN_WORD)
    {
        printf("Ошибка в введении слова");
        return rc;
    }
    else if (rc == ZERO_WORDS)
    {
        printf("В строке отсутствуют слова");
        return rc;
    }
    // Удаление повторяющихся слов
    delete_repeated_words(arr_1, len_arr_1, result_arr_1, &len_arr_result_1);
    // Вывод резулльтата
    print_result(result_arr_1, len_arr_result_1, arr_2, len_arr_2);
    return OK;
}
