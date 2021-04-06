#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "drawwindow.h"
#include "algorithms_efficiency_window.h"
#include "aboutalgorithm.h"

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
    /*!
    *   \brief Slot of 'Sort Visualization' button
    */
    void on_visualizationButton_clicked();
    /*!
    *   \brief Slot of 'Sort duration' button
    */
    void on_durationButton_clicked();
    /*!
    *   \brief Slot of 'About sort algorithm' menu item
    */
    void on_actionAbout_sort_algorithms_triggered();

private:
    Ui::MainWindow *ui;/*!< Pointer to ui */
    DrawWindow* dw;/*!< Pointer to sort visualization window > */
    AboutAlgorithm* about;/*!< Pointer to about algorithms window > */
    algorithms_efficiency_window* algEff_window;/*!< Pointer to sort efficiency window > */

};
#endif // MAINWINDOW_H
