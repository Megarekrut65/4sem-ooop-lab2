#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "Sorts/libraries_and_namespaces.h"

namespace sorts
{
    //Lomuto partition scheme, rightmost pivot
    template<typename T>
    std::size_t partition(std::vector<T>& arr, long low, long high);
    template<typename T>
    void quick_sorting(std::vector<T>& arr, long low, long high);
    template<typename T>
    void quick_sort(std::vector<T>& arr);
}
namespace sorts
{
    template<typename T>
    std::size_t partition(std::vector<T>& arr, long low, long high)
    {
        T pivot = arr[high];
        long i = low - 1;
        for (long j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return std::size_t(i + 1);
    }
    template<typename T>
    void quick_sorting(std::vector<T>& arr, long low, long high)
    {
        if (low < high)
        {
            std::size_t index = partition(arr, low, high);
            quick_sorting(arr, low, index - 1);
            quick_sorting(arr, index + 1, high);
        }
    }
    template<typename T>
    void quick_sort(std::vector<T>& arr)
    {
        if(arr.size() < 2) return;
        quick_sorting(arr, 0, arr.size() - 1);
    }
}
#endif // QUICK_SORT_H
