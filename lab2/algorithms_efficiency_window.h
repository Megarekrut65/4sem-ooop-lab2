#ifndef ALGORITHMS_EFFICIENCY_WINDOW_H
#define ALGORITHMS_EFFICIENCY_WINDOW_H

#include <QWidget>
#include <vector>
#include <QElapsedTimer>
#include <QTimer>
#include <QShortcut>
#include "Sorts/libraries_and_namespaces.h"
#include "Sorts/all_sorts.h"
#include "sort_thread.h"

namespace Ui {
class algorithms_efficiency_window;
enum class sort_mode;
}



class algorithms_efficiency_window : public QWidget
{
    Q_OBJECT

public:
    explicit algorithms_efficiency_window(QWidget *parent = nullptr);
    ~algorithms_efficiency_window();
    sort_thread *sThread;

private:
    Ui::algorithms_efficiency_window *ui;/*!< Pointer to ui */
    QElapsedTimer *timer;/*!< Timer for sorts durations */
    QShortcut * keyCtrlS;/*!< Object shortcut keys Ctrl + S (Start) */
    /*!
    * \brief Calculate sorting duration for selected algorithm
    */
    void sorting();
    bool sort_thread_running;
    Sort current_sort;
    Array_type current_array_type;
    Time_units current_time_units;
signals:
    void mainWindow();/*!< Signal to main window */
private slots:
    /*!
    *   \brief Slot of 'Start' button
    */
    void on_start_pushButton_clicked();
    /*!
    *   \brief Slot of "Ctrl + S" shortcut
    */
    void slotShortcutCtrlS();
    /*!
    *   \brief Slot of 'Back' button
    */
    void on_pushButton_clicked();
public slots:
    void onGetResult(QString);
};

#endif // ALGORITHMS_EFFICIENCY_WINDOW_H
