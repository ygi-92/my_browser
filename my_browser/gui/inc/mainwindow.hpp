#ifndef MAINWAINDOW_H
#define MAINWAINDOW_H

#include <QtGui>
#include <QResizeEvent>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
  Q_OBJECT
  private:

  public:
  MainWindow(QMainWindow *parent = 0);
  virtual ~MainWindow();

private slots:
  void on_actionCopier_triggered(bool state);
};

#endif // MAINWAINDOW_H
