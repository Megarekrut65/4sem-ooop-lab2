#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QDialog>
#include <QTimer>
#include <QTextEdit>
#include <QRandomGenerator>
#include "sort_class.h"
namespace Ui {
class DrawWindow;
}

class DrawWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DrawWindow(QWidget *parent = nullptr);
    ~DrawWindow();

private slots:
    void on_add_pushButton_clicked();

    void on_remove_pushButton_clicked();

    void on_random_pushButton_clicked();

    void on_inorder_pushButton_clicked();

    void on_start_pushButton_clicked();

    void on_pause_Button_clicked();

    void on_stop_pushButton_clicked();

    void on_sorts_listWidget_currentRowChanged(int currentRow);

    void on_pushButton_prev_clicked();

    void on_pushButton_end_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_begin_clicked();

private:
    Ui::DrawWindow *ui;
    QTimer* timer;
    sc::SortClass<int> sort;
    size_t m_delay;
    sd::MyGraphicsView<int>* view;
    bool is_pause;
    bool is_stop;
    std::size_t current_sort;
    void set_timer();
    void set_view();
    void draw();
    void start_draw();
    void stop_draw();
    void pause_draw();
    void sort_array();
    void set_sorts();
    void pause_for_buttons();
    void set_visible_of_buttons(bool visible);
    QString create_precent(std::size_t index);
    void create_diagram(MementoSorting<int>* state, const QString& text);
    std::vector<int> get_array();

};

#endif // DRAWWINDOW_H
