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
            <td align="center">-3</td>
            <td align="center">Error len_elem</td>
            <td align="center">Ввод отридцательной длинны при вводе длинны.</td>
            <td rowspan=5 align="center">Ошибка при вводе длинны массива.</td>
        </tr>
        <tr>
            <td align="center">neg_03</td>
            <td align="center">Negative Test</td>
            <td align="center">11</td>
            <td align="center">Error len_elem</td>
            <td align="center">Ввод длинны массива больше 10.</td>
        </tr>
        <tr>
            <td align="center">neg_04</td>
            <td align="center">Negative Test</td>
            <td align="center">a</td>
            <td align="center">Error len_elem</td>
            <td align="center">При вводе длинны вводится символ.</td>
        </tr>
        <tr>
            <td align="center">neg_05</td>
            <td align="center">Negative Test</td>
            <td align="center">1.5</td>
            <td align="center">Error len_elem</td>
            <td align="center">При вводе длинны массива введено вещественное число.</td>
        </tr>
        <tr>
            <td align="center">neg_06</td>
            <td align="center">Negative Test</td>
            <td align="center">0</td>
            <td align="center">Error len_elem</td>
            <td align="center">При вводе длинны вводится 0.
        </td>
        <tr>
            <td align="center">neg_02</td>
            <td align="center">Negative Test</td>
            <td align="center">
            5
            1 2 a</td>
            <td align="center">Error input_value</td>
            <td align="center">При вводе элементов массива, вводится символ в середине ввода.</td>
            <td rowspan=4 align="center">Ошибка при вводе длинны массива.</td>
        </tr>
        <tr>
            <td align="center">neg_09</td>
            <td align="center">Negative Test</td>
            <td align="center">
            5
            1 2 -3 -5 f</td>
            <td align="center">Error input_value</td>
            <td align="center">При вводе элементов массива, вводится символ в конце ввода.</td>
        </tr>
        <tr>
            <td align="center">neg_07</td>
            <td align="center">Negative Test</td>
            <td align="center">
            5
            a</td>
            <td align="center">Error input_value</td>
            <td align="center">При вводе элементов массива, вводится символ в начале ввода.</td>
        </tr>
        <tr>
            <td align="center">neg_08</td>
            <td align="center">Negative Test</td>
            <td align="center">
            4
            1 2 5.56</td>
            <td align="center">Error input_value</td>
            <td align="center">При вводе элементов массива, вводится вещественное число.</td>
        </tr>
        <tr>
            <td align="center">pos_01</td>
            <td align="center">Positive Test</td>
            <td align="center">
            4
            1 2 9 4</td>
            <td align="center">1</td>
            <td align="center">Тест направлен на проверку максимальной суммы полученной из чисел в начале и в конце.</td>
            <td rowspan=2 align="center">Тест направлен на проверку максимальной суммы полученной из чисел в начале и в конце.</td>
        </tr>
        <tr>
            <td align="center">pos_03</td>
            <td align="center">Positive Test</td>
            <td align="center">
            7 
            6 4 -8 3 6 3 2</td>
            <td align="center">8</td>
            <td align="center">Тест направлен на проверку максимальной суммы полученной из чисел в начале и в конце.</td>
        </tr>
        <tr>
            <td align="center">pos_02</td>
            <td align="center">Positive Test</td>
            <td align="center">
            5 
            1 2 4 0 5</td>
            <td align="center">8</td>
            <td align="center">Тест направлен на проверку максимальной суммы полученной из числа находящегося в центре.</td>
            <td rowspan=2 align="center">Тест направлен на проверку максимальной суммы полученной из числа находящегося в центре.</td>
        </tr>
        <tr>
            <td align="center">pos_05</td>
            <td align="center">Positive Test</td>
            <td align="center">
            7 
            1 2 10 12 1 2 5</td>
            <td align="center">22</td>
            <td align="center">Тест направлен на проверку максимальной суммы полученной из числа находящегося в центре.</td>
        </tr>
        <tr>
            <td align="center">pos_04</td>
            <td align="center">Positive Test</td>
            <td align="center">
            6 
            1 10 2 3 10 1</td>
            <td align="center">20</td>
            <td align="center">Тест направлен на проверку максимальной суммы полученной из числа находящегося в середине.</td>
            <td rowspan=1 align="center">Тест направлен на проверку максимальной суммы полученной из числа находящегося в середине.</td>
        </tr>
        <tr>
            <td align="center">pos_06</td>
            <td align="center">Positive Test</td>
            <td align="center">
            1
            12</td>
            <td align="center">13</td>
            <td align="center">Тест направлен на проверку максимальной суммы полученной, когда вводится одно число.</td>
            <td rowspan=1 align="center">Тест направлен на проверку максимальной суммы полученной, когда вводится одно число.</td>
        </tr>
    </tbody>
</table>