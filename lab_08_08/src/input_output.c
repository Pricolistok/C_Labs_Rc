#include "input_output.h"

// Функция ввода размеров матриц
int input_sizes(size_t *n, size_t *m)
{
    int rc, n_int, m_int;
    printf("Введите N: ");
    rc = scanf("%d", &n_int);
    if ((rc != 1) || (n_int <= 0))
        return ERROR_IN_N;
    
    printf("Введите M: ");
    rc = scanf("%d", &m_int);
    if ((rc != 1) || (m_int <= 0))
        return ERROR_IN_M;

    *n = n_int;
    *m = m_int;

    return OK;
}

// Функция заполнения матриц
int input_matrix(int **arr, size_t n, size_t m)
{
    int rc, elem;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            rc = scanf("%d", &elem);
            if (rc != 1)
                return ERROR_INPUT_ELEM;
            arr[i][j] = elem;
        }
    }
    return OK;
}

// Функция вывода матрицы
void print_matrix(int **arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Ввод степеней матриц
int input_params_multuplication(size_t *cnt_p, size_t *cnt_q)
{
    int rc, p_int, q_int;
    printf("Введите p: ");
    rc = scanf("%d", &p_int);
    if ((rc != 1) || (p_int < 0))
        return ERROR_IN_P;
    
    printf("Введите q: ");
    rc = scanf("%d", &q_int);
    if ((rc != 1) || (q_int < 0))
        return ERROR_IN_Q;

    *cnt_p = p_int;
    *cnt_q = q_int;

    return OK;
}
