#include "algorithms_efficiency_window.h"
#include "ui_algorithms_efficiency_window.h"

algorithms_efficiency_window::algorithms_efficiency_window(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::algorithms_efficiency_window)
{
    ui->setupUi(this);
    QIcon icon(":/icons/Images/duration-icon.ico");
    this->setWindowIcon(icon);
    this->setWindowTitle("Sort duration");
    keyCtrlS = new QShortcut(this);
    keyCtrlS->setKey(QKeySequence::fromString("Ctrl+S"));
    connect(keyCtrlS, SIGNAL(activated()), this, SLOT(slotShortcutCtrlS()));
}

algorithms_efficiency_window::~algorithms_efficiency_window()
{
    delete ui;
}
void algorithms_efficiency_window::start(QFuture<QString>& future,std::vector<int>& vector, QLineEdit* field, void(*sort_function)(std::vector<int>&))
{
    future = QtConcurrent::run([&] {
        std::vector<int> vec;
        std::copy(vector.begin(), vector.end(), std::back_inserter(vec));
        QElapsedTimer sort_timer;
        sort_timer.start();
        sort_function(vec);
        QString res = QString::number(sort_timer.elapsed()) + "ms";
        vec.clear();
        return res;
    });
    while (!future.isFinished()) {
        QCoreApplication::processEvents();
    }
    field->setText(future.result());
}
void algorithms_efficiency_window::start_measuring(QFuture<QString>& future1,QFuture<QString>& future2,QFuture<QString>& future3,
                                                   QCheckBox* sort_box,std::vector<int> random_test_vector,
                                                   std::vector<int> in_order_test_vector,std::vector<int> in_reverse_order_test_vector,
                                                 QLineEdit* first, QLineEdit* second, QLineEdit* third,
                                                   void(*sort_function)(std::vector<int>&))
{
    if (sort_box->isChecked()) {
        if (ui->random_checkBox->isChecked()) {
            start(future1,random_test_vector,first,sort_function);
        }
        else {
            first->setText("-");
        }
        if (ui->atleast_sorted_inorder_checkBox->isChecked()) {
            start(future2,in_order_test_vector,second,sort_function);
        }
        else {
            second->setText("-");
        }
        if (ui->atleast_sorted_rev_checkBox->isChecked()) {
            start(future3,in_reverse_order_test_vector,third,sort_function);
        }
        else {
            third->setText("-");
        }
    }
    else {
        first->setText("-");
        second->setText("-");
        third->setText("-");
    }
}
void algorithms_efficiency_window::sorting()
{
    clear_results();
    std::vector<int> random_test_vector = sorts::create_random_array<int>(ui->count_spinBox->value());
    std::vector<int> in_order_test_vector = sorts::create_ordered_array<int>(ui->count_spinBox->value(), (8 * ui->count_spinBox->value()) / 10);
    std::vector<int> in_reverse_order_test_vector = sorts::create_reverse_ordered_array<int>(ui->count_spinBox->value(), (8 * ui->count_spinBox->value()) / 10);
    QFuture<QString> bubble1, bubble2, bubble3,
        selection1, selection2, selection3,
        merge1, merge2, merge3,
        quick1, quick2, quick3,
        gnome1, gnome2, gnome3,
        cocktail_shaker1, cocktail_shaker2, cocktail_shaker3,
        odd_even1, odd_even2, odd_even3,
        comb1, comb2, comb3;

    start_measuring(bubble1,bubble2,bubble3,ui->bubble_checkBox,random_test_vector,in_order_test_vector,in_reverse_order_test_vector,
                    ui->bubble_first_result_lineEdit,ui->bubble_second_result_lineEdit,
                    ui->bubble_third_result_lineEdit,&sorts::bubble_sort);
    start_measuring(selection1,selection2,selection3,ui->selection_checkBox,random_test_vector,in_order_test_vector,in_reverse_order_test_vector,
                    ui->selection_first_result_lineEdit,ui->selection_second_result_lineEdit,
                    ui->selection_third_result_lineEdit,&sorts::selection_sort);
    start_measuring(merge1,merge2,merge3,ui->merge_checkBox,random_test_vector,in_order_test_vector,in_reverse_order_test_vector,
                    ui->merge_first_result_lineEdit,ui->merge_second_result_lineEdit,
                    ui->merge_third_result_lineEdit,&sorts::merge_sort);
    start_measuring(quick1,quick2,quick3,ui->quick_checkBox,random_test_vector,in_order_test_vector,in_reverse_order_test_vector,
                    ui->quick_first_result_lineEdit,ui->quick_second_result_lineEdit,
                    ui->quick_third_result_lineEdit,&sorts::quick_sort);
    start_measuring(gnome1,gnome2,gnome3,ui->gnome_checkBox,random_test_vector,in_order_test_vector,in_reverse_order_test_vector,
                    ui->gnome_first_result_lineEdit,ui->gnome_second_result_lineEdit,
                    ui->gnome_third_result_lineEdit,&sorts::gnome_sort);
    start_measuring(cocktail_shaker1,cocktail_shaker2,cocktail_shaker3,ui->cocktail_shaker_checkBox,random_test_vector,in_order_test_vector,in_reverse_order_test_vector,
                    ui->cocktail_shaker_first_result_lineEdit,ui->cocktail_shaker_second_result_lineEdit,
                    ui->cocktail_shaker_third_result_lineEdit,&sorts::cocktail_shaker_sort);
    start_measuring(odd_even1,odd_even2,odd_even3,ui->odd_even_checkBox,random_test_vector,in_order_test_vector,in_reverse_order_test_vector,
                    ui->odd_even_first_result_lineEdit,ui->odd_even_second_result_lineEdit,
                    ui->odd_even_third_result_lineEdit,&sorts::odd_even_sort);
    start_measuring(comb1,comb2,comb3,ui->comb_checkBox,random_test_vector,in_order_test_vector,in_reverse_order_test_vector,
                    ui->comb_first_result_lineEdit,ui->comb_second_result_lineEdit,
                    ui->comb_third_result_lineEdit,&sorts::comb_sort);
}

