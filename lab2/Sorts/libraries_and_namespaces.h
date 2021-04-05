#ifndef LIBRARIES_AND_NAMESPACES_H
#define LIBRARIES_AND_NAMESPACES_H
#include <vector>
#include <string>

/*!
*   \brief Namespace for sort algorithm and addition functions
*/
namespace sorts
{
    /*!
    *   \brief Copies part of arr to copy_arr
    *
    *   Addition function for merge_sort().
    *   \param arr - array of items
    *   \param copy_arr - empty array
    *   \param begin - begin index of part to copy
    *   \param size - size of part to copy
    */
    template<typename T>
    void copy_to_array(std::vector<T>& arr, std::vector<T>& copy_arr, std::size_t begin, std::size_t size);
    /*!
    *   \brief Spaws two items
    *
    *   Addition function for bubble_sort(), selection_sort() and quick_sort().
    */
    template<typename T>
    void swap(T& first, T& second);
    /*!
    *   \brief Translates array to line
    *
    *   Addition function.
    */
    template<typename T>
    std::string array_to_string(std::vector<T>& arr);
    /*!
    *   \brief Returns maximum item in arr
    *
    *   Addition function.
    */
    template<typename T>
    T get_max(std::vector<T>& arr);
    /*!
    *   \brief Returns minimum item in arr
    *
    *   Addition function.
    */
    template<typename T>
    T get_min(std::vector<T>& arr);
}
namespace sorts
{
    template<typename T>
    void copy_to_array(std::vector<T>& arr, std::vector<T>& copy_arr, std::size_t begin, std::size_t size)
    {
        copy_arr.clear();
        for (std::size_t i = 0; i < size; i++)
        {
            copy_arr.push_back(arr[begin + i]);
        }
    }
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
