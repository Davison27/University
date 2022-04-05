import sys
from PyQt5.QtWidgets import QApplication
import view as view

app = QApplication(sys.argv)
form = view.EditorTextosDlg()
sys.exit(app.exec_())