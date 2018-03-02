#include <QApplication>

#include "analogclock.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   Graph graph;

   graph.show();

    return app.exec();
}
