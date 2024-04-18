#include <stdio.h>

#define N 10

int input_arr(size_t len, int arr[])
{
    int rc, elem;
    for (size_t i = 0; i < len; i++)
    {
        rc = scanf("%d", &elem);
        if (rc == 1)
        {
            arr[i] = elem;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

size_t find_max(size_t len, int arr[])
{
    int max = arr[0];
    size_t index = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] > max)
        {
            index = i;
            max = arr[i];
        }
    }
    return index;
}

void print_res_arr(size_t len_arr, int arr[])
{
    for (size_t i = 0; i < len_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void del_elems(size_t len, size_t index_elem, int arr[])
{
    size_t i = 0;
    while (i < index_elem)
    {
        for (size_t j = i; j < len; j++)
        {
            arr[j] = arr[j + 1];
        }
        index_elem--;
    }
}


int main(void)
{
    int arr[N], rc, res_input;
    size_t len_arr, index_max;
    printf("Input len: ");
    rc = scanf("%lu", &len_arr);
    if (rc != 1 || len_arr > 10 || len_arr < 1)
    {
        printf("Error input len");
        return 1;
    }
    res_input = input_arr(len_arr, arr);
    if (res_input == 1)
    {
        printf("Error input array");
        return 1;
    }
    printf("Введенный массив \n");
    print_res_arr(len_arr, arr);
    index_max = find_max(len_arr, arr);
    if (index_max == 0)
    {
        printf("Изменений нет \n");
    }
    else
    {
        del_elems(len_arr, index_max, arr);
        printf("Конечный массив: \n");
        print_res_arr(len_arr - index_max, arr);
    }
    return 0;
}

