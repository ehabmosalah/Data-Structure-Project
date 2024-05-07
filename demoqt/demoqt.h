#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_demoqt.h"

class demoqt : public QMainWindow
{
    Q_OBJECT

public:
    demoqt(QWidget *parent = nullptr);
    ~demoqt();

private:
    Ui::demoqtClass ui;
};
