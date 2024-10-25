// Файл для открытия файла, а так же для заполнения и вывод массива
// Подключенные библиотеки и файлы
#include <stdio.h>
#include <string.h>
#include "input_output.h"

// Проверка файла
int check_file(FILE *file)
{
	fseek(file, 0, SEEK_END);
	if (ftell(file) == 0)
	{
		return ERROR_LEN_FILE;
	}
	fseek(file, 0, SEEK_SET);
	return OK;
}

void prin_item(item items_arr[], size_t index_item)
{
	printf("%s\n", items_arr[index_item].name);
	printf("%lf\n", items_arr[index_item].weight);
	printf("%lf\n", items_arr[index_item].volume);
}

// Вывод массива
void print_arr(item items_arr[], size_t len_arr)
{
	for (size_t i = 0; i < len_arr; i++)
	{
		prin_item(items_arr, i);
	}
}

int read_item(FILE *file, item items_arr[], size_t cnt_struct)
{
	int rc;
	char saver_name[LEN_NAME + 2];
	double saver_weight, saver_volume;
	fgets(saver_name, LEN_NAME + 1, file);
	saver_name[strlen(saver_name) - 1] = 0;
	if (strlen(saver_name) > LEN_NAME || strlen(saver_name) == 0)
	{
		return ERROR_NAME_IN_FILE;
	}
	rc = fscanf(file, "%lf", &saver_weight);
	if (rc != 1 || saver_weight <= 0)
	{
		return ERROR_WEIGHT_IN_FILE;
	}
	rc = fscanf(file, "%lf", &saver_volume);
	fgetc(file);
	if (rc != 1 || saver_volume <= 0)
		return ERROR_VOLUME_IN_FILE;
	strcpy(items_arr[cnt_struct].name, saver_name);
	items_arr[cnt_struct].weight = saver_weight;
	items_arr[cnt_struct].volume = saver_volume;
	strcpy(saver_name, "");
	return OK;
}

// Заполнение массива
int create_arr(FILE *file, item items_arr[], size_t *len_arr)
{
	size_t cnt_struct = 0;
	int rc;
	if (check_file(file) == ERROR_LEN_FILE)
		return ERROR_LEN_FILE;
	while (!feof(file))
	{
		if (cnt_struct == LEN_ARR)
			return ERROR_LEN_ARR;
		rc = read_item(file, items_arr, cnt_struct);
		if (rc != OK)
		{
			return rc;
		}
		cnt_struct++;
	}
	*len_arr = cnt_struct;
	return OK;
}

// Открытие файла
int input_file(FILE **file_in, char str_option[LEN_NAME + 2], int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return ERROR_ARGUMENTS;
	if ((*file_in = fopen(argv[1], "r")) == NULL)
	{
		return ERROR_OPEN_FILE;
	}
	strcpy(str_option, "");
	if (argc == 3)
	{
		if (strlen(argv[2]) > LEN_NAME)
		{
			return ERROR_INPUT_FINDER_STR;
		}
		strcpy(str_option, argv[2]);
	}
	return OK;
}
