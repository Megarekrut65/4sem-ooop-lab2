#ifndef ORIGINATOR_SORTING_H
#define ORIGINATOR_SORTING_H
#include "memento_sorting.h"

namespace ms
{
    template<typename T>
    class OriginatorSorting
    {
    private:
        std::vector<MementoSorting<T>> states;
        std::size_t current_index;
    public:
        OriginatorSorting();
        MementoSorting<T>* current_state();
        MementoSorting<T>* next_state();
        MementoSorting<T>* prev_state();
        MementoSorting<T>* last_state();
        void append_state(const MementoSorting<T>& state);
        void clear();
        bool is_next_end();
        std::size_t size();
        std::size_t get_current_index();
    };
}
namespace ms
{
    template<typename T>
    std::size_t OriginatorSorting<T>::get_current_index()
    {
        return current_index;
    }
    template<typename T>
    std::size_t OriginatorSorting<T>::size()
    {
        return states.size();
    }
    template<typename T>
    OriginatorSorting<T>::OriginatorSorting():current_index(0){}
    template<typename T>
    MementoSorting<T>* OriginatorSorting<T>::current_state()
    {
        if(current_index < states.size())
            return &states[current_index];
        return nullptr;
    }
    template<typename T>
    MementoSorting<T>* OriginatorSorting<T>::next_state()
    {
        if(current_index < states.size()) current_index++;
        if(current_index < states.size())
            return &states[current_index];
        return nullptr;
    }
    template<typename T>
    MementoSorting<T>* OriginatorSorting<T>::prev_state()
    {
        if(current_index > 0 && current_index == states.size()) current_index--;
        if(current_index > 0)
            return &states[--current_index];
        return nullptr;
    }
    template<typename T>
    MementoSorting<T>* OriginatorSorting<T>::last_state()
    {
        if(states.size() > 0)
            return &states[states.size() - 1];
        return nullptr;
    }
    template<typename T>
    void OriginatorSorting<T>::append_state(const MementoSorting<T>& state)
    {
        states.push_back(state);
    }
    template<typename T>
    void OriginatorSorting<T>::clear()
    {
        states.clear();
        current_index = 0;
    }
    template<typename T>
    bool OriginatorSorting<T>::is_next_end()
    {
        return (current_index + 2 == states.size());
    }
}
#endif // ORIGINATOR_SORTING_H
