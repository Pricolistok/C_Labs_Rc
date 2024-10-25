#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "input_output.h"
#include "process.h"


int main(void)
{
    int rc;
    int **arr_a = NULL;
    int rm_rows_a = 0, rm_columns_a = 0;
    size_t m_a, n_a;

    int **arr_b = NULL;
    int rm_rows_b = 0, rm_columns_b = 0;
    size_t m_b, n_b;

    size_t add_size;

    rc = input_sizes(&n_a, &m_a);

    printf("Ввод матрицы A\n");
    switch (rc)
    {
    case ERROR_IN_M:
        printf("Ошибка при введении M!\n");
        return ERROR_IN_M;
        
    case ERROR_IN_N:
        printf("Ошибка при введении N!\n");
        return ERROR_IN_N;
    }

    if (n_a == m_a)
    {
        printf("Матрица уже квадратная!\n");
        return SQUARE_MATRIX;
    }

    arr_a = add_memory(n_a, m_a);
    if (!arr_a)
    {
        printf("Ошибка выделения памяти!\n");
        return ERROR_ADD_MEMORY;
    }

    rc = input_matrix(arr_a, n_a, m_a);
    if (rc == ERROR_INPUT_ELEM)
    {
        printf("Ошибка ввода элемента!\n");
        return ERROR_INPUT_ELEM;
    }

    cnt_remove(n_a, m_a, &rm_rows_a, &rm_columns_a);
    
    if ((rm_rows_a != 0) && (rm_columns_a == 0))
        remove_rows(arr_a, &n_a, m_a, rm_rows_a);
    else if ((rm_rows_a == 0) && (rm_columns_a != 0))
        remove_columns(arr_a, n_a, &m_a, rm_columns_a);
    print_matrix(arr_a, n_a, m_a);

    printf("Ввод матрицы B\n");
    rc = input_sizes(&n_b, &m_b);

    switch (rc)
    {
    case ERROR_IN_M:
        printf("Ошибка при введении M!\n");
        return ERROR_IN_M;
        
    case ERROR_IN_N:
        printf("Ошибка при введении N!\n");
        return ERROR_IN_N;
    }

    if (n_b == m_b)
    {
        printf("Матрица уже квадратная!\n");
        return SQUARE_MATRIX;
    }

    arr_b = add_memory(n_b, m_b);
    if (!arr_b)
    {
        printf("Ошибка выделения памяти!\n");
        return ERROR_ADD_MEMORY;
    }

    rc = input_matrix(arr_b, n_b, m_b);
    if (rc == ERROR_INPUT_ELEM)
    {
        printf("Ошибка ввода элемента!\n");
        return ERROR_INPUT_ELEM;
    }

    cnt_remove(n_b, m_b, &rm_rows_b, &rm_columns_b);
    
    if ((rm_rows_b != 0) && (rm_columns_b == 0))
        remove_rows(arr_b, &n_b, m_b, rm_rows_b);
    else if ((rm_rows_b == 0) && (rm_columns_b != 0))
        remove_columns(arr_b, n_b, &m_b, rm_columns_b);
    
    print_matrix(arr_b, n_b, m_b);

    if (n_a > n_b)
    {
        add_size = n_a - n_b;
        rc = create_new_memory_for_rows(&arr_b, n_b, m_b, add_size);
        if (rc == ERROR_ADD_MEMORY)
        {
            printf("Ошибка выделения памяти\n");
            return ERROR_ADD_MEMORY;
        }
        add_row_to_arr(arr_b, n_b, m_b, add_size);
        rc = create_new_memory_for_columns(&arr_b, n_b, m_b, add_size);
        if (rc == ERROR_ADD_MEMORY)
        {
            printf("Ошибка выделения памяти2!\n");
            return ERROR_ADD_MEMORY;
        }
        add_column_to_arr(arr_b, n_b, m_b, add_size);
    }
    else if (n_b > n_a)
    {
        add_size = n_b - n_a;
        printf("BUBA1");
        rc = create_new_memory_for_rows(&arr_a, n_a, m_a, add_size);
        if (rc == ERROR_ADD_MEMORY)
        {
            printf("Ошибка выделения памяти\n");
            return ERROR_ADD_MEMORY;
        }
        printf("BUBA2");
        add_row_to_arr(arr_a, n_a, m_a, add_size);
        printf("BUBA3");
        rc = create_new_memory_for_columns(&arr_a, n_a, m_a, add_size);
        if (rc == ERROR_ADD_MEMORY)
        {
            printf("Ошибка выделения памяти4!\n");
            return ERROR_ADD_MEMORY;
        }
        printf("BUBA4");
        add_column_to_arr(arr_a, n_a, m_a, add_size);
    }

    free_memory(arr_a, n_a);
    return OK;
}