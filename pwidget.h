#ifndef PWIDGET_H
#define PWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <iostream>
#include <QApplication>
#include <QDesktopWidget>

#include "filedevice.h"


#include "showplot.h"



QT_BEGIN_NAMESPACE
namespace Ui { class PWidget; }
QT_END_NAMESPACE

class PWidget : public QWidget
{
    Q_OBJECT

public:
    PWidget(QWidget *parent = nullptr);
    ~PWidget();

private slots:
    void on_pushButton_clicked();


private:
    Ui::PWidget *ui;
    FileDevice* file;
    std::map<std::string, std::vector<std::vector<double>>> opt;
    std::map<std::string, std::vector<std::vector<double>>> sm;
    std::map<std::string, std::vector<std::vector<double>>> vel;
    std::map<std::string, std::vector<std::vector<double>>> acc;
    Dof_exDof df;
    void InitFileDevice(string& path);
};
#endif // PWIDGET_H
