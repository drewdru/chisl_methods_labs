#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>
#include <QtScript/QScriptEngine>
#include <QTime>
#include "cubic_spline.h"
#include "form.h"

double L(double x, double* x_values, double* y_values, int size);
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

void MainWindow::on_pushButton_2_clicked()
{
    int n=0;
        double a,b;
        //n = ui->spinBox_2->text().toInt();
        a = ui->lineEdit_2->text().toDouble();
        b = ui->lineEdit_3->text().toDouble();
        int zum = ui->spinBox->text().toInt();
        double k = ui->doubleSpinBox->text().replace(QString(","), \
                                                     QString(".")).toDouble();
        if(a>b)
        {
            double temp = a;
            a=b;
            b=temp;
        }

        for(double i =a;i<b;i+=k)
        {
            n++;
        }

        QString str;
        QScriptEngine engine;

        double* MasX = new double[n];
        double* MasY = new double[n];
        double x=a;
        for(int i=0; i<n; i++)
        {
            MasX[i] = x;
            engine.globalObject().setProperty("x", x);
            str = getstr(ui->lineEdit->text());
            MasY[i] = engine.evaluate(str).toNumber();
            x+=k;
        }

        cubic_spline cs;
        cs.build_spline(MasX,MasY,n);

        QTime time;
        time.start () ;

        this->scene = new QGraphicsScene(ui->graphicsView);

        //Это как раз создана сцена. Сцена - это класс для работы с 2D графикой.
        //Теперь, раз это график, то построим координатные оси X и Y.
        QPen pen(Qt::green);//Просто выбираем цвет для карандашика
        this->scene->addLine(-100*zum,90*zum,300*zum,90*zum,pen);//x
        this->scene->addLine(90*zum,-100*zum,90*zum,300*zum,pen);//y
        ui->graphicsView->setScene(scene);
        QPen pen2(Qt::red);//Карандашик для графика
        pen2.setWidth(3);

        for(int i = 0;i<n-2;i++)
        {
            scene->addLine((MasX[i]*15+90)*zum,(90-cs.f(MasX[i])*15)*zum,\
                           ((MasX[i+1])*15+90)*zum,\
                           (90-cs.f(MasX[i+1])*15)*zum,pen2);
        }

        QPen pen4(Qt::white);//Карандашик для графика
        pen4.setWidth(3);
        for(int i = 0;i<n-2;i++)
        {
            /*engine.globalObject().setProperty("x", (MasX[i]+k));
            str = getstr(ui->lineEdit->text());
            double y = engine.evaluate(str).toNumber();*/

            scene->addLine((MasX[i]*15+90)*zum,(90-MasY[i]*15)*zum,\
                           ((MasX[i+1])*15+90)*zum,\
                           (90-MasY[i+1]*15)*zum,pen4);

        }
    double k2=ui->doubleSpinBox_2->text().replace(QString(","), \
                                                  QString(".")).toDouble();
    for(double i =a;i<b;i+=k2) ++n;
    //n= (a+b)/(k2);
    QPen pen3(Qt::blue);//Карандашик для графика
    pen3.setWidth(4);
    for(int i = 0;i<n-2;i++)
    {
        scene->addLine((MasX[i]*15+90)*zum,\
                       (90-cs.f(L(MasX[i],MasX,MasY,n))*15)*zum,\
                       ((MasX[i+1])*15+90)*zum,\
                       (90-cs.f(L((MasX[i+1]),MasX,MasY,n))*15)*zum,pen3);

    }



ui->graphicsView->setScene(scene);

    //(90;90) – точка пересечения осей. Значит, мы должны к x-ам прибавить x
    //центра, а из y вычесть значение Y центра. 15 – это количество пикселов в
    //0,5 мм. Это все требуется для наиболее точного расположения графика.
    //Добавляем в наш GraphicsView нарисованную сцену.
    ui->graphicsView->setScene(scene);
    ui->lineEdit_5->setText(QString::number(n));
    ui->lineEdit_7->setText(QString::number(time.elapsed()));
    delete[] MasX;
    delete[] MasY;
}

double L(double x, double* x_values, double* y_values, int size)
{
    double lagrange_pol = 0;
    double basics_pol;

    for (int i = 0; i < size; i++)
    {
        basics_pol = 1;
        for (int j = 0; j < size; j++)
        {
            if (j == i) continue;
            basics_pol *= (x - x_values[j])/(x_values[i] - x_values[j]);
        }
        lagrange_pol += basics_pol*y_values[i];
    }
    return lagrange_pol;
}

void MainWindow::on_pushButton_clicked()
{
    Form* fm = new Form();
    fm->show();
}
