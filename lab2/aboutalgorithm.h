#ifndef ABOUTALGORITHM_H
#define ABOUTALGORITHM_H

#include <QDialog>

namespace Ui {
class AboutAlgorithm;
}
/*!
*   \brief Window class to present information about sort algorithm
*/
class AboutAlgorithm : public QDialog
{
    Q_OBJECT

public:
    explicit AboutAlgorithm(QWidget *parent = nullptr);
    ~AboutAlgorithm();

private slots:
    void on_comboBox_activated(int index);

private:
    Ui::AboutAlgorithm *ui;/*!< Pointer to ui */
    /*!
    * \brief Returns information about sort
    */
    QString get_about(std::size_t index);
    /*!
    * \brief Adds names of sorts to combo box
    */
    void set_names_of_sorts();
    /*!
    * \brief Adds text to label
    */
    void set_about(const QString& about);
};

#endif // ABOUTALGORITHM_H
