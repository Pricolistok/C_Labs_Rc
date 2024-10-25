| Функция | Первая строка | Вторая строка | Описание                         |
|---------|---------------|---------------|----------------------------------|
| strpbrk | Hello world!  | Hled          | Символ стоит первым              |
| strpbrk | gukjbbnm      | bgdrhgk       | Символ стоит в середине          |
| strpbrk | gukjbbnm      | pm            |  Символ стоит в конце            |
| strpbrk | gukjbbnm      | p             | Символ отсутствует               |
| strpbrk |               | pm            | Пустая строка                    |
| strpbrk | uikjhuk       |               | Пустая строка                    |
| -       | -             | -             | -                                |
| strspn  | aaababbb      | accc          | Символ стоит первым              |
| strspn  | uuuabcdef     | ab            | Символ стоит в середине          |
| strspn  | ttututa       | aaaba         | Символ стоит в конце             |
| strspn  | abcdef        | p             | Символ отсутствует               |
| strspn  |               |               | Пустые строки                    |
| -       | -             | -             | -                                |
| strchr  | acaabcde      | a             | Символ стоит первым              |
| strchr  | abedef        | b             | Символ стоит в середине          |
| strchr  |               | \0            | Проверка пустой строки           |
| strchr  | abedef        | f             | Символ стоит в конце             |
| strchr  | abedef        | u             | Отсутствует символ               |
| strchr  | \0            | ' '           | Проверка работы с пустой строкой |
| -       | -             | -             | -                                |
| strrchr | acaabcde      | a             | Символ стоит первым              |
| strrchr | abedef        | b             | Символ стоит в середине          |
| strrchr |               | \0            | Проверка пустой строки           |
| strrchr | abedef        | f             | Символ стоит в конце             |
| strrchr | abedef        | u             | Отсутствует символ               |
| strrchr | \0            | ' '           | Проверка работы с пустой строкой |
