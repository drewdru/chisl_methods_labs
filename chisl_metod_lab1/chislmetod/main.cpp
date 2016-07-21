#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>

using namespace std;

void proizved(double **mas1,double **mas2,int x1,int y1,int y2, double **mas3);
void proizved(double **mas1, double *mas2, int x1, int y1, double *mas3);
void L_1(int n, int k, double** masA, double** masL_1);
double detMatrix(double **xk, int razm);
void inversion(double **A, int N);
int main()
{
    setlocale(LC_ALL,"RUS");

    int n;

    ifstream txtin("1.txt",ios::in);
    txtin>>n;
    cout<<"Введённый массив:\n";

    //выделение памяти под массивы
    double** masA = new double*[n];
    double* masB = new double[n];
    double** masL_1 = new double*[n];
    double* masU = new double[n];
    double* masY = new double[n];
    double* masX = new double[n];
    double** temp1 = new double*[n];
    double** temp2 = new double*[n];
    double** temp3 = new double*[n];
    double** MasL = new double*[n];
    for(int i = 0; i<n; i++)
    {
        masA[i] = new double[n];
        masL_1[i] = new double[n];
        temp1[i] = new double[n];
        temp2[i] = new double[n];
        temp3[i] = new double[n];
        MasL[i] = new double[n];
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

    //Расчёт матрицы матрицы L^(-1)
    L_1(n,0,masA,masL_1);
    for(int i = 1; i<n;i++)
    {
        //temp1 = masL_1;
        for(int k=0;k<n;k++)
            for(int j=0;j<n;j++)
                temp1[k][j] = masL_1[k][j];

        L_1(n,i,masA,masL_1);

        //temp2 = masL_1;
        for(int k=0;k<n;k++)
            for(int j=0;j<n;j++)
                temp2[k][j] = masL_1[k][j];

        proizved(temp2, temp1, n,n,n, temp3);
    }

    double* temp4 = new double[n];
    //вычисление матрицы U
    proizved(temp3, masB, n,n, temp4);
    for(int i = 0; i<n;i++)
        masU[i] = temp4[i];

    //вычисление ответа возможно только, если можно
    //найти обратную матрицу L^(-1)
    if( detMatrix(temp3, n)!=0)
    {
        inversion(temp3, n);//нахождение матрицы L

        //расчёт матрицы Y из уравнение:
        // L*Y = B
        //masY[0] = masB[0]/temp3[0][0];
        for(int i = 0; i<n; i++)
        {
            double sum = masB[i];
            for(int j=0; j<i;j++)
                sum-=(temp3[i][j]*masY[j]);
            masY[i] = sum/temp3[i][i];
        }

        //расчёт матрицы конечного ответа X из уравнение:
        // U*X = Y
        for(int i = 0; i<n; i++)
            masX[i] = masY[i] / masU[i];

        cout<<"Ответ:\n";
        for(int i = 0; i<n; i++)
            cout<<masX[i]<<endl;
    }
    else
        cout<<"Определитель матрицы L^(-1) = 0,\n\
              не возможно найти матрицу L";

    //освобождение выделенной памяти
    delete[] masB;
    delete[] masU;
    delete[] masY;
    delete[] masX;
    for(int i = 0; i<n; i++)
    {
        delete[] masA[i];
        delete[] masL_1[i];        
        delete[] temp1[i];
        delete[] temp2[i];
        delete[] temp3[i];
        delete[] MasL[i];
    }

    return 0;
}

void L_1(int n, int k, double** masA, double** masL_1)//n - размерность массива, k - номер L^(-1) ( 0-- n-1)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) masL_1[i][j] = 1;
            else masL_1[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(i<k) masL_1[i][k] = 0;
        else if(i==k)
            masL_1[i][k] = 1/(masA[i][k]);
        else if(i>k)
            masL_1[i][k] = masA[k][k] / masA[i][k];
    }
}

//x1--количество строк первой матрицы
//y1--количество строк второй матрицы
//y2--количество столбцов второй матрицы
void proizved(double **mas1, double **mas2, int x1, int y1, int y2, double **mas3)
{
    for (int i=0; i < x1; i++)
        for (int j=0; j < y2; j++)
            for (int k=0;k < y1; k++)
                mas3[i][j]+=(mas1[i][k]*mas2[k][j]);
}
void proizved(double **mas1, double *mas2, int x1, int y1, double *mas3)
{
    for (int i=0; i < x1; i++)
        for (int k=0;k < y1; k++)
            mas3[i]+=(mas1[i][k]*mas2[k]);
}
double detMatrix(double** xk, int razm)
{
    int l;
    double d;
    double sum11=1, sum12=0, sum21=1, sum22=0;
    // находим детерминант
            for (int i=0;i<razm;i++)
            {
                    sum11=1; l=2*razm-1-i;sum21=1;
            for (int j=0;j<razm;j++)
                    {
                sum21*=xk[j][l%razm];
                l--;
                sum11*=xk[j][(j+i)%(razm)];
            }
            sum22+=sum21;
            sum12+=sum11;
        }
        d=sum12-sum22;
    return d;
}

void inversion(double **A, int N)
{
    double temp;

    double **E = new double *[N];

    for (int i = 0; i < N; i++)
        E[i] = new double [N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            E[i][j] = 0.0;

            if (i == j)
                E[i][j] = 1.0;
        }

    for (int k = 0; k < N; k++)
    {
        temp = A[k][k];

        for (int j = 0; j < N; j++)
        {
            A[k][j] /= temp;
            E[k][j] /= temp;
        }

        for (int i = k + 1; i < N; i++)
        {
            temp = A[i][k];

            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }

    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = A[i][k];

            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = E[i][j];

    for (int i = 0; i < N; i++)
        delete [] E[i];

    delete [] E;
}
