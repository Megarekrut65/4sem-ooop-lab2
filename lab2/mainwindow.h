#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Sorts/all_sorts.h"
#include <QDebug>
#include "my_graphics_view.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_visualizationButton_clicked();

private:
    Ui::MainWindow *ui;
    sd::MyGraphicsView<int>* view;

    void start();
};
#endif // MAINWINDOW_H
