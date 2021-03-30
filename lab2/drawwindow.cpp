#include "drawwindow.h"
#include "ui_drawwindow.h"

DrawWindow::DrawWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawWindow), timer(nullptr), index(0),
    m_delay(100),view(nullptr), is_pause(false), is_stop(true),current_sort(0)
{
    ui->setupUi(this);
    set_sorts();
    setWindowTitle("Sorting");
    set_timer();
}
void DrawWindow::set_sorts()
{
    QStringList list = {"Bubble sort","Selection sort","Merge sort"};
    for(qsizetype i = 0; i < list.size();i++)
        ui->sorts_listWidget->addItem(list[i]);
}
void DrawWindow::set_timer()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DrawWindow::draw);
}
void DrawWindow::set_view()
{
    index = 0;
    sort.clear();
    m_delay = ui->delay_spinBox->value();
    sort_array();
    qreal width = 1000, height = 600;
    QString note = "delay: " + QString::number(m_delay) +
            "ms  ";
    view = new sd::MyGraphicsView<int>(sort.name,note, sort.queue[0], width, height);
    ui->graphicsView->setScene(view->get_scene());
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setBaseSize(width,height);
    ui->graphicsView->setMinimumSize(width,height);
    ui->graphicsView->setMaximumSize(width,height);
}
void DrawWindow::sort_array()
{
    std::vector<int> arr = get_array();

    switch (current_sort)
    {
    case 0: sort.bubble_sort(arr);
    break;
    case 1: sort.selection_sort(arr);
    break;
    case 2: sort.merge_sort(arr);
    break;
    case 3:
    break;
    case 4:
    break;
    case 5:
    break;
    case 6:
    break;
    case 7:
    break;
    case 8:
    break;
    case 9:
    break;
    }
}
void DrawWindow::draw()
{
    if(is_pause || is_stop) return;
    view->start_color();
    bool the_end = false;
    size_t percent = qreal(index + 1)/qreal(sort.queue.size()) * 100;
    QString text = "completed: " + QString::number(percent) + "%";
    if(index == sort.queue.size() - 1) the_end = true;
    if(index < sort.queue.size())
        view->create_new_scene(sort.queue[index++],text,the_end);
    else
    {
        is_stop = true;
        timer->stop();
    }
    ui->graphicsView->setScene(view->get_scene());
}
void DrawWindow::start_draw()
{
    if(is_stop)
    {
        set_view();
        is_pause = true;
    }
    is_stop = false;
    if(is_pause) is_pause = false;
    else return;
    timer->start(m_delay);
}
void DrawWindow::stop_draw()
{
    is_stop = true;
    timer->stop();
    if(view) view->clear();
}
void DrawWindow::pause_draw()
{
    if(is_stop || is_pause) return;
    is_pause = true;
    timer->stop();
    if(view)
    {
        view->pause_color();
        view->create_new_scene(sort.queue[index],"Pause");
    }
}
DrawWindow::~DrawWindow()
{
    if(view) delete view;
    if(timer) delete timer;
    delete ui;
}

void DrawWindow::on_add_pushButton_clicked()
{
    stop_draw();
    ui->values_listWidget->addItem(ui->newnum_spinBox->text());
    ui->count_spinBox->setValue(ui->values_listWidget->count());
}

void DrawWindow::on_remove_pushButton_clicked()
{
    stop_draw();
    qDeleteAll(ui->values_listWidget->selectedItems());
    ui->count_spinBox->setValue(ui->values_listWidget->count());
}
std::vector<int> DrawWindow::get_array()
{
    std::vector<int> arr;
    for(int i = 0; i < ui->values_listWidget->count();i++)
        arr.push_back(ui->values_listWidget->item(i)->text().toInt());
    return arr;
}

void DrawWindow::on_random_pushButton_clicked()
{
    stop_draw();
    ui->values_listWidget->clear();
    for(int i = 0; i < ui->count_spinBox->text().toInt(); i++)
    {
         ui->values_listWidget->addItem(QString::number(QRandomGenerator::global()->generate()%32000));
    }
}

void DrawWindow::on_inorder_pushButton_clicked()
{
    stop_draw();
    ui->values_listWidget->clear();
    for(int i = 0; i < ui->count_spinBox->text().toInt(); i++)
    {
        ui->values_listWidget->addItem(QString::number(i));
    }
    for(int i = 0; i < ui->count_spinBox->text().toInt(); i++)
    {
        auto move_item = ui->values_listWidget->takeItem(i);
        ui->values_listWidget->insertItem(QRandomGenerator::global()->generate()%ui->count_spinBox->text().toInt(), move_item);
    }
}

void DrawWindow::on_start_pushButton_clicked()
{
    start_draw();
}

void DrawWindow::on_pause_Button_clicked()
{
    pause_draw();
}

void DrawWindow::on_stop_pushButton_clicked()
{
    stop_draw();
}

void DrawWindow::on_sorts_listWidget_currentRowChanged(int currentRow)
{
    current_sort = currentRow;
    stop_draw();
}
