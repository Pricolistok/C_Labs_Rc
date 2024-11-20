#ifndef INPUT_OUTPUT_H__

#define INPUT_OUTPUT_H__

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

int open_file(FILE **file, int argc, char **argv);
int check_len_file(FILE *file);

#endif
