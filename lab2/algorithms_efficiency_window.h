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
    Ui::algorithms_efficiency_window *ui;
    QVector<int> random();
    QVector<int> atleast_sorted_in_order();
    QVector<int> atleast_sorted_in_reverse_order();

signals:
    void mainWindow();
private slots:
    void on_start_pushButton_clicked();
};

#endif // ALGORITHMS_EFFICIENCY_WINDOW_H
