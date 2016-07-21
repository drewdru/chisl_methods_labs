#-------------------------------------------------
#
# Project created by QtCreator 2014-09-02T15:47:15
#
#-------------------------------------------------

QT      += core gui
QT      += opengl
CONFIG  += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Methods1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene3d.cpp

HEADERS  += mainwindow.h \
    glext.h \
    glu.h \
    scene3d.h

FORMS    += mainwindow.ui
