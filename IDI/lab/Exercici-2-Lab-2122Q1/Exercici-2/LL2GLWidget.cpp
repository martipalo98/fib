#include "LL2GLWidget.h"
#include <glm/gtx/string_cast.hpp>

#include <iostream>
#include <string>

LL2GLWidget::LL2GLWidget (QWidget* parent) : QOpenGLWidget(parent), program(NULL)
{
  setFocusPolicy(Qt::StrongFocus);  // per rebre events de teclat
}

LL2GLWidget::~LL2GLWidget ()
{
  if (program != NULL)
    delete program;
}

int centreTerra() {
  return 0;
}

void LL2GLWidget::initializeGL ()
{
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();  
  glEnable(GL_DEPTH_TEST); 
  
  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  carregaShaders();
  creaBuffersHomer();
  creaBuffersTerra();
  iniEscena();
  iniCamera();
}

void LL2GLWidget::iniEscena()
{
  midaTerra = 10.0;
  midaModelHomer = 1.83;
  rotacioHomer = 0;//-numHomer*M_PI/10;
  Theta = float(M_PI/4.0);
  Psi = float(M_PI);
  maxHomers = 10;
  radiRotllana = 4.0;
  girBallHomer = 0.0;
  ortogonal = false;
}

void LL2GLWidget::iniCamera(){

  //obs = glm::vec3(0, 6, 6);
  //vrp = glm::vec3(0, 0, 0.5);
  /*obs = glm::vec3(5, 10, 10); 
  vrp = glm::vec3(5, 0, 5);
  up = glm::vec3(0, 1, 0);
  fov = float(M_PI)/4.0f;
  ra  = 1.0;
  znear =  0.001;
  zfar  = 15;*/
/*
  d = R * 2.0;
  Znear = d - R;
  Zfar = d + R;
  
  FOV = 2.0 * asin(R/d);
  
  raw = 1.0;
  tz = -d;
  
  Theta = float(M_PI/9.0);
  Psi = float(M_PI/4.0);*/

  

  //projectTransform(fov, ra, znear, zfar);
  projectTransform();
  viewTransform();
  //projectTransform();
}

void LL2GLWidget::paintGL ()
{
  // descomentar per canviar paràmetres
  // glViewport (0, 0, ample, alt);
  // Homer
  for (numHomer = 0; numHomer < maxHomers; ++numHomer) {
    homerTransform();
    glBindVertexArray (VAO_Homer);
    glDrawArrays(GL_TRIANGLES, 0, modelHomer.faces().size()*3);
    glBindVertexArray (0);
    rotacioHomer = numHomer*M_PI*2/maxHomers;
  }

  // Terra
  terraTransform();
  glBindVertexArray (VAO_Terra);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindVertexArray (0);
}

