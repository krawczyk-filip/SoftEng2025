#ifndef _QUICK_H
#define _QUICK_H

#include "SortTech.h"
#include "SortError.h"
#include "SortData.h"

template<class T, template<typename...> class Container>
class Quick : public SortTech<T, Container> {
public:
    inline SortError sort(SortData<T>& data) override;

    void quickSort(SortData<T>& data) {
        quickSortHelper(data, 0, data.size() - 1);
    }

    void quickSortHelper(SortData<T> & data, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(data, low, high);
            quickSortHelper(data, low, pivotIndex - 1);
            quickSortHelper(data, pivotIndex + 1, high);
        }
    }

    int partition(SortData<T> & data, int low, int high) {
        T pivot = data[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (data[j] < pivot) {
                i++;
                data.swap(i, j);
            }
        }
        data.swap(i + 1, high);
        return i + 1;
    }
};

template<class T, template<typename...> class Container>
inline SortError Quick<T, Container>::sort(SortData<T> & data) {
    quickSort(data);
    return SE_SUCCESS;
}

#endif
