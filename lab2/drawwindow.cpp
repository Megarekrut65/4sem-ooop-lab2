#include "drawwindow.h"
#include "ui_drawwindow.h"

DrawWindow::DrawWindow( sc::SortClass<int>& sort,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawWindow),sort(sort)
{
    ui->setupUi(this);
    qreal width = 800, height = 600;
    index = 0;
    setBaseSize(width,height);
    setMinimumSize(width,height);
    setMaximumSize(width,height);
    timer = new QTimer(this);
    view = new sd::MyGraphicsView<int>(sort.name, sort.queue[0]);
    view->show();
    connect(timer, &QTimer::timeout, this, &DrawWindow::draw);
    timer->start(100);
}
void DrawWindow::draw()
{
    if(index < sort.queue.size())
        view->create_new_scene(sort.queue[index++]);
    else timer->stop();
}
DrawWindow::~DrawWindow()
{
    delete ui;
}
