#include <stdio.h>

int find_ab(int num, int a, int b)
{
    int elem;
    while (num > 0)
    {
        elem = num % 10;
        if (elem == a)
        {
            return 100;
        }
        else if (elem == b)
        {
            return 200;
        }
        num /= 10;
    }
    return 0;
}

int check_num(int num, int a, int b)
{
    int check_a = 1, check_b = 1, elem;
    while (num > 0)
    {
        elem = num % 10;
        if (elem == a)
        {
            check_a = 0;
        }
        else if (elem == b)
        {
            check_b = 0;
        }
        num /= 10;
    }
    if (check_a == 0 && check_b == 0)
    {
        return 0;
    }
    return 1;
}

int main(void)
{
    int a, b, num, rc, res_check, res_find;
    printf("Input num, a, b: ");
    rc = scanf("%d %d %d", &num, &a, &b);
    if (rc != 3)
    {
        printf("Error input value");
        return 1;
    }
    res_check = check_num(num, a, b);
    if (res_check == 1)
    {
        printf("Error, heven`t a or b");
        return 1;
    }
    res_find = find_ab(num, a, b);
    if (res_find == 100)
    {
        printf("Правее расположено число a");
    }
    else if (res_find == 200)
    {
        printf("Правее расположено число b");
    }
    else
    {
        printf("Error");
    }
    return 0;
}

// gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -o app.exe main.c -lm
