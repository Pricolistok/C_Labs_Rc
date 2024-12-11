#include "process.h"

void *pop_front(node_t **head) {
    void *saver_point = *head;
    if (*head == NULL)
        return NULL;
    *head = (*head)->next;
    product_free(saver_point);
    return saver_point;
}


void *pop_end(node_t **head) {
    node_t *next;
    node_t *end_point = NULL;
    node_t *save_head = *head;
    if (*head == NULL)
        return NULL;
    if ((*head)->next == NULL) {
        end_point = *head;
        product_free(*head);
        *head = NULL;
        return end_point;
    }
    for ( ; *head; *head = next) {
        next = (*head)->next;
        if (next->next == NULL) {
            end_point = (*head)->next;
            (*head)->next = NULL;
            product_free(end_point);
            break;
        }
    }
    *head = save_head;
    return end_point;
}


void product_free(node_t *head) {
    product *elem_data = (product*)head->data;
    free(elem_data->name);
    free(head->data);
    free(head);
}


void free_all_data(node_t *head) {
    node_t *next;
    if (head == NULL)
        return;
    if (head->next == NULL) {
        product_free(head);
        return;
    }
    for ( ; head; head = next) {
        next = head->next;
        product_free(head);
    }
}


int comparator_products (const void *compare_1, const void *compare_2) {
    product *compare_data_1 = (product*)compare_1;
    product *compare_data_2 = (product*)compare_2;
    if (compare_data_1->len_name != compare_data_2->len_name)
        return OK;
    if (strcmp(compare_data_1->name, compare_data_2->name) != 0)
        return OK;
    if (compare_data_1->price != compare_data_2->price)
        return OK;
    return ERROR;
}


// void remove_duplicates(node_t **head, int (*copmarator)(const void*, const void*)) {
//     node_t *saver_head = *head;
//     node_t *next = NULL, *next_tmp, *save_head = *head, *cursor = *head;
//     node_t *tmp = NULL, **saver_point = NULL;
//     tmp = *head;
//     saver_point = head;
//     if (*head == NULL)
//         return;
//     for ( ; *head; *head = next) {
//         printf("P");
//         tmp = saver_head;
//         if ((*head)->next != NULL) {
//             for ( ; tmp; tmp = next_tmp) {
//                 if (tmp != *head) {
//                     if (copmarator((*head)->data, tmp->data) == ERROR) {
//                         *saver_point = cursor;
//                         if (tmp->next != NULL)
//                             (*saver_point)->next = tmp->next;
//                         else
//                             (*saver_point)->next = NULL;
//                         next_tmp = tmp->next;
//                         product_free(tmp);
//                     }
//                     else {
//                         cursor = tmp;
//                         next_tmp = tmp->next;
//                     }
//                 }
//                 else {
//                     cursor = tmp;
//                     next_tmp = tmp->next;
//                 }
//             }
//         }
//         if ((*head)->next == NULL)
//             break;
//         next = (*head)->next;
//     }
//     *head = save_head;
// }

void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*)) {
    node_t *saver_head = *head;
    node_t *next_head = NULL, *next_tmp = NULL;
    node_t *tmp = *head, *saver_tmp = *head;
    for ( ; *head; *head = next_head) {
        tmp = *head;
        for ( ; tmp; tmp = next_tmp) {
            if (tmp == *head) {
                saver_tmp = tmp;
                next_tmp = tmp->next;
            }
            else {
                if (comparator(tmp->data, (*head)->data) == ERROR) {
                    saver_tmp->next = tmp->next;
                    next_tmp = tmp->next;
                    product_free(tmp);
                }
                else {
                    saver_tmp = tmp;
                    next_tmp = tmp->next;
                }
            }
        }
        next_head = (*head)->next;
    }
    *head = saver_head;
}

int comparator_prices(const void *price_1, const void *price_2) {
    product *price_data_1 = (product*)price_1;
    product *price_data_2 = (product*)price_2;
    if (price_data_1->price > price_data_2->price)
        return 1;
    else if (price_data_1->price < price_data_2->price)
        return -1;
    return 0;

}


void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *)) {
    node_t *tmp  = *head;
    while (tmp->next && comparator(tmp->next->data, element->data) <= 0)
        tmp = tmp->next;
    element->next = tmp->next;
    tmp->next = element;
}


node_t* sort(node_t *head, int (*comparator)(const void *, const void *)) {
    node_t *result = NULL;
    node_t *cur, *next;

    if (head == NULL || head->next == NULL)
        return head;

    cur = head;
    while (cur != NULL){
        next = cur->next;
        if (result == NULL || comparator(result->data, cur->data) == 1) {
            cur->next = result;
            result = cur;
        }
        else if (comparator(result->data, cur->data) <= 0)
            sorted_insert(&result, cur, comparator_prices);
        cur = next;
    }
    return result;
}
