#include <stdio.h>
#include "input_output.h"
#include "process.h"
#include <stdlib.h>

#define ERR_OK 0
#define ERR_IO 1

int main(void)
{
    FILE *f;
    int rc, code;
    int result_summ;
	
    f = fopen("data.bin", "wb");
    if (f == NULL)
    {
        printf("Open file error\n");

        return ERROR_OPEN_FILE;
    }
    rc = create_bin_file(f);
    fclose(f);
    if (rc == ERROR_INPUT_FILE)
    {
        printf("Error input\n");
        return rc;
    }
        
    f = fopen("data.bin", "rb");
    if (f == NULL)
    {
        printf("Open file error\n");

        return ERROR_OPEN_FILE;
    }
    rc = cnt_summ(f, &result_summ);
    if (rc == ERROR_READ_FILE)
    {
        printf("Read file error\n");

        return rc;
    }
    fclose(f);

    if (abs(result_summ) % 2 == 0)
        code = 0;
    else
        code = 1;

    f = fopen("data.bin", "r+b");
    if (f == NULL)
    {
        printf("Open file error\n");
        return ERROR_OPEN_FILE;
    }
    rc = replace_elem(f, result_summ, code);
    if (rc == ERROR_REPLACE)
    {
        printf("Replace error\n");

        return rc;
    }
    fclose(f);

    f = fopen("data.bin", "rb");
    if (f == NULL)
    {
        printf("Open file error\n");
        return ERROR_OPEN_FILE;
    }
    rc = print_bin_file(f);
    if (rc == ERROR_READ_FILE)
    {
        printf("Ошибка чтения файла\n");
        return rc;
    }
    fclose(f);

    return OK;
}