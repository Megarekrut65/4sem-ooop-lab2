#ifndef LIBRARIES_AND_NAMESPACES_H
#define LIBRARIES_AND_NAMESPACES_H
#include <vector>

namespace sorts//sorts...
{
    template<typename T>
    void swap(T& first, T& second);
}
namespace sorts//sorts...
{
    template<typename T>
    void swap(T& first, T& second)
    {
        T temp = first;
        first = second;
        second = temp;
    }
}
#endif // LIBRARIES_AND_NAMESPACES_H
