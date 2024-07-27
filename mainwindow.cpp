#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QAction>
#include <QDesktopWidget>
#include <QMessageBox>

#include "SARibbon.h"

MainWindow::MainWindow(QWidget *parent) :
    SARibbonMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //窗体位置及图标
    this->setWindowIcon(QIcon(":/qrc/SA.svg"));
    resize(QApplication::desktop()->width()/2,QApplication::desktop()->height()/2);
    move(QApplication::desktop()->width()/4,QApplication::desktop()->height()/4);


    ui->toolBar->setIconSize(QSize(50,60));
    AddAction();

    //菜单栏
    InitSARibbon();


//    ui->menubar->setFixedSize(100,40);
//    AddMenu();


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

    connect(actionDB,&QAction::triggered,this,&MainWindow::actionDB_triggered);

};
void MainWindow::AddMenu()
{
    //QMenu* filemenu = ui->menubar->addMenu("文件");
//    filemenu->setFixedSize(70,50);

//    QAction* newfile = filemenu->addAction(QIcon(":/qrc/play.svg"),"新建");
//    QAction* savefile = filemenu->addAction(QIcon(":/qrc/play.svg"),"保存");


}

void MainWindow::InitSARibbon()
{
    SARibbonBar* bar = ribbonBar();
    bar->setFont(QFont("微软雅黑", 10));
    bar->applicationButton()->setVisible(false);

//    SARibbonBar::RibbonStyles ribbonStyle = static_cast< SARibbonBar::RibbonStyles >(0x0012);
//    ribbonBar()->setRibbonStyle(ribbonStyle);
    ribbonBar()->setRibbonStyle(SARibbonBar::RibbonStyleCompactTwoRow);

    //设置第一个Category
    SARibbonCategory* mainCate = bar->addCategoryPage(tr("主页"));
    SARibbonCategory* secondCate = bar->addCategoryPage(tr("视图"));

    //  第一种添加pannel方法
    SARibbonPannel* pannel     = new SARibbonPannel("模态编辑");
    pannel->setFont(QFont("微软雅黑", 12));
    mainCate->addPannel(pannel);

    // 不方便用action,弃用
//    pannel->addAction(tr("导入模型"), QIcon(":/qrc/action.svg"), QToolButton::InstantPopup);
//    pannel->addAction(tr("设置"), QIcon(":/qrc/customize0.svg"), QToolButton::InstantPopup,SARibbonPannelItem::Medium);
//    pannel->addAction(tr("文件"), QIcon(":/qrc/folder-star.svg"), QToolButton::DelayedPopup,SARibbonPannelItem::Medium);

    //带menu的action
    QAction* action_import  = new QAction(QIcon(":/qrc/action.svg"),"导入模型");
    SARibbonMenu* menu = new SARibbonMenu(pannel);
    QAction* action = nullptr;
    {
        for (int i = 0 ; i < 5 ; i++) {
            action = menu->addAction(QIcon(":/qrc/test1.svg"),(QString("action-%1").arg(i+1)));

        }
    }
    action_import->setMenu(menu);
    pannel->addAction(action_import,QToolButton::InstantPopup,SARibbonPannelItem::Large);

    //普通acton
    QAction* action_setting = new QAction(QIcon(":/qrc/customize0.svg"),"设置");
    QAction* action_file    = new QAction(QIcon(":/qrc/folder-star.svg"),"文件");
    pannel->addAction(action_setting,QToolButton::InstantPopup,SARibbonPannelItem::Medium);
    pannel->addAction(action_file,QToolButton::InstantPopup,SARibbonPannelItem::Medium);



    //增加action响应connet
    connect(action_import,&QAction::triggered,[=](bool checked){
        QMessageBox::information(this,"导入模型",QString("是否导入:%1").arg(checked));
        //actionDB->setText("稍等");

    });
    connect(action_import,&QAction::triggered,actionDB,&QAction::triggered);

    // 第二种添加pannel方法
    SARibbonPannel* pannel1     = secondCate->addPannel(tr("按键"));
    pannel1->setFont(QFont("微软雅黑", 12));
    //SARibbonPannel* pannel2     = secondCate->addPannel(tr("按键"));

    pannel1->addAction(tr("设置"), QIcon(":/qrc/customize0.svg"), QToolButton::InstantPopup,SARibbonPannelItem::Small);
    pannel1->addAction(tr("导入模型"), QIcon(":/qrc/action.svg"), QToolButton::MenuButtonPopup,SARibbonPannelItem::Small);
    pannel1->addAction(tr("文件"), QIcon(":/qrc/folder-star.svg"), QToolButton::DelayedPopup,SARibbonPannelItem::Small);


}

void MainWindow::actionDB_triggered(bool checked)
{std::cout<<checked<<std::endl;
    if(!checked)
    {
        actionDB->setText("数据库开");
        actionDB->setIcon(QIcon(":/qrc/play.svg"));
    }
    else{
        actionDB->setText("数据库关");
        actionDB->setIcon(QIcon(":/qrc/pause.svg"));
    }
}
