#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), dw(nullptr), about(nullptr)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    setWindowTitle("Sorting");
    QIcon icon("Images/main-icon.ico");
    this->setWindowIcon(icon);
    dw = new DrawWindow();
    about = new AboutAlgorithm();
    QObject::connect(dw, &DrawWindow::mainWindow, this, &MainWindow::show);
    algEff_window = new algorithms_efficiency_window();
    QObject::connect(algEff_window, &algorithms_efficiency_window::mainWindow, this, &MainWindow::show);

}

MainWindow::~MainWindow()
{
    if(dw) delete dw;
    if(algEff_window) delete algEff_window;
    delete ui;
}

void MainWindow::on_visualizationButton_clicked()
{
    this->close();
    dw->show();
}

void MainWindow::on_durationButton_clicked()
{
    this->close();
    algEff_window->show();
}

void MainWindow::on_actionAbout_sort_algorithms_triggered()
{
    about->show();
}
