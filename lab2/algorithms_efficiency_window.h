#ifndef ALGORITHMS_EFFICIENCY_WINDOW_H
#define ALGORITHMS_EFFICIENCY_WINDOW_H

#include <QWidget>

namespace Ui {
class algorithmic_efficiency_window;
}

class algorithmic_efficiency_window : public QWidget
{
    Q_OBJECT

public:
    explicit algorithmic_efficiency_window(QWidget *parent = nullptr);
    ~algorithmic_efficiency_window();

private:
    Ui::algorithmic_efficiency_window *ui;
};

#endif // ALGORITHMS_EFFICIENCY_WINDOW_H
