#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtTrucoApplication.h"

class QtTrucoApplication : public QWidget
{
    Q_OBJECT

public:
    QtTrucoApplication(QWidget *parent = nullptr);
    ~QtTrucoApplication();

private:
    Ui::QtTrucoApplicationClass ui;
};
