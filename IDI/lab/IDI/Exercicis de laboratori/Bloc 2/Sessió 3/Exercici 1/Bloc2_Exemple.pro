# (c) FIBerHub, https://fiberhub.tk

TEMPLATE    = app
QT         += opengl

INCLUDEPATH +=  /usr/include/glm

FORMS += MyForm.ui

HEADERS += MyForm.h MyGLWidget.h

SOURCES += main.cpp MyForm.cpp \
        MyGLWidget.cpp


INCLUDEPATH += ./Model
SOURCES += ./Model/model.cpp
HEADERS += ./Model/model.h
