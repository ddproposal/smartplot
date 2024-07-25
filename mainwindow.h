#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
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
