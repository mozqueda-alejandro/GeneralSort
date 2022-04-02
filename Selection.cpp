#include "Selection.h"

template <class ItemType>
Selection<ItemType>::Selection() {
    initVars();
}

template <class ItemType>
void Selection<ItemType>::initVars() {
    sortStats.comparisons = 0;
    sortStats.swaps = 0;
}

template <class ItemType>
void Selection<ItemType>::sort(int unsortedLen, ItemType unsorted[]) {
    initVars();
    ItemType max;
    int maxIndex, last, index;
    for (last = unsortedLen - 1; last >= 1; last--) {
        max = unsorted[0];
        maxIndex = 0;
        for (index = 1; index < last + 1; index++) {
            if (unsorted[index] > max) {
                max = unsorted[index];
                maxIndex = index;
            }
            ++sortStats.comparisons;
        }
        if (last != maxIndex) {
            std::swap(unsorted[last], unsorted[maxIndex]);
            ++sortStats.swaps;
        }
    }
}

template <class ItemType>
std::tuple<unsigned int, unsigned int> Selection<ItemType>::returnStats() const {
    return std::make_tuple(sortStats.comparisons, sortStats.swaps);
}

template <class ItemType>
std::string Selection<ItemType>::getSortName() const {
    return "Selection";
}