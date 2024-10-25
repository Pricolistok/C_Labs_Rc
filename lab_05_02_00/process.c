// Подклчение заголовочных файлов и библиотек
#include <stdio.h>
#include "process.h"
#include <math.h>

// Подсчет среднего
int cnt_middle(FILE *f, double *middle)
{
    double num, summ = 0;
    int cnt = 0, iter = 0;
    int code_saver;
    code_saver = fscanf(f, "%lf", &num);
    while (code_saver != EOF && code_saver == 1) 
    {
        iter++;
        summ += num;
        cnt++;
        if (feof(f)) 
            break;
        if (ferror(f))
            return ERROR_READ_FILE;
        code_saver = fscanf(f, "%lf", &num);
    }
    if (code_saver != 1)
        return ERROR_SYMBOL;
    if (iter == 0)
        return EMPTY_FILE;
    *middle = summ / cnt;
    return OK;
}

// Поиск искомого числа
void find_num(FILE *f, double middle, double *find_num)
{
    double diff, saver, num;
    fscanf(f, "%lf", &num);
    diff = fabs(middle - num);
    saver = num;
    while (fscanf(f, "%lf", &num) != EOF) 
    {
        if (diff > fabs(middle - num))
        {
            diff = fabs(middle - num);
            saver = num;
        }
        if (feof(f)) 
            break;
    }
    *find_num = saver;
}
