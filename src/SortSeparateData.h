#ifndef _SORTSEPARATEDATA_H
#define _SORTSEPARATEDATA_H

#include "SortData.h"
#include "SortError.h"

// Wrapper around input container to be sorted with one of SortTech child
// classes. Result of the sorting will be stored in separate container.
template <class T, template <typename...> class Container = std::vector>
class SortSeparateData : public SortData<T, Container> {
private:
    Container<T> m_output;

public:
    inline SortError swap(Container<T>& sorted);

    Container<T>& output() { return m_output; }
};
template <class T, template <typename...> class Container>
inline SortError SortSeparateData<T, Container>::swap(Container<T>& sorted)
{
    return SE_SUCCESS;
}

#endif
