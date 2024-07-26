#include "pwidget.h"
#include "ui_pwidget.h"

PWidget::PWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PWidget)
{
    ui->setupUi(this);


    //设置窗口样式
    this->setWindowTitle("绘画曲线小工具");
    this->setMinimumSize(507,220);
    this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);

    //初始化plot
    string path = "/home/td/Documents/";
    //InitFileDevice(path);
}

PWidget::~PWidget()
{
    delete ui;
}


void PWidget::on_pushButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(nullptr, QObject::tr("Open Directory"),
                                                  QDir::homePath());
    std::cout<<dir.toStdString()<<std::endl;
    ui->lineEdit->setText(dir);
}

void PWidget::InitFileDevice(string& filepath)
{
    file->readPlotData(filepath+"plotdataopt.txt", filepath+"plotdatasm.txt", opt, sm, vel, acc,df);
}
