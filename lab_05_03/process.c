// Подключение заголовочных файлов и библиотек
#include <stdio.h>
#include "process.h"
#include <math.h>

// Проверка файла на корректность
int check_file(FILE *f)
{
    fseek(f, 0, SEEK_END);
    if (ftell(f) % sizeof(int) == 0)
        return OK;
    fseek(f, 0, SEEK_SET);
    return ERROR_FILE_ELEM;
}

// Нахождение размеров файла
int find_size(FILE *f, size_t *size)
{
    long int sz;

    if (fseek(f, 0L, SEEK_END))
        return ERROR;

    sz = ftell(f);
    if (sz < 0)
        return ERROR;

    *size = sz;

    return fseek(f, 0L, SEEK_SET);
}

// Создание нового файла
void create_bin_file(FILE *f, int digit)
{
    int num = 0, cnt = 0;
    while (cnt < digit)
    {
        num = cnt % 321;
        fwrite(&num, sizeof(int), 1, f);
        cnt++;
    }
}

// Вывод данных из файла
int print_bin_file(FILE *f)
{
    int number, rc;
    size_t read, size;
    rc = check_file(f);
    if (rc == ERROR_FILE_ELEM)
    {
        return ERROR_FILE_ELEM;
    }
    rc = find_size(f, &size);
    if (rc == ERROR)
    {
        return ERROR_LEN_FILE;
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

// Получение числа по позиции
int get_number_by_pos(FILE *f, size_t position)
{
    int number;
    fseek(f, position * sizeof(int), SEEK_SET);
    fread(&number, sizeof(int), 1, f);
    return number;
}

// Запись чила на позицию
void put_number_by_pos(FILE *f, size_t position, int *number)
{
    fseek(f, position * sizeof(int), SEEK_SET);
    fwrite(number, sizeof(int), 1, f);
    fseek(f, 0, SEEK_SET);
}

// Сортировка массива
int sort_file(FILE *f)
{
    int rc = OK, num1, num2;
    size_t size;
    rc = check_file(f);
    if (rc == ERROR_FILE_ELEM)
    {
        return ERROR_FILE_ELEM;
    }
    rc = find_size(f, &size);
    if (rc != OK)
        return ERROR_LEN_FILE;
    for (size_t i = 0; i < size / sizeof(int) - 1; i++)
    {
        for (size_t j = 0; j < size / sizeof(int) - 1 - i; j++)
        {
            num1 = get_number_by_pos(f, j);
            num2 = get_number_by_pos(f, j + 1);
            if (num1 > num2)
            {
                put_number_by_pos(f, j + 1, &num1);
                put_number_by_pos(f, j, &num2);
            }
        }
    }
    return OK;
}

// Конвертация файлов
void export(FILE *bin_file, FILE *text_file)
{
    int num;
    fseek(bin_file, 0, SEEK_SET);
    while (fread(&num, sizeof(int), 1, bin_file) == 1) 
    {
        fprintf(text_file, "%d\n", num);
    }
}

// Конвертация файлов
int import(FILE *text_file, FILE *bin_file)
{
    int num, rc;
    long unsigned int iter = 0;
    size_t size;
    while (fscanf(text_file, "%d", &num) == 1) 
    {
        fwrite(&num, sizeof(int), 1, bin_file);
        iter++;
    }
    rc = find_size(bin_file, &size);
    if (rc == ERROR)
    {
        return ERROR_LEN_FILE;
    }
    if (iter * sizeof(int) != (long unsigned int)size)
    {
        return INCORRECT_FILE;
    }
    return OK;
}
