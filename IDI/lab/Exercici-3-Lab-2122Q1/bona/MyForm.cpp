#include "MyForm.h"
#include <QTime>
#include <ctime>
#include <algorithm>
#include <QtMath>
#include <QKeyEvent>

bool comp(QLabel *a, QLabel *b) {
    if(a->objectName() < b->objectName()) return true;
    return false;
}

MyForm::MyForm(QWidget *parent):QWidget(parent)
{
    srand(time(NULL));
    comptadorGlobal = 0;
    temps = 1000;
    ui.setupUi(this);
    labels = this->findChildren<QLabel *>();
    labels.pop_back();
    std::sort(labels.begin(), labels.end(), comp);
    /*int i=0;
    foreach(QLabel *l, labels) {
        if(l->text().contains("-")) {
            l->setText(QString::number(i++));
         }
    }*/
    comptadors = this->findChildren<QLCDNumber *>(QRegExp("counter*"));
}

void MyForm::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(temps);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, temps);
}


bool vaigDreta() {
    if(rand()%2) {
        return true;
    }else return false;
}

void MyForm::actualitzaComptador() {
    comptadorGlobal++;
    int digits = ui.comptadorGlobal->digitCount();
    if(comptadorGlobal >= qPow(10, digits)) {
        ui.comptadorGlobal->setDigitCount(ui.comptadorGlobal->digitCount()+1);
    }
    this->findChild<QLCDNumber *>("comptadorGlobal")->display(comptadorGlobal);
}

void MyForm::llencarBola(){
    this->findChild<QPushButton *>("botoAfegir")->setEnabled(false); //evitem moltes boles de cop!
    this->findChild<QPushButton *>("botoReiniciar")->setEnabled(false);
    this->findChild<QLabel *>("labelPilota")->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    this->findChild<QLabel *>("labelPalanques")->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

    //profunditat piramide = profunditat arbre binari balancejat
    int profunditat = QString::number(qLn(labels.size())/qLn(2)).split(".")[0].toInt();
    QString nomcomptador="";
    int tempsantic = temps;
     temps = temps/(ui.quantesBoles->value());
        for(int n = 0; n<ui.quantesBoles->value(); ++n) {
            actualitzaComptador();
            //LLENÇAR BOLA
            this->findChild<QLabel *>("labelPilota")->setText("");
            this->findChild<QLabel *>("labelPalanques")->setText("\\O/");
            delay();
            this->findChild<QLabel *>("labelPalanques")->setText("/ \\");
            //RECORRER PIRAMIDE ETIQUETES
            labels[0]->setText(QString("O"));
            int val = 0;
            labels[val]->setText("O");
            delay();
            for(int i = 0; i < profunditat; ++i) {
                labels[val]->setText("-");
                if(vaigDreta()) {
                    val += i+1;
                }else {
                    val += i+2;
                }
                labels[val]->setText("O");
                delay();
                labels[val]->setText("-");
            }
            labels[profunditat-1]->setText(QString("-"));
            if(vaigDreta()) {
                nomcomptador = "counter"+QString(QString::number(val-comptadors.size()+1));
            }else {
                nomcomptador = "counter"+QString(QString::number(val-comptadors.size()));
            }
            //COMPTADORS FINALS
            foreach(QLCDNumber *compt, comptadors) {
                if(compt->objectName() == nomcomptador) {
                    int digits = compt->digitCount();
                    if((compt->intValue())+1 == qPow(10, digits)) {
                        compt->setDigitCount(compt->digitCount()+1);
                    }
                    compt->display(compt->intValue()+1);
                }
            }

            this->findChild<QLabel *>("labelPilota")->setText("O");
            this->findChild<QLabel *>("labelPalanques")->setText("__ __");

    }
        temps = tempsantic;
        this->findChild<QPushButton *>("botoAfegir")->setEnabled(true);
        this->findChild<QPushButton *>("botoReiniciar")->setEnabled(true);

}

void MyForm::reiniciar() {
    this->findChild<QLabel *>("labelPilota")->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    this->findChild<QLabel *>("labelPalanques")->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

    temps = 1000;
    comptadorGlobal = 0;
    this->findChild<QLCDNumber *>("comptadorGlobal")->display(0);
    foreach(QLabel *l, labels) {
        l->setText(QString("-"));
    }
    foreach(QLCDNumber *c, comptadors) {
        c->display(0);
    }

    foreach(QLCDNumber *compt, comptadors) {
        compt->setDigitCount(1);
    }

    ui.quantesBoles->setValue(1);

    this->findChild<QLabel *>("labelPilota")->setText("O");
    this->findChild<QLabel *>("labelPalanques")->setText("__ __");

}

void MyForm::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_R:
            if(event->modifiers()==Qt::AltModifier) {
                reiniciar();
            }
            break;
        case Qt::Key_B:
            if(event->modifiers()==Qt::AltModifier) {
                temps*=0.75; //ACCELERAR 1/4 de temps
                if(temps < 1) temps = 1000;
            };
            break;
    }
}


void MyForm::afegirBoles() {
    QSpinBox *sliderBoles = this->findChild<QSpinBox *>("quantesBoles");
    if(sliderBoles->value() == 1) {
        ui.botoAfegir->setText("Llençar bola");
    }else {
        ui.botoAfegir->setText(QString("Llençar ") + QString::number(sliderBoles->value()) + QString(" boles"));
    }
}
