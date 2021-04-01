#include "drawwindow.h"
#include "ui_drawwindow.h"

DrawWindow::DrawWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawWindow), timer(nullptr),
    m_delay(100),view(nullptr), is_pause(false), is_stop(true),current_sort(0)
{
    ui->setupUi(this);
    set_sorts();
    setWindowTitle("Sorting");
    set_timer();
    set_visible_of_buttons(false);
}
void DrawWindow::set_sorts()
{
    QStringList list = {"Bubble sort","Selection sort","Merge sort","Quick sort"};
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
    sort.clear();
    m_delay = ui->delay_spinBox->value();
    sort_array();
    qreal width = 1000, height = 600;
    QString note = "delay: " + QString::number(m_delay) +
            "ms  ";
    if(view) view->clear();
    view = new sd::MyGraphicsView<int>(sort.name,note, sort.queue.current_state(), width, height);
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
    case 3: sort.quick_sort(arr);
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
QString DrawWindow::create_precent(std::size_t index)
{
    size_t percent = qreal(index)/qreal(sort.queue.size()) * 100;
    if(percent > 100) percent = 100;
    QString text = "completed: " + QString::number(percent) + "%";
    return text;
}
void DrawWindow::create_diagram(MementoSorting<int>* state, const QString& text)
{
    bool the_end = false;
    if(sort.queue.is_end()) the_end = true;
    if(state) view->create_new_scene(state,text,the_end);
    ui->graphicsView->setScene(view->get_scene());
}
void DrawWindow::draw()
{
    if(is_pause || is_stop) return;
    view->set_start_color();
    QString text = create_precent(sort.queue.get_current_index() + 2);
    auto state = sort.queue.next_state(); 
    if(state) create_diagram(state, text);
    else
    {
        is_stop = true;
        timer->stop();
    }
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
    timer->stop();
    timer->start(m_delay);
}
void DrawWindow::stop_draw()
{
    is_stop = true;
    timer->stop();
    if(view) view->clear();
    set_visible_of_buttons(false);
}
void DrawWindow::pause_draw()
{
    if(is_stop || is_pause) return;
    is_pause = true;
    timer->stop();
    if(view)
    {
        view->set_pause_color();
        view->create_new_scene(sort.queue.current_state(),"Pause");
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
    set_visible_of_buttons(true);
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

void DrawWindow::on_pushButton_prev_clicked()
{
     pause_for_buttons();
     if(sort.queue.get_current_index() <= 0) return;
     auto state = sort.queue.prev_state();
     QString text = create_precent(sort.queue.get_current_index());
     if(state) create_diagram(state, text);
}
void DrawWindow::pause_for_buttons()
{
    is_stop = false;
    is_pause = true;
    timer->stop();
    view->set_start_color();
}
void DrawWindow::on_pushButton_next_clicked()
{
     pause_for_buttons();
     if(sort.queue.get_current_index() >= sort.queue.size()) return;
     auto state = sort.queue.next_state();
     std::size_t index = sort.queue.get_current_index();
     if(sort.queue.is_end()) index++;
     QString text = create_precent(index);
     if(state) create_diagram(state, text);
}

void DrawWindow::on_pushButton_begin_clicked()
{
     pause_for_buttons();
     auto state = sort.queue.to_begin();
     QString text = create_precent(sort.queue.get_current_index());
     if(state) create_diagram(state, text);
}

void DrawWindow::on_pushButton_end_clicked()
{
     pause_for_buttons();
     auto state = sort.queue.to_end();
     QString text = create_precent(sort.queue.get_current_index() + 1);
     if(state) create_diagram(state, text);
}
void DrawWindow::set_visible_of_buttons(bool visible)
{
    ui->pushButton_begin->setEnabled(visible);
    ui->pushButton_end->setEnabled(visible);
    ui->pushButton_prev->setEnabled(visible);
    ui->pushButton_next->setEnabled(visible);
}


