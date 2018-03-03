#include <QtWidgets>
#include <iostream>
#include "analogclock.h"
using namespace std;
Graph::Graph(QWidget *parent)
    : QWidget(parent)
{
    this->resize(800, 800);// размер окна
    //setFixedSize(800,800);//фиксируем размер окна
}

void Graph::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);// функция,которая отглаживает фигуру

    //int side = qMin(width(), height());// от этого зависит функция,которая изменяет размеры графа
    painter.translate(width() / 2, height() / 2);
    QColor lineColor(0, 12, 127, 232); //изменяем цвет рёбер
    QColor ellipseColor(127, 200, 56);//изменяем цвет вершин
    int n=20;
    int Vitalich2=0;
    int Vitalich=0;
    int k2;
    int r2;
    int k=0;
    int i1;
    int v,v1;
    int mas[110][110];
    for(v=1;v!=n;v++)
    {
        for(v1=1;v1!=n;v1++)
        {
            mas[v][v1]=1;
        }
    }
    painter.setPen(ellipseColor);
    painter.setBrush(ellipseColor);
    painter.rotate(90.0);
    int alpha=180;
    int alpha2=180;
    k=2;
    int r=30;
    int betta=180;
    for (i1=2; i1!=n+2; i1++)
    {
        if (i1>k*(k+1)/2)
        {
            k++;//поднимаемся на один уровень выше
            r=r+100;
              alpha=alpha*(k-1)/k;
          Vitalich=Vitalich+90;
        betta=alpha;
        }

        painter.drawEllipse(r*sin((betta+Vitalich)*2*3.14159/360),r*cos((betta+Vitalich)*2*3.14159/360),20,20);

        int f=2;
        k2=2;
        r2=30;
        alpha2=180;
        int betta2=180;
        for (f=2; f!=n+2; f++)
        {
            if (f>k2*(k2+1)/2)
               {
                   k2++;//поднимаемся на один уровень выше
                   r2=r2+100;
                     alpha2=alpha2*(k2-1)/k2;
                     Vitalich2=Vitalich2+90;
                     betta2=alpha2;
                     }
               if (mas[i1-1][f]=1)
               {
                   painter.drawLine(r*sin((betta+Vitalich)*2*3.14159/360)+10,r*cos((betta+Vitalich)*2*3.14159/360)+10,r2*sin((betta2+Vitalich2)*2*3.14159/360)+10,r2*cos((betta2+Vitalich2)*2*3.14159/360)+10);
               }
                betta2=betta2+alpha2;
       }
        Vitalich2=0;
        betta=betta+alpha;
    }

}
