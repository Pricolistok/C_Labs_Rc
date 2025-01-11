#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "errors.h"
#include "input_output.h"

#include <stdint.h>

int check_len_file(FILE *file_in)
{
    long int pos_start;
    pos_start = ftell(file_in);
    fseek(file_in, 0, SEEK_END);
    if (pos_start == ftell(file_in))
        return ERROR;
    fseek(file_in, 0, SEEK_SET);
    return OK;
}


int get_len_from_file(FILE **file_in, size_t *len_arr, int *flag_filter, int argc, char **argv, int *mode_mem, int *write_num)
{
    int rc = 1, elem = 0;
    char ch, *endptr;
    long value;
    size_t cnt_elem = 0;
    if ((argc < 3) || (argc > 5))
        return ERROR_ARGUMENTS;

    if ((argc == 4) && (strcmp("f", argv[3]) == 0))
    {
        *file_in = fopen(argv[1], "r");
        if (*file_in == NULL)
            return ERROR_OPEN_FILE;
        rc = check_len_file(*file_in);
        if (rc == ERROR)
            return ERROR_LEN_FILE;
        rc = fscanf(*file_in, "%c", &ch);
        if (rc != 1)
            return ERROR_ELEM_IN_FILE;
        if (ch == 'm')
            *mode_mem = 0;
        else if (ch == 's')
            *mode_mem = 1;
        else
            return ERROR_ELEM_IN_FILE;
        rc = fscanf(*file_in, "%d", write_num);
        if (rc != 1)
            return ERROR_ELEM_IN_FILE;
        if (*write_num <= 0)
            return ERROR_ELEM_IN_FILE;
        while (fscanf(*file_in, "%d", &elem) == 1)
            cnt_elem++;
        if (!feof(*file_in))
            return ERROR_ELEM_IN_FILE;
        fclose(*file_in);
        *len_arr = cnt_elem;
        *flag_filter = 1;
    }
    else if (((argc == 5) && (strcmp("a", argv[3]) == 0)))
    {
        if (argv[4] == NULL)
            return ERROR_ARGUMENTS;

        value = strtol(argv[4], &endptr, 10);
        if (*endptr == '\0' && value >= INT_MIN && value <= INT_MAX)
            *len_arr = (size_t)value;
        else
            return ERROR_ARGUMENTS;
        *flag_filter = 0;
    }
    else
        return ERROR_ARGUMENTS;
    return OK;
}


int open_files(FILE **file_in, FILE **file_out, char **argv)
{
    *file_in = fopen(argv[1], "r");
    if (*file_in == NULL)
        return ERROR_OPEN_FILE;
    *file_out = fopen(argv[2], "w");
    if (*file_out == NULL)
        return ERROR_OPEN_FILE;
    return OK;
}


void input_arr_from_file(FILE *file_in, int *arr, size_t len_arr)
{
    char ch;
    int elem;
    fscanf(file_in, "%c", &ch);
    fscanf(file_in, "%d", &elem);
    for (size_t i = 0; i <= len_arr; i++)
        fscanf(file_in, "%d", &arr[i]);
}

void write_to_file(FILE *file_out, int *arr, size_t len_arr)
{
    for (size_t i = 0; i < len_arr; i++)
        fprintf(file_out, "%d ", arr[i]);
}

void close_files(FILE *file_in, FILE *file_out)
{
    fclose(file_in);
    fclose(file_out);
}
