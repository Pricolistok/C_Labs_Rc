#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "process.h"


int main(void)
{
    const char *format = "Privet %s %li\0";
    char *str = NULL;
    size_t n = 50;

    str = malloc(n);
    if (!str)
        return ERROR_ADD_MEMORY;

    my_snprintf(str, n, format, "Gosha\0", 123);
    printf("%s", str);
    return OK;
}
