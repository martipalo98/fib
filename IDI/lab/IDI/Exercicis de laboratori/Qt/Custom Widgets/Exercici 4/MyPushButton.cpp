#include "MyPushButton.h"

MyPushButton::MyPushButton(QWidget *parent=0):QPushButton(parent) {
}

void MyPushButton::toggleVowels() {
    if (shift_enabled) setText(text().toLower());
    else setText(text().toUpper());
    shift_enabled ^= 1;
}


void MyPushButton::writeVowel() {
    emit sendVowel(text());
}
