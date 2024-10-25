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
            <td align="center">3 3 <br> 1 2 3 <br> a</td>
            <td align="center">Error array value </td>
            <td align="center">Ошибка при вводе значений массива в середине.</td>
        </tr>
        <tr>
            <td align="center">pos_01</td>
            <td align="center">Positive Test</td>
            <td align="center">2 2 <br> 2 2 <br> 4 4</td>
            <td align="center">2 2 <br> 4 4</td>
            <td align="center">Ни в одной строке нет ни одного элемента с нечетной суммой цифр.</td>
            <td rowspan=2 align="center">Ни в одной строке нет хотя бы двух элементов с нечетной суммой цифр.</td>
        </tr>
        <tr>
            <td align="center">pos_05</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> 111 22 22 <br> 111 22 22 <br> 111 22 22 </td>
            <td align="center">111 22 22 <br> 111 22 22 <br> 111 22 22 </td>
            <td align="center">Во всех строках по одному элементу с нечетной суммой цифр.</td>
        </tr>
        <tr>
            <td align="center">pos_02</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> 111 222 111 <br> 22 22 22 <br>22 22 22</td>
            <td align="center">111 222 111 <br> 22 22 22 <br>22 22 22</td></td>
            <td align="center">В одной строке есть хотя бы два элемента с нечетной суммой цифр.</td>
            <td rowspan=1 align="center">В одной строке есть хотя бы два элемента с нечетной суммой цифр.</td>
        </tr>
        <tr>
            <td align="center">pos_03</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> 111 222 111 <br> 111 222 111 <br>22 22 22</td>
            <td align="center">-1 -1 -1 <br> 111 222 111 <br> -1 -1 -1 <br> 111 22 111 <br> 22 22 22</td>
            <td align="center">В нескольких строках есть хотя бы два элемента с нечетной суммой цифр.</td>
            <td rowspan=1 align="center">В нескольких строках есть хотя бы два элемента с нечетной суммой цифр.</td>
        </tr>
        <tr>
            <td align="center">pos_04</td>
            <td align="center">Positive Test</td>
            <td align="center">3 3 <br> 111 111 22 <br> 111 111 22 <br> 111 111 22</td>
            <td align="center">-1 -1 -1 <br> 111 111 22 <br> -1 -1 -1 <br> 111 111 22 <br> -1 -1 -1 <br> 111 111 22 </td>
            <td align="center">Во всех строках есть хотя бы два элемента с нечетной суммой цифр.</td>
            <td rowspan=1 align="center">Во всех строках есть хотя бы два элемента с нечетной суммой цифр.</td>
        </tr>
        <tr>
            <td align="center">pos_06</td>
            <td align="center">Positive Test</td>
            <td align="center"> 10 3 <br> 111 111 111 <br> 111 111 111 <br> 111 111 111 <br> 111 111 111 <br> 111 111 111 <br> 111 111 111 <br> 111 111 111 <br> 111 111 111 <br> 111 111 111 <br> 111 111 111 </td>
            <td align="center">-1 -1 -1 <br> 111 111 111 <br> -1 -1 -1 <br> 111 111 111 <br> -1 -1 -1 <br> 111 111 111 <br> -1 -1 -1 <br> 111 111 111 <br> -1 -1 -1 <br> 111 111 111 <br> -1 -1 -1 <br> 111 111 111 <br> -1 -1 -1 <br> 111 111 111 <br> -1 -1 -1 <br> 111 111 111 <br> -1 -1 -1 <br> 111 111 111 <br> -1 -1 -1 <br> 111 111 111 </td>
            <td align="center">10 строк, которые подходят по условию.</td>
            <td rowspan=1 align="center">10 строк, которые подходят по условию.</td>
        </tr>
        <tr>
            <td align="center">pos_07</td>
            <td align="center">Positive Test</td>
            <td align="center"> 3 3 <br> -111 111 22 <br> 111 -111 22 <br> 111 -111 22 </td>
            <td align="center">-1 -1 -1 <br> -111 111 22 <br> -1 -1 -1 <br> 111 -111 22 <br> -1 -1 -1 <br> 111 -111 22 </td>
            <td align="center">Проверка работы с отридцательными числами.</td>
            <td rowspan=1 align="center">Проверка работы с отридцательными числами.</td>
        </tr>
    </tbody>
</table>