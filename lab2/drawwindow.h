#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QDialog>
#include <QTimer>
#include <QTextEdit>
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

private slots:
    void on_values_edit_textChanged();

    void on_add_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_remove_pushButton_clicked();

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
