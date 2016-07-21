#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include <QtScript/QScriptEngine>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString getstr(QString str)
{
    str.replace(QString("abs"), QString("Math.abs"));
    str.replace(QString("acos"), QString("Math.acos"));
    str.replace(QString("asin"), QString("Math.asin"));
    str.replace(QString("atan"), QString("Math.atan"));
    str.replace(QString("exp"), QString("Math.exp"));
    str.replace(QString("log"), QString("Math.log"));
    str.replace(QString("pow"), QString("Math.pow"));
    str.replace(QString("random"), QString("Math.random"));
    str.replace(QString("round"), QString("Math.round"));
    str.replace(QString("cos"), QString("Math.cos"));
    str.replace(QString("sin"), QString("Math.sin"));
    str.replace(QString("sqrt"), QString("Math.sqrt"));
    str.replace(QString("tan"), QString("Math.tan"));
    return str;
}

// Следующая функция возвращает значение
// правой части исходной задачи по
// заданным аргументам x и y
double calculate_f(double x, double y,QString str)
{
    QScriptEngine engine;
    engine.globalObject().setProperty("x", x);
    engine.globalObject().setProperty("y", y);
    double res =y + engine.evaluate(str).toNumber();
    return res;
}
void MainWindow::on_pushButton_clicked()
{
    // Задаем границы отрезка, на котором
    // рассматривается исходная задача
    double a;
    double b;
    QString str;
    str = ui->lineEdit->text();
    str = getstr(str);
    double EPS = ui->doubleSpinBox_4->text().replace(QString(","), \
                                                     QString(".")).toDouble();
    a = ui->doubleSpinBox_6->text().replace(QString(","), \
                                            QString(".")).toDouble();
    b = ui->doubleSpinBox_2->text().replace(QString(","), \
                                            QString(".")).toDouble();
    // Задаем начальное условие задачи
    double y0;
    y0 = ui->doubleSpinBox_3->text().replace(QString(","), \
                                             QString(".")).toDouble();
    // Задаем число точек на отрезке и,
    // соответственно, шаг сетки аргумента
    int n;
    n = ui->spinBox->text().toDouble();
    const double h = (b - a) / n;

    // Массив x будет хранить сетку аргумента,
    // а массив y - значения приближенного
    // решения в этих точках
    double x[n + 1];
    double* y = new double[n + 1];

    // Воспользовавшись начальными условиями,
    // определим первые элементы этих массивов
    x[0] = ui->doubleSpinBox->text().replace(QString(","), \
                                             QString(".")).toDouble();
    y[0] = y0;

    // метод Эйлера
    for (int i = 1; i <= n; i++)
    {
        x[i] = x[i - 1] + h;
        y[i] = y[i - 1] + h * calculate_f(x[i - 1], y[i - 1],str);
    }

    int zum = ui->spinBox_3->text().toInt();
    this->scene = new QGraphicsScene(ui->graphicsView);
    //Это как раз создана сцена. Сцена - это класс для работы с 2D графикой.
    //Теперь, раз это график, то построим координатные оси X и Y.
    QPen pen(Qt::green);//Просто выбираем цвет для карандашика
    this->scene->addLine(-100*zum,90*zum,300*zum,90*zum,pen);//x
    this->scene->addLine(90*zum,-100*zum,90*zum,300*zum,pen);//y
    this->scene->addLine(-200*zum,90*zum,-201*zum,90*zum,pen);
    ui->graphicsView->setScene(scene);

    QPen penERROR(Qt::red);//Карандашик для графика
    penERROR.setWidth(3);
    QPen penFunction(Qt::blue);//Карандашик для графика
    penFunction.setWidth(3);
    // Выводим 4 столбца: абсцисса, значения
    // точного и приближенного решения в ней
    // и, наконец, погрешность в этой точке
    for (int i = 0; i < n; i++)
    {
        scene->addLine(((x[i]-4.5)*15+90)*zum,(90-y[i]*15)*zum,\
                       ((x[i+1]-4.5)*15+90)*zum,(90-y[i+1]*15)*zum,\
                penFunction);
    }
    delete[] y;
}

double fx(double y)
{
    return exp(y)+y*y+2*y+2;
}
void MainWindow::on_pushButton_2_clicked()
{
    this->scene = new QGraphicsScene(ui->graphicsView);

    //int n = 200000;
    int zum = ui->spinBox_3->text().toInt();

    this->scene = new QGraphicsScene(ui->graphicsView);
    //Это как раз создана сцена. Сцена - это класс для работы с 2D графикой
    //Теперь, раз это график, то построим координатные оси X и Y.
    QPen pen1(Qt::green);//Просто выбираем цвет для карандашика
    this->scene->addLine(-100*zum,90*zum,300*zum,90*zum,pen1);//x
    this->scene->addLine(90*zum,-100*zum,90*zum,300*zum,pen1);//y
    ui->graphicsView->setScene(scene);

    QPen pen(Qt::red);//Просто выбираем цвет для карандашика
    pen.setWidth(3);
    for (double i = -1; i < 10; i+=0.1)
    {
        scene->addLine(((i)*15+160)*zum,(108-fx(i)*15)*zum,\
                       ((i+0.1)*15+160)*zum,(108-fx(i+0.1)*15)*zum,\
                       pen);
    }
    ui->graphicsView->setScene(scene);
}


float yr_kacat(float x, float y,QString str)
{
    QScriptEngine engine;
    engine.globalObject().setProperty("x", x);
    engine.globalObject().setProperty("y", y);

    float f=y+ engine.evaluate(str).toNumber();
    return f;
}

void MainWindow::on_pushButton_3_clicked()
{
    float xn=3.15, yn=0.15, a=3.15, b=10, /*h=0.1,*/ x, y;
    int i;
    y=yn;
    x=a;

    int n;
    n = ui->spinBox->text().toDouble();
    const double h = (b - a) / n;

    QString str;
    str = ui->lineEdit->text();
    str = getstr(str);
    int zum = 2;
    this->scene = new QGraphicsScene(ui->graphicsView);
    //Это как раз создана сцена. Сцена - это класс для работы с 2D графикой.
    //Теперь, раз это график, то построим координатные оси X и Y.
    QPen pen(Qt::green);//Просто выбираем цвет для карандашика
    this->scene->addLine(-100*zum,90*zum,300*zum,90*zum,pen);//x
    this->scene->addLine(90*zum,-100*zum,90*zum,300*zum,pen);//y
    ui->graphicsView->setScene(scene);

    QPen penFunction(Qt::blue);//Карандашик для графика
    penFunction.setWidth(3);
    //printf("x[0]=%.4f  ", x);
    //printf("y[0]=%.4f\n\n",  y);

    float lastX = x, lastY = y;
    float k1, k2, k3, k4, dy;
    for (i=1; x<b; i++)
    {         x=xn+i*h;
        k1=h*yr_kacat(x, y,str);
        k2=h*yr_kacat((x+(h/2)), (y+(1/2*k1)),str);
        k3=h*yr_kacat((x+(h/2)), (y+(1/2*k2)),str);
        k4=h*yr_kacat((x+h), (y+k3),str);
        dy=(k1+2*k2+2*k3+k4)/6;
        y=y+dy;

        scene->addLine((lastX*15+90)*zum,(90-lastY*15)*zum,\
                       (x*15+90)*zum,(90-y*15)*zum,\
                       penFunction);
        lastX = x;
        lastY = y;
    }
    ui->graphicsView->setScene(scene);
}
