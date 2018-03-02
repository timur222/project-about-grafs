//создает класс GRAPH
#ifndef GRAPH_H
#define CRAPH_H
#include <QWidget>

class Graph : public QWidget
{
    Q_OBJECT

public:
    Graph(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event) ;

};
#endif // GRAPH_H
