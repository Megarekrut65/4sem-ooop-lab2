#ifndef SORT_THREAD_H
#define SORT_THREAD_H

#include <QThread>
#include <QElapsedTimer>
#include "Sorts/libraries_and_namespaces.h"
#include "Sorts/all_sorts.h"

class sort_thread : public QThread
{
    Q_OBJECT
public:
    explicit sort_thread(QObject *parent = nullptr);
    ~sort_thread();
    void run();

    bool Stop;
    void set_sort(const Sort& select_sort);
    void set_array_type(const Array_type& select_array_type);
    void set_time_units(const Time_units& select_time_units);
    void set_array(std::vector<int>& array);

private:
    Sort current_sort;
    Array_type current_array_type;
    Time_units current_time_units;
    QElapsedTimer *timer;/*!< Timer for sorts durations */
    std::vector<int>* array;
signals:
    void SentResult(QString);
};

#endif // SORT_THREAD_H
