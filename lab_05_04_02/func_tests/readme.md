| | | | | | |
|-|-|-|-|-|-|
|Название теста|Входные данные|Выходные данные|Аргументы|Описание|Класс эквивалентности|
|pos_01|Приведены в файлах|Приведены в файлах|st ./func_tests/data/pos_01_in.txt ./func_tests/data/test.txt|Проверка сортировки, обычный случай|Обычные случаи|
|pos_02|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/pos_02_in.txt ppp|Проверка поиска, обычный случай| |
|pos_03|Приведены в файлах|Приведены в файлах|st ./func_tests/data/pos_03_in.txt ./func_tests/data/test.txt|Проверка сортировки, когда элемент 1|Проверка работы программы на разных количествах элементов|
|pos_04|Приведены в файлах|Приведены в файлах|st ./func_tests/data/pos_04_in.txt ./func_tests/data/test.txt|Проверка сортировки, когда элемента 2| |
|pos_05|Приведены в файлах|Приведены в файлах|st ./func_tests/data/pos_05_in.txt ./func_tests/data/test.txt|Проверка работы программы, когда массив уже отсортирован|Проверка работы программы уже на отсортированном массиве|
|pos_06|Приведены в файлах|Приведены в файлах|st ./func_tests/data/pos_06_in.txt ./func_tests/data/test.txt|Проверка работы программы, когда массив расположен в порядке возрастания| |
|pos_07|Приведены в файлах|Приведены в файлах|st ./func_tests/data/pos_07_in.txt ./func_tests/data/test.txt|Проверка работы программы, когда в массиве два элемента с одной ценой|Проверка сортировки с одной ценой|
|pos_08|Приведены в файлах|Приведены в файлах|st ./func_tests/data/pos_08_in.txt ./func_tests/data/test.txt|Проверка работы программы, когда в массиве три элемента с одной ценой| |
|pos_09|Приведены в файлах|Приведены в файлах|st ./func_tests/data/pos_09_in.txt ./func_tests/data/test.txt|Проверка работы программы, когда в массиве есть несколько элементов с повторяющимися ценами| |
|pos_10|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/pos_10_in.txt ppp|Проверка работы программы, когда все элементы полностью состоят из искомой строки|Когда элемент цеиком состояит из искомой подстроки|
|pos_11|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/pos_11_in.txt iii|Проверка работы программы, когда все элементы частично состоят из искомой строки| |
|pos_12|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/pos_12_in.txt ppp|Проверка работы программы на граничных значениях длины наименования|Максимальные длины строк|
|pos_13|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/pos_12_in.txt ppp|Проверка работы программы на граничных значениях длины названия изготовителя| |
|neg_01|Приведены в файлах|Приведены в файлах|(Пустой файл)|Проверка работы программы когда нет аргументов|Недостаточное количество аргументов|
|neg_10|Приведены в файлах|Приведены в файлах|ft |Проверка рботы программы, когда есть всего 1 аргумент| |
|neg_11|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/neg_09_in.txt|Проверка работы программы, когда есть всего 2 аргумента| |
|neg_02|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/neg_02_in.txt ppp|Проверка работы программы, когда введена строка наимменования больше, чем разрешеного|Строка больше разрешенного|
|neg_03|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/neg_03_in.txt ppp|Проверка работы программы, когда введена строка изготовителя больше, чем разрешено| |
|neg_04|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/neg_04_in.txt ppp|Проверка работы программы, когда в цену введено вещественное число|Обработка вещественных чисел|
|neg_05|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/neg_05_in.txt ppp|Проверка работы программы, когда в количество введено вещественное число| |
|neg_06|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/neg_05_in.txt ppp|Проверка работы программы, когда в цену введено отрицательное число|Проверка работы с отрицательными числами|
|neg_07|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/neg_05_in.txt ppp|Проверка работы программы, когда в количество введено отрицательное число| |
|neg_08|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/neg_08_in.txt ppp|Проверкка работы программы, когда в цену введена буква|Проверка рабботы программы, когда введена буква|
|neg_09|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/neg_09_in.txt ppp|Проверкка работы программы, когда в количество введена буква| |
|neg_12|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/neg_in.txt ppp|Проверка работы программы, когда передан несуществующий файл|Несуществующий файл|
|neg_13|(Пустой файл)|Приведены в файлах|ft ./func_tests/data/pos_13_in.txt ppp|Проверка работы программы, когда файл пуст|Пустой файл|
|neg_14|Приведены в файлах|Приведены в файлах|ft ./func_tests/data/pos_14_in.txt ppp|Проверка работы программы при неверной длинне подстроки|Неверная длина подстроки|

