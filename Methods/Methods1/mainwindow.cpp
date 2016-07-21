#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui>
#include "scene3d.h"

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene1 = new Scene3D(ui->OGLwidget); // создаю динамический объект класса Scene3D
    scene1->setMinimumSize(506,397);

}

MainWindow::~MainWindow()
{
    delete ui;
}
