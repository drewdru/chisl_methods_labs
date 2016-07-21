#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "approx.h"
#include <omp.h>
#include <cstdlib>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateGr_clicked()
{
        double t = ui->startInt->text().toDouble();
        double tt = ui->endint->text().toDouble();
        double e = ui->lineEdit_4->text().toDouble();
        QString str =  ui->formula->text();


        approx *s = new approx(t, tt, e, str);


        QVector<double> x, y,oldX, oldGraph, newX, lagr, spline;

        for (double i=0, j=t; j<tt; i++, j+=e*2)
        {
          x.push_back(j);
          y.push_back(s->Func(j));
        }

        //Для построения исходного графика
        for (double i=0, j=t; j<tt; i++, j+=.1)
        {
          oldX.push_back(j);
          oldGraph.push_back(s->Func(j));
        }

        int range = x.size();

        //Поиск значений, используя м-н Лагранжа
        for (double i=0, j=t; j<tt; i++, j+=e)
        {
          newX.push_back(j);
          lagr.push_back(s->Lagrange(j, x, y, range));
        }

        s->build_spline(x, y, range);
        //Значения сплайна
        for (double i=0, j=t; j<tt; i++, j+=e)
        {
          spline.push_back(s->f(j));
        }

        ui->lineEdit_5->setText(QString::number(range));
        ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


        ui->customPlot->graph(0)->setData(oldX, oldGraph);
        ui->customPlot->graph(0)->setName("Исходный");

        if (ui->lagr->isChecked() == true)
        {
            ui->customPlot->graph(1)->setPen(QPen(QColor(255, 100, 0)));
            ui->customPlot->graph(1)->setData(newX, lagr);
            ui->customPlot->graph(1)->setVisible(true);
            ui->customPlot->graph(1)->setName("Лагранж");
        }
        else
        {
            ui->customPlot->graph(1)->setVisible(false);
        }

        if (ui->spl->isChecked() == true)
        {
            ui->customPlot->graph(2)->setPen(QPen(QColor(0, 100, 0)));
            ui->customPlot->graph(2)->setData(newX, spline);
            ui->customPlot->graph(2)->setVisible(true);
            ui->customPlot->graph(2)->setName("Сплайн");
        }
        else
        {
            ui->customPlot->graph(2)->setVisible(false);
        }

        ui->customPlot->legend->setVisible(true);
        ui->customPlot->xAxis->setLabel("x");
        ui->customPlot->yAxis->setLabel("y");

        ui->customPlot->xAxis->setRange(t, tt);
        ui->customPlot->yAxis->setRange(t, tt);
        ui->customPlot->replot();

        x.remove(0,range);
        y.remove(0,range);
        lagr.remove(0,range);
        spline.remove(0,range);


}


