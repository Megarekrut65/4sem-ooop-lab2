#include "drawwindow.h"
#include "ui_drawwindow.h"
#include <QDebug>
DrawWindow::DrawWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawWindow), timer(nullptr),
    m_delay(100),view(nullptr), is_pause(false), is_stop(true),width(1000), height(600), current_sort(0)
{
    ui->setupUi(this);
    set_sorts();
    setWindowTitle("Sorting visualization");
    QIcon icon(":/icons/Images/diagram-icon.ico");
    this->setWindowIcon(icon);
    set_graphics_view();
    set_timer();
    set_visible_of_buttons(false);
    check_log_file();

    keyF5 = new QShortcut(this);
    keyF5->setKey(QKeySequence::fromString("F5"));

    keyShiftF5 = new QShortcut(this);
    keyShiftF5->setKey(QKeySequence::fromString("Shift+F5"));

    keyCtrlP = new QShortcut(this);
    keyCtrlP->setKey(QKeySequence::fromString("Ctrl+P"));

    keyPrev = new QShortcut(this);
    keyPrev->setKey(QKeySequence::fromString("Left"));

    keyNext = new QShortcut(this);
    keyNext->setKey(QKeySequence::fromString("Right"));

    connect(keyF5, SIGNAL(activated()), this, SLOT(slotShortcutF5()));
    connect(keyShiftF5, SIGNAL(activated()), this, SLOT(slotShortcutShiftF5()));
    connect(keyCtrlP, SIGNAL(activated()), this, SLOT(slotShortcutCtrlP()));
    connect(keyPrev, SIGNAL(activated()), this, SLOT(slotShortcutPrev()));
    connect(keyNext, SIGNAL(activated()), this, SLOT(slotShortcutNext()));
}
DrawWindow::~DrawWindow()
{
    if(view) delete view;
    if(timer) delete timer;
    delete keyF5;
    delete keyShiftF5;
    delete keyCtrlP;
    delete ui;
}
void DrawWindow::set_sorts()
{
    QStringList list = {"Bubble sort","Selection sort","Merge sort","Quick sort", "Gnome sort", "Cocktail shaker sort",
                       "Odd-even sort", "Comb sort"};
    for(qsizetype i = 0; i < list.size();i++)
        ui->sorts_listWidget->addItem(list[i]);
    select_sort_in_list(0);
}
void DrawWindow::set_timer()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DrawWindow::draw);
}
void DrawWindow::set_graphics_view()
{
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setBaseSize(width,height);
    ui->graphicsView->setMinimumSize(width,height);
    ui->graphicsView->setMaximumSize(width,height);
}
void DrawWindow::set_view()
{
    sort.clear();
    m_delay = ui->delay_spinBox->value();
    sort_array();
    QString note = "delay: " + QString::number(m_delay) +
            "ms  ";
    if(view) view->clear();
    view = new sd::MyGraphicsView<int>(sort.name,note, sort.queue.current_state(), width, height);
    ui->graphicsView->setScene(view->get_scene());  
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
    case 4: sort.gnome_sort(arr);
    break;
    case 5: sort.cocktail_shaker_sort(arr);
    break;
    case 6: sort.odd_even_sort(arr);
    break;
    case 7: sort.comb_sort(arr);
    break;
    }
    append_to_file();
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
    create_static_diagram(get_array());
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
        for(int j = 0; j < ui->count_spinBox->text().toInt(); j++)
        {
            auto move_item = ui->values_listWidget->takeItem(j);
            ui->values_listWidget->insertItem(QRandomGenerator::global()->generate()%ui->count_spinBox->text().toInt(), move_item);
        }
    }
    create_static_diagram(get_array());
}
void DrawWindow::create_static_diagram(const std::vector<int>& arr)
{
    if(arr.size() == 0) return;
    auto state = new MementoSorting<int>(arr);
    if(view) view->clear();
    view = new sd::MyGraphicsView<int>("","", state, width, height);
    ui->graphicsView->setScene(view->get_scene());
    delete state;
}
void DrawWindow::on_almostsorted_pushButton_clicked()
{
    stop_draw();
    ui->values_listWidget->clear();
    int size = ui->count_spinBox->text().toInt();
    for(int i = 0; i < size; i++)
    {
        ui->values_listWidget->addItem(QString::number(i));
    }
    int index = (8*size)/10;//80% of item will be inorder
    for(int j = index; j < size; j++)
    {
        auto move_item = ui->values_listWidget->takeItem(j);
        ui->values_listWidget->insertItem(QRandomGenerator::global()->generate()%(size - index) + index, move_item);
    }
    create_static_diagram(get_array());
}

