#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "process.h"


int main(void)
{
    char *format = "N %li%liam e: %%li%%li%li    %li   \0";
    size_t n = 10;
    char result_my[10], result_func[10];
    long int arg_1 = -9223372036854775807;
    long int arg_2 = -9223372036854775807;
    long int arg_3 = -9223372036854775807;
    long int arg_4 = -9223372036854775807;
    long int arg_5 = -9223372036854775807;
    int result_len_func = snprintf(result_func, n, format, arg_1, arg_2, arg_3, arg_4, arg_5);
    int result_len_my = my_snprintf(result_my, n, format, arg_1, arg_2, arg_3, arg_4, arg_5);
    printf("f %s %d\nm %s %d\n", result_func, result_len_func, result_my, result_len_my);

    return OK;
}
