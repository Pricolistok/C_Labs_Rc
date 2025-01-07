#include "process.h"

void write_str(char *str, size_t len_str, size_t *position, char *str_arg)
{
    while (*str_arg != '\0' && *position < len_str)
    {
        str[*position] = *str_arg;
        str_arg++;
        *position = *position + 1;
    }
}

size_t cnt_len_num(int num)
{
    size_t len = 0;
    while (num != 0)
    {
        num /= 10;
        len++;
    }
    return len;
}

void reverse_str_num(const char *str_num, char *new_str, size_t last_position)
{
    for (int i = (int)last_position - 1; i >= 0; i--)
    {
        *new_str = str_num[i];
        new_str++;
    }
    *new_str = 0;
}

void write_int_to_str(long int num, size_t position, size_t len_str, char *str_for_num, int flag_negative)
{
    const char *digits = "0123456789";
    size_t position_num = 0;
    while (num != 0 && position + position_num < len_str)
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

int int_to_str(char *str, long int num, size_t len_str, size_t *position)
{
    int flag_negative = 0;
    size_t len_num = 0;
    char *str_for_num = NULL, *result_num = NULL;

    len_num = cnt_len_num(num);
    if (num < 0)
    {
        len_num++;
        flag_negative = 1;
        num *= -1;
    }
    str_for_num = malloc(len_num + 1);
    if (!str_for_num)
        return ERROR_ADD_MEMORY;

    result_num = malloc(len_num + 1);
    if (!result_num)
        return ERROR_ADD_MEMORY;

    write_int_to_str(num, *position, len_str, str_for_num, flag_negative);
    reverse_str_num(str_for_num, result_num, len_num);
    write_str(str, len_str, position, result_num);
    free(str_for_num);
    free(result_num);
    return OK;
}

int my_snprintf(char *str, size_t n, const char *format, ...)
{
    int rc, result_len;;
    va_list vl;
    long int long_int_argument;
    const char *ptr, *saver_ptr;
    char *str_arg;
    size_t position = 0;

    va_start(vl, format);
    ptr = format;
    while (*ptr != 0 && position != n)
    {
        saver_ptr = ptr + 1;
        if (*ptr == '%')
        {
            if (*saver_ptr == '%')
            {
                ptr += 2;
                str[position] = '%';
                position++;
                continue;
            }
            ptr++;
            if (*ptr == 's')
            {
                str_arg = va_arg(vl, char*);
                write_str(str, n, &position, str_arg);
            }
            saver_ptr = ptr + 1;
            if (*ptr == 'l' && *saver_ptr == 'i')
            {
                ptr++;
                long_int_argument = va_arg(vl, long int);
                rc = int_to_str(str, long_int_argument, n, &position);
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
    str[position] = 0;
    result_len = position;
    return result_len;
}
