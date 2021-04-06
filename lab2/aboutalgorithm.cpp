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
    case 4: return "Gnome sort finds the first place where two adjacent elements are in the wrong order and swaps them.";
    case 5: return "The first rightward pass will shift the largest element to its correct place at the end, and the following leftward pass will shift the smallest element to its correct place at the beginning. The second complete pass will shift the second largest and second smallest elements to their correct places, and so on. After i passes, the first i and the last i elements in the list are in their correct positions, and do not need to be checked.";
    case 6: return "Odd-even sort extends efficiently to the case of multiple items per processor. In the Baudet–Stevenson odd–even merge-splitting algorithm, each processor sorts its own sublist at each step, using any efficient sort algorithm, and then performs a merge splitting, or transposition–merge, operation with its neighbor, with neighbor pairing alternating between odd–even and even–odd on each step.";
    case 7: return "The basic idea is to eliminate turtles, or small values near the end of the list, since in a bubble sort these slow the sorting down tremendously. Rabbits, large values around the beginning of the list, do not pose a problem in bubble sort.";
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
