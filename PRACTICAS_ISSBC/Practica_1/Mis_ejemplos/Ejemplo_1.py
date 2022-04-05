import sys
from PyQt5.QtWidgets import QMainWindow, QTextEdit, QAction, QApplication
from PyQt5.QtGui import QIcon


class Example(QMainWindow):

    def __init__(self):
        super().__init__()

        self.initUI()


    def initUI(self):

        EditarTexto = QTextEdit()
        self.setCentralWidget(EditarTexto)

        AccionSalida = QAction(QIcon('exit.png'), 'Exit', self)
        AccionSalida.setShortcut('Ctrl+Q')
        AccionSalida.setStatusTip('Exit')
        AccionSalida.triggered.connect(self.close)

        self.statusBar()

        BarraMenu = self.menuBar()
        MenuArchivo = BarraMenu.addMenu('&File')
        MenuArchivo.addAction(AccionSalida)


        self.setGeometry(800, 800, 500, 400)
        self.setWindowTitle('Ventana Principal')
        self.show()


def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()