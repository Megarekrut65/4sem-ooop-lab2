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
    set_about(get_about(index));
}
QString AboutAlgorithm::get_about(std::size_t index)
{
    switch (index)
    {
    case 0: return "Bubble sort is a simple sorting algorithm that repeatedly steps through the array, compares adjacent elements and swaps them if they are in the wrong order. The pass through the array is repeated until the array is sorted.";
    case 1: return "Selection sort is a simple sorting algorithm. The smallest element is selected from the unsorted array and swapped with the leftmost element, and that element becomes a part of the sorted array. This process continues moving unsorted array boundary by one element to the right.";
    case 2: return "Merge sort works as follows: Divide the unsorted array into n sub-arrays, each containing one element (an array of one element is considered sorted). Repeatedly merge sub-arrays to produce new sorted sub-array until there is only one subarray remaining.";
    case 3: return "Quicksort is a divide-and-conquer algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.";
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    }
   return "";
}
void AboutAlgorithm::set_names_of_sorts()
{
    QStringList list = {"Bubble sort",
                        "Selection sort",
                        "Merge sort",
                        "Quick sort",
                        "Gnome sort",
                        "Cocktail shaker sort",
                        "Odd-even sort",
                        "Comb sort"};
    ui->comboBox->addItems(list);
}
