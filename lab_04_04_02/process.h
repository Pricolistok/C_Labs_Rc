#ifndef PROCESS_H__

#define PROCESS_H__

#include "process.h"
#include "errors.h"
#include "const.h"

int check_separator(char elem);
int create_arr(char str[], char arr[][LEN_MONTH + 1], size_t *len_arr);
int check_arr(char arr[][LEN_MONTH + 1]);
int check_day_month_year(int day, char month[LEN_MONTH + 1], int year, char months[][LEN_MONTH + 1], int days_month[]);
void mod_word(char *word);

#endif
