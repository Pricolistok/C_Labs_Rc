#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "input_output.h"
#include "process.h"


int main(void)
{
    // Инициализация переменных
    int rc;
    int **arr_a = NULL;
    int rm_rows_a = 0, rm_columns_a = 0;
    size_t m_a, n_a;

    int **arr_b = NULL;
    int rm_rows_b = 0, rm_columns_b = 0;
    size_t m_b, n_b;

    int **arr_saver = NULL;

    size_t q = 0, p = 0;

    size_t add_size;

    // Ввод размеров матрицы 1
    rc = input_sizes(&n_a, &m_a);

    // Обработка ошибок
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

    // Выделение памяти для хранения матрицы 1
    arr_a = add_memory(n_a, m_a);
    if (!arr_a)
    {
        printf("Ошибка выделения памяти!\n");
        return ERROR_ADD_MEMORY;
    }

    // Ввод элементов матрицы
    rc = input_matrix(arr_a, n_a, m_a);
    if (rc == ERROR_INPUT_ELEM)
    {
        free_memory(arr_a, n_a);
        printf("Ошибка ввода элемента!\n");
        return ERROR_INPUT_ELEM;
    }

    // Подсчет количества удаляемых элементов
    cnt_remove(n_a, m_a, &rm_rows_a, &rm_columns_a);
    
    // Удаление элементов
    if ((rm_rows_a != 0) && (rm_columns_a == 0))
    {
        arr_a = remove_rows(arr_a, &n_a, m_a, rm_rows_a);
        if (arr_a == NULL)
        {
            printf("Ошибка выделения памяти!\n");
            return ERROR_ADD_MEMORY;
        }
    }
    else if ((rm_rows_a == 0) && (rm_columns_a != 0))
    {
        arr_a = remove_columns(arr_a, n_a, &m_a, rm_columns_a);
        if (arr_a == NULL)
        {
            printf("Ошибка выделения памяти!\n");
            return ERROR_ADD_MEMORY;
        }
    }

    printf("Ввод матрицы B\n");
    // Ввод размера матрицы 2
    rc = input_sizes(&n_b, &m_b);

    // Обработка ошибок
    switch (rc)
    {
        case ERROR_IN_M:
            free_memory(arr_a, n_a);
            printf("Ошибка при введении M!\n");
            return ERROR_IN_M;
        case ERROR_IN_N:
            free_memory(arr_a, n_a);
            printf("Ошибка при введении N!\n");
            return ERROR_IN_N;
    }

    // Выделение памяти для хранения матрицы
    arr_b = add_memory(n_b, m_b);
    if (!arr_b)
    {
        free_memory(arr_a, n_a);
        printf("Ошибка выделения памяти!\n");
        return ERROR_ADD_MEMORY;
    }

    // Ввод элементов матрицы 2
    rc = input_matrix(arr_b, n_b, m_b);
    if (rc == ERROR_INPUT_ELEM)
    {
        free_memory(arr_a, n_a);
        free_memory(arr_b, n_b);
        printf("Ошибка ввода элемента!\n");
        return ERROR_INPUT_ELEM;
    }

    // Подсчет количества элементов для удаления
    cnt_remove(n_b, m_b, &rm_rows_b, &rm_columns_b);

    // Удаление элементов
    if ((rm_rows_b != 0) && (rm_columns_b == 0))
    {
        arr_b = remove_rows(arr_b, &n_b, m_b, rm_rows_b);
        if (arr_b == NULL)
        {
            free_memory(arr_a, n_a);
            free_memory(arr_b, n_b);
            printf("Ошибка выделения памяти!\n");
            return ERROR_ADD_MEMORY;
        }
    }
    else if ((rm_rows_b == 0) && (rm_columns_b != 0))
    {
        arr_b = remove_columns(arr_b, n_b, &m_b, rm_columns_b);
        if (arr_b == NULL)
        {
            free_memory(arr_a, n_a);
            free_memory(arr_b, n_b);
            printf("Ошибка выделения памяти!\n");
            return ERROR_ADD_MEMORY;
        }
    }

    // Добавление элементов, для выравнивания матриц
    if (n_a > n_b)
    {
        add_size = n_a - n_b;
        // Выделение новой памяти для строк
        rc = create_new_memory_for_rows(&arr_b, n_b, m_b, add_size);
        if (rc == ERROR_ADD_MEMORY)
        {
            free_memory(arr_a, n_a);
            free_memory(arr_b, n_b);
            printf("Ошибка выделения памяти\n");
            return ERROR_ADD_MEMORY;
        }
        // Заполнение строк
        rc = add_row_to_arr(arr_b, n_b, m_b, add_size);
        n_b += add_size;
        if (rc == ERROR_CNT_GEO)
        {
            free_memory(arr_a, n_a);
            free_memory(arr_b, n_b);
            printf("Ошибка подсчета среднего геометрического!\n");
            return ERROR_CNT_GEO;
        }
        // Выделение памяти для столбцов
        rc = create_new_memory_for_columns(&arr_b, n_b, m_b, add_size);
        if (rc == ERROR_ADD_MEMORY)
        {
            free_memory(arr_a, n_a);
            free_memory(arr_b, n_b);
            printf("Ошибка выделения памяти!\n");
            return ERROR_ADD_MEMORY;
        }
        // Заполнение столбцов
        add_column_to_arr(arr_b, n_b, m_b, add_size);
        m_b += add_size;
    }
    else if (n_b > n_a)
    {
        add_size = n_b - n_a;
        // Выделение новой памяти для строк
        rc = create_new_memory_for_rows(&arr_a, n_a, m_a, add_size);
        if (rc == ERROR_ADD_MEMORY)
        {
            free_memory(arr_a, n_a);
            free_memory(arr_b, n_b);
            printf("Ошибка выделения памяти\n");
            return ERROR_ADD_MEMORY;
        }
        // Заполнение строк
        rc = add_row_to_arr(arr_a, n_a, m_a, add_size);
        n_a += add_size;
        if (rc == ERROR_CNT_GEO)
        {
            free_memory(arr_a, n_a);
            free_memory(arr_b, n_b);
            printf("Ошибка подсчета среднего геометрического!\n");
            return ERROR_CNT_GEO;
        }
        // Выделение памяти для столбцов
        rc = create_new_memory_for_columns(&arr_a, n_a, m_a, add_size);
        if (rc == ERROR_ADD_MEMORY)
        {
            free_memory(arr_a, n_a);
            free_memory(arr_b, n_b);
            printf("Ошибка выделения памяти!\n");
            return ERROR_ADD_MEMORY;
        }
        // Заполнение столбцов
        add_column_to_arr(arr_a, n_a, m_a, add_size);
        m_a += add_size;
    }
    
    // Ввод степеней матриц
    rc = input_params_multuplication(&p, &q);
    // Обработка ошибок
    switch (rc)
    {
        case ERROR_IN_P:
            free_memory(arr_a, n_a);
            free_memory(arr_b, n_b);
            printf("Ошибка при введении P!\n");
            return ERROR_IN_M;
        case ERROR_IN_Q:
            free_memory(arr_a, n_a);
            free_memory(arr_b, n_b);
            printf("Ошибка при введении Q!\n");
            return ERROR_IN_N;
    }
    // Возведение в степени
    if (p > 1)
    {
        arr_saver = add_memory(n_a, n_a);
        if (!arr_saver)
        {
            printf("Ошибка выделения памяти!\n");
            free_memory(arr_a, n_a);
            free_memory(arr_b, n_b);
            return ERROR_ADD_MEMORY;
        }
        copy_arr(arr_saver, arr_a, n_a);
        for (size_t i = 0; i < p - 1; i++)
            matrix_multiplication(arr_a, arr_saver, n_a);
        free_memory(arr_saver, n_a);
    }
    if (q > 1)
    {
        arr_saver = add_memory(n_b, n_b);
        if (!arr_saver)
        {
            free_memory(arr_a, n_a);
            free_memory(arr_b, n_b);
            printf("Ошибка выделения памяти!\n");
            return ERROR_ADD_MEMORY;
        }
        copy_arr(arr_saver, arr_b, n_b);
        for (size_t i = 0; i < q - 1; i++)
            matrix_multiplication(arr_b, arr_saver, n_b);
        free_memory(arr_saver, n_a);
    }

    // Итоговое перемножение
    if (p == 0 && q != 0)
    {
        create_unit_matrix(arr_a, n_a);
        matrix_multiplication(arr_a, arr_b, n_a);
        print_matrix(arr_a, n_a);
    }
    else if (q == 0 && p != 0)
    {
        create_unit_matrix(arr_b, n_b);
        matrix_multiplication(arr_a, arr_b, n_a);
        print_matrix(arr_a, n_a);
    }
    else if (p == 0 && q == 0)
    {
        create_unit_matrix(arr_a, n_a);
        create_unit_matrix(arr_b, n_b);
        matrix_multiplication(arr_a, arr_b, n_a);
        print_matrix(arr_a, n_a);
    }
    else
    {
        matrix_multiplication(arr_a, arr_b, n_a);
        print_matrix(arr_a, n_a);
    }

    // Очистка памяти
    free_memory(arr_a, n_a);
    free_memory(arr_b, n_b);
    return OK;
}
