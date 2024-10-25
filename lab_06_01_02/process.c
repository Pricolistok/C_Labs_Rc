// Файл для обработки массива
// Подключение файлов и библиотек
#include "process.h"
#include "struct.h"
#include <string.h>

// Функция сортировки
void sort_arr(item items_arr[], size_t len_arr)
{
	char saver_name[LEN_NAME + 2];
	double saver_weight;
	double saver_volume;
	for (size_t i = 0; i < len_arr; i++)
		for (size_t j = 0; j < len_arr - i - 1; j++)
		{
			if (items_arr[j].weight / items_arr[j].volume > items_arr[j + 1].weight / items_arr[j + 1].volume)
			{
				strcpy(saver_name, items_arr[j].name);
				strcpy(items_arr[j].name, items_arr[j + 1].name);
				strcpy(items_arr[j + 1].name, saver_name);
				saver_weight = items_arr[j].weight;
				items_arr[j].weight = items_arr[j + 1].weight;
				items_arr[j + 1].weight = saver_weight;
				saver_volume = items_arr[j].volume;
				items_arr[j].volume = items_arr[j + 1].volume;
				items_arr[j + 1].volume = saver_volume;
			}
		}
}

// Функция проверки имен
int check_name(char name_find[], char name_item[])
{
	for (size_t i = 0; i < strlen(name_find); i++)
	{
		if (name_find[i] != name_item[i])
			return ERROR;
	}
	return OK;
}


// Поиск элементов по имени
int find_item(item items_arr[], size_t len_arr, char name_find[LEN_NAME + 2])
{
	int cnt = 0;
	for (size_t i = 0; i < len_arr; i++)
	{
		if (check_name(name_find, items_arr[i].name) == OK)
		{
			printf("%s\n", items_arr[i].name);
			printf("%lf\n", items_arr[i].weight);
			printf("%lf\n", items_arr[i].volume);
			cnt++;
		}
	}
	return cnt;
}
