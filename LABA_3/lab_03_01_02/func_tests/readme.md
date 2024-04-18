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
            <td align="center">Ввод отридцательного числа при вводе первой длинны.</td>
        </tr>
        <tr>
            <td align="center">neg_04</td>
            <td align="center">Negative Test</td>
            <td align="center">2 -3</td>
            <td align="center">Error value len</td>
            <td align="center">Ввод отридцательного числа при вводе второй длинны.</td>
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
            <td align="center">pos_01</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> 1 2 3 <br> 4 5 6 <br> 7 8 9</td>
            <td align="center">0 0 0</td>
            <td align="center">Ни в одном столбце не чередуются.</td>
            <td rowspan=1 align="center">Ни один из столбцов не подходит.</td>
        </tr>
        <tr>
            <td align="center">pos_02</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> 1 2 3 <br> -1 2 3 <br> 1 2 3</td>
            <td align="center">1 0 0</td>
            <td align="center">В одном столбце чередуются.</td>
            <td rowspan=1 align="center">Один из столбцов подходит.</td>
        </tr>
        <tr>
            <td align="center">pos_03</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> 1 2 3 <br> -1 -2 -3 <br> 1 2 3</td>
            <td align="center">1 1 1</td>
            <td align="center">Во всех столбцах чередуется.</td>
            <td rowspan=1 align="center">Все столбцы подходят.</td>
        </tr>
        <tr>
            <td align="center">pos_04</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> 1 2 3 <br> 0 2 3 <br> 1 2 3</td>
            <td align="center">0 0 0</td>
            <td align="center">Элеметы не чередуются, тк 0 неотридцательное число.</td>
            <td rowspan=2 align="center">В матрице есть элмент со значением 0.</td>
        </tr>
        <tr>
            <td align="center">pos_05</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> -1 2 3 <br> 0 2 3 <br> -1 2 3</td>
            <td align="center">0 0 0</td>
            <td align="center">Элеметы не чередуются, тк 0 неотридцательное число.</td>
        </tr>
        <tr>
            <td align="center">pos_06</td>
            <td align="center">Positive Test</td>
            <td align="center">1 3 <br> 1 2 3</td>
            <td align="center">1 2 3</td>
            <td align="center">Проверка, если количество строк равно 1. </td>
            <td align="center">Проверка, если количество строк равно 1.</td>
        </tr>
    </tbody>
</table>