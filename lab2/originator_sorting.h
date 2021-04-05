#ifndef ORIGINATOR_SORTING_H
#define ORIGINATOR_SORTING_H
#include "memento_sorting.h"

namespace ms
{
    /*!
    *   \brief Template class to set and get states of sorting
    *
    *   Need for pattern memento. See MementoSorting.
    */
    template<typename T>
    class OriginatorSorting
    {
    private:
        std::vector<MementoSorting<T>> states;/*!< Array of states*/
        std::size_t current_index;/*!< Index of current state*/
    public:
        /*!
        * \brief Creates object without states
        *
        * Sets current_index to 0.
        */
        OriginatorSorting();
        /*!
        *   \brief Returns pointer to current state
        *
        *   The current_index will not be changed.
        */
        MementoSorting<T>* current_state();
        /*!
        *   \brief Returns pointer to next state
        *
        *   If there is not next state then returns nullptr else
        *   increases current_index by 1 and return pointer to state.
        */
        MementoSorting<T>* next_state();
        /*!
        *   \brief Returns pointer to prev state
        *
        *   If there is not prev state then returns nullptr else
        *   decreases current_index by 1 and return pointer to state.
        */
        MementoSorting<T>* prev_state();
        /*!
        *   \brief Returns pointer to last added state
        *
        *   The current_index will not be changed.
        */
        MementoSorting<T>* last_state();
        /*!
        *   \brief Returns pointer to the end state
        *
        *   Sets current_index to the end index.
        */
        MementoSorting<T>* to_end();
        /*!
        *   \brief Returns pointer to the begin state
        *
        *   Sets current_index to the begin index.
        */
        MementoSorting<T>* to_begin();
        /*!
        *   \brief Adds state to all states
        */
        void append_state(const MementoSorting<T>& state);
        /*!
        *   \brief Clears all states
        */
        void clear();
        /*!
        *   \brief Checks current_index
        *
        *   \returns - true if current_index is end index
        *   \returns - false else
        */
        bool is_end();
        /*!
        *   \brief Returns number of states
        */
        std::size_t size();
        /*!
        *   \brief Returns current_index
        */
        std::size_t get_current_index();
    };
}
namespace ms
{
    template<typename T>
    MementoSorting<T>* OriginatorSorting<T>::to_end()
    {
        current_index = states.size() - 1;
        return current_state();
    }
    template<typename T>
    MementoSorting<T>* OriginatorSorting<T>::to_begin()
    {
        current_index = 0;
        return current_state();
    }
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
    bool OriginatorSorting<T>::is_end()
    {
        return (current_index + 1 == states.size());
    }
}
#endif // ORIGINATOR_SORTING_H
