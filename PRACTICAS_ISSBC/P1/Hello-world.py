import sys
from PyQt5.QtWidgets import QApplication, QWidget

def Window():
    app=QApplication(sys.argv)
    w=QWidget()
    w.setGeometry(100,100,200,50)
    w.setWindowTitle("PyQt")
    w.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    Window()
