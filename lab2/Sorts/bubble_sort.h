#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include "Sorts/libraries_and_namespaces.h"

namespace sorts
{
    template<typename T>
    void bubble_sort(std::vector<T>& arr);
}
namespace sorts
{
    template<typename T>
    void bubble_sort(std::vector<T>& arr)
    {
        for(std::size_t i = 0; i < arr.size();i++)
            for(std::size_t j = 0; j < arr.size() - i - 1;j++)
                if(arr[j] > arr[j + 1]) swap(arr[j],arr[j+1]);
    }
}
#endif // BUBBLE_SORT_H