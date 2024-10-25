#ifndef PROCESS_H__

#define PROCESS_H__

#include "process.h"
#include "errors.h"
#include "const.h"

int check_separator(char elem);
int create_arr(char str[], char arr[][LEN_WORD + 1], size_t *len_arr);
int created_new_str(char arr[][LEN_WORD + 1], size_t len_arr_1, char new_str[LEN_STR + 1]);
size_t mode_word(char word[LEN_WORD + 1], char new_word[LEN_WORD + 1]);
void reverse_arr(char arr[][LEN_WORD + 1], size_t len_arr, char arr_result[][LEN_WORD + 1]);

#endif
