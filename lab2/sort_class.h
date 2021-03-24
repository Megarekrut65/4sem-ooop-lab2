#ifndef SORT_CLASS_H
#define SORT_CLASS_H
#include <vector>
#include "my_graphics_view.h"
#include <QThread>
#include <QDebug>
/*!
* SortClass
*/
namespace sc
{
    template<typename T>
    class SortClass
    {
    private:

        sd::MyGraphicsView<T>* view;
        QString name;
        void display(std::vector<T>& arr);
        void copy_to_array(std::vector<T>& arr, std::vector<T>& copy_arr, std::size_t begin, std::size_t size);
        void merge(std::vector<T>& arr, std::size_t begin, std::size_t middle, std::size_t end);
        void merge_sorting(std::vector<T>& arr, std::size_t begin, std::size_t end);
    public:
        SortClass();
        void merge_sort(std::vector<T>& arr);
    };
}
namespace sc
{
    template<typename T>
    SortClass<T>::SortClass():view(nullptr),name("Sort"){}
    template<typename T>
    void SortClass<T>::display(std::vector<T>& arr)
    {
        view->create_new_scene(arr);
        QThread::msleep(500);
    }
    template<typename T>
    void SortClass<T>::copy_to_array(std::vector<T>& arr, std::vector<T>& copy_arr, std::size_t begin, std::size_t size)
    {
        copy_arr.clear();
        for (std::size_t i = 0; i < size; i++)
        {
            copy_arr.push_back(arr[begin + i]);
        }
    }
    template<typename T>
    void SortClass<T>::merge(std::vector<T>& arr, std::size_t begin, std::size_t middle, std::size_t end)
    {
        std::size_t left_size = middle - begin, right_size = end - middle;
        std::size_t i = 0, j = 0, k = begin;
        std::vector<T> left_arr, right_arr;
        copy_to_array(arr, left_arr, begin, left_size);
        copy_to_array(arr, right_arr, middle, right_size);
        while (i < left_size && j < right_size)
        {
            if (left_arr[i] <= right_arr[j])
            {
                arr[k] = left_arr[i];
                i++;
            }
            else
            {
                arr[k] = right_arr[j];
                j++;
            }
            k++;
            display(arr);
        }
        for (; i < left_size; i++, k++)
        {
            arr[k] = left_arr[i];
            display(arr);
        }
        for (; j < right_size; j++, k++)
        {
            arr[k] = right_arr[j];
            display(arr);
        }
    }
    template<typename T>
    void SortClass<T>::merge_sorting(std::vector<T>& arr, std::size_t begin, std::size_t end)
    {
        if (end - begin < 2) return;
        std::size_t middle = (end + begin) / 2;
        merge_sorting(arr, begin, middle);
        merge_sorting(arr, middle, end);
        merge(arr, begin, middle, end);
    }
    template<typename T>
    void SortClass<T>::merge_sort(std::vector<T>& arr)
    {
        name = "Merge sort";
        view = new sd::MyGraphicsView<T>(name, arr);
        view->show();
        merge_sorting(arr, 0, arr.size());
        //delete view;
    }
}
#endif // SORT_CLASS_H
