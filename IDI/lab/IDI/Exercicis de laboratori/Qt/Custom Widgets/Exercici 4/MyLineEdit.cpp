#include "MyLineEdit.h"

MyLineEdit::MyLineEdit(QWidget *parent=0):QLineEdit(parent) {
}

void MyLineEdit::appendText(QString s) {
    setText(text() + s);
}
