#include "input_output.h"

int check_len_file(FILE *file)
{
    int saver = ftell(file);
    fseek(file, 0, SEEK_END);
    if (saver == ftell(file))
        return ERROR_LEN_FILE;
    fseek(file, 0, SEEK_SET);
    return OK;
}

int open_file(FILE **file, int argc, char **argv)
{
    int rc;
    if (argc != 2)
        return ERROR_ARGUMENTS;
    *file = fopen(argv[1], "r");
    if (*file == NULL)
        return ERROR_OPEN_FILE;
    rc = check_len_file(*file);
    if (rc == ERROR_LEN_FILE)
        return ERROR_LEN_FILE;
    
    return OK;
}