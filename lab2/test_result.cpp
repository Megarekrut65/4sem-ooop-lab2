#include "test_result.h"

test_result::test_result(const Sort &sort, const Array_type &array_type, const Time_units& time_units, const QString &result)
{
    this->sort = sort;
    this->array_type = array_type;
    this->time_units = time_units;
    this->result = result;
}
