// MyGLWidget.cpp
#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() print  OglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

int MyGLWidget::printOglError(const char file[], int line, const char func[]) 
{
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr)
    {
        case 0x0500:
            error = "GL_INVALID_ENUM";
            break;
        case 0x501:
            error = "GL_INVALID_VALUE";
            break;
        case 0x502: 
            error = "GL_INVALID_OPERATION";
            break;
        case 0x503:
            error = "GL_STACK_OVERFLOW";
            break;
        case 0x504:
            error = "GL_STACK_UNDERFLOW";
            break;
        case 0x505:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "unknown error!";
    }
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s function: %s\n",
                             file, line, error, func);
        retCode = 1;
    }
    return retCode;
}

MyGLWidget::~MyGLWidget() {
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {

  case Qt::Key_Right:
    if(patricioMov.x <= radiEsc)
      patricioMov.x += 1;
    break;

  case Qt::Key_Left:
    if(patricioMov.x > 1)
      patricioMov.x -= 1;
    break;

  case Qt::Key_Up:
    if(patricioMov.z > 1)
      patricioMov.z -= 1;
    break;

  case Qt::Key_Down:
    if(patricioMov.z <= radiEsc)
      patricioMov.z += 1;
    break;

  case Qt::Key_R:
    rotacioPatricio += 45.;
    break;

  case Qt::Key_C:
      //...
    break;

  case Qt::Key_E:
      //...
    break;

  case Qt::Key_P:
      //...
    break;

  default: LL4GLWidget::keyPressEvent(event); break;
  }
  update();
}

void MyGLWidget::iniEscena ()
{
  centreEsc = glm::vec3(5,3,5);
  radiEsc = 8;
  patricioMov = glm::vec3(5, 0, 2);
  rotacioPatricio = 0.;
}


glm::mat4 MyGLWidget::calculaPatricioTG()
{
  glm::mat4 tg = glm::translate(glm::mat4(1.f), patricioMov);
  tg = glm::scale(tg, glm::vec3(escala, escala, escala));
  tg = glm::rotate(tg, glm::radians(rotacioPatricio) ,glm::vec3(0, 1, 0));
  tg = glm::translate(tg, -centreBasePatr);
  return tg;
}

void MyGLWidget::modelTransformPatricio ()
{
  patricioTG = calculaPatricioTG();  // Matriu de transformació
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &patricioTG[0][0]);
}

