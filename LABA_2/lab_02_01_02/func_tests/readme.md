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
            <td align="center">-1</td>
            <td align="center">Error</td>
            <td align="center">Ввод отридцательной длинны при вводе длинны.</td>
            <td rowspan=5 align="center">Ошибка при вводе длинны массива.</td>
        </tr>
        <tr>
            <td align="center">neg_02</td>
            <td align="center">Negative Test</td>
            <td align="center">11</td>
            <td align="center">Error</td>
            <td align="center">Ввод длинны массива больше 10.</td>
        </tr>
        <tr>
            <td align="center">neg_04</td>
            <td align="center">Negative Test</td>
            <td align="center">a</td>
            <td align="center">Error</td>
            <td align="center">При вводе длинны вводится символ.</td>
        </tr>
        <tr>
            <td align="center">neg_07</td>
            <td align="center">Negative Test</td>
            <td align="center">1.5</td>
            <td align="center">Error</td>
            <td align="center">При вводе длинны массива введено вещественное число.</td>
        </tr>
        <tr>
            <td align="center">neg_08</td>
            <td align="center">Negative Test</td>
            <td align="center">0</td>
            <td align="center">Error</td>
            <td align="center">При вводе длинны вводится 0.</td>
        <tr>
            <td align="center">neg_03</td>
            <td align="center">Negative Test</td>
            <td align="center">5 1 4 -3 a</td>
            <td align="center">Error</td>
            <td align="center">При вводе элементов массива, вводится символ в середине ввода.</td>
            <td rowspan=3 align="center">Ошибка при вводе элементов массива.</td>
        </tr>
        <tr>
            <td align="center">neg_05</td>
            <td align="center">Negative Test</td>
            <td align="center">5 1 2 -3 -5 f</td>
            <td align="center">Error</td>
            <td align="center">При вводе элементов массива, вводится символ в конце ввода.</td>
        </tr>
        <tr>
            <td align="center">neg_10</td>
            <td align="center">Negative Test</td>
            <td align="center">5 a</td>
            <td align="center">Error</td>
            <td align="center">При вводе элементов массива, вводится символ в начале ввода.</td>
        </tr>
        <tr>
            <td align="center">neg_09</td>
            <td align="center">Negative Test</td>
            <td align="center">4 1 2 5.56</td>
            <td align="center">Error</td>
            <td align="center">При вводе элементов массива, вводится вещественное число.</td>
        </tr>
        <tr>
            <td align="center">neg_06</td>
            <td align="center">Negative Test</td>
            <td align="center">5 1 2 3 4 5</td>
            <td align="center">Error</td>
            <td align="center">В массиве отсутствуют отридцательные элементы.</td>
            <td rowspan=1 align="center">В массиве отсутствуют отридцательные элементы.</td>
        </tr>
        <tr>
            <td align="center">pos_01</td>
            <td align="center">Positive Test</td>
            <td align="center">3 -1 2 3</td>
            <td align="center">-1.000000</td>
            <td align="center">Подсчёт среднего арифметического, когда в массиве находится одно отридцательное число.</td>
            <td rowspan=1 align="center">Проверка правильности подсчета, когда одно отридцательное число.</td>
        </tr>
        <tr>
            <td align="center">pos_02</td>
            <td align="center">Positive Test</td>
            <td align="center">10 1 -7 4 8 -9 -1 2 3 4 -5</td>
            <td align="center">-5.500000</td>
            <td align="center">Подсчёт среднего арифметического, когда в массиве находится несколько отридцательных чисел.</td>
            <td rowspan=2 align="center">Проверка правильности подсчета, когда в массиве несколько отридцательных чисел.</td>
        </tr>
        <tr>
            <td align="center">pos_04</td>
            <td align="center">Positive Test</td>
            <td align="center">5 -1 2 -4 5 -6</td>
            <td align="center">-3.666667 </td>
            <td align="center">Подсчёт среднего арифметического, когда в массиве несколько отридцательных чисел, расположенных через один.</td>
        </tr>
        <tr>
            <td align="center">pos_03</td>
            <td align="center">Positive Test</td>
            <td align="center">5 -1 -9 -11 -2 -5</td>
            <td align="center">-5.600000</td>
            <td align="center">Подсчёт среднего арифметического, когда в массиве все числа отридцательные.</td>
            <td rowspan=1 align="center">Проверка правильности подсчета, когда в массиве все числа отридцательные.</td>
        </tr>
    </tbody>
</table>