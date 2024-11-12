#include "process.h"

// Функция для начального выделения памяти
int **add_memory(size_t n, size_t m)
{
    int **arr = malloc(n * sizeof(int*));
    if (!arr)
        return NULL;

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = malloc(m * sizeof(int));
        if (!arr[i])
        {
            free_memory(arr, i);
            return NULL;
        }
    }
    return arr;
}

// Функция для освобождения памяти
void free_memory(int **arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

// Функция для поиска минимального
void find_elems(int **arr, size_t n, size_t m, size_t *id_n, size_t *id_m)
{
    int mini = arr[0][0];
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (arr[j][i] <= mini)
            {
                *id_n = j;
                *id_m = i;
                mini = arr[j][i];
            }
        }
    }
}

// Функция обмена строк
void change_rows(int **arr, size_t index_1, size_t index_2)
{
    int *tmp;
    
    tmp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = tmp;
}

// Функция обмена столбцов
void change_columns(int **arr, size_t index_1, size_t index_2, size_t n)
{
    int tmp;

    for (size_t i = 0; i < n; i++)
    {
        tmp = arr[i][index_1];
        arr[i][index_1] = arr[i][index_2];
        arr[i][index_2] = tmp;
    }
}

// Функция удаления строк
int **remove_rows(int **arr, size_t *n, size_t m, int cnt_rm_rows)
{
    size_t id_n, id_m;
    int **temp = NULL;
    for (size_t i = 0; i < (size_t)cnt_rm_rows; i++)
    {
        find_elems(arr, *n, m, &id_n, &id_m);
        for (size_t j = id_n; j < *n - 1; j++)
        {
            change_rows(arr, j, j + 1);
        }

        free(arr[*n - 1]);
        *n = *n - 1;
        temp = realloc(arr, *n * sizeof(int*));
        if (!temp)
        {
            free_memory(arr, *n);
            return NULL;
        }
        arr = temp;
    }
    return arr;
}

// Функция для удаления столбцов
int **remove_columns(int **arr, size_t n, size_t *m, int cnt_rm_columns)
{
    size_t id_n, id_m;
    int *tmp = NULL;
    for (size_t i = 0; i < (size_t)cnt_rm_columns; i++)
    {
        find_elems(arr, n, *m, &id_n, &id_m);
        for (size_t j = id_m; j < *m - 1; j++)
        {
            change_columns(arr, j, j + 1, n);
        }
        tmp = realloc(arr[i], (*m - 1) * sizeof(int));
        if (!tmp)
        {
            free_memory(arr, n);
            return NULL;
        }
        arr[i] = tmp;
        *m = *m - 1;
    }
    return arr;
}

// Функциия для подсчета количества элементов для удаления
void cnt_remove(size_t n, size_t m, int *rm_rows, int *rm_columns)
{
    if (n > m)
    {
        *rm_rows = n - m;
        *rm_columns = 0;
    }
    else
    {
        *rm_rows = 0;
        *rm_columns = m - n;
    }
}

// Функция для выделения новой памяти
int create_new_memory_for_rows(int ***arr, size_t n, size_t m, size_t add_size)
{
    int **tmp = realloc(*arr, (n + add_size) * sizeof(int*));
    if (!tmp)
    {
        free_memory(*arr, n);
        return ERROR_ADD_MEMORY;
    }
    *arr = tmp;

    for (size_t i = n; i < n + add_size; i++)
    {
        (*arr)[i] = malloc(m * sizeof(int));
        if (!(*arr)[i])
        {
            free_memory(*arr, i);
            return ERROR_ADD_MEMORY;
        }
    }
    return OK;
}

// Функция для заполнения строк
int add_row_to_arr(int **arr, size_t n, size_t m, size_t add_size)
{
    int cnt = 1;

    for (size_t i = n; i < n + add_size; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            for (size_t z = 0; z < i; z++)
            {
                if (arr[z][j] < 0)
                    return ERROR_CNT_GEO;
                cnt *= arr[z][j];
            }
            arr[i][j] = (int)pow(cnt, 1.0 / (double)i);
            cnt = 1;
        }
    }
    return OK;
}

// Функция для выделения памяти под новые столбцы
int create_new_memory_for_columns(int ***arr, size_t n, size_t m, size_t add_size)
{
    int *tmp = NULL;
    for (size_t i = 0; i < n; i++)
    {
        tmp = realloc((*arr)[i], (m + add_size) * sizeof(int));
        if (!tmp)
        {
            free_memory(*arr, n);
            return ERROR_ADD_MEMORY;
        }
        (*arr)[i] = tmp;
    }
    return OK;
}

// Функция для заполнения столбцов
void add_column_to_arr(int **arr, size_t n, size_t m, size_t add_size)
{
    int mini;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t z = 0; z < add_size; z++)
        {
            mini = arr[i][0];
            for (size_t j = 0; j < m + z; j++)
            {
                if (arr[i][j] < mini)
                    mini = arr[i][j];
            }
            arr[i][m + z] = mini;
        }
    }
}

// Функция для копирования матрицы
void copy_arr(int **arr_1, int **arr_2, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
            arr_1[i][j] = arr_2[i][j];
    }
}

// Функция для перемножения матриц
int matrix_multiplication(int **arr_a, int **arr_b, size_t n)
{
    int cnt = 0;
    int *arr_res = NULL;

    arr_res = malloc(n * n * sizeof(int));
    if (!arr_res)
        return ERROR_ADD_MEMORY;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            for (size_t z = 0; z < n; z++)
                cnt += (arr_a[j][z] * arr_b[z][i]);
                
            arr_res[i * n + j] = cnt;
            cnt = 0;
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            arr_a[j][i] = arr_res[i * n + j];
        }
    }
    free(arr_res);
    return OK;
}

// Функция для создания единичной матрицы
void create_unit_matrix(int **arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (i == j)
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }
}
