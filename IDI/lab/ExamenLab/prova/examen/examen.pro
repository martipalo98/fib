TEMPLATE    = app
QT         += opengl

INCLUDEPATH +=  /usr/include/glm
INCLUDEPATH += ./Model

FORMS += MyForm.ui

HEADERS += MyForm.h ExamGLWidget.h MyGLWidget.h

SOURCES += main.cpp  MyForm.cpp \
        ExamGLWidget.cpp MyGLWidget.cpp ./Model/model.cpp
