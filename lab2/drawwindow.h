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


    void on_back_pushButton_clicked();

    void on_almostsorted_pushButton_clicked();

    void on_almostsorted_rev_pushButton_clicked();

private:
    Ui::DrawWindow *ui;/*!< Pointer to ui */
    QTimer* timer;/*!< Timer to call drawing */
    sc::SortClass<int> sort;/*!< Class to sort array and save all states of sorting */
    size_t m_delay;/*!< Delay of drawing */
    sd::MyGraphicsView<int>* view;/*!< Class to create diagram by array */
    bool is_pause;/*!< True if drawing is paused */
    bool is_stop;/*!< True if drawing is stoped */
    std::size_t current_sort;/*!< Index of current sort algorithm */
    /*!
    *   \brief Sets all parameters for timer
    */
    void set_timer();
    /*!
    *   \brief Sets all parameters for view
    */
    void set_view();
    /*!
    *   \brief Draws current state of sorting
    */
    void draw();
    /*!
    *   \brief Starts drawing if it was paused or stoped
    */
    void start_draw();
    /*!
    *   \brief Stop drawing and clear diagram
    */
    void stop_draw();
    /*!
    *   \brief Pauses drawing
    */
    void pause_draw();
    /*!
    *   \brief Sorts array using sc::SortClass
    */
    void sort_array();
    /*!
    *   \brief Adds all sorts to sort list
    */
    void set_sorts();
    /*!
    *   \brief Sets pause state for buttons prev,next,begin,end
    */
    void pause_for_buttons();
    /*!
    *   \brief Sets visible for buttons prev,next,begin,end
    *
    *   \param visible - if true then buttons will be visible else invisible
    */
    void set_visible_of_buttons(bool visible);
    /*!
    *   \brief Edits background-color and color of selected sort in list
    */
    void select_sort_in_list(std::size_t index_of_sort);
    /*!
    *   \brief Counts percent of sort compliting
    */
    QString create_precent(std::size_t index);
    /*!
    *   \brief Creates diagram by state and adds to it text in the bottom
    */
    void create_diagram(MementoSorting<int>* state, const QString& text);
    /*!
    *   \brief Returns array from ui list
    */
    std::vector<int> get_array();
signals:
    void mainWindow();
};

#endif // DRAWWINDOW_H
