#include "aboutalgorithm.h"
#include "ui_aboutalgorithm.h"

AboutAlgorithm::AboutAlgorithm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutAlgorithm)
{
    ui->setupUi(this);
    set_names_of_sorts();
    on_comboBox_activated(0);
    setWindowTitle("About algorithms");
    QIcon icon("Images/about-icon.ico");
    this->setWindowIcon(icon);
}

AboutAlgorithm::~AboutAlgorithm()
{
    delete ui;
}
void AboutAlgorithm::set_about(const QString& about)
{
    ui->label_about->setText(about);
}
void AboutAlgorithm::on_comboBox_activated(int index)
{
    switch (index)
    {
    case 0: set_about(about_bubble());
        break;
    case 1: set_about(about_selection());
        break;
    case 2: set_about(about_merge());
        break;
    case 3: set_about(about_quick());
        break;
    case 4:
        break;
    }
}
QString AboutAlgorithm::about_merge()
{
    return "There is merge";
}
QString AboutAlgorithm::about_bubble()
{
    return "There is bubble";
}
QString AboutAlgorithm::about_quick()
{
    return "There is quick";
}
QString AboutAlgorithm::about_selection()
{
    return "There is selection";
}
void AboutAlgorithm::set_names_of_sorts()
{
    QStringList list = {"Bubble sort",
                        "Selection sort",
                        "Merge sort",
                        "Quick sort"};
    ui->comboBox->addItems(list);
}
