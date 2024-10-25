// Заголовочный файл для файла ввода
#ifndef INPUT_OUTPUT_H__
#define INPUT_OUTPUT_H__

#include <stdio.h>
#include "errors.h"

int input_file(FILE **f_work, FILE **f_in, FILE **f_out, int args, char **argv, int *digit);

#endif
