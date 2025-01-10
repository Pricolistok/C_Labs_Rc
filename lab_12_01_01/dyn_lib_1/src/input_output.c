#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "input_output.h"

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


int get_len_from_file(FILE **file_in, size_t *len_arr, int *flag_filter, int argc, char **argv)
{
    int rc = 1, elem = 0;
    size_t cnt_elem = 0;
    if ((argc < 3) || (argc > 4))
        return ERROR_ARGUMENTS;
    if ((argc == 4) && (strcmp("f", argv[3]) != 0))
        return ERROR_FLAG_FILTER;
    else if ((argc == 4) && (strcmp("f", argv[3]) == 0))
        *flag_filter = 1;
    else
        *flag_filter = 0;
    *file_in = fopen(argv[1], "r");
    if (*file_in == NULL)
        return ERROR_OPEN_FILE;
    rc = check_len_file(*file_in);
    if (rc == ERROR)
        return ERROR_LEN_FILE;
    while (fscanf(*file_in, "%d", &elem) == 1)
        cnt_elem++;
    if (!feof(*file_in))
        return ERROR_ELEM_IN_FILE;
    fclose(*file_in);
    *len_arr = cnt_elem;
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


void input_arr_from_file(FILE *file_in, int *start, int *finish)
{
    for (int *i = start; i <= finish; i++)
        fscanf(file_in, "%d", i);
}

void wite_to_file(FILE *file_out, int *start, int *finish)
{
    for (int *i = start; i < finish; i++)
    {
        fprintf(file_out, "%d ", *i);
    }
}

void close_files(FILE *file_in, FILE *file_out)
{
    fclose(file_in);
    fclose(file_out);
}
