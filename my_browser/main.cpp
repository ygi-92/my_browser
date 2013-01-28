#include <iostream>
#include "mainwindow.hpp"
#include <QtOpenGL>

int main(int argc, char** argv)
{

  QApplication app(argc, argv);
  MainWindow win;

  win.show();
  return app.exec();

}
