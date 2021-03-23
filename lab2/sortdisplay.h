#ifndef SORTDISPLAY_H
#define SORTDISPLAY_H

#include <QDialog>
#include <QProgressBar>

namespace Ui {
class SortDisplay;
}

class SortDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit SortDisplay(QWidget *parent = nullptr);
    ~SortDisplay();

private:
    Ui::SortDisplay *ui;
    template<typename T>
    QProgressBar* create_line(T value, size_t height, size_t width);
};

#endif // SORTDISPLAY_H
