#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scene3d.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_MainWindow_iconSizeChanged(const QSize &iconSize);

private:
    Ui::MainWindow *ui;

    Scene3D* scene1; // указатель на объект класса Scene3D

    // меню
    //QMenu* texture_menu; // указатель на меню, меню текстуры
    // дейстивие
    //QAction* changeTexAct; // поменять текстуры местами
    // меню
    //QMenu* timer_menu; // меню таймера
    // действия
    //QAction* stopTimAct; // остановить таймер
    //QAction* startTimAct; // запустить таймер

    //void createActions(); // создание действий
    //void createMenus(); // создание меню
};

#endif // MAINWINDOW_H
