#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QDialog>
#include <QTimer>
#include <QTextEdit>
#include <QRandomGenerator>
#include <QDateTime>
#include <QFile>
#include <QShortcut>
#include "filepath.h"
#include "sort_class.h"

namespace Ui {
class DrawWindow;
}
/*!
*   \brief Window class to present diagram created by sorting states
*/
class DrawWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DrawWindow(QWidget *parent = nullptr);
    ~DrawWindow();

private slots:
    /*!
    *   \brief Slot of 'Add' button
    */
    void on_add_pushButton_clicked();
    /*!
    *   \brief Slot of 'Remove' button
    */
    void on_remove_pushButton_clicked();
    /*!
    *   \brief Slot of 'Random' button
    */
    void on_random_pushButton_clicked();
    /*!
    *   \brief Slot of 'In order mixed' button
    */
    void on_inorder_pushButton_clicked();
    /*!
    *   \brief Slot of 'Start' button
    */
    void on_start_pushButton_clicked();
    /*!
    *   \brief Slot of 'Pause' button
    */
    void on_pause_Button_clicked();
    /*!
    *   \brief Slot of 'Stop' button
    */
    void on_stop_pushButton_clicked();
    /*!
    *   \brief Slot of selecting element in algorithm list
    */
    void on_sorts_listWidget_currentRowChanged(int currentRow);
    /*!
    *   \brief Slot of 'Prev' button
    */
    void on_pushButton_prev_clicked();
    /*!
    *   \brief Slot of 'End' button
    */
    void on_pushButton_end_clicked();
    /*!
    *   \brief Slot of 'Next' button
    */
    void on_pushButton_next_clicked();
    /*!
    *   \brief Slot of 'Begin' button
    */
    void on_pushButton_begin_clicked();
    /*!
    *   \brief Slot of 'Back' button
    */
    void on_back_pushButton_clicked();
    /*!
    *   \brief Slot of 'Almost sorted(in order)' button
    */
    void on_almostsorted_pushButton_clicked();
    /*!
    *   \brief Slot of 'Almost sorted(in reverse order)' button
    */
    void on_almostsorted_rev_pushButton_clicked();
    /*!
    *   \brief Slot of 'F5' shortcut
    */
    void slotShortcutF5();
    /*!
    *   \brief Slot of 'Shift + F5' shortcut
    */
    void slotShortcutShiftF5();
    /*!
    *   \brief Slot of 'Ctrl + P' shortcut
    */
    void slotShortcutCtrlP();
    /*!
    *   \brief Slot of 'Left' shortcut
    */
    void slotShortcutPrev();
    /*!
    *   \brief Slot of 'Right' shortcut
    */
    void slotShortcutNext();

private:
    Ui::DrawWindow *ui;/*!< Pointer to ui */
    QTimer* timer;/*!< Timer to call drawing */
    sc::SortClass<int> sort;/*!< Class to sort array and save all states of sorting */
    size_t m_delay;/*!< Delay of drawing */
    sd::MyGraphicsView<int>* view;/*!< Class to create diagram by array */
    bool is_pause;/*!< True if drawing is paused */
    bool is_stop;/*!< True if drawing is stoped */
    qreal width;/*!< Width of diagram */
    qreal height;/*!< Height of diagram */
    std::size_t current_sort;/*!< Index of current sort algorithm */
    QShortcut * keyF5;/*!< Object shortcut keys F5 (Start) */
    QShortcut * keyShiftF5;/*!< Object shortcut keys Shift + F5 (Stop) */
    QShortcut * keyCtrlP;/*!< Object shortcut keys Ctrl + P (Pause) */
    QShortcut * keyPrev;/*!< Object shortcut keys Ctrl + P (Previous state) */
    QShortcut * keyNext;/*!< Object shortcut keys Ctrl + P (Next state) */
    /*!
    *   \brief Sets all parameters for timer
    */
    void set_timer();
    /*!
    *   \brief Sets all parameters for view
    */
    void set_view();
    /*!
    *   \brief Sets all parameters for graphics view
    */
    void set_graphics_view();
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
    /*!
    *   \brief Adds to log file array and sorted one
    */
    void append_to_file();
    /*!
    *   \brief If size of log file will be most 1 mb then clear file
    */
    void check_log_file();
    /*!
    *   \brief Creates diagram by arr
    */
    void create_static_diagram(const std::vector<int>& arr);
signals:
    void mainWindow();
};

#endif // DRAWWINDOW_H
