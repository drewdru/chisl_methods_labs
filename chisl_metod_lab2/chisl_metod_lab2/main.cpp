#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <locale>
#include <omp.h>

using namespace std;

int Yakobi (double **, double *, double *, int);
void LU(double **,double **,double **,int );

const double eps = 0.0000001; ///< желаемая точность
int main()
{
    setlocale(0,"Russian");

    // //////////////////////////////
    int n;

    ifstream txtin("1.txt",ios::in);
    txtin>>n;
    cout<<"Введённый массив:\n";

    //выделение памяти под массивы
    double* masB = new double[n];
    double* masY = new double[n];
    double* masX = new double[n]; //Решение LU разложения
    double* masR = new double[n];
    double** masA = new double*[n];
    double** tempmasA = new double*[n];
    double** masL = new double*[n];
    double** masU = new double*[n];
    for(int i = 0; i<n; i++)
    {
        masA[i] = new double[n];
        tempmasA[i] = new double[n];
        masL[i] = new double[n];
        masU[i] = new double[n];
    }
    //считывание входных данных
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            txtin>>masA[i][j];
        }
        txtin>>masB[i];
    }
    txtin.close();

    double time;
    time = omp_get_wtime();

    //Вывод входных данных
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<masA[i][j]<<"\t";
        }
        cout<<masB[i]<<endl;
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            tempmasA[i][j] = masA[i][j];

    time = omp_get_wtime();

    LU(masA,masL,masU,n);

    cout<<"Матрица L\n";
    //Вывод входных данных
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<masL[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"Матрица U\n";
    //Вывод входных данных
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<masU[i][j]<<"\t";
        }
        cout<<endl;
    }

    //расчёт матрицы Y из уравнение:
    // L*Y = B
    for(int i = 0; i<n; i++)
    {
        double sum = masB[i];
        for(int j=0; j<i;j++)
            sum-=(masL[i][j]*masY[j]);
        masY[i] = sum/masL[i][i];
    }

    //расчёт матрицы конечного ответа X из уравнение:
    // U*X = Y
    for(int i = n-1; i>=0; i--)
    {
        double sum = masY[i];
        for(int j=n-1; j>i;j--)
            sum-=(masU[i][j]*masX[j]);
        masX[i] = sum/masU[i][i];
    }

    cout<<"Ответ:\n";
    for(int i = 0; i<n; i++)
        cout<<masX[i]<<endl;

    time = omp_get_wtime() - time;
    cout<<"Время поиска решения методом LU разложений "<<time<<", "<<n*(n+n)<<" итераций\n";

    for(int i=0;i<n;i++)
        masR[i] = 0;
    cout<<"Вектор невязки:\n";
    for(int i=0;i<n;i++)
    {
        for(int j = 0; j<n; j++)
            masR[i] += (tempmasA[i][j] * masX[j]);
        masR[i] -= masB[i];
    }
    for(int i = 0; i<n; i++)
        cout<<masR[i]<<endl;

    cout<<"Норма вектора невязки = ";
    double sum=0;
    for(int i=0;i<n;i++)
        sum+=masR[i]*masR[i];
    cout<<sqrt(sum)<<endl;

    // ////////////////////////////////////////////////////

    double *YakobiX = new double[n];//решение Якоби

    cout<<"Исходная матрица\n";
    for(int  i = 0; i<n; i++)
    {
        for(int  j = 0; j<n; j++)
            cout<<tempmasA[i][j]<<" ";
        cout<<masB[i];
        cout<<endl;
    }
    time = omp_get_wtime();
    int itr = Yakobi(tempmasA, masB, YakobiX, n);
    time = omp_get_wtime() - time;

    if(itr>0)
    {

        cout<<"Время поиска решения методом Якоби "<<time<<", "<<itr<<" итераций\n";

        cout<<"Ответ:\n";
        for(int i = 0; i<n; i++)
            cout<<YakobiX[i]<<endl;

        for(int i=0;i<n;i++)
            masR[i] = 0;
        cout<<"Вектор невязки:\n";
        for(int i=0;i<n;i++)
        {
            for(int j = 0; j<n; j++)
                masR[i] += (tempmasA[i][j] * YakobiX[j]);
            masR[i] -= masB[i];
        }
        for(int i = 0; i<n; i++)
            cout<<masR[i]<<endl;

        cout<<"Норма вектора невязки = ";
        sum=0;
        for(int i=0;i<n;i++)
            sum+=masR[i]*masR[i];
        cout<<sqrt(sum)<<endl;
    }

    return 0;
}

//Решение методом Якоби
int Yakobi (double **a, double *b, double *x, int N)
{
    for(int i=0; i<N;i++)
        for(int j=0; j<N;j++)
            if(fabs(a[i][i])<fabs(a[i][j]))
            {
                cout<<"Данную систему не возможно решить методом Якоби"\
                      " т.к. должно быть преобладание диагонального элемента.\n";
                return 0;
            }

    double* TempX = new double[N];
    double norm; // норма, определяемая как наибольшая разность компонент столбца иксов соседних итераций.
 int cnt = 0;
    do {
        cnt++;
        for (int i = 0; i < N; i++) {
            TempX[i] = b[i];
            for (int g = 0; g < N; g++) {
                if (i != g)
                    TempX[i] -= a[i][g] * x[g];
            }
            TempX[i] /= a[i][i];
        }
                norm = fabs(x[0] - TempX[0]);
        for (int h = 0; h < N; h++) {
            if (fabs(x[h] - TempX[h]) > norm)
                norm = fabs(x[h] - TempX[h]);
            x[h] = TempX[h];
        }
    } while (norm > eps);
    delete[] TempX;
    return cnt;
}

void LU(double **A,double **L,double **U,int N)
{
    //инициализация матриц L и U
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==j) L[i][j]=1.0;
            else L[i][j]=0.0;
            U[i][j]=0.0;
        }
    }
    //непосредственно разложение
    for(int k=0;k<N;k++)
    {
        U[k][k]=A[k][k];
        for(int i=k+1;i<N;i++)
        {
            L[i][k]=A[i][k]/U[k][k];
            U[k][i]=A[k][i];
        }
        for(int i=k+1;i<N;i++)
        {
            for(int j=k+1;j<N;j++) A[i][j]=A[i][j]-L[i][k]*U[k][j];
        }
    }
}
