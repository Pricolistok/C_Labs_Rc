Задача:
Есть некоторый текстовый редактор, который может генерировать списки простых чисел для группы математиков, которые занимаются 
изучением простых чисел, а также он может выделять и четные числа, которые необходимы им для других исследований.

Функциональные тесты
    Позитивные
      Фильтрация
         Тесты, когда внутри несоклько элементов
            1. Тест, когда элемент один и он четный
            2. Тест, когда элемент один и он не четный
            3. Тест, когда элементов 2 и они четные
            4. Тест, когда элементов 2 и они не четные
            5. Тест, когда элементов много и есть один четный в начале
            6. Тест, когда элементов много и есть четный в середине
            7. Тест, когда элементов много и есть четный в конце
            8. Тест, когда элементов много и есть много четных, стоящих рядом
            9. Тест, когда элементов много и есть много четных, которые стоят в разнобой  
            10. Тест, когда четных элементов вообще нет
            11. Тест, где много разных элементов и память выделяется с запасом
      Заполнение
            12. Когда элемент 1 
            13. Когда элементов 2
            14. Когда элементов много
         

 Негативные
   Ошибки аргументов
      1. Тест, когда указан 1 файл
      2. Тест, когда указано 3 файла
      3. Тест, когда указан не существующий файл
      4. Тест когда указан неверный режим
      5. Тест, когда указано несколько аргументов для режима
      6. Тест, когда указано число равное 0 при а
      7. Тест, когда указано число отрицательное при а
      8. Тест, когда указана буква при а
      9. Тест, когда в указано вещественное число при а
   Ошибки наполнения файла
      10. Тест, когда файл пуст
      11. Тест, когда в файле при запуске режима фильтрации указан не тот аргумент для выделения памяти
      12. Тест, когда вместо числа фильтрации указана буква
      13. Тест, когда вместо числа фильтрации указаны символы
      14. Тест, когда вместо числа фильтрации указано вещественное число
      15. Тест, когда в значениях есть буква в начале
      16. Тест, когда в значениях есть вещественное число в начале
      17. Тест, когда в значениях есть буква в середине
      18. Тест, когда в значениях есть вещественное число в середине
   
      