// Заголовочный файл для файла functions.c
#ifndef FUNCTIONS_H__

#define FUNCTIONS_H__

void my_strpbrk(char *str_scan, char *str_find, char *str_my_res, size_t len_str_scan, size_t len_str_find);
size_t my_strspn(char *str_scan, char *str_find, size_t len_str_scan, size_t len_str_find);
size_t my_strcspn(char *str_scan, char *str_find, size_t len_str_scan, size_t len_str_find);
char  *my_strchr(char *str_scan, char *str_find, size_t len_str_scan);
char  *my_strrchr(char *str_scan, char *str_find, size_t len_str_scan);



#endif
