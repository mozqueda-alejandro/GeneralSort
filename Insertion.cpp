#include "Insertion.h"

template <class ItemType>
Insertion<ItemType>::Insertion() {
    initVars();
}
template <class ItemType>
void Insertion<ItemType>::initVars() {
    comparisons = 0;
    swaps = 0;
}

template <class ItemType>
void Insertion<ItemType>::sort(int unsortedLen, ItemType unsorted[]) {
    initVars();
    for (int ind = 1; ind < unsortedLen; ind++) {
        int key = unsorted[ind];
        int it = ind;
        for ( ; it > 0 && unsorted[it - 1] > key; (--it, comparisons++)) {
            ++swaps;
            unsorted[it] = unsorted[it - 1];
        }
        ++swaps;
        unsorted[it] = key;
    }
}

template <class ItemType>
std::tuple<int, int> Insertion<ItemType>::returnStats() const {
    return std::make_tuple(comparisons, swaps);
}

template <class ItemType>
std::string Insertion<ItemType>::getSortName() const {
    return "Insertion";
}