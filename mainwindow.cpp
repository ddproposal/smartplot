#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("诉 讼");
    this->setWindowIcon(QIcon(":/qrc/pause.svg"));


    ui->toolBar->setIconSize(QSize(50,60));
    AddAction();

    ui->menubar->setFixedSize(100,40);
    AddMenu();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddAction()
{
    actionDB = new QAction(this);
    actionDB->setIcon(QIcon(":/qrc/play.svg"));
    actionDB->setText("数据库开");
    actionDB->setCheckable(true);

    ui->toolBar->addAction(actionDB);
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);  //icon在上，文字在下

    connect(actionDB,&QAction::triggered,this,[=](bool checked){

        if(!checked)
        {
            actionDB->setText("数据库开");
            actionDB->setIcon(QIcon(":/qrc/play.svg"));
        }
        else{
            actionDB->setText("数据库关");
            actionDB->setIcon(QIcon(":/qrc/pause.svg"));
        }
    });

};
void MainWindow::AddMenu()
{
    QMenu* filemenu = ui->menubar->addMenu("文件");
    filemenu->setFixedSize(70,50);

    QAction* newfile = filemenu->addAction(QIcon(":/qrc/play.svg"),"新建");
    QAction* savefile = filemenu->addAction(QIcon(":/qrc/play.svg"),"保存");


}
