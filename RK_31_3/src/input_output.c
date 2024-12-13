#include "input_output.h"

// Функция для проверки длины файла
int check_len_file(FILE *file)
{
    long int pos_start;
    pos_start = ftell(file);
    fseek(file, 0, SEEK_END);
    if (pos_start == ftell(file))
        return ERROR_LEN_FILE;
    fseek(file, 0, SEEK_SET);
    return OK;
}

// Функция открытия файла ввода
int open_file_in(FILE **file, int argc, char **argv)
{
    int rc;

    if (argc != 3)
        return ERROR_ARGS;

    *file = fopen(argv[1], "r");
    if (*file == NULL)
        return ERROR_OPEN_FILE;

    rc = check_len_file(*file);
    if (rc == ERROR_LEN_FILE)
    {
        fclose(*file);
        return ERROR_LEN_FILE;
    }

    return OK;
}

// Функция открытия файла вывода
int open_file_out(FILE **file, int argc, char **argv)
{
    if (argc != 3)
        return ERROR_ARGS;

    *file = fopen(argv[2], "w");
    if (*file == NULL)
        return ERROR_OPEN_FILE;

    return OK;
}

// Функция подсчета строк и столбцов
void cnt_elem_matrix(FILE *file_in, size_t *n, size_t *m)
{
    char *token;
    char line[LEN_LINE + 1];
    size_t cnt_n = 0, cnt_m = 0;

    while (fgets(line, LEN_LINE + 1, file_in) != NULL)
    {
        if (cnt_n == 0)
        {
            token = strtok(line, " ");
            while (token != NULL)
            {
                cnt_m++;
                token = strtok(NULL, " ");
            }
        }
        cnt_n++;
    }
    *n = cnt_n;
    *m = cnt_m;
}

// Функция ввода в матрицу из файла
void input_from_file(FILE *file, double **arr, size_t m)
{
    char *token;
    char *fn_elem;
    char line[LEN_LINE + 1];
    double value;
    size_t cnt_n = 0, cnt_m = 0;
    fseek(file, 0, SEEK_SET);
    while (fgets(line, LEN_LINE + 1, file) != NULL)
    {
        token = strtok(line, " ");
        cnt_m = 0;
        while (token != NULL)
        {
            value = strtod(token, &fn_elem);
            if (*fn_elem != '\0' && *fn_elem != '\n' && token == fn_elem && cnt_m < m)
            {
                arr[cnt_n][cnt_m] = NAN;
                cnt_m++;
            }
            else if (cnt_m < m)
            {
                arr[cnt_n][cnt_m] = value;
                cnt_m++;
            }
            token = strtok(NULL, " ");
        }
        cnt_n++;
    }
}


// Функция для вывода матрицы в файл
void print_matrix_to_file(double **arr, size_t n, size_t m, FILE *file_out)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            fprintf(file_out, "%lf ", arr[i][j]);
        }
        fprintf(file_out, "\n");
    }
}
