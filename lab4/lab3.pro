#-------------------------------------------------
#
# Project created by QtCreator 2014-10-31T21:52:05
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab3
TEMPLATE = app
QMAKE_LFLAGS += -fopenmp

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    approx.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    approx.h

FORMS    += mainwindow.ui

