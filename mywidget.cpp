#include "mywidget.h"
#include <QDesktopWidget>
#include <QSpacerItem>
#include <QGridLayout>


mywidget::mywidget(QWidget *parent) : QWidget(parent)
{
    //设置主窗体
    this->setWindowTitle("一个案例");
    this->setMinimumSize(900,600);
    this->move((QApplication::desktop()->width()-this->width())/2,(QApplication::desktop()->height()-this->height())/2);

    QHBoxLayout* mainlayout = new QHBoxLayout(this);

    //两个窗体水平布局
    leftwidget = new QWidget(this);
    rightwidget = new QWidget(this);
    leftwidget->setObjectName("lfwidget");
    leftwidget->setStyleSheet(QString("QWidget#%1{background-color:rgb(100,197,255);}").arg(leftwidget->objectName()));
    rightwidget->setObjectName("rightwidget");
    rightwidget->setStyleSheet(QString("QWidget#%1{background-color:rgb(255,200,200);}").arg(rightwidget->objectName()));

    initleft();
    initright();

    mainlayout->addWidget(leftwidget);
    mainlayout->addWidget(rightwidget);
    mainlayout->setStretchFactor(leftwidget,2);
    mainlayout->setStretchFactor(rightwidget,1);


}

void mywidget::initleft()
{
    QVBoxLayout* leftlayout = new QVBoxLayout(leftwidget);

    lwidget = new PWidget(this);
    lwidget->setStyleSheet("background-color: rgb(240,255,255);");

    lslider = new QSlider(this);
    lslider->setOrientation(Qt::Horizontal);
    lslider->setRange(0,50);
    lslider->setFixedSize(400,10);


    leftlayout->addWidget(lwidget,1,Qt::AlignHCenter);
    leftlayout->addWidget(lslider,2,Qt::AlignHCenter);

    QSpacerItem* horspace = new QSpacerItem(5,1,QSizePolicy::Fixed,QSizePolicy::Expanding);
    leftlayout->addItem(horspace);
}

void mywidget::initright()
{
    QVBoxLayout* righlayout = new QVBoxLayout(rightwidget);

    //1
    QGroupBox* basegroup = new QGroupBox("基础设置",rightwidget);

    QGridLayout* gridlay1 = new QGridLayout(basegroup);
    line1 = new QLabel("first",this);
    spin1 = new QSpinBox(this);

    gridlay1->addWidget(line1,0,0);
    gridlay1->addWidget(spin1,0,1);

    //2
    QGroupBox* colorgroup = new QGroupBox("颜色设置",rightwidget);

    QGridLayout* gridlay2 = new QGridLayout(colorgroup);
    line2 = new QLabel("颜色",this);
    spin2 = new QSpinBox(this);

    gridlay2->addWidget(line2,0,0,Qt::AlignRight);
    gridlay2->addWidget(spin2,0,1);
    righlayout->addWidget(basegroup);
    righlayout->addWidget(colorgroup);


}
