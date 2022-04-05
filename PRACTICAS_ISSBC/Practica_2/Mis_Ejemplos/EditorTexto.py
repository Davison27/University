from PyQt5.QtWidgets import *
from PyQt5.QtGui import QIcon
import sys
from pathlib import Path


class Editor_texto(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.path = None
        self.txt = QTextEdit()
        self.setCentralWidget(self.txt)
        self.statusBar()

        AbrirArchivo = QAction("Abrir", self)
        AbrirArchivo.setShortcut("Ctrl+O")
        AbrirArchivo.setStatusTip("Abrir archivo")
        AbrirArchivo.triggered.connect(self.AbrirArchivo)

        NuevoArchivo = QAction("Nuevo", self)
        NuevoArchivo.setShortcut("Ctrl+N")
        NuevoArchivo.setStatusTip("Nuevo archivo")
        NuevoArchivo.triggered.connect(self.NuevoArchivo)

        GuardarArchivo = QAction("Guardar", self)
        GuardarArchivo.setShortcut("Ctrl+S")
        GuardarArchivo.setStatusTip("Guardar Archivo")
        GuardarArchivo.triggered.connect(self.GuardarArchivo)

        GuardarComoArchivo = QAction("Guardar como", self)
        GuardarComoArchivo.setShortcut("F12")
        GuardarComoArchivo.setStatusTip("Guardar como")
        GuardarComoArchivo.triggered.connect(self.GuardarComoArchivo)

        menubar = self.menuBar()
        fileMenu = menubar.addMenu("&Archivo")
        fileMenu.addAction(AbrirArchivo)
        fileMenu.addAction(NuevoArchivo)
        fileMenu.addAction(GuardarArchivo)
        fileMenu.addAction(GuardarComoArchivo)

        self.setGeometry(300, 300, 500, 500)
        self.setWindowTitle("Editor de texto")
        self.show()

    def NuevoArchivo(self):
        self.txt.clear()

    def AbrirArchivo(self):
        home_dir = str(Path.home())
        fname = QFileDialog.getOpenFileName(self, "Abrir archivo", home_dir)
        if fname[0]:
            f = open(fname[0], "r")
            with f:
                data = f.read()
                self.txt.setText(data)
                self.path = fname
                self.setWindowTitle(fname[0])

    def GuardarArchivo(self):
        if self.path is None:
            return self.GuardarComoArchivo()
        self.save_path()

    def GuardarComoArchivo(self):
        fname = QFileDialog.getSaveFileName(self, "Guardar archivo")
        if fname[0]:
            f = open(fname[0], "w")
            with f:
                data = self.txt.toPlainText()
                f.write(data)
                f.close()
                self.path = fname
                self.setWindowTitle(fname[0])

    def save_path(self):
        text = self.txt.toPlainText()
        with open(self.path[0], "w") as f:
            f.write(text)


def main():
    app = QApplication(sys.argv)
    ex = Editor_texto()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()