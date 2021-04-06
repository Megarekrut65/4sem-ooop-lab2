#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H
#include "libraries_and_namespaces.h"

namespace sorts
{
    /*!
    *   \brief Sorts array
    *
    *   See [Selection sort.](https://en.wikipedia.org/wiki/Selection_sort "Information about this algorithm in Wikipedia")
    */
    template<typename T>
    void selection_sort(std::vector<T>& arr);
}
namespace sorts
{
    template<typename T>
    void selection_sort(std::vector<T>& arr)
    {
        std::size_t min_index = 0, size = arr.size();
        for (std::size_t i = 0; i < size-1; i++)
        {
            min_index = i;
            for (std::size_t j = i+1; j < size; j++)
                    if (arr[j] < arr[min_index])
                            min_index = j;
            swap(arr[min_index], arr[i]);
        }
    }
}
#endif // SELECTION_SORT_H

