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

MyGLWidget::~MyGLWidget ()
{}

void MyGLWidget::paintGL() {
  //ExamGLWidget::paintGL();
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //--------------------------------------------------------
  // Activem el VAO per a pintar el terra
  glBindVertexArray (VAO_Terra);  
  // pintem terra
  modelTransformTerra ();
  glDrawArrays(GL_TRIANGLES, 0, 12);

  //--------------------------------------------------------
  // Activem el VAO per a pintar el Patricio
  glBindVertexArray (VAO_Pat);
  // pintem el Patricio
  modelTransformPatricio();
  glDrawArrays(GL_TRIANGLES, 0, patModel.faces().size()*3);

  glBindVertexArray (VAO_Pat);
  // pintem el Patricio
  modelTransformPatricio2();
  glDrawArrays(GL_TRIANGLES, 0, patModel.faces().size()*3);

  //--------------------------------------------------------
  glBindVertexArray(0);
}

void MyGLWidget::iniCamera ()
{
  //ExamGLWidget::iniCamera();
  rav = 1.0;
  angleY = 0.0;
  angleX = M_PI/6.0;
  camera2 = false;

    fov = float(M_PI/3.0);

  projectTransform ();
  viewTransform ();

}

void MyGLWidget::iniEscena ()
{
  //ExamGLWidget::iniEscena();
  creaBuffersPatricio();
  creaBuffersTerra();
  posPatX = 4.f;
  posPatZ = 6.f;
  centreEsc = glm::vec3 (4, 2, 4);
  radiEsc = distance(glm::vec3(0,0,0), glm::vec3(8,4,8))/2.f;

  zoomSliderAnterior = 50;
}

void MyGLWidget::modelTransformPatricio ()
{
  //ExamGLWidget::modelTransformPatricio();
  TG = glm::mat4(1.0f);
  TG = glm::translate(TG, glm::vec3(2,0,1));
  TG = glm::scale(TG, glm::vec3(2*escalaPat, 2*escalaPat, 2*escalaPat));
  TG = glm::rotate(TG, float(M_PI/2), glm::vec3(0,1,0));
  TG = glm::translate(TG, -centreBasePat);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformPatricio2 ()
{
  //ExamGLWidget::modelTransformPatricio();
  TG = glm::mat4(1.0f);
  TG = glm::translate(TG, glm::vec3(posPatX,0,posPatZ));
  TG = glm::scale(TG, glm::vec3(3*escalaPat, 3*escalaPat, 3*escalaPat));
  TG = glm::rotate(TG, float(M_PI), glm::vec3(0,1,0));
  TG = glm::translate(TG, -centreBasePat);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::viewTransform() {
  //ExamGLWidget::viewTransform();
  if(camera2) {
    //View = glm::translate(glm::mat4(1.f), glm::vec3(-posPatX, -3.5, -posPatZ));
    //View = glm::translate(View, -centreEsc);
    glm::vec3 obs, vrp, up;
    obs = glm::vec3(posPatX, 3.5, posPatZ);
    vrp = glm::vec3(posPatX, 3.5, 0);
    up = glm::vec3(0, 1, 0);
    View = glm::lookAt(obs, vrp, up);
  }else {
    View = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -2*radiEsc));
    View = glm::rotate(View,  angleX, glm::vec3(1, 0, 0));
    View = glm::rotate(View, -angleY, glm::vec3(0, 1, 0));
    View = glm::translate(View, -centreEsc);
  }
  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::projectTransform() {
  // ExamGLWidget::projectTransform();
  float  zn, zf;
  glm::mat4 Proj;  // Matriu de projecció
  if(camera2) {
    fov = float(M_PI/2.0);
    zn = 0.1;
    zf = 2*radiEsc + radiEsc;
  }else{
    zn = 2*radiEsc - radiEsc;
    zf = 2*radiEsc + radiEsc;
  }

  Proj = glm::perspective(fov, rav, zn, zf);
  glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::keyPressEvent(QKeyEvent* event)
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: {
      if(posPatZ < 7.5) posPatZ += 0.5;
      viewTransform();
      projectTransform();
      break;
    }
    case Qt::Key_W: {
      if(posPatZ > 0.5) posPatZ -= 0.5;
      viewTransform();
      projectTransform();
      break;
    }
    case Qt::Key_A: {
      if(posPatX > 0.5) posPatX -= 0.5;
      viewTransform();
      projectTransform();
      break;
    }
    case Qt::Key_D: {
      if(posPatX < 7.5) posPatX += 0.5;
      viewTransform();
      projectTransform();
      break;
    }
    case Qt::Key_C: {
      canviarCamera();
      break;
    }
    default: {
      ExamGLWidget::keyPressEvent(event);
      break;
    }
  }
  update();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
{
  makeCurrent();
  // Aqui cal que es calculi i s'apliqui la rotacio o el zoom com s'escaigui...
  if (DoingInteractive == ROTATE)
  {
    // Fem la rotació
    angleY += (e->x() - xClick) * M_PI / ample;
    viewTransform ();
  }

  xClick = e->x();
  yClick = e->y();

  update ();
}

  
void MyGLWidget::canviarCamera() {
  makeCurrent();
  camera2 = !camera2;
  viewTransform();
  projectTransform();
  update();
}

void MyGLWidget::ferZoom(int n) {
  makeCurrent();
  if(zoomSliderAnterior > n) {
    if(fov < 5) fov += n*0.001;
    zoomSliderAnterior = n;
  }else if(zoomSliderAnterior > n){
    if(fov > 0) fov -= n*0.001;
    zoomSliderAnterior = n;
  }
  projectTransform();
  update();
}