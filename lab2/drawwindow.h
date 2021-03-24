#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QDialog>
#include <QTimer>
#include "sort_class.h"
namespace Ui {
class DrawWindow;
}

class DrawWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DrawWindow( sc::SortClass<int>& sort, size_t m_delay = 50, QWidget *parent = nullptr);
    ~DrawWindow();

private:
    Ui::DrawWindow *ui;
    QTimer* timer;
    sc::SortClass<int>& sort;
    std::size_t index;
    size_t m_delay;
    sd::MyGraphicsView<int>* view;
    void set_timer();
    void set_view();
    void draw();

};

#endif // DRAWWINDOW_H
