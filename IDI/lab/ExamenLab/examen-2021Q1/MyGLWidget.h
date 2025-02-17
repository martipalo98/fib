#include "ExamGLWidget.h"

class MyGLWidget:public ExamGLWidget
{
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : ExamGLWidget(parent) {}
    ~MyGLWidget();

  protected:
    virtual void paintGL ();
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void modelTransformCub (float escala, float angle);
    virtual void modelTransformPatricio ();
    virtual void projectTransform ();
    virtual void viewTransform ();
    

  private:
    int printOglError(const char file[], int line, const char func[]);
    int mostraPat = false;
    int posPat = 0;
    bool llumBlanca = true;
    float angleTecles = 0.;
    void posPat1();
    void posPat2();
    void posPat3();

  private slots:
    void mocPatricio();
    void canviaCamera();

};
