#include "algorithmic_efficiency_window.h"
#include "ui_algorithmic_efficiency_window.h"

algorithmic_efficiency_window::algorithmic_efficiency_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::algorithmic_efficiency_window)
{
    ui->setupUi(this);
}

algorithmic_efficiency_window::~algorithmic_efficiency_window()
{
    delete ui;
}
