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
            <td align="center"> </td>
            <td align="center">Сразу введен символ, завершающий ввод.</td>
            <td rowspan=2 align="center">Сразу введен элемент, завершающий ввод.</td>
        </tr>
        <tr>
            <td align="center">neg_02</td>
            <td align="center">Negative Test</td>
            <td align="center">1 2 3 4 5 6 7 8 9 10 11</td>
            <td align="center">1 2 3 4 5 6 7 8 9 10</td>
            <td align="center">Сразу введено вещественное число, завершающий ввод.</td>
        </tr>
        <tr>
            <td align="center">pos_01</td>
            <td align="center">Positive Test</td>
            <td align="center">4 5 -1000 3 -9 100 8 a</td>
            <td align="center">-1000 -9 3 4 5 8 100 </td>
            <td align="center">Cимвол введен в середине массива.</td>
            <td rowspan=3 align="center">Стоп элемент введен в середине массива.</td>
        </tr>
        <tr>
            <td align="center">pos_03</td>
            <td align="center">Positive Test</td>
            <td align="center">33456 5 56 -6 -5677 888 0 4 a</td>
            <td align="center">-5677 -6 0 4 5 56 888 33456</td>
            <td align="center">Cимвол введен в середине массива.</td>
        </tr>
        <tr>
            <td align="center">pos_04</td>
            <td align="center">Positive Test</td>
            <td align="center">4 -8 10 100 -4 1.5</td>
            <td align="center">-8 -4 4 10 100</td>
            <td align="center">Вещественное число введено в середине массива.</td>
        </tr>
        <tr>
            <td align="center">pos_01</td>
            <td align="center">Positive Test</td>
            <td align="center">234 -6 4563 46783 353 1 -3456789 73 67 a</td>
            <td align="center">-3456789 -6 1 67 73 234 353 4563 46783 </td>
            <td align="center">Символ введен в конце массива.</td>
            <td rowspan=2 align="center">Стоп элемент введен в конце массива.</td>
        </tr>
        <tr>
            <td align="center">pos_05</td>
            <td align="center">Positive Test</td>
            <td align="center">234 -6 4563 46783 353 1 -3456789 73 67 1.5</td>
            <td align="center">-3456789 -6 1 67 73 234 353 4563 46783 </td>
            <td align="center">Вещественное число введено в конце массива.</td>
        </tr>
    </tbody>
</table>