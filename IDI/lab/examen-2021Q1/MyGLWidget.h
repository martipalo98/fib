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
    virtual void canviaCamera();

  private:
    float posicioPatricio = 0.;
    bool mostraPatricio = false;
    bool llumBlanca = true;
    float angleTecles = 0.;
    int printOglError(const char file[], int line, const char func[]);

  public slots:
    void rota();


};
