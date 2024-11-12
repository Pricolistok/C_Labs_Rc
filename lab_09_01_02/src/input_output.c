// Файл для открытия файла, а так же для заполнения и вывод массива
// Подключенные библиотеки и файлы
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

// Вывод одного элемента
void print_item(item *items_arr, size_t index_item)
{
	printf("%s\n", items_arr[index_item].name);
	printf("%lf\n", items_arr[index_item].weight);
	printf("%lf\n", items_arr[index_item].volume);
}

// Вывод массива
void print_arr(item *items_arr, size_t len_arr)
{
	for (size_t i = 0; i < len_arr; i++)
		print_item(items_arr, i);
}

// Функиця для обработки одного считанного элемента
int cnt_item(FILE *file)
{
	int rc;
	size_t len_name = 0;
	char ch;
	double saver_weight, saver_volume;

	while ((ch = fgetc(file)) != '\n' && ch != EOF)
		len_name++;
	if (len_name == 0)
		return ERROR_NAME_IN_FILE;

	rc = fscanf(file, "%lf", &saver_weight);
	if (rc != 1 || saver_weight <= 0)
		return ERROR_WEIGHT_IN_FILE;

	rc = fscanf(file, "%lf", &saver_volume);
	fgetc(file);
	if (rc != 1 || saver_volume <= 0)
		return ERROR_VOLUME_IN_FILE;
	return OK;
}

// Выделение памяти под название
int add_memory_for_name(char **name, size_t len)
{
	*name = malloc(len * sizeof(char));
	if (!name)
		return ERROR_ADD_MEMORY;
	return OK;
}

// Функция для считывания файла
int read_item(FILE *file, item *items_arr, size_t cnt_struct)
{
	size_t len_name = 0;
	long int saver_pos = ftell(file);
	char ch;
	double saver_weight, saver_volume;

	items_arr[cnt_struct].name = NULL;

	while ((ch = fgetc(file)) != '\n' && ch != EOF)
		len_name++;

	items_arr[cnt_struct].name = malloc(len_name + 1);
	if (items_arr[cnt_struct].name == NULL)
		return ERROR_ADD_MEMORY;

	fseek(file, saver_pos, SEEK_SET);
	for (size_t i = 0; i < len_name; i++)
		items_arr[cnt_struct].name[i] = fgetc(file);
	items_arr[cnt_struct].name[len_name] = 0;

	fscanf(file, "%lf", &saver_weight);
	fscanf(file, "%lf", &saver_volume);
	fgetc(file);

	items_arr[cnt_struct].weight = saver_weight;
	items_arr[cnt_struct].volume = saver_volume;
	items_arr[cnt_struct].len_name = len_name;
	
	return OK;
}

// Функция для подсчета количества структур
int cnt_structs(FILE *file, size_t *len_arr)
{
	int rc;
	size_t cnt_struct = 0;
	while (!feof(file))
	{
		rc = cnt_item(file);
		if (rc != OK)
			return rc;
		cnt_struct++;
	}
	*len_arr = cnt_struct;
	return OK;
}

// Заполнение массива
int create_arr(FILE *file, item *items_arr, size_t len_arr)
{
	int rc;
	for (size_t i = 0; i < len_arr; i++)
	{
		rc = read_item(file, items_arr, i);
		if (rc == ERROR_ADD_MEMORY)
		{
			for (size_t j = 0; j < i; j++)
				free(items_arr[j].name);
			free(items_arr);
			return ERROR_ADD_MEMORY;
		}
	}
	return OK;	
}

// Открытие файла и обработка ошибок
int input_file(FILE **file_in, char **str_option, int argc, char **argv, size_t *len_arg)
{
	int rc;
	size_t len_name = 0;
	
	if (argc < 2 || argc > 3)
		return ERROR_ARGUMENTS;

	if ((*file_in = fopen(argv[1], "r")) == NULL)
		return ERROR_OPEN_FILE;

	if (argc == 3)
	{
		len_name = strlen(argv[2]);
		*str_option = malloc(len_name + 1);
		if (*str_option == NULL)
			return ERROR_ADD_MEMORY;
		
		strcpy(*str_option, argv[2]);
		*len_arg = len_name;
	}
	rc = check_file(*file_in);
	if (rc == ERROR_LEN_FILE)
	{
		if (argc == 3)
			free(*str_option);
		fclose(*file_in);
		return ERROR_LEN_FILE;
	}
	return OK;
}

// Открытие файла
int open_file(FILE **file_in, char **argv)
{
	int rc;

	if ((*file_in = fopen(argv[1], "r")) == NULL)
		return ERROR_OPEN_FILE;

	rc = check_file(*file_in);
	if (rc == ERROR_LEN_FILE)
	{
		fclose(*file_in);
		return ERROR_LEN_FILE;
	}
	return OK;
}
