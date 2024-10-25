// Заголовочный файл, хранящий в себе функции для обработки данных
#ifndef PROCESS_H__

#define PROCESS_H__

#include "process.h"
#include "errors.h"
#include "const.h"

int check_separator(char elem);
int create_arr(const char str[], char arr[][LEN_WORD + 1], size_t *len_arr);
void delete_repeated_words(char arr[][LEN_WORD + 1], size_t len_arr, char arr_result[][LEN_WORD + 1], size_t *len_arr_result);

#endif
