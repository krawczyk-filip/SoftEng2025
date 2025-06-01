#ifndef _SORTTECHFACTORY_H
#define _SORTTECHFACTORY_H

#include "SortTech.h"
#include "SortError.h"
#include "Bubble.h"
#include "Quick.h"
#include "Insert.h"
#include "Merge.h"
#include "Radix.h"
#include "Select.h"

#include <array>
#include <memory>

enum SortTechType
{
    STT_NONE = 0,
    STT_BUBBLE,
    STT_INSERT,
    STT_MERGE,
    STT_QUICK,
    STT_RADIX,
    STT_SELECT
};

/* template <template <typename...> class Container>
struct is_std_vector : std::false_type
{
};

template <> struct is_std_vector<std::vector> : std::true_type
{
};


template <template <typename...> class Container>
struct is_std_list : std::false_type
{
};

template <> struct is_std_list<std::list> : std::true_type
{
};


template <template <typename...> class Container>
struct is_std_deque : std::false_type
{
};

template <> struct is_std_deque<std::deque> : std::true_type
{
};
*/

// This class extends the "factory" design pattern and is responsible for
// selecting and creating the appropriate sorting technique. The choice of
// technique should be made at compile time by specializing the SortData class
// templates.
class SortTechFactory {
public:
    template <class T, template <typename...> class Container, SortTechType TT>
    static inline std::unique_ptr<SortTech<T, Container>>
    createSorter(SortError& error);
};
template <class T, template <typename...> class Container, SortTechType TT>
inline std::unique_ptr<SortTech<T, Container>>
SortTechFactory::createSorter(SortError& error)
{
    error = SE_SUCCESS;

    if constexpr (TT != STT_NONE)
    {
        if constexpr (TT == STT_MERGE)
        {
            return std::make_unique<Merge<T, Container>>();
        }
        else if constexpr (TT == STT_BUBBLE)
        {
            return std::make_unique<Bubble<T, Container>>();
        }
        else if constexpr (TT == STT_INSERT)
        {
            return std::make_unique<Insert<T, Container>>();
        }
        else if constexpr (TT == STT_QUICK)
        {
            return std::make_unique<Quick<T, Container>>();
        }
        else if constexpr (TT == STT_RADIX)
        {
            return std::make_unique<Radix<T, Container>>();
        }
        else if constexpr (TT == STT_SELECT)
        {
            return std::make_unique<Select<T, Container>>();
        }
    }
    else
    {
        if (std::is_same<T, float>::value && is_std_vector<Container>::value)
        {
            return std::make_unique<Quick<T, Container>>();
        }
        else if (std::is_same<T, int>::value && is_std_vector<Container>::value)
        {
            return std::make_unique<Radix<T, Container>>();
        }
        else if (is_std_list<Container>::value
                 || is_std_deque<Container>::value)
        {
            return std::make_unique<Merge<T, Container>>();
        }
        else if (std::is_same<std::string, T>::value)
        {
            return std::make_unique<Select<T, Container>>();
        }
        else
        {
            return std::make_unique<Bubble<T, Container>>();
        }
    }

    return nullptr;
}

#endif