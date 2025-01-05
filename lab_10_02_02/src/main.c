#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "errors.h"
#include "process.h"
#include "input_output.h"


int main(void)
{
    int rc, mode, cnt_coefficients, cnt_coefficients_for_mode_sum;
    double val;
    node_t *head = NULL, *head_for_mode_sum = NULL, *head_ch = NULL, *head_nch =NULL;
    rc = input_mode(&mode);

    switch(rc)
    {
        case ERROR_LEN_MODE:
            // printf("Ошибка длины аргумента меню!\n");
            return ERROR_LEN_MODE;

        case ERROR_VALUE_MODE:
            // printf("Ошибка занчения аргумента меню!\n");
            return ERROR_VALUE_MODE;

        default:;
    }

    rc = read_coefficients(&head, &cnt_coefficients);
    switch (rc)
    {
        case ERROR_CNT_COEFFICIENTS:
            // printf("Ошибка количсетва коафициентов!\n");
            return ERROR_CNT_COEFFICIENTS;

        case ERROR_INPUT_COEFFICIENT:
            free_list(head);
            // printf("Ошибка значения коафициента!\n");
            return ERROR_CNT_COEFFICIENTS;

        case ERROR_INPUT_MORE_COEFFICIENT:
            free_list(head);
            // printf("Ошибка количества коафициентов!\n");
            return ERROR_INPUT_MORE_COEFFICIENT;

        default:;
    }

    switch (mode)
    {
        case 1:
            rc = input_val(&val);
            if (rc == ERROR_INPUT_VAL)
            {
                free_list(head);
                // printf("Ошибка ввода значения val!\n");
                return ERROR_INPUT_VAL;
            }
            printf("%lf\n", cnt_val(head, val, cnt_coefficients));
            break;

        case 2:
            cnt_derivative(head, cnt_coefficients);
            print_list(head);
            break;

        case 3:
            rc = read_coefficients(&head_for_mode_sum, &cnt_coefficients_for_mode_sum);
            switch (rc)
            {
                case ERROR_CNT_COEFFICIENTS:
                    // printf("Ошибка количсетва коафициентов!\n");
                    return ERROR_CNT_COEFFICIENTS;

                case ERROR_INPUT_COEFFICIENT:
                    // printf("Ошибка значения коафициента!\n");
                    return ERROR_CNT_COEFFICIENTS;

                default:;
            }
            if (cnt_coefficients > cnt_coefficients_for_mode_sum)
            {
                cnt_sum_of_polynomials(head,head_for_mode_sum, cnt_coefficients - cnt_coefficients_for_mode_sum);
                print_list(head);
            }
            else
            {
                cnt_sum_of_polynomials(head_for_mode_sum,head, cnt_coefficients_for_mode_sum - cnt_coefficients);
                print_list(head_for_mode_sum);
            }
            free_list(head_for_mode_sum);
            break;

        case 4:
            separator_coefficients(head, &head_ch, &head_nch, cnt_coefficients);
            print_list(head_ch);
            print_list(head_nch);
            free_list(head_ch);
            free_list(head_nch);

        default:;
    }
    free_list(head);
    return OK;
}
