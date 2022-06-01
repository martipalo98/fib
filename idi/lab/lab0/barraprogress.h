/********************************************************************************
** Form generated from reading UI file 'barraprogress.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BARRAPROGRESS_H
#define UI_BARRAPROGRESS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLayout>
#include <QtGui/QProgressBar>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Progress
{
public:
    QWidget *page;
    QProgressBar *progressBar;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QWidget *page1;

    void setupUi(QToolBox *Progress)
    {
        if (Progress->objectName().isEmpty())
            Progress->setObjectName(QString::fromUtf8("Progress"));
        Progress->resize(904, 538);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 904, 476));
        progressBar = new QProgressBar(page);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(110, 0, 469, 25));
        progressBar->setValue(24);
        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(220, 60, 471, 291));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        verticalLayout->addWidget(spinBox);

        Progress->addItem(page, QString::fromUtf8("Page 1"));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        page1->setGeometry(QRect(0, 0, 904, 476));
        Progress->addItem(page1, QString::fromUtf8("Page 2"));
        QWidget::setTabOrder(spinBox, horizontalSlider);

        retranslateUi(Progress);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));
        Q4Object::connect(spinBox, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));

        Progress->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Progress);
    } // setupUi

    void retranslateUi(QToolBox *Progress)
    {
        Progress->setWindowTitle(QApplication::translate("Progress", "ToolBox", 0, QApplication::UnicodeUTF8));
        Progress->setItemText(Progress->indexOf(page), QApplication::translate("Progress", "Page 1", 0, QApplication::UnicodeUTF8));
        Progress->setItemText(Progress->indexOf(page1), QApplication::translate("Progress", "Page 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Progress: public Ui_Progress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BARRAPROGRESS_H
