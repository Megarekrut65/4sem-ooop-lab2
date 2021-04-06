#ifndef SORT_THREAD_H
#define SORT_THREAD_H

#include <QObject>

class sort_thread : public QObject
{
    Q_OBJECT
public:
    explicit sort_thread(const QVector<bool>& sort_modes, QObject *parent = 0);
    QVector<bool> sort_modes;
    QVector<bool> sorts_enabled;
    QVector<QString> bubble_sort_durations();
public slots:


};

#endif // SORT_THREAD_H
