#include "process.h"

// Запись символов в результирующую строку
void write_str(char *str, size_t len_str, size_t *position, char *str_arg, int *flag_overflow)
{
    // printf("%zu\n", len_str);
    while (*str_arg != '\0')
    {
        if (*position < len_str - 1)
        {
            str[*position] = *str_arg;
            // printf("%zu num %c ", *position, str[*position]);
        }
        if (*flag_overflow == 0 && *position >= len_str)
            *flag_overflow = 1;
        *position = *position + 1;
        str_arg++;
    }
    // printf("\n");
}

// Подсчет длины числа
size_t cnt_len_num(long int num)
{
    size_t len = 0;
    while (num != 0)
    {
        num /= 10;
        len++;
    }
    return len;
}

// Переворот строки с числом
void reverse_str_num(const char *str_num, char *new_str, size_t last_position)
{
    for (int i = (int)last_position - 1; i >= 0; i--)
    {
        *new_str = str_num[i];
        new_str++;
    }
    *new_str = 0;
}

// Перевод числа в строковый вид
void write_int_to_str(long int num, char *str_for_num, int flag_negative)
{
    const char *digits = "0123456789";
    size_t position_num = 0;
    while (num != 0)
    {
        str_for_num[position_num] = digits[num % 10];
        num /= 10;
        position_num++;
    }
    if (flag_negative == 1)
    {
        str_for_num[position_num] = '-';
        position_num++;
        str_for_num[position_num] = 0;
    }
    else
        str_for_num[position_num] = 0;
}

// Запись числа в строку
int int_to_str(char *str, long int num, size_t len_str, size_t *position, int *flag_overflow)
{
    int flag_negative = 0, flag_long_min = 0;
    size_t len_num = 0;
    char *str_for_num = NULL, *result_num = NULL;

    if (num < 0 && num != LONG_MIN)
    {
        flag_negative = 1;
        num *= -1;
    }
    else if (num == LONG_MIN)
    {
        flag_negative = 1;
        flag_long_min = 1;
        num++;
        num *= -1;
    }
    len_num = cnt_len_num(num) + flag_negative;
    str_for_num = malloc(len_num + 1);
    if (!str_for_num)
        return ERROR_ADD_MEMORY;

    result_num = malloc(len_num + 1);
    if (!result_num)
        return ERROR_ADD_MEMORY;

    write_int_to_str(num, str_for_num, flag_negative);
    reverse_str_num(str_for_num, result_num, len_num);
    if (flag_long_min == 1)
        result_num[strlen(result_num) - 1] = '8';
    if (*flag_overflow != 1)
        write_str(str, len_str, position, result_num, flag_overflow);
    else
        *position = *position + strlen(result_num);
    free(str_for_num);
    free(result_num);
    return OK;
}

// Собственна реализация snprintf
int my_snprintf(char *str, size_t n, const char *format, ...)
{
    int rc, result_len;;
    va_list vl;
    long int long_int_argument;
    const char *ptr, *saver_ptr;
    int flag_overflow = 0;
    char *str_arg;
    size_t position = 0;

    va_start(vl, format);
    if (n == 0)
        flag_overflow = 1;
    if (str == NULL && n != 0)
        return -1;
    ptr = format;
    while (*ptr != 0)
    {
        if (flag_overflow == 0 && position >= n)
            flag_overflow = 1;


        saver_ptr = ptr + 1;
        if (*ptr == '%')
        {
            if (*saver_ptr == '%')
            {
                ptr += 2;
                if (flag_overflow != 1)
                    str[position] = '%';
                position++;
                continue;
            }
            ptr++;
            if (*ptr == 's')
            {
                str_arg = va_arg(vl, char*);
                if (flag_overflow != 1)
                    write_str(str, n, &position, str_arg, &flag_overflow);
                else
                    position += strlen(str_arg);
            }
            saver_ptr = ptr + 1;
            if (*ptr == 'l' && *saver_ptr == 'i')
            {
                ptr++;
                long_int_argument = va_arg(vl, long int);
                rc = int_to_str(str, long_int_argument, n, &position, &flag_overflow);
                if (rc == ERROR_ADD_MEMORY)
                    return ERROR_ADD_MEMORY;
            }
        }
        else
        {
            if (position < n)
                str[position] = *ptr;
            position++;
        }
        ptr++;
    }
    va_end(vl);
    if (flag_overflow == 1)
    {
        if (n != 0)
            str[n - 1] = 0;
    }
    else
    {
        str[position] = 0;
    }
    result_len = position;
    return result_len;
}
