#include <QDebug>
#include "mainwindow.hpp"

MainWindow::MainWindow(QMainWindow* parent) : QMainWindow(parent)
{
  setupUi(this);
  connect(actionCopier, SIGNAL(triggered(bool)), this, SLOT(on_actionCopier_triggered(bool)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_actionCopier_triggered(bool state) {

  qDebug() << "on a cliquer sur copier " << state;
}
