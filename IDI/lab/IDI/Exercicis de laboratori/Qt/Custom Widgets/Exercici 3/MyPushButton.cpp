#include "MyPushButton.h"

MyPushButton::MyPushButton(QWidget *parent=0):QPushButton(parent) {
    color_id = rand()%4;
    changeColor(0);
}

void MyPushButton::changeColor(int c) {
    color_id = (color_id+c)%4;

    QString rgb;
    if (color_id == 0) rgb = "255,0,255";
    else if (color_id == 1) rgb = "0,255,0";
    else if (color_id == 2) rgb = "0,0,255";
    else rgb = "0,0,0";

    setStyleSheet("background-color: rgba(" + rgb + ");");
}
