#include "ExamGLWidget.h"

class MyGLWidget : public ExamGLWidget
{
 Q_OBJECT
	   
 public:
  MyGLWidget (QWidget *parent=NULL) : ExamGLWidget(parent) {}
  ~MyGLWidget ();

 public slots:

 signals:

 protected:
  virtual void paintGL ();
  virtual void iniCamera ();
  virtual void iniEscena ();
  virtual void viewTransform ();
  virtual void projectTransform ();
  virtual void modelTransformPatricio ();
  virtual void modelTransformPatricio2 ();
  
  virtual void mouseMoveEvent(QMouseEvent *e);
  virtual void keyPressEvent (QKeyEvent *event);
  
 private:
  int printOglError(const char file[], int line, const char func[]);
  float posPatX, posPatZ, fov;
  bool camera2;
  int zoomSliderAnterior;

 public slots:
    void canviarCamera();
    void ferZoom(int n);
};
