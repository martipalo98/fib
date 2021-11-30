// (c) FIBerHub, https://fiberhub.tk

#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent), program(NULL)
{
  setFocusPolicy(Qt::StrongFocus);  // per rebre events de teclat
  scale = 0.0f;
  rotate = 0.0f;
  ortho = false;

  theta = 0.0;
  psi = 0.0;
  phi = 0.0;

  xClick = 0;
  yClick = 0;
  deltaA = M_PI / 180.0;

  FOV_offset = 0;
}

MyGLWidget::~MyGLWidget ()
{
  if (program != NULL)
    delete program;
}

void MyGLWidget::initializeGL ()
{
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);

  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  carregaShaders();

  m.load("./models/Patricio.obj");
  creaBuffers();

  ini_camera();
}

void MyGLWidget::paintGL ()
{
// Aquest codi és necessari únicament per a MACs amb pantalla retina.
#ifdef __APPLE__
  GLint vp[4];
  glGetIntegerv (GL_VIEWPORT, vp);
  ample = vp[2];
  alt = vp[3];
#endif

// En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
// useu els paràmetres que considereu (els que hi ha són els de per defecte)
//  glViewport (0, 0, ample, alt);

  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Carreguem la transformació de model
  modelTransform ();

  // Activem el VAO per a pintar la caseta
  glBindVertexArray (VAO_Patricio);

  // pintem
  glDrawArrays(GL_TRIANGLES, 0, m.faces().size()*3);

  glBindVertexArray (0);

  // Carreguem la transformació de model
  floorTransform();

  // Activem el VAO per a pintar la caseta
  glBindVertexArray (VAO_Terra);

  // pintem
  glDrawArrays(GL_TRIANGLES, 0, 6);

  glBindVertexArray (0);
}

