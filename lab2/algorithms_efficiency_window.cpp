#include "algorithms_efficiency_window.h"
#include "ui_algorithms_efficiency_window.h"


algorithms_efficiency_window::algorithms_efficiency_window(QWidget *parent)
    : QWidget(parent), ui(new Ui::algorithms_efficiency_window),
      timer(new QElapsedTimer),
      sort_thread_running(true)
{
  ui->setupUi(this);
  QIcon icon(":/icons/Images/duration-icon.ico");
  this->setWindowIcon(icon);
  this->setWindowTitle("Sort duration");
  keyCtrlS = new QShortcut(this);
  keyCtrlS->setKey(QKeySequence::fromString("Ctrl+S"));
  connect(keyCtrlS, SIGNAL(activated()), this, SLOT(slotShortcutCtrlS()));

  sThread = new sort_thread(this);
  QObject::connect(sThread, SIGNAL(SentResult(QString)), this, SLOT(onGetResult(QString)));
  //QObject::connect(sThread, SIGNAL(SentStop()), this, SLOT(onGetStop()));
}

algorithms_efficiency_window::~algorithms_efficiency_window()
{
    delete sThread;
    delete timer;
    delete ui;
}

void algorithms_efficiency_window::sorting()
{
    std::vector<int> random_test_vector =
        sorts::create_random_array<int>(ui->count_spinBox->value());
    std::vector<int> in_order_test_vector = sorts::create_ordered_array<int>(ui->count_spinBox->value(), (8 * ui->count_spinBox->value()) / 10);
    std::vector<int> in_reverse_order_test_vector = sorts::create_reverse_ordered_array<int>(ui->count_spinBox->value(), (8 * ui->count_spinBox->value()) / 10);
    std::vector<int> temp_random_vector;
    std::vector<int> temp_in_order_vector;
    std::vector<int> temp_in_reverse_order_vector;
    if (ui->bubble_checkBox->isChecked())
    {
      if (ui->random_checkBox->isChecked())
      {
          temp_random_vector = random_test_vector;
          this->current_sort = Sort::BUBBLE;
          this->current_array_type = Array_type::full_random;
          sThread->set_array(temp_random_vector);
          sThread->set_sort(Sort::BUBBLE);
          sThread->start();

           sThread->quit();
          /*while(true)
          {
              if(!sThread->isRunning())
                  break;
          }*/

      }
      else
      {
        ui->bubble_first_result_lineEdit->setText("-");
      }
      if (ui->atleast_sorted_inorder_checkBox->isChecked())
      {
          temp_in_order_vector = in_order_test_vector;
          this->current_sort = Sort::BUBBLE;
          this->current_array_type = Array_type::almost_sorted;
          sThread->set_array(temp_random_vector);
          sThread->set_sort(Sort::BUBBLE);
          sThread->start();
          sThread->quit();
          /*while(true)
          {
              if(!sort_thread_running)
                  break;
          }*/
      }
      else
      {
        ui->bubble_second_result_lineEdit->setText("-");
      }
      if (ui->atleast_sorted_rev_checkBox->isChecked())
      {
        temp_in_reverse_order_vector = in_reverse_order_test_vector;
        timer->start();
        sorts::bubble_sort(temp_in_reverse_order_vector);
        ui->bubble_third_result_lineEdit->setText(
            QString::number(timer->nsecsElapsed()) + "ns");
      }
      else
      {
        ui->bubble_third_result_lineEdit->setText("-");
      }
    }
    else
    {
      ui->bubble_first_result_lineEdit->setText("-");
      ui->bubble_second_result_lineEdit->setText("-");
      ui->bubble_third_result_lineEdit->setText("-");
    }
    if (ui->selection_checkBox->isChecked())
    {
      if (ui->random_checkBox->isChecked())
      {
        temp_random_vector = random_test_vector;
        timer->start();
        sorts::selection_sort(temp_random_vector);
        ui->selection_first_result_lineEdit->setText(
            QString::number(timer->nsecsElapsed()) + "ns");
      }
      else
      {
        ui->selection_first_result_lineEdit->setText("-");
      }
      if (ui->atleast_sorted_inorder_checkBox->isChecked())
      {
        temp_in_order_vector = in_order_test_vector;
        timer->start();
        sorts::selection_sort(temp_in_order_vector);
        ui->selection_second_result_lineEdit->setText(
            QString::number(timer->nsecsElapsed()) + "ns");
      }
      else
      {
        ui->selection_second_result_lineEdit->setText("-");
      }
      if (ui->atleast_sorted_rev_checkBox->isChecked())
      {
        temp_in_reverse_order_vector = in_reverse_order_test_vector;
        timer->start();
        sorts::selection_sort(temp_in_reverse_order_vector);
        ui->selection_third_result_lineEdit->setText(
            QString::number(timer->nsecsElapsed()) + "ns");
      }
      else
      {
        ui->selection_third_result_lineEdit->setText("-");
      }
    }
    else
    {
      ui->selection_first_result_lineEdit->setText("-");
      ui->selection_second_result_lineEdit->setText("-");
      ui->selection_third_result_lineEdit->setText("-");
    }
    if (ui->merge_checkBox->isChecked())
    {
        if (ui->random_checkBox->isChecked())
              {
                temp_random_vector = random_test_vector;
                timer->start();
                sorts::merge_sort(temp_random_vector);
                ui->merge_first_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->merge_first_result_lineEdit->setText("-");
              }
              if (ui->atleast_sorted_inorder_checkBox->isChecked())
              {
                temp_in_order_vector = in_order_test_vector;
                timer->start();
                sorts::merge_sort(temp_in_order_vector);
                ui->merge_second_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->merge_second_result_lineEdit->setText("-");
              }
              if (ui->atleast_sorted_rev_checkBox->isChecked())
              {
                temp_in_reverse_order_vector = in_reverse_order_test_vector;
                timer->start();
                sorts::merge_sort(temp_in_reverse_order_vector);
                ui->merge_third_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->merge_third_result_lineEdit->setText("-");
              }
    }
    else
    {
        ui->merge_first_result_lineEdit->setText("-");
        ui->merge_second_result_lineEdit->setText("-");
        ui->merge_third_result_lineEdit->setText("-");
    }
    if (ui->quick_checkBox->isChecked())
    {
        if (ui->random_checkBox->isChecked())
              {
                temp_random_vector = random_test_vector;
                timer->start();
                sorts::quick_sort(temp_random_vector);
                ui->quick_first_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->quick_first_result_lineEdit->setText("-");
              }
              if (ui->atleast_sorted_inorder_checkBox->isChecked())
              {
                temp_in_order_vector = in_order_test_vector;
                timer->start();
                sorts::quick_sort(temp_in_order_vector);
                ui->quick_second_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->quick_second_result_lineEdit->setText("-");
              }
              if (ui->atleast_sorted_rev_checkBox->isChecked())
              {
                temp_in_reverse_order_vector = in_reverse_order_test_vector;
                timer->start();
                sorts::quick_sort(temp_in_reverse_order_vector);
                ui->quick_third_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->quick_third_result_lineEdit->setText("-");
              }
    }
    else
    {
        ui->quick_first_result_lineEdit->setText("-");
        ui->quick_second_result_lineEdit->setText("-");
        ui->quick_third_result_lineEdit->setText("-");
    }
    if (ui->gnome_checkBox->isChecked())
    {
        if (ui->random_checkBox->isChecked())
              {
                temp_random_vector = random_test_vector;
                timer->start();
                sorts::gnome_sort(temp_random_vector);
                ui->gnome_first_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->gnome_first_result_lineEdit->setText("-");
              }
              if (ui->atleast_sorted_inorder_checkBox->isChecked())
              {
                temp_in_order_vector = in_order_test_vector;
                timer->start();
                sorts::gnome_sort(temp_in_order_vector);
                ui->gnome_second_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->gnome_second_result_lineEdit->setText("-");
              }
              if (ui->atleast_sorted_rev_checkBox->isChecked())
              {
                temp_in_reverse_order_vector = in_reverse_order_test_vector;
                timer->start();
                sorts::gnome_sort(temp_in_reverse_order_vector);
                ui->gnome_third_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->gnome_third_result_lineEdit->setText("-");
              }
    }
    else
    {
        ui->gnome_first_result_lineEdit->setText("-");
        ui->gnome_second_result_lineEdit->setText("-");
        ui->gnome_third_result_lineEdit->setText("-");
    }
    if (ui->cocktail_shaker_checkBox->isChecked())
    {
        if (ui->random_checkBox->isChecked())
              {
                temp_random_vector = random_test_vector;
                timer->start();
                sorts::cocktail_shaker_sort(temp_random_vector);
                ui->cocktail_shaker_first_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->cocktail_shaker_first_result_lineEdit->setText("-");
              }
              if (ui->atleast_sorted_inorder_checkBox->isChecked())
              {
                temp_in_order_vector = in_order_test_vector;
                timer->start();
                sorts::cocktail_shaker_sort(temp_in_order_vector);
                ui->cocktail_shaker_second_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->cocktail_shaker_second_result_lineEdit->setText("-");
              }
              if (ui->atleast_sorted_rev_checkBox->isChecked())
              {
                temp_in_reverse_order_vector = in_reverse_order_test_vector;
                timer->start();
                sorts::cocktail_shaker_sort(temp_in_reverse_order_vector);
                ui->cocktail_shaker_third_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->cocktail_shaker_third_result_lineEdit->setText("-");
              }
    }
    else
    {
        ui->cocktail_shaker_first_result_lineEdit->setText("-");
        ui->cocktail_shaker_second_result_lineEdit->setText("-");
        ui->cocktail_shaker_third_result_lineEdit->setText("-");
    }
    if (ui->odd_even_checkBox->isChecked())
    {
        if (ui->random_checkBox->isChecked())
              {
                temp_random_vector = random_test_vector;
                timer->start();
                sorts::odd_even_sort(temp_random_vector);
                ui->odd_even_first_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->odd_even_first_result_lineEdit->setText("-");
              }
              if (ui->atleast_sorted_inorder_checkBox->isChecked())
              {
                temp_in_order_vector = in_order_test_vector;
                timer->start();
                sorts::odd_even_sort(temp_in_order_vector);
                ui->odd_even_second_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->odd_even_second_result_lineEdit->setText("-");
              }
              if (ui->atleast_sorted_rev_checkBox->isChecked())
              {
                temp_in_reverse_order_vector = in_reverse_order_test_vector;
                timer->start();
                sorts::odd_even_sort(temp_in_reverse_order_vector);
                ui->odd_even_third_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->odd_even_third_result_lineEdit->setText("-");
              }
    }
    else
    {
        ui->odd_even_first_result_lineEdit->setText("-");
        ui->odd_even_second_result_lineEdit->setText("-");
        ui->odd_even_third_result_lineEdit->setText("-");
    }
    if (ui->comb_checkBox->isChecked())
    {
        if (ui->random_checkBox->isChecked())
              {
                temp_random_vector = random_test_vector;
                timer->start();
                sorts::comb_sort(temp_random_vector);
                ui->comb_first_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->comb_first_result_lineEdit->setText("-");
              }
              if (ui->atleast_sorted_inorder_checkBox->isChecked())
              {
                temp_in_order_vector = in_order_test_vector;
                timer->start();
                sorts::comb_sort(temp_in_order_vector);
                ui->comb_second_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->comb_second_result_lineEdit->setText("-");
              }
              if (ui->atleast_sorted_rev_checkBox->isChecked())
              {
                temp_in_reverse_order_vector = in_reverse_order_test_vector;
                timer->start();
                sorts::comb_sort(temp_in_reverse_order_vector);
                ui->comb_third_result_lineEdit->setText(
                    QString::number(timer->nsecsElapsed()) + "ns");
              }
              else
              {
                ui->comb_third_result_lineEdit->setText("-");
              }
    }
    else
    {
        ui->comb_first_result_lineEdit->setText("-");
        ui->comb_second_result_lineEdit->setText("-");
        ui->comb_third_result_lineEdit->setText("-");
    }
}


