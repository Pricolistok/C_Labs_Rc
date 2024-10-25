// Файл хранящий структуру
#ifndef STRUCT_H__

#define STRUCT_H__

#include "const.h"

typedef struct 
{
	char name[LEN_NAME + 2];
	double weight;
	double volume;
} item;

#endif
