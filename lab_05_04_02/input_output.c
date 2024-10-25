// Подключение библиотек и заголовочных файлов
#include "input_output.h"
#include "const.h"
#include "process.h"
#include <string.h>

// Функция для проверки корректности ввода наименования
int check_name(char str[NAME_LEN + 2])
{
    if (strlen(str) < 1)
        return INPUT_STR_ERROR;
    
    if (strlen(str) > NAME_LEN)
        return INPUT_STR_ERROR;
    return OK;
}

// Функция для проверки ввода изготовителя
int check_manufactor(char str[MANUFACTURER_LEN + 2])
{
    if (strlen(str) <= 1)
        return INPUT_STR_ERROR;
    
    if (strlen(str) > MANUFACTURER_LEN)
        return INPUT_STR_ERROR;
    return OK;
}

// Функция для проверки файла
int check_len_file(FILE *f)
{
    fseek(f, 0, SEEK_END);
    if (ftell(f) == 0)
    {
        return ERROR_LEN_FILE;
    }
    return OK;
}

// Функция для создания массива структур
int create_arr(FILE *f, product products_arr[], size_t *len_arr)
{
    size_t len_file = 0;
    int rc;
    char name_save[NAME_LEN + 2]; 
    char manufacturer_save[MANUFACTURER_LEN + 2];
    unsigned int price_save;
    unsigned int count_save;
    // Проверка файла
    if (check_len_file(f) == ERROR_LEN_FILE)
    {
        return ERROR_LEN_FILE;
    }
    fseek(f, 0, SEEK_SET);
    while (!feof(f))
    {
        fscanf(f, "%s", name_save);
        // Проверка наименования
        rc = check_name(name_save);
        if (rc == INPUT_STR_ERROR)
            return INPUT_STR_ERROR;
        fscanf(f, "%s", manufacturer_save);
        // Проверка изготовителя
        rc = check_manufactor(manufacturer_save);
        if (rc == INPUT_STR_ERROR)
            return INPUT_STR_ERROR;
        // Проверка цены
        rc = fscanf(f, "%u", &price_save);
        if (rc != 1)
            return INPUT_NUM_ERROR;
        // Проверка количества
        rc = fscanf(f, "%u", &count_save);
        if (rc != 1)
            return INPUT_NUM_ERROR;
        strcpy(products_arr[len_file].name, name_save);
        strcpy(products_arr[len_file].manufacturer, manufacturer_save);
        products_arr[len_file].price = price_save;
        products_arr[len_file].count = count_save;
        len_file++;
    }
    *len_arr = len_file;
    return OK;
}

int input_file(FILE **f_in, FILE **f_out, char str[NAME_LEN + 2], int args, char **argv)
{
    int rc;
    // Проверка количества аргументов
    if (args != 4)
    {
        return MISSING_ARG;
    }
    // Обработчик команды сортировки
    else if (strcmp(argv[1], "st") == 0 && args == 4)
    {
        if ((*f_in = fopen(argv[2], "r")) == NULL)
        {
            return ERROR_OPEN_FILE;
        }
        if ((*f_out = fopen(argv[3], "w")) == NULL)
        {
            return ERROR_OPEN_FILE;
        }
        return ST;
    }
    // Обработчик команды поиска
    else if (strcmp(argv[1], "ft") == 0 && args == 4)
    {
        if ((*f_in = fopen(argv[2], "r")) == NULL)
        {
            return ERROR_OPEN_FILE;
        }
        strcpy(str, argv[3]);
        rc = check_name(str);
        if (rc == INPUT_STR_ERROR)
            return ERROR_ARG_STR;
        return FT;
    }
    return ERROR_KEY;
}
