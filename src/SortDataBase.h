#ifndef _SORTDATABASE_H
#define _SORTDATABASE_H


#include "OpState.h"

#include <deque>
#include <list>
#include <vector>

template <template <typename...> class Container>
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


#ifdef _WIN32
#ifdef BUILDING_CLIENT_DLL
#define CLIENT_API __declspec(dllexport)
#else
#define CLIENT_API __declspec(dllimport)
#endif
#else
// -fvisibility=hidden
#define CLIENT_API __attribute__((visibility("default")))
#endif

//Interface for data wrapper class
class CLIENT_API SortDataBase {
};
#endif
