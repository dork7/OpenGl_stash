#-------------------------------------------------
#
# Project created by QtCreator 2020-03-03T17:20:13
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = openGL_img
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    stb_image.c \
    imageloader.cpp

HEADERS += \
        mainwindow.h \
    stb_image.h \
    imageloader.h

FORMS += \
        mainwindow.ui
LIBS += -lglut -lGLU -lGLEW  -lGL
MY_LIB_FILES += "$$_PRO_FILE_PWD_/shapelib/shapelib.dll"


LIBS += -L"/usr/local/lib/" -lshp
LIBS += -lSDL2
LIBS += -lIL

