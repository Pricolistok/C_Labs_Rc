#include "process.h"

int find_size(FILE *f, size_t *size)
{
    long int sz;

    if (fseek(f, 0L, SEEK_END))
        return 1;

    sz = ftell(f);
    if (sz < 0)
        return 1;

    *size = sz;

    return fseek(f, 0L, SEEK_SET);
}

int cnt_summ(FILE *f, int *summ_result)
{
    int number, summ = 0;
    while (fread(&number, sizeof(int), 1, f))
    {   
        summ += number;
    }
    *summ_result = summ;
    return OK;
}

int replace_elem(FILE *f, int summ_result, int code)
{
    int number;
    while (fread(&number, sizeof(int), 1, f))
    {   
        if (code == 0 && number > 0)
        {
            fseek(f, ftell(f) - sizeof(int), SEEK_SET);
            fwrite(&summ_result, sizeof(int), 1, f);
            return OK;
        }
        if (code == 1 && number < 0)
        {
            fseek(f, ftell(f) - sizeof(int), SEEK_SET);
            fwrite(&summ_result, sizeof(int), 1, f);
            return OK;
        }

    }
    return ERROR_REPLACE;
}
