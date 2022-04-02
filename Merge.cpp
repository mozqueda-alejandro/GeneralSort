#include "Merge.h"

template <class ItemType>
Merge<ItemType>::Merge() {
    initVars();
}
template <class ItemType>
void Merge<ItemType>::initVars() {
    sortStats.comparisons = 0;
    sortStats.swaps = 0;
}

template <class ItemType>
void Merge<ItemType>::sort(int unsortedLen, ItemType unsorted[]) {
    
    
}

template <class ItemType>
std::tuple<unsigned int, unsigned int> Merge<ItemType>::returnStats() const {
    return std::make_tuple(sortStats.comparisons, sortStats.swaps);
}

template <class ItemType>
std::string Merge<ItemType>::getSortName() const {
    return "Merge";
}