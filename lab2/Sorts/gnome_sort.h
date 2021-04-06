#ifndef GNOME_SORT_H
#define GNOME_SORT_H
#include "libraries_and_namespaces.h"

namespace sorts
{
    /*!
    *   \brief Sorts array
    *
    *   See [Gnome sort.](https://en.wikipedia.org/wiki/Gnome_sort "Information about this algorithm in Wikipedia")
    */
    template<typename T>
    void gnome_sort(std::vector<T>& arr);
}
namespace sorts
{
    template<typename T>
    void gnome_sort(std::vector<T>& arr)
    {
        for (size_t i = 1; i < arr.size(); )
        {
            if (arr[i] >= arr[i-1])
            {
                ++i;
            }
            else
            {
                swap(arr[i], arr[i-1]);
                if (i > 1) --i;
            }
        }
    }
}
#endif // GNOME_SORT_H
