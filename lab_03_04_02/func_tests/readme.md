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
            <td rowspan=9 align="center">Ошибка при вводе длинны массива.</td>
        </tr>
        <tr>
            <td align="center">neg_12</td>
            <td align="center">Negative Test</td>
            <td align="center">3 4</td>
            <td align="center">Error value len</td>
            <td align="center">Размер массива введен некорректно, значение ширианы не равно высоте.</td>
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
            <td align="center">3 3 <br> 1 2 3 <br> 1 2 3 <br> 1 2 3</td>
            <td align="center">Error array value </td>
            <td align="center">Отсутствуют элементы, которые оканчиваются на 5.</td>
            <td rowspan=1 align="center">Отсутствуют элементы, которые оканчиваются на 5.</td>
        </tr>
        <tr>
            <td align="center">pos_01</td>
            <td align="center">Positive Test</td>
            <td align="center">4 4 <br> 1 2 3 4 <br> 1 2 3 5 <br> 1 2 3 4 <br> 1 2 3 4</td>
            <td align="center">5</td>
            <td align="center">Под побочной диагональю всего один элемент, заканчивающийся на 5.</td>
            <td rowspan=1 align="center">Под побочной диагональю всего один элемент заканчивающийся на 5.</td>
        </tr>
        <tr>
            <td align="center">pos_02</td>
            <td align="center">Positive Test</td>
            <td align="center">4 4 <br> 1 2 3 4 <br> 1 2 3 5 <br> 1 2 3 25 <br> 1 2 3 4</td>
            <td align="center">25</td>
            <td align="center">Под побочной диагональю несколько элементов заканчивающихся на 5.</td>
            <td rowspan=1 align="center">Под побочной диагональю несколько элементов, заканчивающихся на 5.</td>
        </tr>
        <tr>
            <td align="center">pos_03</td>
            <td align="center">Positive Test</td>
            <td align="center"> 4 4 <br> 1 2 3 4 <br> 1 2 3 5 <br> 1 2 35 25 <br> 1 45 15 45</td>
            <td align="center">45</td>
            <td align="center">Под побочной диагональю все элементы заканчиваются на 5.</td>
            <td rowspan=1 align="center">Под побочной диагональю все элементы заканчиваются на 5.</td>
        </tr>
        <tr>
            <td align="center">pos_04</td>
            <td align="center">Positive Test</td>
            <td align="center"> 4 4 <br> 1 2 3 4 <br> 1 2 3 -5 <br> 1 2 -35 -25 <br> 1 -45 -15 -45</td>
            <td align="center">-5</td>
            <td align="center">Под побочной диагональю максимальный элемент, оканчивающийся на 5 - отрицательный.</td>
            <td rowspan=1 align="center">Под побочной диагональю максимальный элемент, оканчивающийся на 5 - отрицательный.</td>
        </tr>
    </tbody>
</table>