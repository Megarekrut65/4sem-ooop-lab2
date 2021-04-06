#ifndef ALGORITHMS_EFFICIENCY_WINDOW_H
#define ALGORITHMS_EFFICIENCY_WINDOW_H

#include <QWidget>
#include <vector>
#include <QThread>
#include <QRandomGenerator>
#include <QElapsedTimer>
#include "Sorts/libraries_and_namespaces.h"
#include "Sorts/all_sorts.h"

namespace Ui {
class algorithms_efficiency_window;
}

class algorithms_efficiency_window : public QWidget
{
    Q_OBJECT

public:
    explicit algorithms_efficiency_window(QWidget *parent = nullptr);
    ~algorithms_efficiency_window();

private:
    Ui::algorithms_efficiency_window *ui;/*!< Pointer to ui */
    QElapsedTimer *timer;
    /*!
    * \brief Calculate sorting duration for selected algorithm
    */
    void sorting();
signals:
    void mainWindow();/*!< Signal to main window */
private slots:
    void on_start_pushButton_clicked();/*!< Signal for 'Start' button */

    void on_pushButton_clicked();
};

#endif // ALGORITHMS_EFFICIENCY_WINDOW_H
