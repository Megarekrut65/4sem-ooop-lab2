#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "drawwindow.h"
#include "algorithms_efficiency_window.h"

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

    void on_durationButton_clicked();

private:
    Ui::MainWindow *ui;
    DrawWindow* dw;
    algorithms_efficiency_window* algEff_window;

    void startVisualization();
    void startDuration();
};
#endif // MAINWINDOW_H
