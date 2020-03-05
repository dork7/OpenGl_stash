#-------------------------------------------------
#
# Project created by QtCreator 2015-11-13T13:00:43
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtOpenGl_benny
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \


HEADERS  += mainwindow.h \
    glwidget.h \
    display.h \


FORMS    += mainwindow.ui

LIBS += -lglut -lGLU -lGLEW  -lGL

MY_LIB_FILES += "$$_PRO_FILE_PWD_/shapelib/shapelib.dll"


LIBS += -L"/usr/local/lib/" -lshp
LIBS += -lSDL2

