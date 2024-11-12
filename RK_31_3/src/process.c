#include "process.h"

// Функция для начального выделения памяти
double **add_memory(size_t n, size_t m)
{
    double **arr = malloc(n * sizeof(double*));
    if (!arr)
        return NULL;

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = malloc(m * sizeof(double));
        if (!arr[i])
        {
            free_memory(arr, i);
            return NULL;
        }
    }
    return arr;
}

// Функция для освобождения памяти
void free_memory(double **arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

