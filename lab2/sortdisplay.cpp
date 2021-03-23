#include "sortdisplay.h"
#include "ui_sortdisplay.h"

SortDisplay::SortDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDisplay)
{
    ui->setupUi(this);
}

SortDisplay::~SortDisplay()
{
    delete ui;
}
template<typename T>
QProgressBar* SortDisplay::create_line(T value, size_t height, size_t width)
{
    QProgressBar* obj = new QProgressBar();
    obj->setOrientation(Qt::Orientation::Vertical);
    obj->setTextVisible(false);
    obj->setFixedHeight(height);
    obj->setFixedWidth(width);
    return obj;
}
