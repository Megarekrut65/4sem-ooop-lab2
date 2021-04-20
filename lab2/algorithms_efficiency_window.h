#ifndef ALGORITHMS_EFFICIENCY_WINDOW_H
#define ALGORITHMS_EFFICIENCY_WINDOW_H

#include <QWidget>
#include <vector>
#include <QElapsedTimer>
#include <QShortcut>
#include <QFuture>
#include <QtConcurrent>
#include <QLineEdit>
#include <QCheckBox>
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
    QShortcut * keyCtrlS;/*!< Object shortcut keys Ctrl + S (Start) */
    /*!
    * \brief Calculate sorting duration for selected algorithm
    */
    void sorting();
    /*!
    * \brief Clear filed with previous result
    */
    void clear_results();
    void start_measuring(QFuture<QString>& future1,QFuture<QString>& future2,QFuture<QString>& future3,
                         QCheckBox* sort_box,std::vector<int> random_test_vector,
                         std::vector<int> in_order_test_vector,std::vector<int> in_reverse_order_test_vector,
                         QLineEdit* first, QLineEdit* second, QLineEdit* third, void(*sort_function)(std::vector<int>&));
    void start(QFuture<QString>& future,std::vector<int>& vector, QLineEdit* field, void(*sort_function)(std::vector<int>&));
signals:
    void mainWindow();/*!< Signal to main window */
private slots:
    /*!
    *   \brief Slot of 'Start' button
    */
    void on_start_pushButton_clicked();
    /*!
    *   \brief Slot of "Ctrl + S" shortcut
    */
    void slotShortcutCtrlS();
    /*!
    *   \brief Slot of 'Back' button
    */
    void on_pushButton_clicked();
};

#endif // ALGORITHMS_EFFICIENCY_WINDOW_H