void algorithms_efficiency_window::on_start_pushButton_clicked()
{
    this->sorting();
    /*QVector<bool> modes;
    modes.push_back(ui->random_checkBox->isChecked());
    modes.push_back(ui->atleast_sorted_inorder_checkBox);
    modes.push_back(ui->atleast_sorted_rev_checkBox);

    sort_thread my_st_class(modes);

    if(ui->bubble_checkBox)
    {
        QObject::connect(&sortThread, &QThread::started, &my_st_class, &sort_thread::bubble_sort_durations);

        my_st_class.moveToThread(&sortThread);
        thread()->start();
    }*/
    //moveToThread(&sort_thread);

  // this->random();
    // this->atleast_sorted_in_reverse_order();
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

void algorithms_efficiency_window::onGetResult(QString res)
{
    sort_thread_running = false;
    switch (current_sort) {
    case Sort::BUBBLE :
    {
        switch (current_array_type) {
        case Array_type::full_random :
        {
            ui->bubble_first_result_lineEdit->setText(res);
            break;
        }
        case Array_type::almost_sorted :
        {
            ui->bubble_second_result_lineEdit->setText(res);
            break;
        }
        case Array_type::almost_sorted_reverse :
        {
            ui->bubble_third_result_lineEdit->setText(res);
            break;
        }
        }
        break;
    }
    case Sort::COCKTAIL_SHAKER :
    {
        switch (current_array_type) {
        case Array_type::full_random :
        {
            ui->bubble_first_result_lineEdit->setText(res);
            break;
        }
        case Array_type::almost_sorted :
        {
            ui->bubble_second_result_lineEdit->setText(res);
            break;
        }
        case Array_type::almost_sorted_reverse :
        {
            ui->bubble_third_result_lineEdit->setText(res);
            break;
        }
        }
        break;
    }
    case Sort::COMB :
    {
        switch (current_array_type) {
        case Array_type::full_random :
        {
            ui->bubble_first_result_lineEdit->setText(res);
            break;
        }
        case Array_type::almost_sorted :
        {
            ui->bubble_second_result_lineEdit->setText(res);
            break;
        }
        case Array_type::almost_sorted_reverse :
        {
            ui->bubble_third_result_lineEdit->setText(res);
            break;
        }
        }
        break;
    }
    case Sort::GNOME:
    {
        switch (current_array_type) {
        case Array_type::full_random :
        {
            ui->bubble_first_result_lineEdit->setText(res);
            break;
        }
        case Array_type::almost_sorted :
        {
            ui->bubble_second_result_lineEdit->setText(res);
        }
        case Array_type::almost_sorted_reverse :
        {
            ui->bubble_third_result_lineEdit->setText(res);
            break;
        }
        }
        break;
    }
    case Sort::MERGE:
    {
        switch (current_array_type) {
        case Array_type::full_random :
        {
            ui->bubble_first_result_lineEdit->setText(res);
            break;
        }
        case Array_type::almost_sorted :
        {
            ui->bubble_second_result_lineEdit->setText(res);
            break;
        }
        case Array_type::almost_sorted_reverse :
        {
            ui->bubble_third_result_lineEdit->setText(res);
            break;
        }
        }
        break;
    }
    case Sort::ODD_EVEN:
    {
        switch (current_array_type) {
        case Array_type::full_random :
        {

            break;
        }
        case Array_type::almost_sorted :
        {

            break;
        }
        case Array_type::almost_sorted_reverse :
        {

            break;
        }
        }
        break;
    }
    case Sort::QUICK:
    {
        switch (current_array_type) {
        case Array_type::full_random :
        {

            break;
        }
        case Array_type::almost_sorted :
        {

            break;
        }
        case Array_type::almost_sorted_reverse :
        {

            break;
        }
        }
    }
    case Sort::SELECTION:
    {
        switch (current_array_type) {
        case Array_type::full_random :
        {

            break;
        }
        case Array_type::almost_sorted :
        {

            break;
        }
        case Array_type::almost_sorted_reverse :
        {

            break;
        }
        }
    }
        break;
    }
}
