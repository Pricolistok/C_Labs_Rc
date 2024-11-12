// Подключение библиотек и файлов
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errors.h"
#include "struct.h"
#include "input_output.h"
#include "process.h"

// Функция из которой происходит вызов остальных
int main(int argc, char **argv)
{
	// Переменные
	int rc;
	int *arr_for_print = NULL;
	size_t len_arr = 0;
	FILE *file_in;
	item *items_arr = NULL;
	char *str_option = NULL;
	size_t len_option = 0;
	// Открытие файла и обработка аргументов
	rc = input_file(&file_in, &str_option, argc, argv, &len_option);
	// Обработка открытия файла
	switch (rc)
	{
		case ERROR_ADD_MEMORY:
			return ERROR_ADD_MEMORY;
		case ERROR_ARGUMENTS:
			return ERROR_ARGUMENTS;
		case ERROR_OPEN_FILE:
			return ERROR_OPEN_FILE;
		case ERROR_INPUT_FINDER_STR:
			return ERROR_INPUT_FINDER_STR;
		case ERROR_LEN_FILE:
			return ERROR_LEN_FILE;
	}
	// Поодсчет количества структур в файле
	rc = cnt_structs(file_in, &len_arr);
	// Проверка элементов файла
	fclose(file_in);
	switch (rc)
	{
		case ERROR_ADD_MEMORY:
			free(str_option);
			return ERROR_ADD_MEMORY;
		case ERROR_NAME_IN_FILE:
			free(str_option);
			return ERROR_NAME_IN_FILE;
		case ERROR_WEIGHT_IN_FILE:
			free(str_option);
			return ERROR_WEIGHT_IN_FILE;
		case ERROR_VOLUME_IN_FILE:
			free(str_option);
			return ERROR_VOLUME_IN_FILE;
	}
	// Выделение памяти для массива структур
	rc = add_memory(&items_arr, len_arr);
	if (rc == ERROR_ADD_MEMORY)
		return ERROR_ADD_MEMORY;

	// Открыттие файла
	rc = open_file(&file_in, argv);
	// Обработка ошибок при открытии файла
	switch (rc)
	{
		case ERROR_OPEN_FILE:
			free(str_option);
			free(items_arr);
			return ERROR_OPEN_FILE;
		case ERROR_LEN_FILE:
			free(str_option);
			free(items_arr);
			return ERROR_LEN_FILE;
	}

	// Заполнение массива структур
	rc = create_arr(file_in, items_arr, len_arr);
	if (rc == ERROR_ADD_MEMORY)
	{
		fclose(file_in);
		return ERROR_ADD_MEMORY;
	}

	// Выбор функции в зависимости от аругмента
	if (len_option == 0)
	{
		sort_arr(items_arr, len_arr);
		print_arr(items_arr, len_arr);
	}
	else if (strcmp(str_option, "ALL") == 0)
	{
		print_arr(items_arr, len_arr);
	}
	else
	{
		// Выделение памяти под массив, хранящий в себе индексы найденных элемментов
		rc = add_memory_for_print(&arr_for_print, len_arr);
		if (rc == ERROR_ADD_MEMORY)
		{
			for (size_t i = 0; i < len_arr; i++)
				free(items_arr[i].name);
			free(str_option);
			free(items_arr);
			fclose(file_in);
			return ERROR_ADD_MEMORY;
		}
		// Поиск элементов в массиве
		rc = find_item(items_arr, len_arr, str_option, arr_for_print);
		if (rc == 0)
		{
			for (size_t i = 0; i < len_arr; i++)
				free(items_arr[i].name);
			free(str_option);
			free(items_arr);
			free(arr_for_print);
			fclose(file_in);
			// printf("Error find\n");
			return ERROR_FIND;
		}
		// Вывод найденных элементов массива
		for (int i = 0; i < rc; i++)
			print_item(items_arr, arr_for_print[i]);
		// Освобождение выделенной памяти под массив индексов
		free(arr_for_print);
	}
	// Освобождение памяти под массив структур
	for (size_t i = 0; i < len_arr; i++)
		free(items_arr[i].name);
	free(str_option);
	free(items_arr);
	fclose(file_in);
	return OK;
}
