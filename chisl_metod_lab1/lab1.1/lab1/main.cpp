#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <math.h>

using namespace std;

void LU(double **A,double **L,double **U,int N);

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;

    ifstream txtin("1.txt",ios::in);
    txtin>>n;
    cout<<"Введённый массив:\n";

    //выделение памяти под массивы
    double* masB = new double[n];
    double* masY = new double[n];
    double* masX = new double[n];
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
    double sum;
    for(int i=0;i<n;i++)
        sum+=masR[i]*masR[i];
    cout<<sqrt(sum)<<endl;

    return 0;
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
