#ifndef TEST_RESULT_H
#define TEST_RESULT_H

#include <QString>

enum class Sort
{
    BUBBLE,
    COCKTAIL_SHAKER,
    COMB,
    GNOME,
    MERGE,
    ODD_EVEN,
    QUICK,
    SELECTION
};

enum class Array_type
{
    full_random,
    almost_sorted,
    almost_sorted_reverse
};

enum class Time_units
{
    ns,
    ms
};

class test_result
{
public:
    test_result(const Sort& sort, const Array_type& array_type, const Time_units& time_units, const QString& result);
    Sort sort;
    Array_type array_type;
    Time_units time_units;
    QString result;

};

#endif // TEST_RESULT_H
