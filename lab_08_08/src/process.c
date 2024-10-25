#include "process.h"

int** add_memory(size_t n, size_t m)
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

void free_memory(int **arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

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

void change_rows(int **arr, size_t index_1, size_t index_2)
{
    int *tmp;
    
    tmp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = tmp;
}

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


void remove_rows(int **arr, size_t *n, size_t m, int cnt_rm_rows)
{
    size_t id_n, id_m;
    for (size_t i = 0; i < (size_t)cnt_rm_rows; i++)
    {
        find_elems(arr, *n, m, &id_n, &id_m);
        for (size_t j = id_n; j < *n - 1; j++)
        {
            change_rows(arr, j, j + 1);
        }
        free(arr[*n - 1]);
        *n = *n - 1;
    }
}

void remove_columns(int **arr, size_t n, size_t *m, int cnt_rm_columns)
{
    size_t id_n, id_m;
    for (size_t i = 0; i < (size_t)cnt_rm_columns; i++)
    {
        find_elems(arr, n, *m, &id_n, &id_m);
        for (size_t j = id_m; j < *m - 1; j++)
        {
            change_columns(arr, j, j + 1, n);
        }
        *m = *m - 1;

    }
}

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
        *arr[i] = malloc(m * sizeof(int));
        if (!arr[i])
        {
            free_memory(*arr, i);
            return ERROR_ADD_MEMORY;
        }
    }
    return OK;
}

void add_row_to_arr(int **arr, size_t n, size_t m, size_t add_size)
{
    int cnt = 1;

    for (size_t i = n; i < n + add_size; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            for (size_t z = 0; z < i; z++)
            {
                cnt *= arr[j][z];
            }
            arr[i][j] = (int)pow(cnt, 1 / (int)i);
            cnt = 1;
        }
    }
}

int create_new_memory_for_columns(int ***arr, size_t n, size_t m, size_t add_size)
{
    int *tmp = NULL;
    for (size_t i = 0; i < n; i++)
    {
        tmp = realloc(*arr[i],  (m + add_size) * sizeof(int));
        if (!tmp)
        {
            free_memory(*arr, n);
            return ERROR_ADD_MEMORY;
        }
        *arr[i] = tmp;
    }
    return OK;
}

void add_column_to_arr(int **arr, size_t n, size_t m, size_t add_size)
{
    int mini;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t z = 0; z < add_size; z++)
        {
            mini = arr[i][0];
            for (size_t j; j < m + z; j++)
            {
                if (arr[i][j] < mini)
                    mini = arr[i][j];
            }
            arr[i][m + z] = mini;
        }
    }
}