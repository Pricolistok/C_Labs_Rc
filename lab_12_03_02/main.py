import sys
from curses.ascii import isdigit
from PyQt5.Qt import *
from PyQt5 import QtWidgets
import ctypes

lib = ctypes.CDLL('./dynlib_1.so')

class Creator(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.windowAboutCreator = QWidget()
        self.windowAboutCreator.setWindowTitle('About creator')
        self.windowAboutCreator.resize(400, 200)
        textboxAboutCreator = QLabel(self.windowAboutCreator)
        textboxAboutCreator.setText("Доколин Георгий ИУ7-32Б")
        textboxAboutCreator.move(50, 60)
        textboxAboutCreator.setFont(QFont('Comfortaa', 18))
        self.windowAboutCreator.show()


class Calc(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.window_about_prog = QWidget()
        self.window_about_prog.setWindowTitle('About programm')
        self.window_about_prog.resize(1000, 200)
        textbox_about_creator = QLabel(self.window_about_prog)
        textbox_about_creator.setText("Приложение использует самописную библиотеку на си")
        textbox_about_creator.move(2, 40)
        textbox_about_creator.setFont(QFont('Comfortaa', 18))
        self.window_about_prog.show()


class App(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.answer = ''
        self.window = QWidget()
        self.window.setWindowTitle('Calculator')
        type_font = 'Comfortaa'
        self.grid = QGridLayout(self.window)
        self.menubar = QMenuBar(self.window)
        self.grid.addWidget(self.menubar)
        inform = self.menubar.addMenu('INFO')
        inform.addAction('About creator').triggered.connect(self.about_creator_func)
        inform.addAction('About programm').triggered.connect(self.about_programm_func)
        font_size = 18
        self.row_for_calc = ''
        size_x, size_y = 250, 60

        self.row_input = QLineEdit()
        self.row_input.setFixedSize(260, 40)
        self.row_input.setFont(QFont(type_font, font_size))
        self.grid.addWidget(self.row_input, 1, 0, 1, 4, alignment=Qt.AlignCenter)

        self.btn_cr = QPushButton('CREATOR')
        self.grid.addWidget(self.btn_cr, 1, 4)
        self.btn_cr.clicked.connect(lambda: self.create_row())
        self.btn_cr.setFixedSize(size_x, size_y)
        self.btn_cr.setFont(QFont(type_font, font_size))

        self.btn_more_mem = QPushButton('FLAG MORE MEM')
        self.grid.addWidget(self.btn_more_mem, 2, 4)
        self.btn_more_mem.clicked.connect(lambda: self.flag_more_mem())
        self.btn_more_mem.setFixedSize(size_x, size_y)
        self.btn_more_mem.setFont(QFont(type_font, font_size))

        self.btn_small_mem = QPushButton('FLAG IDEAL MEM')
        self.grid.addWidget(self.btn_small_mem, 2, 6)
        self.btn_small_mem.clicked.connect(lambda: self.flag_ideal_mem())
        self.btn_small_mem.setFixedSize(size_x, size_y)
        self.btn_small_mem.setFont(QFont(type_font, font_size))

        self.row_input_elem = QLineEdit()
        self.row_input_elem.setFixedSize(260, 40)
        self.row_input_elem.setFont(QFont(type_font, font_size))
        self.grid.addWidget(self.row_input_elem, 2, 0, 2, 4, alignment=Qt.AlignCenter)

        self.row_result = QLineEdit()
        self.row_result.setFixedSize(1100, 40)
        self.row_result.setFont(QFont(type_font, font_size))
        self.grid.addWidget(self.row_result, 4, 0, 4, 12, alignment=Qt.AlignCenter)

        self.window.show()

    def checker_row(self, nums):
        nums = nums.split()
        for i in nums:
            if isdigit(i) != True:
                return False
        return True

    def create_row(self):
        _creator = lib.add_simple_nums_to_arr
        _creator.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t)
        _creator.restype = None
        def creator(n):
            arr = (ctypes.c_int * n)()
            _creator(arr, n)
            return list(arr)
        row = ""
        text = self.row_input.text()
        if (len(text) != 0 and self.checker_row(text) == True):
            if len(text) != 0 and isdigit(str(text)) == True:
                for i in creator(int(text)):
                    row += f" {i}"
                self.row_result.setText(row)
            else:
                self.row_result.setText("")
        else:
            self.row_result.setText("")

    def flag_more_mem(self):
        _more_mem = lib.filter_nums
        _more_mem.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_size_t), ctypes.c_int)
        _more_mem.restype = ctypes.c_int
        def more_mem(nums, elem):
            nums = list(map(int, nums.split()))
            src_len = len(nums)
            src = (ctypes.c_int * src_len)(*nums)
            dst_len = ctypes.c_size_t(0)
            rc = _more_mem(src, src_len, None, dst_len, elem)
            if rc == 104:
                dst = (ctypes.c_int * dst_len.value)()
                rc = _more_mem(src, src_len, dst, dst_len, elem)
                return list(dst)
            else:
                return list()
        text = self.row_input.text()
        if (len(text) != 0 and self.checker_row(text) == True and isdigit(self.row_input_elem.text()) == True):
            row = ""
            for i in more_mem(text, int(self.row_input_elem.text())):
                row += f" {i}"
            self.row_result.setText(row)
        else:
            self.row_result.setText("")


    def flag_ideal_mem(self):
        _cnt_ch = lib.cnt_ch_nums
        _cnt_ch.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t, ctypes.POINTER(ctypes.c_size_t))
        _cnt_ch.restype = None
        _more_mem = lib.filter_nums
        _more_mem.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_size_t), ctypes.c_int)
        _more_mem.restype = ctypes.c_int

        def cnt_ch(nums, elem):
            nums = list(map(int, nums.split()))
            src_len = len(nums)
            dst_len = ctypes.c_size_t(0)
            src = (ctypes.c_int * src_len)(*nums)
            _cnt_ch(src, src_len, dst_len)
            print(dst_len.value, src_len)
            dst = (ctypes.c_int * (dst_len.value + src_len))()
            dst_len = ctypes.c_size_t(dst_len.value + src_len)
            _more_mem(src, src_len, dst, dst_len, elem)
            print(list(dst))
            return list(dst)
        text = self.row_input.text()
        if (len(text) != 0 and self.checker_row(text) == True and isdigit(self.row_input_elem.text()) == True):
            row = ""
            for i in cnt_ch(text, int(self.row_input_elem.text())):
                row += f" {i}"
            self.row_result.setText(row)
        else:
            self.row_result.setText("")


    def about_creator_func(self):
        self.creator_inform = Creator()

    def about_programm_func(self):
        self.programm_inform = Calc()



def main():
    # Create app and window
    app = QApplication([])
    ex = App()
    ex.setStyle(QStyleFactory.create('CDEstyle'))
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()