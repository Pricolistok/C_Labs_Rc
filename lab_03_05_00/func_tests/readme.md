<table>
    <thead>
        <tr>
            <th>Name Test</th>
            <th>Type</th>
            <th>Input</th>
            <th>Output</th>
            <th>Description</th>
            <th>Equivalence class</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td align="center">neg_01</td>
            <td align="center">Negative Test</td>
            <td align="center">a</td>
            <td align="center">Error input len </td>
            <td align="center">Ввод символа при вводе первой длинны.</td>
            <td rowspan=8 align="center">Ошибка при вводе длинны массива.</td>
        </tr>
        <tr>
            <td align="center">neg_02</td>
            <td align="center">Negative Test</td>
            <td align="center">2 a</td>
            <td align="center">Error input len</td>
            <td align="center">Ввод символа при вводе второй длинны.</td>
        </tr>
        <tr>
            <td align="center">neg_03</td>
            <td align="center">Negative Test</td>
            <td align="center">-2 3</td>
            <td align="center">Error value len</td>
            <td align="center">Ввод отрицательного числа при вводе первой длинны.</td>
        </tr>
        <tr>
            <td align="center">neg_04</td>
            <td align="center">Negative Test</td>
            <td align="center">2 -3</td>
            <td align="center">Error value len</td>
            <td align="center">Ввод отрицательного числа при вводе второй длинны.</td>
        </tr>
        <tr>
            <td align="center">neg_05</td>
            <td align="center">Negative Test</td>
            <td align="center">0</td>
            <td align="center">Error value len</td>
            <td align="center">Ввод нуля при вводе первой длинны.</td>
        </tr>
        <tr>
            <td align="center">neg_06</td>
            <td align="center">Negative Test</td>
            <td align="center">5 0</td>
            <td align="center">Error value len</td>
            <td align="center">Ввод нуля при вводе второй длинны.</td>
        </tr>
        <tr>
            <td align="center">neg_07</td>
            <td align="center">Negative Test</td>
            <td align="center">11</td>
            <td align="center">Error value len</td>
            <td align="center">Ввод числа больше 10 при вводе первой длинны.</td>
        </tr>
        <tr>
            <td align="center">neg_08</td>
            <td align="center">Negative Test</td>
            <td align="center">7 11</td>
            <td align="center">Error value len</td>
            <td align="center">Ввод числа больше 10 при вводе второй длинны.</td>
        </tr>
        <tr>
            <td align="center">neg_09</td>
            <td align="center">Negative Test</td>
            <td align="center">3 3 a</td>
            <td align="center">Error array value </td>
            <td align="center">Ошибка при вводе значений массива в начале.</td>
            <td rowspan=2 align="center">Ошибка при вводе значений массива.</td>
        </tr>
        <tr>
            <td align="center">neg_10</td>
            <td align="center">Negative Test</td>
            <td align="center">3 3 1 2 3 a</td>
            <td align="center">Error array value </td>
            <td align="center">Ошибка при вводе значений массива в середине.</td>
        </tr>
        <tr>
            <td align="center">neg_11</td>
            <td align="center">Negative Test</td>
            <td align="center">3 3 <br> 8 8 8 <br> 8 8 8 <br> 8 8 8</td>
            <td align="center">Haven`t simple elements</td>
            <td align="center">В массиве отсутствуют простые числа.</td>
            <td rowspan=1 align="center">В массиве отсутствуют простые числа.</td>
        </tr>
        <tr>
            <td align="center">pos_01</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> 1 1 1 <br> 3 1 1 <br> 1 1 1</td>
            <td align="center">1 1 1 <br> 3 1 1 <br> 1 1 1</td>
            <td align="center">В массиве всего одно простое число.</td>
            <td rowspan=1 align="center">В массиве всего одно простое число.</td>
        </tr>
        <tr>
            <td align="center">pos_02</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> 1 2 1 <br> 3 1 1 <br> 1 3 1</td>
            <td align="center">3 3 <br> 1 3 1 <br> 3 1 1 <br> 1 2 1</td>
            <td align="center">В массиве нечетное количество простых элементов.</td>
            <td rowspan=1 align="center">В массиве нечетное количество простых элементов.</td>
        </tr>
        <tr>
            <td align="center">pos_03</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> 1 2 5 <br> 1 1 1 <br> 1 3 7</td>
            <td align="center">1 7 3 <br> 1 1 1 <br> 1 5 2</td>
            <td align="center">В массиве четное количество простых элементов.</td>
            <td rowspan=1 align="center">В массиве четное количество простых элементов.</td>
        </tr>
        <tr>
            <td align="center">pos_04</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> 2 3 5  <br> 7 11 13 <br> 17 19 23</td>
            <td align="center">23 19 17 <br> 13 11 7 <br> 5 3 2</td>
            <td align="center">В массиве все элементы простые.</td>
            <td rowspan=2 align="center">В массиве все элементы простые.</td>
        </tr>
        <tr>
            <td align="center">pos_04</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> 1 2 1 <br> -3 1 1 <br> 1 3 1</td>
            <td align="center">1 3 1 <br> -3 1 1 <br> 1 2 1</td>
            <td align="center"> Проверка работы программы с отрицательными числами</td>
            <td rowspan=2 align="center">Проверка работы программы с отрицательными числами</td>
        </tr>
    </tbody>
</table>