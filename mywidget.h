#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QGroupBox>

#include "pwidget.h"

class mywidget : public QWidget
{
    Q_OBJECT
public:
    explicit mywidget(QWidget *parent = nullptr);

public:

    void initleft();
    void initright();

private:
    QWidget* leftwidget;
    QWidget* rightwidget;

    //left
    PWidget* lwidget;
    QSlider* lslider;

    //right
    QLabel* line1;
    QSpinBox*  spin1;

    QLabel* line2;
    QSpinBox*  spin2;


};

#endif // MYWIDGET_H
