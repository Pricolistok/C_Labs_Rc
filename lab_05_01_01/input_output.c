// Подключение заголовочного файла
#include "input_output.h"

// Функция заполнениия файла
int create_int_file(FILE *f)
{
    int num, cnt = 0;

    printf("Input integers: ");
    while (scanf("%d", &num) == 1)
    {
        fprintf(f, "%d", num);
        cnt++;
        fprintf(f, " ");
    }
    if (cnt < 2)
        return NOT_ENOUGH;
    return OK;
}
