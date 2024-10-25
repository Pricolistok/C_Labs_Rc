// Заголовочный файл для файла ввода и вывода результата
#ifndef INPUT_OUTPUT_H__

#define INPUT_OUTPUT_H__

#include "const.h"
#include "errors.h"

int input_str(char str[LEN_STR + 2]);
void print_result(char arr_result_1[][LEN_WORD + 1], size_t len_arr_result_1, char arr_result_2[][LEN_WORD + 1], size_t len_arr_result_2);

#endif
