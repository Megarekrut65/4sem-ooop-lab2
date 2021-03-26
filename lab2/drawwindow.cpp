#include "drawwindow.h"
#include "ui_drawwindow.h"

DrawWindow::DrawWindow( sc::SortClass<int>& sort, size_t m_delay,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawWindow), timer(nullptr),sort(sort), index(0),m_delay(m_delay > 0?m_delay:1),view(nullptr)
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
    qreal width = 1200, height = 600;
    QString note = "delay: " + QString::number(m_delay) +
            "ms";
    view = new sd::MyGraphicsView<int>(sort.name,note, sort.queue[0], width, height);
    ui->graphicsView->setScene(view->get_scene());
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    //setBaseSize(width,height);
    //setMinimumSize(width,height);
    //setMaximumSize(width,height);
    //ui->graphicsView->setBaseSize(width,height);
    //ui->graphicsView->setMinimumSize(width,height);
    //ui->graphicsView->setMaximumSize(width,height);
}

void DrawWindow::draw()
{
    bool the_end = false;
    size_t percent = qreal(index + 1)/qreal(sort.queue.size()) * 100;
    QString text = "completed: " + QString::number(percent) + "%";
    if(index == sort.queue.size() - 1) the_end = true;
    if(index < sort.queue.size())
        view->create_new_scene(sort.queue[index++],text,the_end);
    else timer->stop();
    ui->graphicsView->setScene(view->get_scene());
}
DrawWindow::~DrawWindow()
{
    if(view) delete view;
    if(timer) delete timer;
    delete ui;
}

void DrawWindow::on_add_pushButton_clicked()
{
    ui->values_listWidget->addItem(ui->newnum_spinBox->text());
    ui->count_spinBox->setValue(ui->values_listWidget->count());
}

void DrawWindow::on_remove_pushButton_clicked()
{
    qDeleteAll(ui->values_listWidget->selectedItems());
    ui->count_spinBox->setValue(ui->values_listWidget->count());
}
