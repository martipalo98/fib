#include "ui_MyForm.h"

class MyForm : public QWidget
{
  Q_OBJECT

  public:
    MyForm(QWidget *parent=0);
  
  private:
    Ui::MyForm ui;
    int comptadorGlobal, temps;
    QList<QLabel*> labels;
    QList<QLCDNumber *>comptadors;

    void delay();
    void keyPressEvent(QKeyEvent *event);
    void actualitzaComptador();

  private slots:
    void llencarBola();
    void reiniciar();
    void afegirBoles();
};
