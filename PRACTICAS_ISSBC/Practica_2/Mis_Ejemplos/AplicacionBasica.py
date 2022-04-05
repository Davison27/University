import sys
from PyQt5.QtWidgets import QMainWindow, QTextEdit,QSlider ,QLabel ,QAction, QApplication, QProgressBar, QWidget, QPushButton, qApp
from PyQt5.QtGui import QIcon, QPixmap
from PyQt5.QtCore import QBasicTimer, Qt


class Example(QMainWindow):

    def __init__(self):
        super().__init__()

        self.initUI()


    def initUI(self):

        self.pbar = QProgressBar(self)
        self.pbar.setGeometry(120, 150, 250, 20)

        self.btn = QPushButton('Start', self)
        self.btn.move(200, 180)
        self.btn.clicked.connect(self.doAction)

        sld = QSlider(Qt.Horizontal, self)
        sld.setFocusPolicy(Qt.NoFocus)
        sld.setGeometry(120, 120, 250, 30)

        self.timer = QBasicTimer()
        self.step = 0

        AccionSalida = QAction(QIcon('pngegg.png'), 'Exit', self)
        AccionSalida.setShortcut('Ctrl+Q')
        AccionSalida.setStatusTip('Exit')
        AccionSalida.triggered.connect(self.close)

        self.statusBar()

        BarraMenu = self.menuBar()
        MenuArchivo = BarraMenu.addMenu('&File')
        MenuArchivo.addAction(AccionSalida)

        BarraHerramienta = QAction(QIcon('pngegg.png'), 'Exit', self)
        BarraHerramienta.setShortcut('Ctrl+Q')
        BarraHerramienta.triggered.connect(qApp.quit)

        self.toolbar = self.addToolBar('Exit')
        self.toolbar.addAction(BarraHerramienta)

        self.setGeometry(800, 800, 500, 400)
        self.setWindowTitle('Ventana Principal')
        self.show()


    def timerEvent(self, e):

        if self.step >= 100:
            self.timer.stop()
            self.btn.setText('Finished')
            return

        self.step = self.step + 1
        self.pbar.setValue(self.step)

    def doAction(self):

        if self.timer.isActive():
            self.timer.stop()
            self.btn.setText('Start')
        else:
            self.timer.start(100, self)
            self.btn.setText('Stop')

def main():
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()