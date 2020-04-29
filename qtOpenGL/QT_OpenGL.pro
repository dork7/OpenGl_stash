#-------------------------------------------------
#
# Project created by QtCreator 2015-11-13T13:00:43
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_OpenGL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    display.cpp \
    shader.cpp \
    mesh.cpp \
    stb_image.c \
    texture.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    display.h \
    shader.h \
    mesh.h \
    stb_image.h \
    texture.h

FORMS    += mainwindow.ui

LIBS += -lglut -lGLU -lGLEW  -lGL

MY_LIB_FILES += "$$_PRO_FILE_PWD_/shapelib/shapelib.dll"


LIBS += -L"/usr/local/lib/" -lshp
LIBS += -lSDL2

