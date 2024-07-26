#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "SARibbon.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public SARibbonMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void AddAction();
    void AddMenu();


private:
    Ui::MainWindow *ui;
    QAction* actionDB;
};

#endif // MAINWINDOW_H
