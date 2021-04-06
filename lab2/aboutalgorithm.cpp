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
    QIcon icon(":/icons/Images/about-icon.ico");
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
    return "Merge sort works as follows: Divide the unsorted array into n sub-arrays, each containing one element (an array of one element is considered sorted). Repeatedly merge sub-arrays to produce new sorted sub-array until there is only one subarray remaining.";
}
QString AboutAlgorithm::about_bubble()
{
    return "Bubble sort is a simple sorting algorithm that repeatedly steps through the array, compares adjacent elements and swaps them if they are in the wrong order. The pass through the array is repeated until the array is sorted.";
}
QString AboutAlgorithm::about_quick()
{
    return "Quicksort is a divide-and-conquer algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.";
}
QString AboutAlgorithm::about_selection()
{
    return "Selection sort is a simple sorting algorithm. The smallest element is selected from the unsorted array and swapped with the leftmost element, and that element becomes a part of the sorted array. This process continues moving unsorted array boundary by one element to the right.";
}
void AboutAlgorithm::set_names_of_sorts()
{
    QStringList list = {"Bubble sort",
                        "Selection sort",
                        "Merge sort",
                        "Quick sort"};
    ui->comboBox->addItems(list);
}
