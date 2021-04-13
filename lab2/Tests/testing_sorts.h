#ifndef TESTING_SORTS_H
#define TESTING_SORTS_H
#include "doctest.h"
#include "sort_class.h"
#include "Sorts/all_sorts.h"
#include <iostream>

void subcase_sorts(sc::SortClass<int>& sort, std::vector<int>& array_for_diagram, std::vector<int>& array_for_benchmark)
{
    SUBCASE("merge sort")
    {
        sort.merge_sort(array_for_diagram);
        sorts::merge_sort(array_for_benchmark);
    }
    SUBCASE("bubble sort")
    {
        sort.bubble_sort(array_for_diagram);
        sorts::bubble_sort(array_for_benchmark);
    }
    SUBCASE("selection sort")
    {
        sort.selection_sort(array_for_diagram);
        sorts::selection_sort(array_for_benchmark);
    }
    SUBCASE("quick sort")
    {
        sort.quick_sort(array_for_diagram);
        sorts::quick_sort(array_for_benchmark);
    }
    SUBCASE("gnome sort")
    {
        sort.gnome_sort(array_for_diagram);
        sorts::gnome_sort(array_for_benchmark);
    }
    SUBCASE("comb sort")
    {
        sort.comb_sort(array_for_diagram);
        sorts::comb_sort(array_for_benchmark);
    }
    SUBCASE("cocktail shaker sort")
    {
        sort.cocktail_shaker_sort(array_for_diagram);
        sorts::cocktail_shaker_sort(array_for_benchmark);
    }
    SUBCASE("odd-even shaker sort")
    {
        sort.odd_even_sort(array_for_diagram);
        sorts::odd_even_sort(array_for_benchmark);
    }
}
void test_all_sorts(std::vector<int>& arr)
{
    sc::SortClass<int> sort;
    std::vector<int> array_for_diagram = arr, //this array will be sorted by SortClass. This class to saving states of sorting
                     array_for_benchmark = arr; //this array will be sorted by sort functions. These functions to time measurement of sorting
    std::sort(arr.begin(), arr.end());
    CHECK(!(array_for_diagram == arr));
    CHECK(!(array_for_benchmark == arr));
    subcase_sorts(sort, array_for_diagram, array_for_benchmark);
    CHECK(array_for_diagram == arr);
    CHECK(array_for_benchmark == arr);
}
TEST_CASE("testing on random items")
{
    std::size_t size = 100;
    std::vector<int> arr = create_random_array<int>(size);
    test_all_sorts(arr);
}
TEST_CASE("testing on ordered items")
{
    std::size_t size = 100;
    std::vector<int> arr = create_ordered_array<int>(size, 8*size/10);
    test_all_sorts(arr);
}
TEST_CASE("testing on reverse ordered items")
{
    std::size_t size = 100;
    std::vector<int> arr = create_reverse_ordered_array<int>(size, 8*size/10);
    test_all_sorts(arr);
}
TEST_CASE("testing on own items")
{
    std::vector<int> arr ={4,8,1,3,9,3,2,0,1,0,4,3,2,17,43,7,12,89,32,6,3,1,9,5,4};
    sc::SortClass<int> sort;
    std::vector<int> array_for_diagram = arr, array_for_benchmark = arr;
    subcase_sorts(sort, array_for_diagram, array_for_benchmark);
    CHECK(array_for_diagram == std::vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9, 9, 12, 17, 32, 43, 89 });
    CHECK(array_for_diagram == std::vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 6, 7, 8, 9, 9, 12, 17, 32, 43, 89 });
}
TEST_CASE("testing creating about ordered array")
{
    std::size_t size = 100, part = 8*size/10;
    std::vector<int> arr = create_ordered_array<int>(size, part);
    REQUIRE(size == arr.size());
    std::size_t number = 0;
    for(std::size_t i = 1; i < size; i++)
    {
        if(arr[i- 1] < arr[i] ) number++;
        else break;
    }
    CHECK(number >= part);
}
TEST_CASE("testing creating about reverse ordered array")
{
    std::size_t size = 100, part = 8*size/10;
    std::vector<int> arr = create_reverse_ordered_array<int>(size, part);
    REQUIRE(size == arr.size());
    std::size_t number = 0;
    for(std::size_t i = 1; i < size; i++)
    {
        if(arr[i - 1] > arr[i] ) number++;
        else break;
    }
    CHECK(number >= part);
}
TEST_CASE("testing creating random array")
{
    std::size_t size = 100;
    std::vector<int> arr = create_random_array<int>(size);
    REQUIRE(size == arr.size());
}
#endif // TESTING_SORTS_H
