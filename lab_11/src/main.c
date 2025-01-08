#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "process.h"


int main(void)
{
    int rc = OK;
    char *format = "Name: %s %li\0";
    size_t n = 0;
    char *result_my = NULL, *result_func = NULL;
    char *arg_1_str = "Alina\0";
    long int arg_1_num = 1;
    int result_len_func = snprintf(result_func, n, format, arg_1_str, arg_1_num);
    int result_len_my = my_snprintf(result_my, n, format, arg_1_str, arg_1_num);
    if (result_len_func != result_len_my)
        rc = ERROR;
    return rc;
}
