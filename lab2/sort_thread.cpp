#include "sort_thread.h"
#include <QtCore>

sort_thread::sort_thread(QObject *parent) : QThread(parent), current_time_units(Time_units::ms), timer(new QElapsedTimer), Stop(true)
{

}

sort_thread::~sort_thread()
{
    delete timer;
}

void sort_thread::run()
{
    Stop = false;
    QString res;
    QMutex mutex;
    mutex.lock();




    timer->start();

    if(current_sort==Sort::BUBBLE)
    {
        sorts::bubble_sort(*array);
    }
    else if(current_sort==Sort::COCKTAIL_SHAKER)
    {
        sorts::cocktail_shaker_sort(*array);
    }
    else if(current_sort==Sort::COMB)
    {
        sorts::comb_sort(*array);
    }
    else if(current_sort==Sort::GNOME)
    {
        sorts::gnome_sort(*array);
    }
    else if(current_sort==Sort::MERGE)
    {
        sorts::merge_sort(*array);
    }
    else if(current_sort==Sort::ODD_EVEN)
    {
        sorts::odd_even_sort(*array);
    }
    else if(current_sort==Sort::QUICK)
    {
        sorts::quick_sort(*array);
    }
    else if(current_sort==Sort::SELECTION)
    {
        sorts::selection_sort(*array);
    }
    else
    {
        throw std::runtime_error("Not selected sort!");
    }

    if(current_time_units==Time_units::ms)
    {
        res = QString::number(timer->elapsed()) + "ms";
    }
    else if (current_time_units==Time_units::ns)
    {
        res = QString::number(timer->nsecsElapsed()) + "ns";
    }
    mutex.unlock();
    emit SentResult(res);
    Stop = true;
}

void sort_thread::set_sort(const Sort &select_sort)
{
    current_sort=select_sort;
}

void sort_thread::set_array_type(const Array_type &select_array_type)
{
    current_array_type = select_array_type;
}

void sort_thread::set_time_units(const Time_units &select_time_units)
{
    current_time_units = select_time_units;
}

void sort_thread::set_array(std::vector<int> &array)
{
    this->array=&array;
}
