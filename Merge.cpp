#include "Merge.h"

template <class ItemType>
Merge<ItemType>::Merge() {
    initVars();
}
template <class ItemType>
void Merge<ItemType>::initVars() {
    comparisons = 0;
    swaps = 0;
}

template <class ItemType>
void Merge<ItemType>::sort(int unsortedLen, ItemType unsorted[]) {
    
    
}

template <class ItemType>
std::tuple<int, int> Merge<ItemType>::returnStats() const {
    return std::make_tuple(comparisons, swaps);
}

template <class ItemType>
std::string Merge<ItemType>::getSortName() const {
    return "Merge";
}