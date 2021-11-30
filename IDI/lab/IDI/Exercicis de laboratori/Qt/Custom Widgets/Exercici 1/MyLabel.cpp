#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent=0):QLabel(parent) {
}

void MyLabel::ChangeHighwayColor(bool b) {
    QString rgb = "255,0,0";
    if (b) rgb  = "0,255,0";

    setStyleSheet("background-color: rgba(" + rgb + ");");
}


void MyLabel::UpdateCarMotorcyclePrice() {
    totalrecaudation += 1;
    setText(QString("Total diners recaudats: %1€").arg(totalrecaudation));
}

void MyLabel::UpdateTruckPrice() {
    totalrecaudation += 4;
    setText(QString("Total diners recaudats: %1€").arg(totalrecaudation));
}



void MyLabel::UpdateCarNum() {
    totalcars += 1;
    setText(QString("Total cotxes: %1").arg(totalcars));
}

void MyLabel::UpdateMotorcycleNum() {
    totalmotorcycles += 1;
    setText(QString("Total motos: %1").arg(totalmotorcycles));
}

void MyLabel::UpdateTruckNum() {
    totaltrucks += 1;
    setText(QString("Total camions: %1").arg(totaltrucks));
}
