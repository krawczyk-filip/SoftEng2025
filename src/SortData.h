#ifndef _SORTDATA_H
#define _SORTDATA_H

#include "SortError.h"
#include "OpState.h"
#include "SortDataBase.h"

#include <array>
#include <cstddef>
#include <list>
#include <vector>


// This class acts as a wrapper around an input/output container that will be
// sorted using one of the child classes of SortTech. Direct access to the
// container should be provided through public methods.
template <class T, template <typename...> class Container = std::vector>
class SortData : public SortDataBase {
    friend class Sorter;

private:
    Container<T> m_data;


public:
    inline SortError add(const T& elem);

    inline SortError add(const T*& data, unsigned int length);

    inline typename Container<T>::iterator begin(SortError& error);

    inline typename Container<T>::iterator end(SortError& error);

    T& operator[](unsigned int ind)
    {
        if (is_std_vector<Container>::value)
            return m_data[ind];
        else if (is_std_list<Container>::value
                 || is_std_deque<Container>::value)
        {
            auto it = m_data.begin();
            std::advance(it, ind);
            return *it;
        }
        else
            return m_data[ind];
    }

    size_t size() { return m_data.size(); }

    Container<T>& data() { return m_data; }


private:
    OpState m_state = OS_IDLE;

public:
    // Callback method to be called by separate thread at the end of sorting
    // operation.
    inline virtual void notifyDone();

    inline SortError swap(unsigned int ind_a, unsigned int ind_b);

    inline SortError setState(const OpState& state);
};
template <class T, template <typename...> class Container>
inline SortError SortData<T, Container>::add(const T& elem)
{
    m_data.push_back(elem);
    return SE_SUCCESS;
}

template <class T, template <typename...> class Container>
inline SortError SortData<T, Container>::add(const T*& data,
                                             unsigned int length)
{
    for (unsigned i = 0; i < length; i++)
    {
        m_data.push_back(data[i]);
    }
    return SE_SUCCESS;
}

template <class T, template <typename...> class Container>
inline typename Container<T>::iterator
SortData<T, Container>::begin(SortError& error)
{
    return m_data.begin();
}

template <class T, template <typename...> class Container>
inline typename Container<T>::iterator
SortData<T, Container>::end(SortError& error)
{
    return m_data.end();
}

// Callback method to be called by separate thread at the end of sorting
// operation.
template <class T, template <typename...> class Container>
inline void SortData<T, Container>::notifyDone()
{}

template <class T, template <typename...> class Container>
inline SortError SortData<T, Container>::swap(unsigned int ind_a,
                                              unsigned int ind_b)
{

    if (ind_a == ind_b) return SE_SUCCESS;

    auto a = m_data.begin();
    auto b = m_data.begin();

    std::advance(a, ind_a);
    std::advance(b, ind_b);

    std::swap(*a, *b);

    return SE_SUCCESS;
}

template <class T, template <typename...> class Container>
inline SortError SortData<T, Container>::setState(const OpState& state)
{
    m_state = state;
    return SE_SUCCESS;
}

#endif
