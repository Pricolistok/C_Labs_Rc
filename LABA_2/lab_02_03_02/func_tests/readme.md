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
            <td align="center">neg_02</td>
            <td align="center">Negative Test</td>
            <td align="center">-5</td>
            <td align="center">Error len_elem</td>
            <td align="center">Ввод отридцательной длинны при вводе длинны.</td>
            <td rowspan=5 align="center">Ошибка при вводе длинны массива.</td>
        </tr>
        <tr>
            <td align="center">neg_06</td>
            <td align="center">Negative Test</td>
            <td align="center">11 1 1 1 1 1 1 1 1 1 1 1</td>
            <td align="center">Error len_elem</td>
            <td align="center">Ввод длинны массива больше 10.</td>
        </tr>
        <tr>
            <td align="center">neg_08</td>
            <td align="center">Negative Test</td>
            <td align="center">a</td>
            <td align="center">Error len_elem</td>
            <td align="center">При вводе длинны вводится символ.</td>
        </tr>
        <tr>
            <td align="center">neg_09</td>
            <td align="center">Negative Test</td>
            <td align="center">1.5</td>
            <td align="center">Error len_elem</td>
            <td align="center">При вводе длинны массива введено вещественное число.</td>
        </tr>
        <tr>
            <td align="center">neg_01</td>
            <td align="center">Negative Test</td>
            <td align="center">0</td>
            <td align="center">Error len_elem</td>
            <td align="center">При вводе длинны вводится 0.</td>
        <tr>
            <td align="center">neg_03</td>
            <td align="center">Negative Test</td>
            <td align="center">3 2 a 5</td>
            <td align="center">Error input_value</td>
            <td align="center">При вводе элементов массива, вводится символ в середине ввода.</td>
            <td rowspan=3 align="center">Ошибка при вводе элементов массива.</td>
        </tr>
        <tr>
            <td align="center">neg_05</td>
            <td align="center">Negative Test</td>
            <td align="center">5 1 2 3 4 a</td>
            <td align="center">Error input_value</td>
            <td align="center">При вводе элементов массива, вводится символ в конце ввода.</td>
        </tr>
        <tr>
            <td align="center">neg_10</td>
            <td align="center">Negative Test</td>
            <td align="center">5 a</td>
            <td align="center">Error input_value</td>
            <td align="center">При вводе элементов массива, вводится символ в начале ввода.</td>
        </tr>
        <tr>
            <td align="center">neg_04</td>
            <td align="center">Negative Test</td>
            <td align="center">5 23 45 44.56 33 89</td>
            <td align="center">Error input_value</td>
            <td align="center">При вводе элементов массива, вводится вещественное число.</td>
        </tr>
        <tr>
            <td align="center">neg_07</td>
            <td align="center">Negative Test</td>
            <td align="center">5 121 25 64 4 16</td>
            <td align="center">Error</td>
            <td align="center">Все элементы массива являются полными квадратами.</td>
            <td rowspan=1 align="center">Все элементы массива являются полными квадратами.</td>
        </tr>
        <tr>
            <td align="center">pos_01</td>
            <td align="center">Positive Test</td>
            <td align="center">5 1 2 3 4 5</td>
            <td align="center">2 3 5</td>
            <td align="center">В массиве некоторые числа являются полными квадратами.</td>
            <td rowspan=1 align="center">В массиве некоторые числа являются полными квадратами.</td>
        </tr>
        <tr>
            <td align="center">pos_02</td>
            <td align="center">Positive Test</td>
            <td align="center">5 -1 -4 -16 23 7</td>
            <td align="center">-1 -4 -16 23 7</td>
            <td align="center">В массиве ни одно число не является полным квадратом.</td>
            <td rowspan=1 align="center">В массиве ни одно число не является полным квадратом.</td>
        </tr>
    </tbody>
</table>