void DrawWindow::on_almostsorted_rev_pushButton_clicked()
{
    stop_draw();
    ui->values_listWidget->clear();
    int size = ui->count_spinBox->text().toInt();
    for(int i = size - 1; i >= 0; i--)
    {
        ui->values_listWidget->addItem(QString::number(i));
    }
    int index = (8*size)/10;//80% of item will be preorder
    for(int j = index; j < size; j++)
    {
        auto move_item = ui->values_listWidget->takeItem(j);
        ui->values_listWidget->insertItem(QRandomGenerator::global()->generate()%(size - index) + index, move_item);
    }
    create_static_diagram(get_array());
}

void DrawWindow::slotShortcutF5()
{
    start_draw();
    set_visible_of_buttons(true);
}

void DrawWindow::slotShortcutShiftF5()
{
    stop_draw();
}

void DrawWindow::slotShortcutCtrlP()
{
    pause_draw();
}

void DrawWindow::slotShortcutPrev()
{
    pause_for_buttons();
    if(sort.queue.get_current_index() <= 0) return;
    auto state = sort.queue.prev_state();
    QString text = create_precent(sort.queue.get_current_index());
    if(state) create_diagram(state, text);
}

void DrawWindow::slotShortcutNext()
{
    pause_for_buttons();
    if(sort.queue.get_current_index() >= sort.queue.size()) return;
    auto state = sort.queue.next_state();
    std::size_t index = sort.queue.get_current_index();
    if(sort.queue.is_end()) index++;
    QString text = create_precent(index);
    if(state) create_diagram(state, text);
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
void DrawWindow::select_sort_in_list(std::size_t index_of_sort)
{
    for(int i = 0; i < ui->sorts_listWidget->count();i++)
    {
        auto item = ui->sorts_listWidget->item(i);
        item->setBackground(QColor("white"));
        item->setForeground(QColor("black"));
    }
    auto item = ui->sorts_listWidget->item(index_of_sort);
    item->setBackground(QColor("gray"));
    item->setForeground(QColor("white"));
}
void DrawWindow::on_sorts_listWidget_currentRowChanged(int currentRow)
{
    current_sort = currentRow;
    select_sort_in_list(currentRow);
    stop_draw();
    create_static_diagram(get_array());
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

void DrawWindow::on_back_pushButton_clicked()
{
    emit mainWindow();
    this->close();
}
void DrawWindow::append_to_file()
{
    QFile file(FilePath::sorting_diagram_log_file.c_str());
    if (file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QDateTime now = QDateTime::currentDateTime();
        file.write((now.toString("-[yyyy-MM-dd, HH:mm:ss]")+ " ").toStdString().c_str());
        std::vector<int> arr = sort.queue.current_state()->array;
        std::vector<int>& sorted_arr = sort.queue.last_state()->array;
        file.write((sort.name.toStdString() + ", array(" + std::to_string(arr.size())+"): {").c_str());
        file.write((array_to_string(arr)+ "}, ").c_str());
        file.write(("sorted array(" + std::to_string(sorted_arr.size())+"): {").c_str());
        file.write((array_to_string(sorted_arr)+ "};\r\n").c_str());
    }
    file.close();
}
void DrawWindow::check_log_file()
{
    std::size_t sizef = FilePath::count_size(FilePath::sorting_diagram_log_file);
    if(sizef > 1024*1024)
    {
        FilePath::clear_file(FilePath::sorting_diagram_log_file);
    }
}
