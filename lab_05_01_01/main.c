// Подключение библиотек и заголовочных файлов
#include <stdio.h>
#include "errors.h"
#include "process.h"
#include "input_output.h"

int main(void)
{
    // Инициализация перменных
    FILE *f;
    int max_1, max_2;
    int rc;
    // Открытие файла с режимом записи
    f = fopen("task_1.txt", "w");
    // Заполнения файла
    rc = create_int_file(f);
    // Обработка ошибок
    if (rc == NOT_ENOUGH)
    {
        printf("Not enough elems");
        return rc;
    }
    // Закрытие файла
    fclose(f);
    // Открытие файла с режимом чтения
    f = fopen("task_1.txt", "r");
    // Функция поиска максимумов
    rc = process(f, &max_1, &max_2);
    // Закрытие файла
    fclose(f);
    // Вывод результата
    printf("Result: %d %d \n", max_1, max_2);
    return rc;
}
