#ifndef _SELECT_H
#define _SELECT_H

#include "SortData.h"
#include "SortError.h"
#include "SortTech.h"

template <class T, template <typename...> class Container>
class Select : public SortTech<T, Container> {
public:
    inline SortError sort(SortData<T> &data) override;
};
template <class T, template <typename...> class Container>
inline SortError Select<T, Container>::sort(SortData<T> &data)
{

    size_t n = data.size();

    for (size_t i = 0; i < n; ++i)
    {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; ++j)
        {
            if (data[j] < data[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            data.swap(i, min_idx);
        }
    }


    return SE_SUCCESS;
}


#endif