void LL2GLWidget::homerTransform ()
{
  // Matriu de transformació de Homer
  glm::mat4 TG(1.0f);
  
  //TG = glm::translate(TG, glm::vec3(0.0,-baseHomer.y,0.0));
  //TG = glm::scale(TG, glm::vec3(1.85/2, 1.85/2, 1.85/2));
  //TG = glm::scale(TG, glm::vec3(midaModelHomer));
  //std::cout<<glm::to_string(TG)<<std::endl;
  //TEST ROTACIO
  //TG = glm::rotate(TG, 45.0f, glm::vec3(0.0, 1.0, 0.0));
  
  //TG = glm::rotate(TG, rotacioHomer, glm::vec3(0,1,0));
  //TG = glm::translate(TG, glm::vec3(midaTerra/4, 1, midaTerra/4));
  //TG = glm::translate(TG, baseHomer);
  //TG = glm::translate(TG, glm::vec3(0, 0, glm::sqrt(midaTerra)));
  TG = glm::translate(TG, centreEscena);//glm::translate(TG, glm::vec3 (5.0, 0, 5.0));
  TG = glm::rotate(TG, rotacioHomer, glm::vec3 (0., 1., 0.));
  TG = glm::translate(TG, -baseHomer);
  TG = glm::translate(TG, glm::vec3(0.0,0.0,-radiRotllana));
  TG = glm::rotate(TG, -girBallHomer, glm::vec3(0., 1., 0.));
  //std::cout << glm::to_string(TG) << std::endl;
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void LL2GLWidget::terraTransform ()
{
  // Matriu de transformació de l'escac
  glm::mat4 TG(1.0f);
  TG = glm::scale(TG, glm::vec3(midaTerra, 1.0, midaTerra));
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void LL2GLWidget::projectTransform ()
{
  glm::mat4 Proj(1.0f);
  Proj = glm::perspective (fov, ra, znear, zfar);
  glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void LL2GLWidget::viewTransform ()
{
  glm::mat4 View(1.0f);
  if(ortogonal)
  {
    View = glm::lookAt(obs, vrp, up);
  }
  else
  {
    View = glm::translate(View, -glm::vec3(0.0, 0.0, 2*radiEscena));
    View = glm::rotate(View, Theta, glm::vec3(1.0, 0.0, 0.0));
    View = glm::rotate(View, -Psi, glm::vec3(0.0, 1.0, 0.0));
    View = glm::translate(View, -vrp);                                  // movem el vrp a l'origen de coordenades
  }
  
  //std::cout << glm::to_string(View) << std::endl;
  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void LL2GLWidget::resizeGL (int w, int h) 
{
// Aquest codi és necessari únicament per a MACs amb pantalla retina.
#ifdef __APPLE__
  GLint vp[4];
  glGetIntegerv (GL_VIEWPORT, vp);
  ample = vp[2];
  alt = vp[3];
#else
  ample = w;
  alt = h;
#endif
  glViewport(0,0,ample, alt);     //nou
  ra = float(ample)/float(alt);
  factorAngleY = M_PI / ample;
  factorAngleX = M_PI / alt;
  projectTransform();
  //projectTransform(float(2.0 * atan(tan(fov/2.0)/ra)), ra, znear, zfar); //nou
}

void LL2GLWidget::creaBuffersTerra ()
{
  // Pla quadrat pel terra
  glm::vec3 geomTerra[6] = {
      glm::vec3(0.0, 0.0, 0.0),
      glm::vec3(1.0, 0.0, 0.0),
      glm::vec3(1.0, 0.0, 1.0),
      glm::vec3(0.0, 0.0, 0.0),
      glm::vec3(1.0, 0.0, 1.0),
      glm::vec3(0.0, 0.0, 1.0)
  };

  glm::vec3 c(0.8, 0.8, 0.8);
  glm::vec3 colTerra[6] = { c, c, c, c, c, c };

  // VAO
  glGenVertexArrays(1, &VAO_Terra);
  glBindVertexArray(VAO_Terra);

  GLuint VBO_Terra[2];
  glGenBuffers(2, VBO_Terra);

  // geometria
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Terra[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(geomTerra), geomTerra, GL_STATIC_DRAW);
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  // color
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Terra[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(colTerra), colTerra, GL_STATIC_DRAW);
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);
  
  glBindVertexArray (0);
}

void LL2GLWidget::creaBuffersHomer ()
{
  // Càrrega del model
  modelHomer.load("./models/HomerProves.obj");

  // Calculem la capsa contenidora del model
  calculaCapsaModel ();
  calculaCapsaEscena ();

  // Creació de VAOs i VBOs per pintar
  // Homer
  glGenVertexArrays(1, &VAO_Homer);
  glBindVertexArray(VAO_Homer);

  GLuint VBO_Homer[2];
  glGenBuffers(2, VBO_Homer);

  // geometria
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Homer[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*modelHomer.faces().size()*3*3,
           modelHomer.VBO_vertices(), GL_STATIC_DRAW);
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  // color
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Homer[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*modelHomer.faces().size()*3*3,
           modelHomer.VBO_matdiff(), GL_STATIC_DRAW);
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);
  
  glBindVertexArray (0);
}

void LL2GLWidget::carregaShaders()
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

  // Identificador per als  atributs
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
  colorLoc = glGetAttribLocation (program->programId(), "color");

  // Identificadors dels uniform locations
  transLoc = glGetUniformLocation(program->programId(), "TG");
  projLoc  = glGetUniformLocation (program->programId(), "Proj");
  viewLoc  = glGetUniformLocation (program->programId(), "View");
}

void LL2GLWidget::calculaCapsaModel ()
{
  // Càlcul capsa contenidora i valors transformacions inicials
  float minx, miny, minz, maxx, maxy, maxz;
  minx = maxx = modelHomer.vertices()[0];
  miny = maxy = modelHomer.vertices()[1];
  minz = maxz = modelHomer.vertices()[2];
  for (unsigned int i = 3; i < modelHomer.vertices().size(); i+=3)
  {
    if (modelHomer.vertices()[i+0] < minx)
      minx = modelHomer.vertices()[i+0];
    if (modelHomer.vertices()[i+0] > maxx)
      maxx = modelHomer.vertices()[i+0];
    if (modelHomer.vertices()[i+1] < miny)
      miny = modelHomer.vertices()[i+1];
    if (modelHomer.vertices()[i+1] > maxy)
      maxy = modelHomer.vertices()[i+1];
    if (modelHomer.vertices()[i+2] < minz)
      minz = modelHomer.vertices()[i+2];
    if (modelHomer.vertices()[i+2] > maxz)
      maxz = modelHomer.vertices()[i+2];
  }
  midaModelHomer = maxy-miny;
  baseHomer[0]   = (maxx+minx)/2.0;
  baseHomer[1]   = miny;
  baseHomer[2]   = (maxz+minz)/2.0;
}

void LL2GLWidget::calculaCapsaEscena()
{
  minEscena = glm::vec3(0.0, 0.0, 0.0);
  maxEscena = glm::vec3(10.0, 0.0, 10.0);
  centreEscena = (maxEscena + minEscena);
  centreEscena = centreEscena / glm::vec3(2.0, 2.0, 2.0);
  
  //radiEscena = distance(minEscena, maxEscena)/2.0;
  radiEscena = sqrt((maxEscena[0]-minEscena[0])*(maxEscena[0]-minEscena[0])+(maxEscena[1]-minEscena[1])*(maxEscena[1]-minEscena[1])+(maxEscena[2]-minEscena[2])*(maxEscena[2]-minEscena[2]))/2.0;
	//radiEscena = sqrt((minEscena[0]-vrp[0])*(minEscena[0]-vrp[0]) + (minEscena[1]-vrp[1])*(minEscena[1]-vrp[1]) + (minEscena[2]-vrp[2])*(minEscena[2]-VRP[2])); 	// radi (igual amb maxEscena)

/*
radiEscena = sqrt((minEscena[0]-vrp[0])*(minEscena[0]-vrp[0]) + (minEscena[1]-vrp[1])*(minEscena[1]-vrp[1]) + (minEscena[2]-vrp[2])*(minEscena[2]-vrp[2])); 	// radi (igual amb maxEscena)

  d = 2 * radiEscena;
  fov = 2.0*asin(radiEscena/(d));
  ra = 1.0f;
  znear = d -radiEscena;
  zfar = d+radiEscena;
*/
  vrp = glm::vec3((maxEscena[0]-minEscena[0])/2, 1.0, (maxEscena[2]-minEscena[2])/2);//centreEscena;//glm::vec3((xmax+xmin)/2.0,(ymax+ymin)/2.0,(zmax+zmin)/2.0);  //Centre de l'escena

  fov = 2.0*asin(radiEscena/(radiEscena*2));
  ra = 1.0f;
  znear = radiEscena*2-radiEscena;      // d - R
  zfar = radiEscena*2+radiEscena;       // d + R
  //calculaParametres(minEscena[0], maxEscena[0], minEscena[1], maxEscena[1], minEscena[2], maxEscena[2]);
}

void LL2GLWidget::keyPressEvent(QKeyEvent* event) 
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_Plus: { // escalar a més gran
      if(maxHomers<15) ++maxHomers;
      break;
    }
    case Qt::Key_Minus: { // escalar a més gran
      if(maxHomers>1) maxHomers--;
      //else rotacioHomer = 0;
      break;
    }
    case Qt::Key_Up: { 
        if(radiRotllana < 5) radiRotllana += 0.5;
        break;
    }
    case Qt::Key_Down: { 
        if(radiRotllana > 1.5) radiRotllana -= 0.5;
        break;
    }
    case Qt::Key_Left: { 
        girBallHomer -= float(5.0*M_PI/180);
        break;
    }
    case Qt::Key_Right: { 
        girBallHomer += float(5.0*M_PI/180);
        break;
    }
    case Qt::Key_R: {
      iniEscena();
      iniCamera();
        break;
    }
    case Qt::Key_C: {
      if(ortogonal)
      {
        cameraPerspectiva();
      }
      else{
        cameraOrtogonal();
      }
      break;
    }
    default: event->ignore(); break;
  }
  update();
}

