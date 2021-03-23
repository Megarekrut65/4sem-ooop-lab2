#ifndef LIBRARIES_AND_NAMESPACES_H
#define LIBRARIES_AND_NAMESPACES_H
#include <vector>
#include <string>

namespace sorts//sorts...
{
    template<typename T>
    void swap(T& first, T& second);
    template<typename T>
    std::string array_to_string(std::vector<T>& arr);
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
    template<typename T>
    std::string array_to_string(std::vector<T>& arr)
    {
        std::string res = "";
        for(std::size_t i = 0; i < arr.size();i++)
            res += std::to_string(arr[i]) + " ";
        return res;
    }
}
#endif // LIBRARIES_AND_NAMESPACES_H
