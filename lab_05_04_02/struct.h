// Заголовочный файл, хранящий структуру даных
#ifndef STRUCT_H__
#define STRUCT_H__

#include "const.h"

typedef struct 
{
    char name[NAME_LEN + 2]; 
    char manufacturer[MANUFACTURER_LEN + 2];
    int price;
    int count;
} product;

#endif
