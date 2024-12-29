#include "process.h"

void free_all_data(node_t *head)
{
    node_t *next;
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        free(head);
        return;
    }
    for (;head; head = next)
    {
        next = head->next;
        free(head->name);
        free(head->group);
        free(head);
    }
}

int select_elems(node_t *head, const char *finder) {
    int cnt = 0;
    const char *name_ptr;
    const char *finder_ptr;

    if (!head || !finder) {
        return ERROR;
    }

    while (head) {
        name_ptr = head->name;
        finder_ptr = finder;

        while (*finder_ptr && *name_ptr && *finder_ptr == *name_ptr) {
            finder_ptr++;
            name_ptr++;
        }

        if (*finder_ptr == '\0') {
            printf("%s %d %s\n", head->name, head->year, head->group);
            cnt++;
        }

        head = head->next;
    }

    return cnt;
}

