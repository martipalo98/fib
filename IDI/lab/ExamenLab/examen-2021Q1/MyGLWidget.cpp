// MyGLWidget.cpp
#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
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

void MyGLWidget::paintGL ()   // Mètode que has de modificar
{
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Pintem el terra
  glBindVertexArray (VAO_Terra);
  modelTransformTerra ();
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  // Pintem el Patricio
  glBindVertexArray (VAO_Patr);
  modelTransformPatricio ();
  glDrawArrays(GL_TRIANGLES, 0, patr.faces().size()*3);

  // Pintem el cub
  if(!mostraPat) {
    glBindVertexArray(VAO_Cub);
    modelTransformCub (2.0, 0.0);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    
    glBindVertexArray(VAO_Cub);
    modelTransformCub (2.5, 2*M_PI/3);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    
    glBindVertexArray(VAO_Cub);
    modelTransformCub (3.0, 4*M_PI/3);
    glDrawArrays(GL_TRIANGLES, 0, 36);
  }
  
  
  glBindVertexArray(0);
}

void MyGLWidget::modelTransformCub (float escala, float angle) 
{
  //ExamGLWidget::modelTransformCub (1.0, 0.0);
  // En aquest mètode has de substituir aquest codi per construir la 
  // transformació geomètrica (TG) del cub usant els paràmetres adientment
  TG = glm::mat4(1.f);
  TG = glm::rotate(TG, angle+angleTecles, glm::vec3(0, 1, 0));
  TG = glm::translate(TG, glm::vec3(5, 0, 0));
  TG = glm::scale(TG, glm::vec3(2*escala, 2*escala, 2*escala));
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformPatricio ()    // Mètode que has de modificar
{
  TG = glm::mat4(1.f);
  TG = glm::rotate(TG, float(posPat*M_PI/3) + angleTecles, glm::vec3(0, 1, 0));
  TG = glm::translate(TG, glm::vec3(5, 0, 0));
  TG = glm::rotate(TG, float(-M_PI/2), glm::vec3(0, 1, 0));
  TG = glm::scale(TG, glm::vec3 (2*escala, 2*escala, 2*escala));
  TG = glm::translate(TG, -centreBasePat);
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::viewTransform ()    // Mètode que has de modificar
{
  if (!camPlanta)
    ExamGLWidget::viewTransform();
  else
  {
    glm::vec3 obs = glm::vec3(centreEsc[0], 2*radiEsc, centreEsc[2]);
    glm::vec3 vrp = centreEsc;
    glm::vec3 up = glm::vec3(1., 0., 0.);
    View = glm::lookAt(obs, vrp, up);
    glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
  }
}

void MyGLWidget::projectTransform ()
{
  if (!camPlanta)
    ExamGLWidget::projectTransform();
  else
  {
    glm::mat4 Proj;  // Matriu de projecció
    float l,r,b,t;
    l = -radiEsc;
    r = radiEsc;
    b = -radiEsc;
    t = radiEsc;
    Proj = glm::ortho(l, r, b, t, zn, zf);

    glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);
  }
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {
  case Qt::Key_V: {
    mostraPat = !mostraPat;
    break;
	}
  case Qt::Key_1: {
    posPat1();
    break;
	}
  case Qt::Key_2: {
    posPat2();
    break;
	}
  case Qt::Key_3: {
    posPat3();
    break;
	}
  case Qt::Key_F: {
    llumBlanca = !llumBlanca;
    if(llumBlanca) colFoc = glm::vec3(1,1,1);
    else colFoc = glm::vec3(1,1,0);
    enviaColFocus();
    break;
	}
  case Qt::Key_C: {
    canviaCamera();
    break;
	}
  case Qt::Key_Right: {
    angleTecles += 2*M_PI/3;
    break;
	}
  case Qt::Key_Left: {
    angleTecles -= 2*M_PI/3;
    break;
	}
  case Qt::Key_R: {
    angleY = 0.65;
    angleX = -1.2;
    mostraPat = false;
    posPat = 0;
    llumBlanca = true;
    angleTecles = 0.;
    colFoc = glm::vec3(1,1,1);
    enviaColFocus();
    viewTransform();
    break;
	}
  default: ExamGLWidget::keyPressEvent(event); break;
  }
  update();
}

void MyGLWidget::posPat1() {
  posPat = 0;
}

void MyGLWidget::posPat2() {
  posPat = 2;
  
}

void MyGLWidget::posPat3() {
  posPat = 4;
  
}

void MyGLWidget::canviaCamera() {
  camPlanta = !camPlanta;
  viewTransform();
  projectTransform();
  update();
}

void MyGLWidget::mocPatricio() {
  if(posPat == 0) posPat = 2;
  else if(posPat == 2) posPat = 4;
  else posPat = 0;
  update();
}