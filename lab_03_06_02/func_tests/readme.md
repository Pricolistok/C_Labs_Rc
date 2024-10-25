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
            <td align="center">pos_01</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3</td>
            <td align="center">9 4 3 <br> 8 5 2 <br> 7 6 1 </td>
            <td align="center">Проверка работы программы, когда квадратная матрица с нечетным размером</td>
            <td rowspan=2 align="center">Квадратная матрица</td>
        </tr>
        <tr>
            <td align="center">pos_02</td>
            <td align="center">Positive Test</td>
            <td align="center">4 4</td>
            <td align="center">13 12 5 4 <br> 14 11 6 3 <br> 15 10 7 2 <br> 16 9 8 1 </td>
            <td align="center">Проверка работы программы, когда квадратная матрица с четным размером</td>
        </tr>
        <tr>
            <td align="center">pos_03</td>
            <td align="center">Positive Test</td>
            <td align="center">1</td>
            <td align="center">1</td>
            <td align="center">Матрица размером 1*1.</td>
            <td rowspan=1 align="center">Матрица размером 1*1.</td>
        </tr>
        <tr>
            <td align="center">pos_04</td>
            <td align="center">Positive Test</td>
            <td align="center">3 4</td>
            <td align="center">10 9 4 3 <br> 11 8 5 2 <br> 12 7 6 1</td>
            <td align="center">Проверка работы, когда матрица прямоугольная.</td>
            <td rowspan=2 align="center">Прямоугольная матрица.</td>
        </tr>
    </tbody>
</table>