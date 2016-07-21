#ifndef APPROX_H
#define APPROX_H
#include <QString>
//#include <QtScript/QScriptEngine>

class approx
{
public:
    approx(double start, double end, double step, QString formula);
    ~approx();
    QString convstr(QString str);
    double Lagrange(double _x, QVector<double> x, QVector<double> y, int n);
    double Func(double x);
    double Deviation(QVector<double> y, QVector<double> lagr, int n);
    void build_spline(QVector<double> x, QVector<double> y, int n);
    double f(double x);//по сплайну
    double x;

private:
    double start;
    double end;
    double step;
    QString formula;
    QScriptEngine engine;
    struct spline_tuple
    {
        double a, b, c, d, x;
    };
    spline_tuple *splines; // Сплайн
    int n;//размер сплайна


};

#endif // APPROX_H
