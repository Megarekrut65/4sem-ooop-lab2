#ifndef SORT_CLASS_H
#define SORT_CLASS_H
#include <vector>
#include "originator_sorting.h"
#include <QString>
using namespace sorts;
using namespace ms;

/*!
* \brief Sort Class
*
* Namespace for class SortClass.
*/
namespace sc
{
    /*!
    *   \brief Template class to save all states of sorting
    *
    *   State will be added to queue when space of the item will be changed.
    *   If algorithm uses addition container(array, list, heap) to sort then this algorithm can not be added to this class
    *   (count sort, heap sort...).
    */
    template<typename T>
    class SortClass
    {
    private:
        /*!
        *   \brief Adds array(state of sorting) to queue
        */
        void display(const std::vector<T>& arr);
        /*!
        *   \brief Adds array(state of sorting) to queue and marks some items
        *
        *   \param arr - state of sorting
        *   \param mark_begin - index of begin item to mark
        *   \param mark_end - index of end item to mark
        */
        void display(const std::vector<T>& arr, std::size_t mark_begin, std::size_t mark_end);
        /*!
        *   \brief Adds array(state of sorting) to queue and mark the item
        *
        *   \param arr - state of sorting
        *   \param mark - index of item to mark
        */
        void display(const std::vector<T>& arr, std::size_t mark);
        /*!
        *   See sorts::merge().
        */
        void merge(std::vector<T>& arr, std::size_t begin, std::size_t middle, std::size_t end);
        /*!
        *   See sorts::merge_sorting().
        */
        void merge_sorting(std::vector<T>& arr, std::size_t begin, std::size_t end);
        /*!
        *   See sorts::partition().
        */
        std::size_t partition(std::vector<T>& arr, long low, long high);
        /*!
        *   See sorts::quick_sorting().
        */
        void quick_sorting(std::vector<T>& arr, long low, long high);
    public:
        QString name;/*!< Name of sort */
        OriginatorSorting<T> queue;/*!< Queue for all states of sorting */
        /*!
        *   \brief Creates object with empty queue
        */
        SortClass();
        /*!
        *   \brief Sorts array
        *
        *   See sorts::merge_sort().
        */
        void merge_sort(std::vector<T>& arr);
        /*!
        *   \brief Sorts array
        *
        *   See sorts::quick_sort().
        */
        void quick_sort(std::vector<T>& arr);
        /*!
        *   \brief Sorts array
        *
        *   See sorts::selection_sort().
        */
        void selection_sort(std::vector<T>& arr);
        /*!
        *   \brief Sorts array
        *
        *   See sorts::bubble_sort.
        */
        void bubble_sort(std::vector<T>& arr);
        /*!
        *   \brief Sorts array
        *
        *   See sorts::gnome_sort.
        */
        void gnome_sort(std::vector<T>& arr);
        /*!
        *   \brief Sorts array
        *
        *   See sorts::cocktail_shaker_sort.
        */
        void cocktail_shaker_sort(std::vector<T>& arr);
        /*!
        *   \brief Sorts array
        *
        *   See sorts::odd_even_sort.
        */
        void odd_even_sort(std::vector<T>& arr);
        /*!
        *   \brief Sorts array
        *
        *   See sorts::comb_sort.
        */
        void comb_sort(std::vector<T>& arr);
        /*!
        *   \brief Clears states
        */
        void clear();
    };
}
namespace sc
{
    template<typename T>
    std::size_t SortClass<T>::partition(std::vector<T>& arr, long low, long high)
    {
        T pivot = arr[high];
        long i = low - 1;
        for (long j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr[i], arr[j]);
                display(arr, high);
            }
        }
        swap(arr[i + 1], arr[high]);
        display(arr,high);
        return std::size_t(i + 1);
    }
    template<typename T>
    void SortClass<T>::quick_sorting(std::vector<T>& arr, long low, long high)
    {
        if (low < high)
        {
            std::size_t index = partition(arr, low, high);
            quick_sorting(arr, low, index - 1);
            quick_sorting(arr, index + 1, high);
        }
    }
    template<typename T>
    void SortClass<T>::quick_sort(std::vector<T>& arr)
    {
        name = "Quick sort";
        display(arr);
        if(arr.size() >= 2) quick_sorting(arr, 0, arr.size() - 1);
        display(arr);
    }
    template<typename T>
    void SortClass<T>::clear()
    {
        name = "";
        queue.clear();
    }
    template<typename T>
    void SortClass<T>::bubble_sort(std::vector<T>& arr)
    {
        name = "Bubble sort";
        display(arr);
        for(std::size_t i = 0; i < arr.size();i++)
            for(std::size_t j = 0; j < arr.size() - i - 1;j++)
                if(arr[j] > arr[j + 1])
                {
                    swap(arr[j],arr[j+1]);
                    display(arr, j, j + 1);
                }
        display(arr);
    }
    template<typename T>
    void SortClass<T>::selection_sort(std::vector<T>& arr)
    {
        name = "Selection sort";
        display(arr);
        if(arr.size() >= 2)
        {
            std::size_t min_index = 0, size = arr.size();
            for (std::size_t i = 0; i < size-1; i++)
            {
                min_index = i;
                for (std::size_t j = i+1; j < size; j++)
                        if (arr[j] < arr[min_index])
                                min_index = j;
                swap(arr[min_index], arr[i]);
                display(arr, min_index);
            }
        }
        display(arr);
    }
    template<typename T>
    SortClass<T>::SortClass(): name("Sort"){}
    template<typename T>
    void SortClass<T>::display(const std::vector<T>& arr, std::size_t mark_begin, std::size_t mark_end)
    {
        display(arr);
        auto state = queue.last_state();
        state->set_mark(mark_begin, mark_end);
    }
    template<typename T>
    void SortClass<T>::display(const std::vector<T>& arr, std::size_t mark)
    {
        display(arr);
        auto state = queue.last_state();
        state->set_mark(mark);
    }
    template<typename T>
    void SortClass<T>::display(const std::vector<T>& arr)
    {
        queue.append_state(MementoSorting(arr));
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
            display(arr, begin, end - 1);
        }
        for (; i < left_size; i++, k++)
        {
            arr[k] = left_arr[i];
            display(arr, begin, end - 1);
        }
        for (; j < right_size; j++, k++)
        {
            arr[k] = right_arr[j];
            display(arr, begin, end - 1);
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
        display(arr);
        merge_sorting(arr, 0, arr.size());
        display(arr);
    }
    template<typename T>
    void SortClass<T>::gnome_sort(std::vector<T>& arr)
    {
        display(arr);
        name = "Gnome sort";
        display(arr);
        for (size_t i = 1; i < arr.size(); )
        {
            if (arr[i] >= arr[i-1])
            {
                ++i;
            }
            else
            {
                swap(arr[i], arr[i-1]);
                display(arr, i - 1, i);
                if (i > 1) --i;
            }
        }
        display(arr);
    }

    template<typename T>
    void SortClass<T>::cocktail_shaker_sort(std::vector<T> &arr)
    {
        display(arr);
        name = "Cocktail shaker sort";
        if(arr.size() > 0)
        {
            size_t lo = 0, hi = arr.size() - 1, mov = lo;
            while (lo < hi)
            {
                for (size_t i = hi; i > lo; --i)
                {
                    if (arr[i-1] > arr[i])
                    {
                        swap(arr[i-1], arr[i]);
                        display(arr, i - 1, i);
                        mov = i;
                    }
                }
                lo = mov;
                for (size_t i = lo; i < hi; ++i)
                {
                    if (arr[i] > arr[i+1])
                    {
                        swap(arr[i], arr[i + 1]);
                        display(arr, i, i + 1);
                        mov = i;
                    }
                }
                hi = mov;
            }
        }
        display(arr);
    }
    template<typename T>
    void SortClass<T>::odd_even_sort(std::vector<T> &arr)
    {
        name = "Odd-even sort";
        display(arr);
        if(arr.size() > 0)
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
                        display(arr, i, i + 1);
                        sorted = false;
                    }
                }

                for (size_t i = 0; i < arr.size()-1; i += 2)
                {
                    if(arr[i] > arr[i+1])
                    {
                        swap(arr[i], arr[i+1]);
                        display(arr, i, i + 1);
                        sorted = false;
                    }
                }
            }
        }
        display(arr);
    }

    template<typename T>
    void SortClass<T>::comb_sort(std::vector<T> &arr)
    {
        name = "Comb sort";
        display(arr);
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
                    display(arr, i, i+gap);
                    swapped = true;
                }
            }
        }
        display(arr);
    }
}
#endif // SORT_CLASS_H
