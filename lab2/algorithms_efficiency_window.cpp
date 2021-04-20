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

    if (ui->bubble_checkBox->isChecked()) {
        if (ui->random_checkBox->isChecked()) {
                bubble1 = QtConcurrent::run([&random_test_vector] {
                std::vector<int> vector;
                std::copy(random_test_vector.begin(), random_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::bubble_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!bubble1.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->bubble_first_result_lineEdit->setText(bubble1.result());
        }
        else {
            ui->bubble_first_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_inorder_checkBox->isChecked()) {
            bubble2 = QtConcurrent::run([&in_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_order_test_vector.begin(), in_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::bubble_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!bubble2.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->bubble_second_result_lineEdit->setText(bubble2.result());
        }
        else {
            ui->bubble_second_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_rev_checkBox->isChecked()) {
            bubble3 = QtConcurrent::run([&in_reverse_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_reverse_order_test_vector.begin(), in_reverse_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::bubble_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!bubble3.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->bubble_third_result_lineEdit->setText(bubble3.result());
        }
        else {
            ui->bubble_third_result_lineEdit->setText("-");
        }
    }
    else {
        ui->bubble_first_result_lineEdit->setText("-");
        ui->bubble_second_result_lineEdit->setText("-");
        ui->bubble_third_result_lineEdit->setText("-");
    }
    if (ui->selection_checkBox->isChecked()) {
        if (ui->random_checkBox->isChecked()) {
            selection1 = QtConcurrent::run([&random_test_vector] {
                std::vector<int> vector;
                std::copy(random_test_vector.begin(), random_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::bubble_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!selection1.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->selection_first_result_lineEdit->setText(selection1.result());
        }
        else {
            ui->selection_first_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_inorder_checkBox->isChecked()) {
            selection2 = QtConcurrent::run([&in_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_order_test_vector.begin(), in_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::bubble_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!selection2.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->selection_second_result_lineEdit->setText(selection2.result());
        }
        else {
            ui->selection_second_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_rev_checkBox->isChecked()) {
            selection3 = QtConcurrent::run([&in_reverse_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_reverse_order_test_vector.begin(), in_reverse_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::bubble_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!selection3.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->selection_third_result_lineEdit->setText(selection3.result());
        }
        else {
            ui->selection_third_result_lineEdit->setText("-");
        }
    }
    else {
        ui->selection_first_result_lineEdit->setText("-");
        ui->selection_second_result_lineEdit->setText("-");
        ui->selection_third_result_lineEdit->setText("-");
    }
    if (ui->merge_checkBox->isChecked()) {
        if (ui->random_checkBox->isChecked()) {
            merge1 = QtConcurrent::run([&random_test_vector] {
                std::vector<int> vector;
                std::copy(random_test_vector.begin(), random_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::merge_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!merge1.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->merge_first_result_lineEdit->setText(merge1.result());
        }
        else {
            ui->merge_first_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_inorder_checkBox->isChecked()) {
            merge2 = QtConcurrent::run([&in_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_order_test_vector.begin(), in_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::merge_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!merge2.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->merge_second_result_lineEdit->setText(merge2.result());
        }
        else {
            ui->merge_second_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_rev_checkBox->isChecked()) {
            merge3 = QtConcurrent::run([&in_reverse_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_reverse_order_test_vector.begin(), in_reverse_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::merge_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!merge3.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->merge_third_result_lineEdit->setText(merge3.result());
        }
        else {
            ui->merge_third_result_lineEdit->setText("-");
        }
    }
    else {
        ui->merge_first_result_lineEdit->setText("-");
        ui->merge_second_result_lineEdit->setText("-");
        ui->merge_third_result_lineEdit->setText("-");
    }
    if (ui->quick_checkBox->isChecked()) {
        if (ui->random_checkBox->isChecked()) {
            quick1 = QtConcurrent::run([&random_test_vector] {
                std::vector<int> vector;
                std::copy(random_test_vector.begin(), random_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::quick_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!quick1.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->quick_first_result_lineEdit->setText(quick1.result());
        }
        else {
            ui->quick_first_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_inorder_checkBox->isChecked()) {
            quick2 = QtConcurrent::run([&in_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_order_test_vector.begin(), in_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::quick_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!quick2.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->quick_second_result_lineEdit->setText(quick2.result());
        }
        else {
            ui->quick_second_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_rev_checkBox->isChecked()) {
            quick3 = QtConcurrent::run([&in_reverse_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_reverse_order_test_vector.begin(), in_reverse_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::quick_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!quick3.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->quick_third_result_lineEdit->setText(quick3.result());
        }
        else {
            ui->quick_third_result_lineEdit->setText("-");
        }
    }
    else {
        ui->quick_first_result_lineEdit->setText("-");
        ui->quick_second_result_lineEdit->setText("-");
        ui->quick_third_result_lineEdit->setText("-");
    }
    if (ui->gnome_checkBox->isChecked()) {
        if (ui->random_checkBox->isChecked()) {
            gnome1 = QtConcurrent::run([&random_test_vector] {
                std::vector<int> vector;
                std::copy(random_test_vector.begin(), random_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::gnome_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!gnome1.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->gnome_first_result_lineEdit->setText(gnome1.result());
        }
        else {
            ui->gnome_first_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_inorder_checkBox->isChecked()) {
            gnome2 = QtConcurrent::run([&in_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_order_test_vector.begin(), in_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::gnome_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!gnome2.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->gnome_second_result_lineEdit->setText(gnome2.result());
        }
        else {
            ui->gnome_second_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_rev_checkBox->isChecked()) {
            gnome3 = QtConcurrent::run([&in_reverse_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_reverse_order_test_vector.begin(), in_reverse_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::gnome_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!gnome3.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->gnome_third_result_lineEdit->setText(gnome3.result());
        }
        else {
            ui->gnome_third_result_lineEdit->setText("-");
        }
    }
    else {
        ui->gnome_first_result_lineEdit->setText("-");
        ui->gnome_second_result_lineEdit->setText("-");
        ui->gnome_third_result_lineEdit->setText("-");
    }
    if (ui->cocktail_shaker_checkBox->isChecked()) {
        if (ui->random_checkBox->isChecked()) {
            cocktail_shaker1 = QtConcurrent::run([&random_test_vector] {
                std::vector<int> vector;
                std::copy(random_test_vector.begin(), random_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::cocktail_shaker_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!cocktail_shaker1.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->cocktail_shaker_first_result_lineEdit->setText(cocktail_shaker1.result());
        }
        else {
            ui->cocktail_shaker_first_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_inorder_checkBox->isChecked()) {
            cocktail_shaker2 = QtConcurrent::run([&in_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_order_test_vector.begin(), in_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::cocktail_shaker_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!cocktail_shaker2.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->cocktail_shaker_second_result_lineEdit->setText(cocktail_shaker2.result());
        }
        else {
            ui->cocktail_shaker_second_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_rev_checkBox->isChecked()) {
            cocktail_shaker3 = QtConcurrent::run([&in_reverse_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_reverse_order_test_vector.begin(), in_reverse_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::cocktail_shaker_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!cocktail_shaker3.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->cocktail_shaker_third_result_lineEdit->setText(cocktail_shaker3.result());
        }
        else {
            ui->cocktail_shaker_third_result_lineEdit->setText("-");
        }
    }
    else {
        ui->cocktail_shaker_first_result_lineEdit->setText("-");
        ui->cocktail_shaker_second_result_lineEdit->setText("-");
        ui->cocktail_shaker_third_result_lineEdit->setText("-");
    }
    if (ui->odd_even_checkBox->isChecked()) {
        if (ui->random_checkBox->isChecked()) {
            odd_even1 = QtConcurrent::run([&random_test_vector] {
                std::vector<int> vector;
                std::copy(random_test_vector.begin(), random_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::odd_even_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!odd_even1.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->odd_even_first_result_lineEdit->setText(odd_even1.result());
        }
        else {
            ui->odd_even_first_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_inorder_checkBox->isChecked()) {
            odd_even2 = QtConcurrent::run([&in_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_order_test_vector.begin(), in_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::odd_even_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!odd_even2.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->odd_even_second_result_lineEdit->setText(odd_even2.result());
        }
        else {
            ui->odd_even_second_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_rev_checkBox->isChecked()) {
            odd_even3 = QtConcurrent::run([&in_reverse_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_reverse_order_test_vector.begin(), in_reverse_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::odd_even_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!odd_even3.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->odd_even_third_result_lineEdit->setText(odd_even3.result());
        }
        else {
            ui->odd_even_third_result_lineEdit->setText("-");
        }
    }
    else {
        ui->odd_even_first_result_lineEdit->setText("-");
        ui->odd_even_second_result_lineEdit->setText("-");
        ui->odd_even_third_result_lineEdit->setText("-");
    }
    if (ui->comb_checkBox->isChecked()) {
        if (ui->random_checkBox->isChecked()) {
            comb1 = QtConcurrent::run([&random_test_vector] {
                std::vector<int> vector;
                std::copy(random_test_vector.begin(), random_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::comb_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!comb1.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->comb_first_result_lineEdit->setText(comb1.result());
        }
        else {
            ui->comb_first_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_inorder_checkBox->isChecked()) {
            comb2 = QtConcurrent::run([&in_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_order_test_vector.begin(), in_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::comb_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!comb2.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->comb_second_result_lineEdit->setText(comb2.result());
        }
        else {
            ui->comb_second_result_lineEdit->setText("-");
        }
        if (ui->atleast_sorted_rev_checkBox->isChecked()) {
            comb3 = QtConcurrent::run([&in_reverse_order_test_vector] {
                std::vector<int> vector;
                std::copy(in_reverse_order_test_vector.begin(), in_reverse_order_test_vector.end(), std::back_inserter(vector));
                QElapsedTimer sort_timer;
                sort_timer.start();
                sorts::comb_sort(vector);
                vector.clear();
                return QString::number(sort_timer.elapsed()) + "ms";
            });
            while (!comb3.isFinished()) {
                QCoreApplication::processEvents();
            }
            ui->comb_third_result_lineEdit->setText(comb3.result());
        }
        else {
            ui->comb_third_result_lineEdit->setText("-");
        }
    }
    else {
        ui->comb_first_result_lineEdit->setText("-");
        ui->comb_second_result_lineEdit->setText("-");
        ui->comb_third_result_lineEdit->setText("-");
    }

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
