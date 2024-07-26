#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    SARibbonMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setWindowTitle("诉 讼");
    this->setWindowIcon(QIcon(":/qrc/SA.svg"));


//    ui->toolBar->setIconSize(QSize(50,60));
//    AddAction();

//    ui->menubar->setFixedSize(100,40);
//    AddMenu();

        SARibbonBar* bar = ribbonBar();
        bar->applicationButton()->setText(tr("  File  "));
        SARibbonCategory* mainCate = bar->addCategoryPage(tr("DEV"));
        SARibbonPannel* pannel     = mainCate->addPannel(tr("actions"));
        pannel->addAction(tr("action1"), QIcon(":/qrc/action.svg"), QToolButton::InstantPopup);
        pannel->addAction(tr("action2"), QIcon(":/qrc/customize0.svg"), QToolButton::InstantPopup);

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
    //QMenu* filemenu = ui->menubar->addMenu("文件");
//    filemenu->setFixedSize(70,50);

//    QAction* newfile = filemenu->addAction(QIcon(":/qrc/play.svg"),"新建");
//    QAction* savefile = filemenu->addAction(QIcon(":/qrc/play.svg"),"保存");


}