void LL2GLWidget::mousePressEvent (QMouseEvent *e)
{
  xClick = e->x();
  yClick = e->y();

  if (e->button() & Qt::LeftButton &&
      ! (e->modifiers() & (Qt::ShiftModifier|Qt::AltModifier|Qt::ControlModifier)))
  {
    DoingInteractive = ROTATE;
  }
}

void LL2GLWidget::mouseReleaseEvent( QMouseEvent *)
{
  DoingInteractive = NONE;
}

void LL2GLWidget::mouseMoveEvent(QMouseEvent *e)
{
  makeCurrent();
  xClick = e->x();
  yClick = e->y();
  
  int dx = (e -> x() - ultima_x);
  int dy = (e -> y() - ultima_y);
  Psi -= fmod(dx*factorAngleX,100);
  Theta += fmod(dy*factorAngleY,100);
  update();
  if(DoingInteractive == ROTATE)
  {
    ultima_x = e->x();
    ultima_y = e->y();
  }else {
    ultima_y = e->y()+500;//glm::glGetIntegerv(GL_VIEWPORT, m_viewport);
    ultima_x = e->x();
  }
  std::cout << "factorAngleX: " << factorAngleX << ", factorAngleY: " << factorAngleY << ", ultima_x: " <<ultima_x << "ultima_y: " << ultima_y << std::endl;
  std::cout << "x: " <<xClick << "y: " << yClick << ", psi: " << Psi << ", Theta: " << Theta << std::endl;

  viewTransform();
}



// AFEGIDES


void LL2GLWidget::cameraPerspectiva()
{
  ortogonal = false;
  viewTransform();
  projectTransform();
}

void LL2GLWidget::cameraOrtogonal()
{
  ortogonal = true;
  obs = glm::vec3(centreEscena[0], 10, centreEscena[2]);
  vrp = centreEscena;
  up = glm::vec3(0., 0., -1.);
  //znear = (radiRotllana*2 - radiRotllana)*tan(asin(radiRotllana/ 2*radiRotllana));
  znear = 1.;
  zfar = 2*(radiRotllana*2 + radiRotllana);
  //fov = 2 * asin(radiRotllana/ 2*radiRotllana);
  viewTransform();
  projectTransform();
}

