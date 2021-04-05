#ifndef COCKTAILSHAKER_SORT_H
#define COCKTAILSHAKER_SORT_H

#include "Sorts/libraries_and_namespaces.h"

namespace sorts
{
    /*!
    *   \brief Sorts array
    *
    *   See [Cocktailshaker sort.](https://en.wikipedia.org/wiki/Cocktail_shaker_sort "Information about this algorithm in Wikipedia")
    */
    template<typename T>
    void cocktailshaker_sort(std::vector<T>& arr);
}
namespace sorts
{
    template<typename T>
    void cocktailshaker_sort(std::vector<T>& arr)
    {
        size_t lo = 0, hi = arr.size() - 1, mov = lo;
            while (lo < hi)
            {
                for (size_t i = hi; i > lo; --i)
                {
                    if (arr[i-1] > arr[i])
                    {
                        swap(arr[i-1], arr[i]);
                        mov = i;
                    }
                }
                lo = mov;
                for (size_t i = lo; i < hi; ++i)
                {
                    if (arr[i] > arr[i+1])
                    {
                        swap(arr[i], arr[i+1]);
                        mov = i;
                    }
                }
                hi = mov;
            }
    }
}
#endif // COCKTAILSHAKER_SORT_H
