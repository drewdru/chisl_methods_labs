#include "approx.h"
#include <math.h>
#include <QString>
#include <QtScript/QScriptEngine>
#include <QtCore/QVector>


approx::approx(double start, double end, double step, QString formula)
{
    this->start = start;
    this->end = end;
    this->step = step;
    this->formula = formula;
    this->formula = convstr(formula);

}

approx::~approx()
{

}

QString approx::convstr(QString str)
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

double approx::Lagrange(double _x, QVector<double> x, QVector<double> y, int n)
{
    /*
    double lagrange_pol = 0;
    double basics_pol;

    for (int i = 0; i < n; i++)
    {
        basics_pol = 1;
        for (int j = 0; j < n; j++)
        {
            if (j == i) continue;
            basics_pol *= (_x - x[j])/(x[i] - x[j]);
        }
        lagrange_pol += basics_pol*y[i];
    }
    return lagrange_pol;
    */

    double result = 0.0;

    double h = x[1] - x[0];

    for (short i = 0; i < n; i++)
    {
        double P = 1.0;

        for (short j = 0; j < n; j++)
            if (i != j)
                P *= (_x - x[0] - h* j)/ h/ (i - j);

        result += P* y[i];
    }

    return result;
}


double approx::Func(double x)
{
    engine.globalObject().setProperty("x", x);
    double answer = engine.evaluate(formula).toNumber();
    return answer;
}

void approx::build_spline(QVector<double> x, QVector<double> y, int n)
{
    this->n = n;

    // Инициализация массива сплайнов
        splines = new spline_tuple[n];
        for (int i = 0; i < n; ++i)
        {
            splines[i].x = x[i];
            splines[i].a = y[i];
        }
        splines[0].c = 0;

        // прямой ход
        double *alpha = new double[n - 1];
        double *beta = new double[n - 1];
        double A, B, C, F, h_i, h_i1, z;
        alpha[0] = beta[0] = 0.;
        for (int i = 1; i < n - 1; ++i)
        {
            h_i = x[i] - x[i - 1], h_i1 = x[i + 1] - x[i];
            A = h_i;
            C = 2. * (h_i + h_i1);
            B = h_i1;
            F = 6. * ((y[i + 1] - y[i]) / h_i1 - (y[i] - y[i - 1]) / h_i);
            z = (A * alpha[i - 1] + C);
            alpha[i] = -B / z;
            beta[i] = (F - A * beta[i - 1]) / z;
        }

        splines[n - 1].c = (F - A * beta[n - 2]) / (C + A * alpha[n - 2]);

        //обратный ход
        for (int i = n - 2; i > 0; --i)
            splines[i].c = alpha[i] * splines[i + 1].c + beta[i];


        delete[] beta;
        delete[] alpha;

        //находим  b[i] и d[i]
        for (int i = n - 1; i > 0; --i)
        {
            double h_i = x[i] - x[i - 1];
            splines[i].d = (splines[i].c - splines[i - 1].c) / h_i;
            splines[i].b = h_i * (2. * splines[i].c + splines[i - 1].c) / 6. + (y[i] - y[i - 1]) / h_i;
        }
}

double approx::f(double x)
{
    spline_tuple *s;
    if (x <= splines[0].x)
        s = splines + 1;
    else if (x >= splines[n - 1].x)
        s = splines + n - 1;
    else
    {
        int i = 0, j = n - 1;
        while (i + 1 < j)
        {
            int k = i + (j - i) / 2;
            if (x <= splines[k].x)
                j = k;
            else
                i = k;
        }
        s = splines + j;
    }

    double dx = (x - s->x);
    return s->a + (s->b + (s->c / 2. + s->d * dx / 6.) * dx) * dx; // Вычисляем значение сплайна в заданной точке.
}

double approx::Deviation(QVector<double> y, QVector<double> lagr, int n)
{
    ;
    
}

