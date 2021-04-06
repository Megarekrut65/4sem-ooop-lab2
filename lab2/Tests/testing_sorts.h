#ifndef TESTING_SORTS_H
#define TESTING_SORTS_H
#include "doctest.h"
#include "sort_class.h"
#include "Sorts/all_sorts.h"
#include <iostream>

void subcase_sorts(sc::SortClass<int>& sort, std::vector<int>& arr1, std::vector<int>& arr2)
{
    SUBCASE("merge sort")
    {
        sort.merge_sort(arr1);
        sorts::merge_sort(arr2);
    }
    SUBCASE("bubble sort")
    {
        sort.bubble_sort(arr1);
        sorts::bubble_sort(arr2);
    }
    SUBCASE("selection sort")
    {
        sort.selection_sort(arr1);
        sorts::selection_sort(arr2);
    }
    SUBCASE("quick sort")
    {
        sort.quick_sort(arr1);
        sorts::quick_sort(arr2);
    }
    SUBCASE("gnome sort")
    {
        sort.gnome_sort(arr1);
        sorts::gnome_sort(arr2);
    }
    SUBCASE("comb sort")
    {
        sort.comb_sort(arr1);
        sorts::comb_sort(arr2);
    }
    SUBCASE("cocktail shaker sort")
    {
        sort.cocktail_shaker_sort(arr1);
        sorts::cocktail_shaker_sort(arr2);
    }
    SUBCASE("odd-even shaker sort")
    {
        sort.odd_even_sort(arr1);
        sorts::odd_even_sort(arr2);
    }
}
void test_all_sorts(std::vector<int>& arr)
{
    sc::SortClass<int> sort;
    auto arr1 = arr, arr2 = arr;
    std::sort(arr.begin(), arr.end());
    CHECK(!(arr1 == arr));
    CHECK(!(arr2 == arr));
    subcase_sorts(sort, arr1, arr2);
    CHECK(arr1 == arr);
    CHECK(arr2 == arr);
}
TEST_CASE("testing on random items")
{
    std::size_t size = 100;
    auto arr = create_random_array<int>(size);
    test_all_sorts(arr);
}
TEST_CASE("testing on ordered items")
{
    std::size_t size = 100;
    auto arr = create_ordered_array<int>(size, 8*size/10);
    test_all_sorts(arr);
}
TEST_CASE("testing on inordered items")
{
    std::size_t size = 100;
    auto arr = create_inordered_array<int>(size, 8*size/10);
    test_all_sorts(arr);
}
TEST_CASE("testing on own items")
{
    std::vector<int> arr ={4,8,1,3,9,3,2,0,1,0,4,3,2,17,43,7,12,89,32,6,3,1,9,5,4};
    sc::SortClass<int> sort;
    auto arr1 = arr, arr2 = arr;
    subcase_sorts(sort, arr1, arr2);
    CHECK(arr1 == std::vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9, 9, 12, 17, 32, 43, 89 });
    CHECK(arr2 == std::vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9, 9, 12, 17, 32, 43, 89 });
}
#endif // TESTING_SORTS_H
