#include "algorithms_efficiency_window.h"
#include "ui_algorithms_efficiency_window.h"

algorithms_efficiency_window::algorithms_efficiency_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::algorithms_efficiency_window)
{
    ui->setupUi(this);
}

algorithms_efficiency_window::~algorithms_efficiency_window()
{
    delete ui;
}
