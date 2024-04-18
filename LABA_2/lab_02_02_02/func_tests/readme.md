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
            <td align="center">-2</td>
            <td align="center">Error len_elem</td>
            <td align="center">Ввод отридцательной длинны при вводе длинны.</td>
            <td rowspan=5 align="center">Ошибка при вводе длинны массива.</td>
        </tr>
        <tr>
            <td align="center">neg_05</td>
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
            <td align="center">neg_06</td>
            <td align="center">Negative Test</td>
            <td align="center">1.5</td>
            <td align="center">Error len_elem</td>
            <td align="center">При вводе длинны массива введено вещественное число.</td>
        </tr>
        <tr>
            <td align="center">neg_04</td>
            <td align="center">Negative Test</td>
            <td align="center">0</td>
            <td align="center">Error len_elem</td>
            <td align="center">При вводе длинны вводится 0.</td>
        <tr>
            <td align="center">neg_02</td>
            <td align="center">Negative Test</td>
            <td align="center">3 1 a 3</td>
            <td align="center">Error input_value</td>
            <td align="center">При вводе элементов массива, вводится символ в середине ввода.</td>
            <td rowspan=3 align="center">Ошибка при вводе элементов массива.</td>
        </tr>
        <tr>
            <td align="center">neg_07</td>
            <td align="center">Negative Test</td>
            <td align="center">5 1 2 -3 -5 f</td>
            <td align="center">Error input_value</td>
            <td align="center">При вводе элементов массива, вводится символ в конце ввода.</td>
        </tr>
        <tr>
            <td align="center">neg_08</td>
            <td align="center">Negative Test</td>
            <td align="center">5 a</td>
            <td align="center">Error input_value</td>
            <td align="center">При вводе элементов массива, вводится символ в начале ввода.</td>
        </tr>
        <tr>
            <td align="center">neg_09</td>
            <td align="center">Negative Test</td>
            <td align="center">4 1 2 5.56</td>
            <td align="center">Error input_value</td>
            <td align="center">При вводе элементов массива, вводится вещественное число.</td>
        </tr>
        <tr>
            <td align="center">neg_03</td>
            <td align="center">Negative Test</td>
            <td align="center">5 12 23 34 45 56</td>
            <td align="center">Error haven`t simetric elements</td>
            <td align="center">В массиве отсутствуют числа, которые начинают и заканчиваются на одну и ту же цифру элементы.</td>
            <td rowspan=1 align="center">В массиве отсутствуют числа, которые начинают и заканчиваются на одну и ту же цифру элементы.</td>
        </tr>
        <tr>
            <td align="center">pos_01</td>
            <td align="center">Positive Test</td>
            <td align="center">3 1 2 3</td>
            <td align="center">1 2 3</td>
            <td align="center">В массиве все числа начинаются и заканчиваются на одну и ту же цифру.</td>
            <td rowspan=2 align="center">В массиве все числа начинаются и заканчиваются на одну и ту же цифру.</td>
        </tr>
        <tr>
            <td align="center">pos_04</td>
            <td align="center">Positive Test</td>
            <td align="center">4 323 -121 3213 -454</td>
            <td align="center">323 -121 3213 -454</td>
            <td align="center">В массиве все числа начинаются и заканчиваются на одну и ту же цифру.</td>
        </tr>
        <tr>
            <td align="center">pos_02</td>
            <td align="center">Positive Test</td>
            <td align="center">4 100 101 202 23</td>
            <td align="center">101 202</td>
            <td align="center">В массиве несколько чисел начинаются и заканчиваются на одну и ту же цифру.</td>
            <td rowspan=2 align="center">В массиве несколько чисел начинаются и заканчиваются на одну и ту же цифру<td>
        </tr>
        <tr>
            <td align="center">pos_05</td>
            <td align="center">Positive Test</td>
            <td align="center">7 1 12 11 0 121 88 91</td>
            <td align="center">1 11 0 121 88</td>
            <td align="center">В массиве несколько чисел начинаются и заканчиваются на одну и ту же цифру.</td>
        </tr>
        <tr>
            <td align="center">pos_03</td>
            <td align="center">Positive Test</td>
            <td align="center">5 -1 12 -2 3 4</td>
            <td align="center">-1 -2 3 4</td>
            <td align="center">В массиве есть несколько отридцательных чисел, которые начинаются и заканчиваются на одну и ту же цифру.</td>
            <td rowspan=2 align="center">В массиве есть несколько отридцательных чисел, которые начинаются и заканчиваются на одну и ту же цифру.<td>
        </tr>
        <tr>
            <td align="center">pos_04</td>
            <td align="center">Positive Test</td>
            <td align="center">4 323 -121 3213 -454</td>
            <td align="center">323 -121 3213 -454</td>
            <td align="center">В массиве все числа отридфательные, которые начинаются и заканчиваются на одну и ту же цифру.</td>
        </tr>
        <tr>
            <td align="center">pos_06</td>
            <td align="center">Positive Test</td>
            <td align="center">4 -121 -22 -313 -4</td>
            <td align="center">-121 -22 -313 -4</td>
            <td align="center">В массиве все числа отридфательные, которые начинаются и заканчиваются на одну и ту же цифру.</td>
            <td rowspan=1 align="center">В массиве все числа отридфательные, которые начинаются и заканчиваются на одну и ту же цифру.<td>
        </tr>
    </tbody>
</table>