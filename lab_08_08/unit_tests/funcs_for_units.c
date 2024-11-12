#include "funcs_for_unit.h"
#include "errors.h"

// Функция записи данных из одномерного массива в матрицу
void input_data_to_mtrix(int **arr, int data[], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            arr[i][j] = data[i * m + j];
        }
    }
}

// Функция для сравнивания матриц
int check_result(int **arr, int data[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (arr[i][j] != data[i * n + j])
                return ERROR;
        }
    }
    return OK;
}
