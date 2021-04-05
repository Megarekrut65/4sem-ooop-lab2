#ifndef COMB_SORT_H
#define COMB_SORT_H
#include "Sorts/libraries_and_namespaces.h"

namespace sorts
{
    /*!
    *   \brief Sorts array
    *
    *   See [Comb sort.](https://en.wikipedia.org/wiki/Comb_sort "Information about this algorithm in Wikipedia")
    */
    template<typename T>
    void comb_sort(std::vector<T>& arr);
}
namespace sorts
{
    template<typename T>
    void comb_sort(std::vector<T>& arr)
    {
        const double shrink = 1.3;

        bool swapped = false;
        size_t gap = arr.size();

        while ((gap > 1) || swapped)
        {
            if (gap > 1) {
                gap = (size_t)((float)gap / shrink);
            }

            swapped = false;

            for (size_t i = 0; gap + i < arr.size(); ++i)
            {
                if (arr[i] > arr[i + gap])
                {
                    swap(arr[i], arr[i+gap]);
                    swapped = true;
                }
            }
        }
    }
}
#endif // COMB_SORT_H