void algorithms_efficiency_window::clear_results()
{
    ui->bubble_first_result_lineEdit->clear();
    ui->bubble_second_result_lineEdit->clear();
    ui->bubble_third_result_lineEdit->clear();

    ui->selection_first_result_lineEdit->clear();
    ui->selection_second_result_lineEdit->clear();
    ui->selection_third_result_lineEdit->clear();

    ui->merge_first_result_lineEdit->clear();
    ui->merge_second_result_lineEdit->clear();
    ui->merge_third_result_lineEdit->clear();

    ui->quick_first_result_lineEdit->clear();
    ui->quick_second_result_lineEdit->clear();
    ui->quick_third_result_lineEdit->clear();

    ui->gnome_first_result_lineEdit->clear();
    ui->gnome_second_result_lineEdit->clear();
    ui->gnome_third_result_lineEdit->clear();

    ui->cocktail_shaker_first_result_lineEdit->clear();
    ui->cocktail_shaker_second_result_lineEdit->clear();
    ui->cocktail_shaker_third_result_lineEdit->clear();

    ui->odd_even_first_result_lineEdit->clear();
    ui->odd_even_second_result_lineEdit->clear();
    ui->odd_even_third_result_lineEdit->clear();

    ui->comb_first_result_lineEdit->clear();
    ui->comb_second_result_lineEdit->clear();
    ui->comb_third_result_lineEdit->clear();
}

void algorithms_efficiency_window::on_start_pushButton_clicked()
{
    this->sorting();
}

void algorithms_efficiency_window::slotShortcutCtrlS()
{
    this->sorting();
}

void algorithms_efficiency_window::on_pushButton_clicked()
{
    emit mainWindow();
    this->close();
}
