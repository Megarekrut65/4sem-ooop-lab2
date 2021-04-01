#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), dw(nullptr)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    setWindowTitle("Sorting");
    QIcon icon("Images/main-icon.ico");
    this->setWindowIcon(icon);
}

MainWindow::~MainWindow()
{
    if(dw) delete dw;
    delete ui;
}
void MainWindow::startVisualization()
{
    std::vector<int> arr = {1,7, 9, 12, 4, 8, 20, 55, 32, 48, 24, 19, 51, 39, 44, 10, 19, 22, 42,3,10,12,50,9,49,29,30,17};
    sorts::quick_sort(arr);
    qDebug(sorts::array_to_string(arr).c_str());
    dw = new DrawWindow();
    dw->show();
    this->hide();
}

void MainWindow::on_visualizationButton_clicked()
{
    ui->verticalWidget->setEnabled(false);
    ui->verticalWidget->setVisible(false);
    startVisualization();
    /*ui->graphicsView->setEnabled(true);
    ui->graphicsView->setScene(view->get_scene());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->fitInView( ui->centralwidget->rect(), Qt::KeepAspectRatio );*/
}
