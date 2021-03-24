#include "drawwindow.h"
#include "ui_drawwindow.h"

DrawWindow::DrawWindow( sc::SortClass<int>& sort, size_t m_delay,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawWindow), timer(nullptr),sort(sort), index(0),m_delay(m_delay),view(nullptr)
{
    ui->setupUi(this);
    setWindowTitle(sort.name);
    if(sort.queue.size() > 0)
    {
        set_view();
        set_timer();
    }
    else this->close();
}
void DrawWindow::set_timer()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DrawWindow::draw);
    timer->start(m_delay);
}
void DrawWindow::set_view()
{
    qreal width = 1000, height = 600;
    view = new sd::MyGraphicsView<int>(sort.name, sort.queue[0], width, height);
    ui->graphicsView->setScene(view->get_scene());
    setBaseSize(width,height);
    setMinimumSize(width,height);
    setMaximumSize(width,height);
    ui->graphicsView->setBaseSize(width,height);
    ui->graphicsView->setMinimumSize(width,height);
    ui->graphicsView->setMaximumSize(width,height);
}
void DrawWindow::draw()
{
    bool the_end = false;
    if(index == sort.queue.size() - 1) the_end = true;
    if(index < sort.queue.size())
        view->create_new_scene(sort.queue[index++],the_end);
    else timer->stop();
    ui->graphicsView->setScene(view->get_scene());
}
DrawWindow::~DrawWindow()
{
    if(view) delete view;
    if(timer) delete timer;
    delete ui;
}
