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
    
    
}

template <class ItemType>
std::tuple<int, int> Insertion<ItemType>::returnStats() const {
    return std::make_tuple(comparisons, swaps);
}

template <class ItemType>
std::string Insertion<ItemType>::getSortName() const {
    return "Insertion";
}