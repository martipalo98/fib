// (c) FIBerHub, https://fiberhub.tk

#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Model/model.h"

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();

  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    // resizeGL - És cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);
    // keyPressEvent - Es cridat quan es prem una tecla
    virtual void keyPressEvent (QKeyEvent *event);
    // mouse event
    virtual void mouseMoveEvent (QMouseEvent *event);

  private:
    void creaBuffers ();
    void carregaShaders ();
    void modelTransform ();
    void floorTransform ();
    void calculateAttributes(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax);
    void projectTransform(float FOV, float ra, float znear, float zfar);
    void viewTransform();
    void ini_camera();

    // attribute locations
    GLuint vertexLoc, colorLoc;
    // uniform locations
    GLuint transLoc, projLoc, viewLoc;
    // VAO i VBO names
    GLuint VAO_Patricio, VAO_Terra;
    // Program
    QOpenGLShaderProgram *program;
    // Viewport
    GLint ample, alt;
    // Internal vars
    float scale, rotate;
    glm::vec3 pos;

    glm::vec3 VRP;

    float FOV, ra, znear, zfar;
    bool ortho;

    float theta, psi, phi;
    float k, radi;

    // Interacció amb cursor
    int xClick, yClick;
    float deltaA;

    float FOV_offset;

    Model m;    //un únic model
};
