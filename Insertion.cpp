#include "Insertion.h"

template <class ItemType>
Insertion<ItemType>::Insertion() {
    initVars();
}
template <class ItemType>
void Insertion<ItemType>::initVars() {
    sortStats.comparisons = 0;
    sortStats.swaps = 0;
}

template <class ItemType>
void Insertion<ItemType>::sort(int unsortedLen, ItemType unsorted[]) {
    initVars();
    for (int ind = 1; ind < unsortedLen; ind++) {
        ItemType key = unsorted[ind];
        int it = ind;
        for ( ; it > 0 && unsorted[it - 1] > key; --it) {
            ++sortStats.comparisons;
            ++sortStats.swaps;
            unsorted[it] = unsorted[it - 1];
        }
        ++sortStats.comparisons;
        unsorted[it] = key;
    }
}

template <class ItemType>
std::tuple<unsigned int, unsigned int> Insertion<ItemType>::returnStats() const {
    return std::make_tuple(sortStats.comparisons, sortStats.swaps);
}

template <class ItemType>
std::string Insertion<ItemType>::getSortName() const {
    return "Insertion";
}