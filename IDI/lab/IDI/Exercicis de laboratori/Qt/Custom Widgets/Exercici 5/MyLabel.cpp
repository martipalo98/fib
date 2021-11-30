#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent=0):QLabel(parent) {
}

void MyLabel::setName(QString s) {
    name = s;
}

void MyLabel::setSurname(QString s) {
    surname = s;
}

void MyLabel::setDNI(QString s) {
    dni = s;
}

void MyLabel::showResult() {
    QStringList list = {};
    if (name == "") list.append("nom");
    if (surname == "") list.append("cognom");
    if (dni == "") list.append("DNI");

    if (list != QStringList{}) {
        QString error_str = "ERROR: Els camps ";
        for (int i = 0; i < list.length(); ++i) {
            error_str += list[i];
            if (i == list.length()-2) error_str += " i ";
            else if (i != list.length()-1) error_str += ", ";
        }
        error_str += " són obligatoris!";
        setText(error_str);
    } else {
        setText(name+surname+dni);
    }
}
