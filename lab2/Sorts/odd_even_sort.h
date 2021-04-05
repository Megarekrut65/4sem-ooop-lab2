#ifndef ODD_EVEN_SORT_H
#define ODD_EVEN_SORT_H
#include "Sorts/libraries_and_namespaces.h"

namespace sorts
{
    /*!
    *   \brief Sorts array
    *
    *   See [Odd-even sort.](https://en.wikipedia.org/wiki/Odd-even_sort "Information about this algorithm in Wikipedia")
    */
    template<typename T>
    void odd_even_sort(std::vector<T>& arr);
}
namespace sorts
{
    template<typename T>
    void odd_even_sort(std::vector<T>& arr)
    {
        bool sorted = false;
            while (!sorted)
            {
                sorted = true;

                for (size_t i = 1; i < arr.size()-1; i += 2)
                {
                    if(arr[i] > arr[i+1])
                    {
                        swap(arr[i], arr[i+1]);
                        sorted = false;
                    }
                }

                for (size_t i = 0; i < arr.size()-1; i += 2)
                {
                    if(arr[i] > arr[i+1])
                    {
                        swap(arr[i], arr[i+1]);
                        sorted = false;
                    }
                }
            }
    }
}
#endif // ODD_EVEN_SORT_H
