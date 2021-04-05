#ifndef ABOUTALGORITHM_H
#define ABOUTALGORITHM_H

#include <QDialog>

namespace Ui {
class AboutAlgorithm;
}

class AboutAlgorithm : public QDialog
{
    Q_OBJECT

public:
    explicit AboutAlgorithm(QWidget *parent = nullptr);
    ~AboutAlgorithm();

private slots:
    void on_comboBox_activated(int index);

private:
    Ui::AboutAlgorithm *ui;

    QString about_merge();
    QString about_bubble();
    QString about_quick();
    QString about_selection();
    void set_names_of_sorts();
    void set_about(const QString& about);
};

#endif // ABOUTALGORITHM_H
