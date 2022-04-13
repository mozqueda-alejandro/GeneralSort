#include "Selection.h"

template <class T>
Selection<T>::Selection() : SortBase<T>() {}

template <class T>
void Selection<T>::sort()
{
    comparisons = 0;
    swaps = 0;
    sortTime = 0;
    std::cout << "In the selection sort" << std::endl;
    // T max;
    // int maxIndex, last, index;
    // for (last = unsortedLen - 1; last >= 1; last--) {
    //     max = unsorted[0];
    //     maxIndex = 0;
    //     for (index = 1; index < last + 1; index++) {
    //         if (unsorted[index] > max) {
    //             max = unsorted[index];
    //             maxIndex = index;
    //         }
    //         ++sortStats.comparisons;
    //     }
    //     if (last != maxIndex) {
    //         std::swap(unsorted[last], unsorted[maxIndex]);
    //         ++sortStats.swaps;
    //     }
    // }
}

template <class T>
inline std::string Selection<T>::getSortName() const
{
    return "Selection";
}