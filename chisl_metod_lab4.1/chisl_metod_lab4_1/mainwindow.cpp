#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <math.h>
#include <iostream>
#include <QtScript/QScriptEngine>
#include <QTime>
#include "help.h"
#include <limits>
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

double change_function(double x,QString str)
{
    QScriptEngine engine;
    engine.globalObject().setProperty("x", x);
    double aaa = engine.evaluate(str).toNumber();
    return engine.evaluate(str).toNumber();
}
double f_(double x,double min,double max,QString str)
{
    double t;
    if(min+max >1)
        t= 2 / (min+max);
    else
        t = 2 *(min+max);
    return x-change_function(x,str)*t;
}

//void MainWindow::
void MainWindow::on_pushButton_2_clicked()
{
    double a,b,eps,m,d;
    a = ui->lineEdit_2->text().toDouble();
    b = ui->lineEdit_3->text().toDouble();
    eps = ui->lineEdit_4->text().toDouble();
    int zum = ui->spinBox->text().toInt();
    double h = ui->doubleSpinBox->text().replace(QString(","), \
                                                 QString(".")).toDouble();
    double h2=ui->lineEdit_8->text().replace(QString(","), \
                                             QString(".")).toDouble();;
    double min = numeric_limits<double>::max();
    double max = numeric_limits<double>::min();
    if(a>b)
    {
        double temp = a;
        a=b;
        b=temp;
    }

    this->scene = new QGraphicsScene(ui->graphicsView);
    //Это как раз создана сцена. Сцена - это класс для работы с 2D графикой.
    //Теперь, раз это график, то построим координатные оси X и Y.
    QPen pen(Qt::green);//Просто выбираем цвет для карандашика
    this->scene->addLine(-100*zum,90*zum,300*zum,90*zum,pen);//x
    this->scene->addLine(90*zum,-100*zum,90*zum,300*zum,pen);//y
    ui->graphicsView->setScene(scene);

    QString str =ui->lineEdit->text();
    str = getstr(str);
    for(double i = a; i < b; i+=h)
    {
        double qwer1 =change_function(i+h2,str);
        double qwer2 =change_function(i-h2,str);
        m =(qwer1- qwer2)/(2*h2);
        if(max < m)
            max = m;
        if(min > m)
            min = m;
    }
    double x1 = a, x0;
    int count =0;
    QTime time;
    time.start () ;
    do
    {
        x0 = x1;
        x1 = f_(x0,min,max,str);
        d = fabs(x1 - x0);
        count++;
    } while (d > eps);
    ui->textEdit->setText(QString::number(x1));
    ui->textEdit->append("min =" + QString::number(min));
    ui->textEdit->append("max =" + QString::number(max));
    ui->lineEdit_5->setText(QString::number(count));
    ui->lineEdit_7->setText(QString::number(time.elapsed()));

    QScriptEngine engine;    
    QPen pen2(Qt::red);//Карандашик для графика
    pen2.setWidth(3);
    h = ui->doubleSpinBox_2->text().replace(QString(","), \
                                                 QString(".")).toDouble();
    for(double x = a; x<=b;x+=h)
    {
        engine.globalObject().setProperty("x", x);
        double fx = engine.evaluate(str).toNumber();
        engine.globalObject().setProperty("x", x+h);
        double fx2 = engine.evaluate(str).toNumber();
        scene->addLine((x*15+90)*zum,(90-fx*15)*zum,((x+h)*15+90)*zum\
                       ,(90-fx2*15)*zum,pen2);
    }
    ui->graphicsView->setScene(scene);

    /*int cnt=(b-a)/eps;
    double x2,f1,f2,x1=a;
    str = getstr(ui->lineEdit->text());
    ui->textEdit->setText("Ответ:");

    engine.globalObject().setProperty("x", x1);
    f1 = engine.evaluate(str).toNumber();
    for(int i =0; i<cnt;i++)
    {
        x2 =x1+(b-a)/cnt;
        engine.globalObject().setProperty("x", x2);
        f2= engine.evaluate(str).toNumber();
        if (f1*f2 <= 0)
        {
            //cout<<"x = "<<(x2 + x1)/2<<endl;
            //ui->lineEdit_6->setText(QString::number((x2 + x1)/2));
            ui->textEdit->append(QString::number((x2 + x1)/2));
        }
        x1=x2;
        f1=f2;
    }
    ui->lineEdit_5->setText(QString::number(n));
    ui->lineEdit_7->setText(QString::number(time.elapsed()));*/
}

void MainWindow::on_pushButton_clicked()
{
    Help* help = new Help();
    help->show();
}
