#include "Insertion.h"

template<class T>
Insertion<T>::Insertion() : SortBase<T>() {}

template<class T>
void Insertion<T>::sort()
{
    comparisons = 0;
    swaps = 0;
    sortTime = 0;
    std::cout << "In the insertion sort" << std::endl;

    // for (int ind = 1; ind < unsortedLen; ind++) {
    //     ItemType key = unsorted[ind];
    //     int it = ind;
    //     for ( ; it > 0 && unsorted[it - 1] > key; --it) {
    //         ++sortStats.comparisons;
    //         ++sortStats.swaps;
    //         unsorted[it] = unsorted[it - 1];
    //     }
    //     ++sortStats.comparisons;
    //     unsorted[it] = key;
    // }
}

template<class T>
std::string Insertion<T>::getSortName() const
{
    return "Insertion";
}