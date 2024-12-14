#include "input_output.h"

int check_len_file(FILE *file)
{
    long int saver_position = ftell(file);
    fseek(file, 0, SEEK_END);
    if (saver_position == ftell(file))
        return ERROR_LEN_FILE;
    fseek(file, 0, SEEK_SET);
    return OK;
}

int work_with_args(FILE **file_in, int argc, char **argv, int *choice_menu, char **finder, size_t *len_finder)
{
    if (argc < 3)
        return ERROR_ARGUMENTS;
    *file_in = fopen(argv[1], "r");
    if (*file_in == NULL)
        return ERROR_OPEN_FILE;
    if (check_len_file(*file_in) == ERROR_LEN_FILE)
        return ERROR_LEN_FILE;
    if ((strcmp(argv[2], "list") == 0 && argc != 3) || (strcmp(argv[2], "select") == 0 && argc != 4))
    {
        fclose(*file_in);
        return ERROR_ARGUMENTS;
    }
    if (strcmp(argv[2], "list") == 0)
        *choice_menu = 1;
    else
    {
        *len_finder = strlen(argv[3]);
        *finder = malloc(*len_finder + 1);
        if (!(*finder))
            return ERROR_ADD_MEMORY;
        *choice_menu = 2;
        strcpy(*finder, argv[3]);
    }
    return OK;
}


int read_from_file(FILE *file, node_t **head)
{
    long long int saver_pos;
    int rc, year;
    size_t len_name = 0, len_group = 0;
    char *name_saver, ch;
    char *group_saver;
    node_t *elem;

    while (!feof(file))
    {
        len_name = 0;
        len_group = 0;
        saver_pos = ftell(file);
        while ((ch = fgetc(file)) != '\n' && ch != EOF)
            len_name++;
        if (len_name == 0 || len_name > LEN_NAME)
        {
            free_all_data(*head);
            return ERROR_LEN_NAME;
        }
        name_saver = malloc(len_name + 1);
        if (!name_saver)
        {
            free_all_data(*head);
            return ERROR_ADD_MEMORY;
        }
        fseek(file, saver_pos, SEEK_SET);
        for (size_t i = 0; i < len_name + 1; i++)
            name_saver[i] = fgetc(file);
        name_saver[len_name] = 0;

        rc = fscanf(file, "%d", &year);
        if (rc != 1)
        {
            free(name_saver);
            free_all_data(*head);
            return ERROR_READ_YEAR;
        }
        if (year <= 0 || year > 2024)
        {
            free(name_saver);
            free_all_data(*head);
            return ERROR_YEAR;
        }
        fgetc(file);

        saver_pos = ftell(file);
        while ((ch = fgetc(file)) != '\n' && ch != EOF)
            len_group++;
        if (len_group == 0 || len_group > LEN_GROUP)
        {
            free(name_saver);
            free_all_data(*head);
            return ERROR_LEN_GROUP;
        }
        group_saver = malloc(len_group + 1);
        if (!group_saver)
        {
            free(name_saver);
            free_all_data(*head);
            return ERROR_ADD_MEMORY;
        }
        fseek(file, saver_pos, SEEK_SET);
        for (size_t i = 0; i < len_group + 1; i++)
            group_saver[i] = fgetc(file);
        group_saver[len_group] = 0;


        elem = create_elem(name_saver, year, group_saver);
        if (elem == NULL)
        {
            free(name_saver);
            free(group_saver);
            free_all_data(*head);
            return ERROR_ADD_MEMORY;
        }
        *head = add_to_list_elem_end(*head, elem);
        if (*head == NULL)
        {
            free(name_saver);
            free(group_saver);
            free_all_data(*head);
            return ERROR_ADD_MEMORY;
        }
    }
    return OK;
}


node_t *add_to_list_elem_end(node_t *head, node_t *elem)
{
    node_t *cur = head;
    if (!head)
        return elem;
    for (;cur->next; cur = cur->next);
    cur->next = elem;
    return head;
}


node_t *create_elem(char *name, int year, char *group)
{
    node_t *elem = malloc(sizeof(node_t));
    if (!elem)
        return elem;
    elem->name = name;
    elem->year = year;
    elem->group = group;
    elem->next = NULL;
    return elem;
}

void print_list(node_t *head)
{
    if (head == NULL)
        return;

    for (; head != NULL; head = head->next)
    {
        printf("%s %d %s\n", head->name, head->year, head->group);
    }
}

