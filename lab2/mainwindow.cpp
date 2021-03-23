#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start();
    auto diagram = new sd::DiagramBuilder<int>(100,100);
    diagram->append_column(50);
    diagram->append_column(80);
    diagram->append_column(20);
    diagram->append_column(110);
    diagram->append_column(5);
    diagram->append_column(130);
    auto graphicsView = new QGraphicsView(diagram->get_scene());
    graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::start()
{
    std::vector<int> arr = {5,3,1,9,8,1};
    sorts::merge_sort(arr);
    qDebug(sorts::array_to_string(arr).c_str());
}
