#include "input_output.h"
#include "process.h"

int create_bin_file(FILE *f)
{
    int num, cnt = 0;
    size_t wrote;
    int rc = OK;

    printf("Input integers: ");
    while (rc == OK && scanf("%d", &num) == 1)
    {
        wrote = fwrite(&num, sizeof(int), 1, f);
        if (wrote == 1)
            rc = OK ;
        else
            rc = ERROR_INPUT_FILE;
        cnt++;
    }
    if (cnt == 0)
        return ERROR_INPUT_FILE;
    return rc;
}

int print_bin_file(FILE *f)
{
    int number, rc;
    size_t read, size;
    rc = find_size(f, &size);
    if (rc == 1)
    {
        return ERROR_READ_FILE;
    }
    printf("Result: ");
    for (size_t i = 0; rc == OK && i < size / sizeof(int); i++)
    {
        read = fread(&number, sizeof(int), 1, f);
        if (read == 1)
            printf("%d ", number);
        else
            rc = ERROR_READ_FILE;
    }
    printf("\n");
    return OK;
}