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
    template<typename T>
    T get_max(std::vector<T>& arr);
    template<typename T>
    T get_min(std::vector<T>& arr);
}
namespace sorts//sorts...
{
    template<typename T>
    T get_max(std::vector<T>& arr)
    {
        if(arr.size() < 1) return T();
        T max = arr[0];
        for(std::size_t i = 1; i < arr.size(); i++)
            if(arr[i] > max) max = arr[i];
        return max;
    }
    template<typename T>
    T get_min(std::vector<T>& arr)
    {
        if(arr.size() < 1) return T();
        T min = arr[0];
        for(std::size_t i = 1; i < arr.size(); i++)
            if(arr[i] < min) min = arr[i];
        return min;
    }
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
