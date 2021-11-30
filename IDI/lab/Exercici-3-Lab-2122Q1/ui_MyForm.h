/********************************************************************************
** Form generated from reading UI file 'MyForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QLCDNumber *counter1;
    QSpacerItem *horizontalSpacer_10;
    QLCDNumber *counter2;
    QSpacerItem *horizontalSpacer_11;
    QLCDNumber *counter3;
    QSpacerItem *horizontalSpacer_12;
    QLCDNumber *counter4;
    QSpacerItem *horizontalSpacer_13;
    QLCDNumber *counter5;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *horizontalSpacer;
    QLabel *label10;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label11;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QLabel *label00;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label30;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label31;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label32;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label33;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label20;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label21;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label22;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelPilota;
    QLabel *labelPalanques;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_8;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_2;
    QSlider *sliderComptador;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_13;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_24;
    QLabel *label;
    QSpinBox *quantesBoles;
    QSpacerItem *horizontalSpacer_23;
    QPushButton *botoAfegir;
    QSpacerItem *verticalSpacer_12;
    QLabel *label_11;
    QLCDNumber *comptadorGlobal;
    QSpacerItem *verticalSpacer_11;
    QPushButton *botoReiniciar;
    QSpacerItem *verticalSpacer_10;
    QPushButton *botoSortir;
    QSpacerItem *verticalSpacer_9;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QString::fromUtf8("MyForm"));
        MyForm->resize(940, 544);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MyForm->sizePolicy().hasHeightForWidth());
        MyForm->setSizePolicy(sizePolicy);
        MyForm->setMinimumSize(QSize(273, 228));
        MyForm->setMaximumSize(QSize(5000, 5000));
        MyForm->setSizeIncrement(QSize(1, 1));
        MyForm->setBaseSize(QSize(1, 1));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(40, 44, 52, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        MyForm->setPalette(palette);
        MyForm->setAutoFillBackground(false);
        MyForm->setStyleSheet(QString::fromUtf8("background-color: #282C34;\n"
"color: #FFFFFF;\n"
"\n"
"QLabel { 	font: 30 bold \"Montserrat\"; }\n"
""));
        horizontalLayout_6 = new QHBoxLayout(MyForm);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 4, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        counter1 = new QLCDNumber(MyForm);
        counter1->setObjectName(QString::fromUtf8("counter1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(counter1->sizePolicy().hasHeightForWidth());
        counter1->setSizePolicy(sizePolicy1);
        counter1->setMinimumSize(QSize(28, 23));
        counter1->setMaximumSize(QSize(16777215, 16777215));
        counter1->setSizeIncrement(QSize(1, 1));
        counter1->setBaseSize(QSize(1, 1));
        QFont font;
        font.setFamily(QString::fromUtf8("Caladea"));
        font.setItalic(true);
        counter1->setFont(font);
        counter1->setLayoutDirection(Qt::LeftToRight);
        counter1->setStyleSheet(QString::fromUtf8("text-align: center;"));
        counter1->setFrameShape(QFrame::NoFrame);
        counter1->setFrameShadow(QFrame::Plain);
        counter1->setLineWidth(0);
        counter1->setMidLineWidth(0);
        counter1->setDigitCount(1);
        counter1->setSegmentStyle(QLCDNumber::Flat);
        counter1->setProperty("value", QVariant(0.000000000000000));
        counter1->setProperty("intValue", QVariant(0));

        horizontalLayout_4->addWidget(counter1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        counter2 = new QLCDNumber(MyForm);
        counter2->setObjectName(QString::fromUtf8("counter2"));
        sizePolicy1.setHeightForWidth(counter2->sizePolicy().hasHeightForWidth());
        counter2->setSizePolicy(sizePolicy1);
        counter2->setMinimumSize(QSize(28, 23));
        counter2->setMaximumSize(QSize(16777215, 16777215));
        counter2->setSizeIncrement(QSize(1, 1));
        counter2->setBaseSize(QSize(1, 1));
        counter2->setFont(font);
        counter2->setLayoutDirection(Qt::LeftToRight);
        counter2->setStyleSheet(QString::fromUtf8("text-align: center;"));
        counter2->setFrameShape(QFrame::NoFrame);
        counter2->setFrameShadow(QFrame::Plain);
        counter2->setLineWidth(0);
        counter2->setMidLineWidth(0);
        counter2->setDigitCount(1);
        counter2->setSegmentStyle(QLCDNumber::Flat);
        counter2->setProperty("value", QVariant(0.000000000000000));
        counter2->setProperty("intValue", QVariant(0));

        horizontalLayout_4->addWidget(counter2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        counter3 = new QLCDNumber(MyForm);
        counter3->setObjectName(QString::fromUtf8("counter3"));
        sizePolicy1.setHeightForWidth(counter3->sizePolicy().hasHeightForWidth());
        counter3->setSizePolicy(sizePolicy1);
        counter3->setMinimumSize(QSize(28, 23));
        counter3->setMaximumSize(QSize(16777215, 16777215));
        counter3->setSizeIncrement(QSize(1, 1));
        counter3->setBaseSize(QSize(1, 1));
        counter3->setFont(font);
        counter3->setLayoutDirection(Qt::LeftToRight);
        counter3->setStyleSheet(QString::fromUtf8("text-align: center;"));
        counter3->setFrameShape(QFrame::NoFrame);
        counter3->setFrameShadow(QFrame::Plain);
        counter3->setLineWidth(0);
        counter3->setMidLineWidth(0);
        counter3->setDigitCount(1);
        counter3->setSegmentStyle(QLCDNumber::Flat);
        counter3->setProperty("value", QVariant(0.000000000000000));
        counter3->setProperty("intValue", QVariant(0));

        horizontalLayout_4->addWidget(counter3);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);

        counter4 = new QLCDNumber(MyForm);
        counter4->setObjectName(QString::fromUtf8("counter4"));
        sizePolicy1.setHeightForWidth(counter4->sizePolicy().hasHeightForWidth());
        counter4->setSizePolicy(sizePolicy1);
        counter4->setMinimumSize(QSize(28, 23));
        counter4->setMaximumSize(QSize(16777215, 16777215));
        counter4->setSizeIncrement(QSize(1, 1));
        counter4->setBaseSize(QSize(1, 1));
        counter4->setFont(font);
        counter4->setLayoutDirection(Qt::LeftToRight);
        counter4->setStyleSheet(QString::fromUtf8("text-align: center;"));
        counter4->setFrameShape(QFrame::NoFrame);
        counter4->setFrameShadow(QFrame::Plain);
        counter4->setLineWidth(0);
        counter4->setMidLineWidth(0);
        counter4->setDigitCount(1);
        counter4->setSegmentStyle(QLCDNumber::Flat);
        counter4->setProperty("value", QVariant(0.000000000000000));
        counter4->setProperty("intValue", QVariant(0));

        horizontalLayout_4->addWidget(counter4);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_13);

        counter5 = new QLCDNumber(MyForm);
        counter5->setObjectName(QString::fromUtf8("counter5"));
        sizePolicy1.setHeightForWidth(counter5->sizePolicy().hasHeightForWidth());
        counter5->setSizePolicy(sizePolicy1);
        counter5->setMinimumSize(QSize(28, 23));
        counter5->setMaximumSize(QSize(16777215, 16777215));
        counter5->setSizeIncrement(QSize(1, 1));
        counter5->setBaseSize(QSize(1, 1));
        counter5->setFont(font);
        counter5->setLayoutDirection(Qt::LeftToRight);
        counter5->setStyleSheet(QString::fromUtf8(""));
        counter5->setFrameShape(QFrame::NoFrame);
        counter5->setFrameShadow(QFrame::Plain);
        counter5->setLineWidth(0);
        counter5->setMidLineWidth(0);
        counter5->setDigitCount(1);
        counter5->setSegmentStyle(QLCDNumber::Flat);
        counter5->setProperty("value", QVariant(0.000000000000000));
        counter5->setProperty("intValue", QVariant(0));

        horizontalLayout_4->addWidget(counter5);


        gridLayout_2->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_17);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_21);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label10 = new QLabel(MyForm);
        label10->setObjectName(QString::fromUtf8("label10"));
        sizePolicy.setHeightForWidth(label10->sizePolicy().hasHeightForWidth());
        label10->setSizePolicy(sizePolicy);
        label10->setMinimumSize(QSize(78, 15));
        label10->setSizeIncrement(QSize(1, 1));
        label10->setBaseSize(QSize(1, 1));
        label10->setLayoutDirection(Qt::LeftToRight);
        label10->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label10);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label11 = new QLabel(MyForm);
        label11->setObjectName(QString::fromUtf8("label11"));
        sizePolicy.setHeightForWidth(label11->sizePolicy().hasHeightForWidth());
        label11->setSizePolicy(sizePolicy);
        label11->setMinimumSize(QSize(78, 15));
        label11->setSizeIncrement(QSize(1, 1));
        label11->setBaseSize(QSize(1, 1));
        label11->setLayoutDirection(Qt::LeftToRight);
        label11->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label11);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_18);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_22);


        gridLayout->addLayout(horizontalLayout_3, 5, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 6, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 4, 0, 1, 1);

        label00 = new QLabel(MyForm);
        label00->setObjectName(QString::fromUtf8("label00"));
        sizePolicy.setHeightForWidth(label00->sizePolicy().hasHeightForWidth());
        label00->setSizePolicy(sizePolicy);
        label00->setMinimumSize(QSize(164, 15));
        label00->setSizeIncrement(QSize(1, 1));
        label00->setBaseSize(QSize(1, 1));
        label00->setLayoutDirection(Qt::LeftToRight);
        label00->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label00, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_15);

        label30 = new QLabel(MyForm);
        label30->setObjectName(QString::fromUtf8("label30"));
        sizePolicy.setHeightForWidth(label30->sizePolicy().hasHeightForWidth());
        label30->setSizePolicy(sizePolicy);
        label30->setMinimumSize(QSize(36, 15));
        label30->setSizeIncrement(QSize(1, 1));
        label30->setBaseSize(QSize(1, 1));
        label30->setLayoutDirection(Qt::LeftToRight);
        label30->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label30);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        label31 = new QLabel(MyForm);
        label31->setObjectName(QString::fromUtf8("label31"));
        sizePolicy.setHeightForWidth(label31->sizePolicy().hasHeightForWidth());
        label31->setSizePolicy(sizePolicy);
        label31->setMinimumSize(QSize(36, 15));
        label31->setSizeIncrement(QSize(1, 1));
        label31->setBaseSize(QSize(1, 1));
        label31->setLayoutDirection(Qt::LeftToRight);
        label31->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label31);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        label32 = new QLabel(MyForm);
        label32->setObjectName(QString::fromUtf8("label32"));
        sizePolicy.setHeightForWidth(label32->sizePolicy().hasHeightForWidth());
        label32->setSizePolicy(sizePolicy);
        label32->setMinimumSize(QSize(36, 15));
        label32->setSizeIncrement(QSize(1, 1));
        label32->setBaseSize(QSize(1, 1));
        label32->setLayoutDirection(Qt::LeftToRight);
        label32->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label32);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        label33 = new QLabel(MyForm);
        label33->setObjectName(QString::fromUtf8("label33"));
        sizePolicy.setHeightForWidth(label33->sizePolicy().hasHeightForWidth());
        label33->setSizePolicy(sizePolicy);
        label33->setMinimumSize(QSize(36, 15));
        label33->setSizeIncrement(QSize(1, 1));
        label33->setBaseSize(QSize(1, 1));
        label33->setLayoutDirection(Qt::LeftToRight);
        label33->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label33);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_16);


        gridLayout->addLayout(horizontalLayout, 10, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_19);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label20 = new QLabel(MyForm);
        label20->setObjectName(QString::fromUtf8("label20"));
        sizePolicy.setHeightForWidth(label20->sizePolicy().hasHeightForWidth());
        label20->setSizePolicy(sizePolicy);
        label20->setMinimumSize(QSize(50, 15));
        label20->setSizeIncrement(QSize(1, 1));
        label20->setBaseSize(QSize(1, 1));
        label20->setLayoutDirection(Qt::LeftToRight);
        label20->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label20);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        label21 = new QLabel(MyForm);
        label21->setObjectName(QString::fromUtf8("label21"));
        sizePolicy.setHeightForWidth(label21->sizePolicy().hasHeightForWidth());
        label21->setSizePolicy(sizePolicy);
        label21->setMinimumSize(QSize(50, 15));
        label21->setSizeIncrement(QSize(1, 1));
        label21->setBaseSize(QSize(1, 1));
        label21->setLayoutDirection(Qt::LeftToRight);
        label21->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label21);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label22 = new QLabel(MyForm);
        label22->setObjectName(QString::fromUtf8("label22"));
        sizePolicy.setHeightForWidth(label22->sizePolicy().hasHeightForWidth());
        label22->setSizePolicy(sizePolicy);
        label22->setMinimumSize(QSize(50, 15));
        label22->setSizeIncrement(QSize(1, 1));
        label22->setBaseSize(QSize(1, 1));
        label22->setLayoutDirection(Qt::LeftToRight);
        label22->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label22);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_14);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_20);


        gridLayout->addLayout(horizontalLayout_2, 7, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 8, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelPilota = new QLabel(MyForm);
        labelPilota->setObjectName(QString::fromUtf8("labelPilota"));

        verticalLayout_4->addWidget(labelPilota);

        labelPalanques = new QLabel(MyForm);
        labelPalanques->setObjectName(QString::fromUtf8("labelPalanques"));

        verticalLayout_4->addWidget(labelPalanques);


        gridLayout->addLayout(verticalLayout_4, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_4 = new QLabel(MyForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_5->addWidget(label_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_2 = new QLabel(MyForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_10->addWidget(label_2);

        sliderComptador = new QSlider(MyForm);
        sliderComptador->setObjectName(QString::fromUtf8("sliderComptador"));
        sliderComptador->setMaximum(5000);
        sliderComptador->setSingleStep(250);
        sliderComptador->setValue(1000);
        sliderComptador->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(sliderComptador);

        label_3 = new QLabel(MyForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_10->addWidget(label_3);


        verticalLayout_5->addLayout(horizontalLayout_10);


        verticalLayout->addLayout(verticalLayout_5);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_13);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_24);

        label = new QLabel(MyForm);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_9->addWidget(label);

        quantesBoles = new QSpinBox(MyForm);
        quantesBoles->setObjectName(QString::fromUtf8("quantesBoles"));
        quantesBoles->setWrapping(false);
        quantesBoles->setFrame(true);
        quantesBoles->setAlignment(Qt::AlignCenter);
        quantesBoles->setAccelerated(true);
        quantesBoles->setProperty("showGroupSeparator", QVariant(true));
        quantesBoles->setMinimum(1);
        quantesBoles->setMaximum(1000);
        quantesBoles->setValue(1);

        horizontalLayout_9->addWidget(quantesBoles);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_23);


        verticalLayout->addLayout(horizontalLayout_9);

        botoAfegir = new QPushButton(MyForm);
        botoAfegir->setObjectName(QString::fromUtf8("botoAfegir"));
        botoAfegir->setMinimumSize(QSize(82, 45));

        verticalLayout->addWidget(botoAfegir);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_12);

        label_11 = new QLabel(MyForm);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(82, 15));
        label_11->setSizeIncrement(QSize(1, 1));
        label_11->setBaseSize(QSize(1, 1));

        verticalLayout->addWidget(label_11, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        comptadorGlobal = new QLCDNumber(MyForm);
        comptadorGlobal->setObjectName(QString::fromUtf8("comptadorGlobal"));
        sizePolicy1.setHeightForWidth(comptadorGlobal->sizePolicy().hasHeightForWidth());
        comptadorGlobal->setSizePolicy(sizePolicy1);
        comptadorGlobal->setMinimumSize(QSize(15, 20));
        comptadorGlobal->setMaximumSize(QSize(16777215, 16777215));
        comptadorGlobal->setSizeIncrement(QSize(1, 1));
        comptadorGlobal->setBaseSize(QSize(1, 1));
        comptadorGlobal->setFont(font);
        comptadorGlobal->setLayoutDirection(Qt::LeftToRight);
        comptadorGlobal->setStyleSheet(QString::fromUtf8(""));
        comptadorGlobal->setFrameShape(QFrame::NoFrame);
        comptadorGlobal->setFrameShadow(QFrame::Plain);
        comptadorGlobal->setLineWidth(0);
        comptadorGlobal->setMidLineWidth(0);
        comptadorGlobal->setDigitCount(1);
        comptadorGlobal->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout->addWidget(comptadorGlobal);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_11);

        botoReiniciar = new QPushButton(MyForm);
        botoReiniciar->setObjectName(QString::fromUtf8("botoReiniciar"));
        botoReiniciar->setMinimumSize(QSize(82, 45));

        verticalLayout->addWidget(botoReiniciar, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_10);

        botoSortir = new QPushButton(MyForm);
        botoSortir->setObjectName(QString::fromUtf8("botoSortir"));
        botoSortir->setMinimumSize(QSize(82, 45));

        verticalLayout->addWidget(botoSortir, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_9);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_2);


        retranslateUi(MyForm);
        QObject::connect(botoAfegir, SIGNAL(clicked()), MyForm, SLOT(llencarBola()));
        QObject::connect(botoSortir, SIGNAL(clicked()), MyForm, SLOT(close()));
        QObject::connect(botoReiniciar, SIGNAL(clicked()), MyForm, SLOT(reiniciar()));
        QObject::connect(quantesBoles, SIGNAL(valueChanged(int)), MyForm, SLOT(afegirBoles()));
        QObject::connect(sliderComptador, SIGNAL(valueChanged(int)), MyForm, SLOT(canviSlider()));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Galton", nullptr));
#ifndef QT_NO_WHATSTHIS
        label10->setWhatsThis(QApplication::translate("MyForm", "<html><head/><body><p align=\"right\">-<br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label10->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">-</p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        label11->setWhatsThis(QApplication::translate("MyForm", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label11->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">-</p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        label00->setWhatsThis(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label00->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">-</p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        label30->setWhatsThis(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label30->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">-</p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        label31->setWhatsThis(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label31->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">-</p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        label32->setWhatsThis(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label32->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">-</p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        label33->setWhatsThis(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label33->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">-</p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        label20->setWhatsThis(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label20->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">-</p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        label21->setWhatsThis(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label21->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">-</p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        label22->setWhatsThis(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label22->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">-</p></body></html>", nullptr));
        labelPilota->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">O</p></body></html>", nullptr));
        labelPalanques->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">__ __</p></body></html>", nullptr));
        label_4->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">velocitat:</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("MyForm", "0", nullptr));
        label_3->setText(QApplication::translate("MyForm", "500", nullptr));
        label->setText(QApplication::translate("MyForm", "#boles: ", nullptr));
        botoAfegir->setText(QApplication::translate("MyForm", "Llen\303\247ar bola", nullptr));
        label_11->setText(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\">Total</p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        comptadorGlobal->setWhatsThis(QApplication::translate("MyForm", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        botoReiniciar->setText(QApplication::translate("MyForm", "Reiniciar", nullptr));
        botoSortir->setText(QApplication::translate("MyForm", "Sortir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H
