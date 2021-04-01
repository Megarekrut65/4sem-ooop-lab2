#ifndef MEMENTO_SORTING_H
#define MEMENTO_SORTING_H
#include "Sorts/libraries_and_namespaces.h"
/*!
*   Memento of sorting
*/
namespace ms
{
    template<typename T>
    struct MementoSorting
    {
        std::vector<T> array;
        std::vector<bool> marks;
        MementoSorting(const std::vector<T>& array);
        void set_mark(std::size_t begin, std::size_t end);
        void set_mark(std::size_t index);
    };
}
namespace ms
{
    template<typename T>
    MementoSorting<T>::MementoSorting(const std::vector<T>& array):
        array{array}
    {
        marks = std::vector<bool>(array.size(),false);
    }
    template<typename T>
    void MementoSorting<T>::set_mark(std::size_t begin, std::size_t end)
    {
        if(begin >= marks.size() || end >=marks.size() || begin == end) return;
        for(std::size_t i = begin; i <= end; i++)
                marks[i] = true;
    }
    template<typename T>
    void MementoSorting<T>::set_mark(std::size_t index)
    {
        if(index < marks.size())
        {
            marks[index] = true;
        }
    }
}
#endif // MEMENTO_SORTING_H
