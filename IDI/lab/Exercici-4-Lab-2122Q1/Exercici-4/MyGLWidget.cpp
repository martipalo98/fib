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
    if(patricioMov.x <= radiEsc){
      patricioMov.x += 1;
      posicioMa.x   += 1;
      posicioRotacio = calculaMaPatricioTG();
      glUniformMatrix4fv(posicioMaLoc, 1, GL_FALSE, &posicioRotacio[0][0]);
      }
    break;

  case Qt::Key_Left:
    if(patricioMov.x > 1){
      patricioMov.x -= 1;
      posicioMa.x   -= 1;
      posicioRotacio = calculaMaPatricioTG();
      glUniformMatrix4fv(posicioMaLoc, 1, GL_FALSE, &posicioRotacio[0][0]);
  }
    break;

  case Qt::Key_Up:
    if(patricioMov.z > 1){
      patricioMov.z -= 1;
      posicioMa.z   -= 1;
      posicioRotacio = calculaMaPatricioTG();
      glUniformMatrix4fv(posicioMaLoc, 1, GL_FALSE, &posicioRotacio[0][0]);
    }
    break;

  case Qt::Key_Down:
    if(patricioMov.z <= radiEsc){
      patricioMov.z += 1;
      posicioMa.z   += 1;
      posicioRotacio = calculaMaPatricioTG();
      glUniformMatrix4fv(posicioMaLoc, 1, GL_FALSE, &posicioRotacio[0][0]);
    }
    break;

  case Qt::Key_R:
    rotacioPatricio += 45.;

      posicioRotacio = calculaMaPatricioTG();
      glUniformMatrix4fv(posicioMaLoc, 1, GL_FALSE, &posicioRotacio[0][0]);
    break;

  case Qt::Key_C:
    if(cPushed) {
      glUniform3fv(llumVermellaLoc, 1, &llumNegra[0]);
      cPushed = false;
    }else {
      glUniform3fv(llumVermellaLoc, 1, &llumVermella[0]);
      cPushed = true;
    }
    break;

  case Qt::Key_E:
    if(ePushed) {
      glUniform3fv(llumVerdaLoc, 1, &llumNegra[0]);
      ePushed = false;
    }else {
      glUniform3fv(llumVerdaLoc, 1, &llumVerda[0]);
      ePushed = true;
    }
    break;

  case Qt::Key_P:
    if(pPushed) {
      glUniform3fv(llumBlavaLoc, 1, &llumNegra[0]);
      pPushed = false;
    }else {
      glUniform3fv(llumBlavaLoc, 1, &llumBlava[0]);
      pPushed = true;
    }
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
  cPushed = ePushed = pPushed = true;
}


glm::mat4 MyGLWidget::calculaPatricioTG()
{
  glm::mat4 tg = glm::translate(glm::mat4(1.f), patricioMov);
  tg = glm::scale(tg, glm::vec3(escala, escala, escala));
  tg = glm::rotate(tg, glm::radians(rotacioPatricio) ,glm::vec3(0, 1, 0));
  tg = glm::translate(tg, -centreBasePatr);
  return tg;
}

glm::mat4 MyGLWidget::calculaMaPatricioTG()
{
  glm::mat4 tg = glm::translate(glm::mat4(1.f), patricioMov);
  tg = glm::rotate(tg, glm::radians(rotacioPatricio) ,glm::vec3(0, 1, 0));
  tg = glm::translate(tg, glm::vec3(-dimCapsaPatr[0]/4,dimCapsaPatr[0]/4,0.));
  return tg;
}

void MyGLWidget::modelTransformPatricio ()
{
  patricioTG = calculaPatricioTG();  // Matriu de transformació
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &patricioTG[0][0]);
}

void MyGLWidget::carregaShadersColors () {
  llumVermella  = glm::vec3(0.9, 0.2, 0.2);
  llumVerda     = glm::vec3(0.2, 0.9, 0.2);
  llumBlava     = glm::vec3(0.2, 0.2, 0.9);
  llumNegra     = glm::vec3(0., 0., 0.);
  posicioRotacio = calculaMaPatricioTG();

  llumVerdaLoc = glGetUniformLocation (program->programId(), "green");
  llumVermellaLoc = glGetUniformLocation (program->programId(), "red");
  llumBlavaLoc = glGetUniformLocation (program->programId(), "blue");
  llumNegraLoc = glGetUniformLocation (program->programId(), "black");
  posicioMaLoc = glGetUniformLocation (program->programId(), "posicioMa");
  rotacioLoc = glGetUniformLocation (program->programId(), "rotacio");


  glUniform3fv(llumVermellaLoc, 1, &llumVermella[0]);
  glUniform3fv(llumVerdaLoc, 1,&llumVerda[0]);
  glUniform3fv(llumBlavaLoc, 1, &llumBlava[0]);
  glUniform3fv(llumNegraLoc, 1, &llumNegra[0]);
  glUniformMatrix4fv(posicioMaLoc, 1, GL_FALSE, &posicioRotacio[0][0]);
  glUniform1f(rotacioLoc, rotacioPatricio);
}

void MyGLWidget::initializeGL ()
{
  initializeOpenGLFunctions();  
  glClearColor(0.5, 0.7, 1.0, 1.0);
  glEnable(GL_DEPTH_TEST);
  carregaShaders();
  creaBuffersPatricio();
  creaBuffersTerraIParet();

  iniEscena();
  iniCamera();
  carregaShadersColors();           // afegida
}

