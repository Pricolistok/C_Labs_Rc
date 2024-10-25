#include "input_output.h"

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

void print_matrix(int **arr, size_t n, size_t m)
{
    printf("----------------------------\n");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------\n");
}