void MyGLWidget::modelTransform ()
{
  float xmin, ymin, zmin, xmax, ymax, zmax;

  xmin = xmax = m.vertices()[0];
  ymin = ymax = m.vertices()[0+1];
  zmin = zmax = m.vertices()[0+2];

  for(unsigned int i = 3; i < m.vertices().size(); i += 3){
    if (m.vertices()[i] > xmax) xmax = m.vertices()[i];
    if (m.vertices()[i] < xmin) xmin = m.vertices()[i];
    if (m.vertices()[i+1] > ymax) ymax = m.vertices()[i+1];
    if (m.vertices()[i+1] < ymin) ymin = m.vertices()[i+1];
    if (m.vertices()[i+2] > zmax) zmax = m.vertices()[i+2];
    if (m.vertices()[i+2] < zmin) zmin = m.vertices()[i+2];
  }

  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::scale(transform, glm::vec3(4/(xmax-xmin))+scale);
  transform = glm::rotate(transform, rotate, glm::vec3(0.0, 1.0, 0.0));
  transform = glm::translate(transform, -glm::vec3((xmax+xmin)/2.0,ymin, (zmax+zmin)/2.0));
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::floorTransform ()
{
  glm::mat4 transform (1.0f);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::calculateAttributes(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax)
{
    radi = sqrt((xmax-xmin)*(xmax-xmin)+(ymax-ymin)*(ymax-ymin)+(zmax-zmin)*(zmax-zmin))/2.0;
    k = 2;

    VRP = glm::vec3((xmax+xmin)/2.0,(ymax+ymin)/2.0,(zmax+zmin)/2.0);  //Centre de l'escena

    FOV = 2.0*asin(radi/(radi*k));
    ra = 1.0f;
    znear = radi*k-radi;
    zfar = radi*k+radi;
}

void MyGLWidget::projectTransform(float FOV, float ra, float znear, float zfar)
{
  glm::mat4 proj = glm::perspective(FOV+FOV_offset, ra, znear, zfar);
  if (ortho) proj = glm::ortho (-2.5f*(1+FOV_offset), 2.5f*(1+FOV_offset), 0.0f*(1+FOV_offset), 4.0f*(1+FOV_offset), znear, zfar);
  glUniformMatrix4fv(projLoc, 1, GL_FALSE, &proj[0][0]);
}

void MyGLWidget::viewTransform()
{
  glm::mat4 View(1.0f);
  View = glm::translate(View, -glm::vec3(0.0, 0.0, k*radi));

  View = glm::rotate(View, -phi, glm::vec3(0.0, 0.0, 1.0)); // no sempre s'usa
  View = glm::rotate(View, theta, glm::vec3(1.0, 0.0, 0.0));
  View = glm::rotate(View, -psi, glm::vec3(0.0, 1.0, 0.0));

  // trasllada el vrp a l'origen
  View = glm::translate(View, -VRP);
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::ini_camera()
{
  calculateAttributes(-2.5f, 2.5f, 0.0f, 4.0f, -2.5f, 2.5f);
  projectTransform(FOV, ra, znear, zfar);
  viewTransform();
}

void MyGLWidget::resizeGL (int w, int h)
{
  glViewport(0, 0, w, h);
  ra = float(w)/float(h);
  projectTransform(float(2.0 * atan(tan(FOV/2.0)/ra)), ra, znear, zfar);
}

void MyGLWidget::keyPressEvent(QKeyEvent* event)
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: { // escalar a més gran
      scale += 0.05;
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      scale -= 0.05;
      break;
    }
    case Qt::Key_R: { // escalar a més petit
      rotate += (float)M_PI/4;
      break;
    }
    case Qt::Key_O: {
        ortho = !ortho;
        projectTransform(FOV, ra, znear, zfar);
        break;
    }
    case Qt::Key_Z: { // escalar a més petit
      FOV_offset -= 0.05;
      projectTransform(FOV, ra, znear, zfar);
      break;
    }
    case Qt::Key_X: { // escalar a més petit
      FOV_offset += 0.05;
      projectTransform(FOV, ra, znear, zfar);
      break;
    }
    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
{
  makeCurrent();
  int dx = abs(e->x() - xClick);
  int dy = abs(e->y() - yClick);

  if (dx > dy) {
    if (e->x() > xClick) psi  = psi - abs(e->x() - xClick) * deltaA;
    else if (e->x() < xClick)psi  = psi + abs(e->x() - xClick) * deltaA;
  } else {
    if (e->y() > yClick) theta = theta + abs(e->y() - yClick) * deltaA;
    else if (e->y() < yClick) theta = theta - abs(e->y() - yClick) * deltaA;
  }
  viewTransform();
  update();

  xClick = e->x();
  yClick = e->y();
}

void MyGLWidget::creaBuffers ()
{
  // Dades de la caseta

  // Creació del Vertex Array Object per pintar
  glGenVertexArrays(1, &VAO_Patricio);
  glBindVertexArray(VAO_Patricio);

  GLuint VBO_Patricio[2];
  glGenBuffers(2, VBO_Patricio);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Patricio[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m.faces().size()*3*3, m.VBO_vertices(), GL_STATIC_DRAW);
  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glBindBuffer(GL_ARRAY_BUFFER, VBO_Patricio[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m.faces().size()*3*3, m.VBO_matdiff(), GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  glBindVertexArray (0);


  // Dades de la caseta
  // Dos VBOs, un amb posició i l'altre amb color
  glm::vec3 posicio[6] = {
    glm::vec3(-2.5, 0.0, -2.5),
    glm::vec3( 2.5, 0.0, -2.5),
    glm::vec3(-2.5, 0.0, 2.5),
    glm::vec3(-2.5, 0.0, 2.5),
    glm::vec3( 2.5, 0.0, 2.5),
    glm::vec3( 2.5, 0.0, -2.5)
  };
  glm::vec3 color[6] = {
    glm::vec3(1,0,1),
    glm::vec3(1,0,1),
    glm::vec3(1,0,1),
    glm::vec3(1,0,1),
    glm::vec3(1,0,1),
    glm::vec3(1,0,1)
  };

  // Creació del Vertex Array Object per pintar
  glGenVertexArrays(1, &VAO_Terra);
  glBindVertexArray(VAO_Terra);

  GLuint VBO_Terra[2];
  glGenBuffers(2, VBO_Terra);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Terra[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(posicio), posicio, GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glBindBuffer(GL_ARRAY_BUFFER, VBO_Terra[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  glBindVertexArray (0);
}

void MyGLWidget::carregaShaders()
{
  // Creem els shaders per al fragment shader i el vertex shader
  QOpenGLShader fs (QOpenGLShader::Fragment, this);
  QOpenGLShader vs (QOpenGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem
  fs.compileSourceFile("shaders/basicShader.frag");
  vs.compileSourceFile("shaders/basicShader.vert");
  // Creem el program
  program = new QOpenGLShaderProgram(this);
  // Li afegim els shaders corresponents
  program->addShader(&fs);
  program->addShader(&vs);
  // Linkem el program
  program->link();
  // Indiquem que aquest és el program que volem usar
  program->bind();

  // Obtenim identificador per a l'atribut “vertex” del vertex shader
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
  // Obtenim identificador per a l'atribut “color” del vertex shader
  colorLoc = glGetAttribLocation (program->programId(), "color");
  // Uniform locations
  transLoc = glGetUniformLocation(program->programId(), "TG");
  projLoc = glGetUniformLocation(program->programId(), "proj");
  viewLoc = glGetUniformLocation(program->programId(), "view");
}
