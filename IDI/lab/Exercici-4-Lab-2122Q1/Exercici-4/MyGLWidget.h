// MyGLWidget.h
#include "LL4GLWidget.h"

class MyGLWidget : public LL4GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : LL4GLWidget(parent) {}
    ~MyGLWidget();

  protected:
    virtual void keyPressEvent(QKeyEvent* event);
    // uniform locations
    GLuint llumVermellaLoc, llumVerdaLoc, llumBlavaLoc, llumNegraLoc, posicioMaLoc, rotacioLoc;
    

  private:
    int printOglError(const char file[], int line, const char func[]);
    void modelTransformPatricio();
    glm::mat4 calculaPatricioTG();
    glm::mat4 calculaMaPatricioTG();
    void carregaShadersColors ();
    void initializeGL();
    void iniEscena();

    glm::vec3 patricioMov;

    GLfloat rotacioPatricio;
    bool cPushed, ePushed, pPushed;
    glm::vec3 llumVerda, llumVermella, llumBlava, llumNegra, posicioMa;
    glm::mat4 posicioRotacio;
};
