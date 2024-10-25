// Подключение библиотек и файлов
#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "const.h"
#include "struct.h"
#include "input_output.h"
#include "process.h"

// Функция из которой происходит вызов остальных
int main(int argc, char **argv)
{
	// Переменные
	int rc;
	size_t len_arr = 0;
	FILE *file_in;
	item items_arr[LEN_ARR];
	char str_option[LEN_NAME + 2];
	rc = input_file(&file_in, str_option, argc, argv);
	// Проверки открытия файла
	if (rc == ERROR_ARGUMENTS)
	{
		// printf("Error open file\n");
		return rc;
	}
	if (rc == ERROR_OPEN_FILE)
	{
		// printf("Error open file\n");
		return rc;
	}
	if (rc == ERROR_INPUT_FINDER_STR)
	{
		// printf("Error input str\n");
		return rc;
	}
	rc = create_arr(file_in, items_arr, &len_arr);
	// Проверки заполнения массива
	fclose(file_in);
	if (rc == ERROR_LEN_FILE)
	{
		// printf("File is free\n");
		return rc;
	}
	if (rc == ERROR_NAME_IN_FILE)
	{
		// printf("Error name in file\n");
		return rc;
	}
	if (rc == ERROR_WEIGHT_IN_FILE)
	{
		// printf("Error weight in file\n");
		return rc;
	}
	if (rc == ERROR_VOLUME_IN_FILE)
	{
		// printf("Error volume in file\n");
		return rc;
	}
	if (rc == ERROR_LEN_ARR)
	{
		// printf("Error len arr\n");
		return ERROR_LEN_ARR;
	}
	// Выбор функции в зависимости от аругмента
	if (strlen(str_option) == 0)
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
		// Поиск элемента
		rc = find_item(items_arr, len_arr, str_option);
		if (rc == 0)
		{
			// printf("Error find\n");
			return ERROR_FIND;
		}
	}

	return OK;
}
