#include "Selection.h"

template <class ItemType>
Selection<ItemType>::Selection() {
    initVars();
}

template <class ItemType>
void Selection<ItemType>::initVars() {
    comparisons = 0;
    swaps = 0;
}

template <class ItemType>
void Selection<ItemType>::sort(ItemType unsorted[], int unsortedLen) {
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
                ++comparisons;
            }
        }
        std::swap(unsorted[last], unsorted[maxIndex]);
        ++swaps;
    }
}

template <class ItemType>
std::tuple<int, int> Selection<ItemType>::returnStats() const {
    return std::make_tuple(comparisons, swaps);
}

template <class ItemType>
std::string Selection<ItemType>::getSortName() const {
    return "Selection";
}