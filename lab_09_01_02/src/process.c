// Файл для обработки массива
// Подключение файлов и библиотек
#include "process.h"

int add_memory(item **arr, size_t len_arr)
{
	*arr = (item*)malloc(len_arr * sizeof(item));
	if (!arr)
		return ERROR_ADD_MEMORY;
	return OK;
}

// Добавление памяти для массива, хранящего индексы для вывода
int add_memory_for_print(int **arr, size_t len_arr)
{
	*arr = (int*)malloc(len_arr * sizeof(int));
	if (!arr)
		return ERROR_ADD_MEMORY;
	return OK;
}

// Функция для перестановки элементов массива
void change_elems(item *items_arr, size_t index_1, size_t index_2)
{
	item tmp;

	tmp = items_arr[index_1];
	items_arr[index_1] = items_arr[index_2];
	items_arr[index_2] = tmp;
}

// Функция сортировки
void sort_arr(item *items_arr, size_t len_arr)
{
	for (size_t i = 0; i < len_arr; i++)
		for (size_t j = 0; j < len_arr - i - 1; j++)
		{
			if (items_arr[j].weight / items_arr[j].volume > items_arr[j + 1].weight / items_arr[j + 1].volume)
				change_elems(items_arr, j, j + 1);
		}
}

// Функция проверки имен
int check_name(char *name_find, char name_item[], size_t len_name)
{
	for (size_t i = 0; i < len_name; i++)
	{
		if (name_find[i] != name_item[i])
			return ERROR;
	}
	return OK;
}


// Поиск элементов по имени
int find_item(item *items_arr, size_t len_arr, char *name_find, int *arr)
{
	int cnt = 0;
	for (size_t i = 0; i < len_arr; i++)
	{
		if (check_name(name_find, items_arr[i].name, strlen(name_find)) == OK)
		{
			arr[cnt] = i;
			cnt++;
		}
	}
	return cnt;
}
