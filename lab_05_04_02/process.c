// Подключение библиотек и заголовочных файлов
#include <stdio.h>
#include "process.h"
#include "const.h"
#include <math.h>
#include <string.h>

// Запись в массив
void write_to_file(FILE *f, product products_arr[], size_t len_arr)
{
    for (size_t i = 0; i < len_arr; i++)
    {
        fprintf(f, "%s\n", products_arr[i].name);
        fprintf(f, "%s\n", products_arr[i].manufacturer);
        fprintf(f, "%d\n", products_arr[i].price);
        fprintf(f, "%d\n", products_arr[i].count);
    }
}

// Сортировка массива
int sort_arr(product products_arr[], size_t len_arr)
{
    product temp;
    for (size_t i = 0; i < len_arr; i++)
    {
        for (size_t j = 0; j < len_arr - 1 - i; j++)
        {
            if (products_arr[j].price < products_arr[j + 1].price)
            {
                strcpy(temp.name, products_arr[j].name);
                strcpy(temp.manufacturer, products_arr[j].manufacturer);
                temp.price = products_arr[j].price;
                temp.count = products_arr[j].count;

                strcpy(products_arr[j].name, products_arr[j + 1].name);
                strcpy(products_arr[j].manufacturer, products_arr[j + 1].manufacturer);
                products_arr[j].price = products_arr[j + 1].price;
                products_arr[j].count = products_arr[j + 1].count;

                strcpy(products_arr[j + 1].name, temp.name);
                strcpy(products_arr[j + 1].manufacturer, temp.manufacturer);
                products_arr[j + 1].price = temp.price;
                products_arr[j + 1].count = temp.count;
            }
            else if (products_arr[j].price == products_arr[j + 1].price)
            {
                if (products_arr[j].count < products_arr[j + 1].count)
                {
                    strcpy(temp.name, products_arr[j].name);
                    strcpy(temp.manufacturer, products_arr[j].manufacturer);
                    temp.price = products_arr[j].price;
                    temp.count = products_arr[j].count;

                    strcpy(products_arr[j].name, products_arr[j + 1].name);
                    strcpy(products_arr[j].manufacturer, products_arr[j + 1].manufacturer);
                    products_arr[j].price = products_arr[j + 1].price;
                    products_arr[j].count = products_arr[j + 1].count;

                    strcpy(products_arr[j + 1].name, temp.name);
                    strcpy(products_arr[j + 1].manufacturer, temp.manufacturer);
                    products_arr[j + 1].price = temp.price;
                    products_arr[j + 1].count = temp.count;
                }
            }
        }
    }
    return OK;
}

// Поиск элементов
int find_elems(product products_arr[], size_t len_arr, char str[])
{
    int flag = 0, iter = 0;
    size_t len_elem;
    for (size_t i = 0; i < len_arr; i++)
    {
        len_elem = strlen(products_arr[i].name) - strlen(str);
        for (size_t j = 0; j < strlen(str); j++) 
        {
            if (products_arr[i].name[len_elem + j] != str[j]) 
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("%s\n", products_arr[i].name);
            printf("%s\n", products_arr[i].manufacturer);
            printf("%u\n", products_arr[i].price);
            printf("%u\n", products_arr[i].count);
            iter++;
        }
        flag = 0;
    }
    if (iter == 0)
        return HAVENT_CMP_RESULT;
    return OK;
}

