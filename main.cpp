#include <QtWidgets>
#include <iostream>
#include <QString>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <QPoint>
#include <fstream>
#include <string>
#include "analogclock.h"
using namespace std;
Graph::Graph(QWidget *parent)
    : QWidget( parent)
{
    this->resize(1100, 1100); // размер окна вывода

}
void swap(int *a, int i, int j) //эти две функции нужны дляперебора всех перестановок
{
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}
bool NextSet(int *a, int n)
{
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1]) j--;
    if (j == -1)
        return false; // больше перестановок нет
    int k = n - 1;
    while (a[j] >= a[k]) k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
    while (l<r)
        swap(a, l++, r--);
    return true;
}



void Graph::paintEvent(QPaintEvent *)
{
    int opredelitel=0;// она определяет,по какому методу рисовать граф
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    QColor lineColor(0, 12, 127, 232);
    QColor ellipseColor(12, 250, 56);
    painter.setPen(lineColor);
    painter.setBrush(lineColor);

    int t2=0;
    int t=0;
    int k2;
    int r2;
    int i1;
    qsrand(QTime::currentTime().msec());

    painter.setPen(ellipseColor);
    painter.setBrush(ellipseColor);

    setlocale(LC_ALL, "rus");
    char s[8000];
    int n;
    fstream inOut;
    inOut.open("C:\\example39.txt", ios::in);
    inOut.seekg(3*(-1), ios::end);//  мы смотрим три последние буквы,привязанного файла
    inOut >>s;
    int mas[100][100];
    if(s[0]=='r') // если r,то он рисует рандомный граф
    {
        if((s[2]=='0') && (s[1]=='0')) //рисует рандомный граф с рандомным кол-вом вершин
        {
            n=rand()%22;
        }
        else
        {
            n=(int)s[2]+((int)s[1]-48)*10-48;// иначе он рисует граф с заданным кол-вом вершин
        }
        for(int v1=1; v1!=n*n; v1++)
        {
            mas[v1/n+1][v1 % n+1]=rand()%2;// через единицы и нули он проставляет,где есть ребра,а где нет
        }
    }
    else
    {
        n=(int)s[2]+((int)s[1]-48)*10-48;// если стоит не рандом ,то программ считывает кол-во вершин
        inOut.close();// c 88 - 104 программа считывает расположение вершин
        fstream tOut;
        tOut.open("C:\\example6.txt", ios::in);
        tOut.seekg(n*n*(-1), ios::end);
        tOut >> s;
        for (int i=1 ; i!=n*n; i++)
        {
            if(s[i]!='0') // если ноль вершина есть
            {
                mas[i/n+1][i % n+1]=1;
            }
            else
            {
                mas[i/n+1][i % n+1]=0;
            }
        }
        tOut.close();
    }
    int mas2[100][2];

    for (int i=1; i!=n; i++)
    {
        for(int v=1; v!=2; v++)
        {
            mas2[i][v]=sqrt(300*i+v*100); // этот цикл обеспечивает небольшой сдвиг вершин
        }
    }

    int alpha=180;
    int alpha2=180;
    int k=2;
    int r=30;
    int betta=180;


    if (n<8)// если чсило вершин меньше 8,то программа рисует вершины по кругу
    {
        opredelitel=2;
    }
    int sum;
    sum=0;


    for(int i=1; i<n+1; i++) // этот цикл проверяет,можно ли расположить вершины так,чтобы рёбра не пересекались
    {
        for(int i1=1; i1<n+1; i1++)
        {
            if((mas[i][i1]!=1)&&(i1!=i))
            {
                sum=sum+1;
            }
        }

    }

    sum=sum/2;

    if(sum<(n+n+n-6)) // это условие тоже проверяет,можно ли расположить вершины так,чтобы рёбра не пересекались
    {

        int *a;
        a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = i + 1;
        int r=100;
        float mas1[n+1][n+1][2];
        float mas2[n+1][2];
        float mas4[n+1][2];
        float mas3[n+1][n+1];
        float mas5[n+2][n+2];
        for(int v=1; v<n+1; v++)//
        {
            for(int v1=1; v1<n+1; v1++)
            {
                mas3[v][v1]=sqrt(v+v1);
            }
        }

        float x1,x2,y1,y2,x3,x4,y3,y4;
        for(int v=1; v<n+1; v++)
        {
            for(int v1=1; v1<n+1; v1++)
            {
                mas1[v][v1][1]=0;
            }
        }

        for (int i=1; i<n+1; i++)
        {
            mas2[i][1]=r*sin(i*2*3.14159265/3);
            mas2[i][2]=r*cos(i*2*3.14159265/3);
            if (i %3==0)
            {
                r=r+100;
            }
        }
        int fact=1;
        for(int i=1; i<n+2; i++)
        {
            fact=fact*i;
        }

        int k=1;
        float k1,b1,k2,b2,x,y;
        int m=0;
        int zap;
        while(k!=0)
        {
            k=0;
            m=m+1;
            for(int i1=1; i1<n; i1++)
            {
                for(int i2=1; i2<n; i2++)
                {
                    if(mas[i1][i2]==0)
                    {
                        for(int i3=1; i3<n+1; i3++)
                        {
                            for(int i4=1; i4<n+1; i4++)
                            {
                                if(mas[i3][i4]==0)
                                {
                                    if((i1!=i2)||(i3!=i4))
                                    {
                                        if(((mas2[i1][1]+mas3[i1][i1]-mas2[i2][1]-mas3[i2][i2]!=0)&&(mas2[i3][1]+mas3[i3][i3]-mas2[i4][1]-mas3[i4][i4]))!=0)
                                        {
                                            x1=mas2[i1][1]+mas3[i1][i1];
                                            x2=mas2[i2][1]+mas3[i2][i2];
                                            x3=mas2[i3][1]+mas3[i3][i3];
                                            x4=mas2[i4][1]+mas3[i4][i4];
                                            y1=mas2[i1][2]+mas3[i1][i1];
                                            y2=mas2[i2][2]+mas3[i2][i2];
                                            y3=mas2[i3][2]+mas3[i3][i3];
                                            y4=mas2[i4][2]+mas3[i4][i4];

                                            k1=(y1-y2)/(x1-x2);
                                            b1=y1-k1*x1;
                                            k2=(y3-y4)/(x3-x4);
                                            b2=y3-k2*x3;
                                            if((k1-k2>0.01)||(k1-k2<-0.01))
                                            {
                                                x=(b2-b1)/(k1-k2);
                                                y=x*k1+b1;
                                                if ((((x>x1)&&(x<x2))||((x<x1)&&(x>x2)))&&(((x>x3)&&(x<x4))||((x<x3)&&(x>x4))))
                                                {
                                                    k=1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            k1=0;
            b1=0;
            k2=0;
            b2=0;
            if(k!=0)
            {

                NextSet(a, n);
                for(int i =1; i<n+1; i++)
                {
                    for(int k=1; k<n+1; k++)
                    {
                        mas5[k][i]=mas[a[k-1]][a[i-1]];
                    }
                }
                for(int i =1; i<n+1; i++)
                {
                    for(int k=1; k<n+1; k++)
                    {
                        mas[k][i]=mas5[k][i];
                    }
                }
            }
            if(m>fact)
            {
                k=0;
            }
        }
        if(m<fact)
        {
            for(int i=1; i<n+1; i++)
            {
                float mas3[100][100];
                painter.drawEllipse(mas2[i][1]+mas3[i][i],mas2[i][2]+mas3[i][i],20,20);
                for(int f=i; f<n+1; f++)
                {
                    if(mas[i][f]!=1)
                    {
                        painter.drawLine(mas2[i][1]+mas3[i][i]+10,mas2[i][2]+mas3[i][i]+10,mas2[f][1]+mas3[f][f]+10,mas2[f][2]+mas3[f][f]+10);
                    }
                }
            }
            opredelitel=10;
        }
    }



    switch (opredelitel)
    {
    case 0:
        if(opredelitel==0)
        {
            r=100;
            for (i1=2; i1!=n+2; i1++)
            {
                if (i1>k*(k+1)/2)
                {
                    k++;
                    r=r+100;
                    alpha=alpha*(k-1)/k;
                    t=t+90;
                    betta=alpha;
                }
                int betta2=180;
                int f=1;
                QString s3[800];
                int j=i1-1;
                s3[i1]=char(j%10+304);
                while(j/10>0)
                {
                    j=j/10;
                    s3[i1]=char(j%10+304)+ s3[i1];
                }
                painter.drawText(r*sin((betta+t)*3.14159/180)+mas2[i1][1],r*cos((betta+t)*3.14159/180)+mas2[i1][2],s3[i1]);
                painter.setPen(ellipseColor);
                painter.setBrush(ellipseColor);
                painter.drawEllipse(r*sin((betta+t)*3.14159/180)+mas2[i1][1],r*cos((betta+t)*3.14159/180)+mas2[i1][2],20,20);
                k2=2;
                r2=100;
                alpha2=180;
                for (f=2; f!=n+2; f++)
                {
                    if (f>k2*(k2+1)/2)
                    {
                        k2++;
                        r2=r2+100;
                        alpha2=alpha2*(k2-1)/k2;
                        t2=t2+90;
                        betta2=alpha2;
                    }

                    if (mas[i1-1][f-1]==0)
                    {
                        painter.setPen(lineColor);
                        painter.setBrush(lineColor);
                        painter.drawLine(r*sin((betta+t)*3.14159/180)+10+mas2[i1][1],r*cos((betta+t)*3.14159/180)+10+mas2[i1][2],r2*sin((betta2+t2)*3.14159/180)+10+mas2[f][1],r2*cos((betta2+t2)*3.14159/180)+10+mas2[f][2]);
                    }
                    betta2=betta2+alpha2;
                }

                t2=0;
                betta=betta+alpha;
            }
        }
        break;

    case 2:
        if(opredelitel==2)
        {
            int alpha=360/n;
            int alpha2=360/n;
            k=2;
            int r=300;
            //int betta=180;

            for (i1=2; i1!=n+2; i1++)
            {
                QString s3[800];
                int j=i1-1;
                s3[i1]=char(j%10+304);
                while(j/10>0)
                {
                    j=j/10;
                    s3[i1]=char(j%10+304)+ s3[i1];
                }
                painter.drawText(r*sin(alpha*3.14159/180),r*cos(alpha*3.14159/180),s3[i1]);
                painter.drawEllipse(r*sin(alpha*3.14159/180),r*cos(alpha*3.14159/180),20,20);
                for (int f=2; f!=n+2; f++)
                {

                    if (mas[i1-1][f-1]==0)
                    {
                        painter.setPen(lineColor);
                        painter.setBrush(lineColor);
                        painter.drawLine(r*sin(alpha*3.14159/180)+10,r*cos(alpha*3.14159/180)+10,r*sin(alpha2*3.14159/180)+10,r*cos(alpha2*3.14159/180)+10);
                    }
                    alpha2+=360/n;
                }
                alpha+=360/n;
                alpha2=360/n;
            }
        }
        break;
    case 10:
        opredelitel=0;
        break;

    default:
        ;

    }


    ifstream myfile("example.txt", std::ofstream::in);
    for(int i = 1; i<n+1; i++)
    {
        for(i1=1; i1<n+1; i1++)
        {
            myfile>>mas[i][i1];
        }
    }

    myfile.close();


}
