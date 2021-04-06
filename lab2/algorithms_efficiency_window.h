#ifndef ALGORITHMS_EFFICIENCY_WINDOW_H
#define ALGORITHMS_EFFICIENCY_WINDOW_H

#include <QWidget>
#include <QVector>
#include <QRandomGenerator>

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
    QVector<int> random();/*!< Generate vector of random int values for test */
    QVector<int> atleast_sorted_in_order();/*!< Generate vector of alteast sorted in order int values for test */
    QVector<int> atleast_sorted_in_reverse_order();/*!< Generate vector of alteast sorted in reverse order int values for test */

signals:
    void mainWindow();/*!< Signal to main window */
private slots:
    void on_start_pushButton_clicked();
};

#endif // ALGORITHMS_EFFICIENCY_WINDOW_H
