#ifndef TESTING_SORTS_H
#define TESTING_SORTS_H
#include "doctest.h"
#include "sort_class.h"
#include "Sorts/all_sorts.h"
TEST_CASE("testing example")
{
    sc::SortClass<int> sort;
    auto arr = create_random_array<int>(100);
    auto arr1 = arr, arr2 = arr;
    sort.merge_sort(arr1);
    sorts::merge_sort(arr2);
    std::sort(arr.begin(), arr.end());
    CHECK(arr1 == arr);
    CHECK(arr2 == arr);
}
#endif // TESTING_SORTS_H
