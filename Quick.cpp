#include "Quick.h"

template <class ItemType>
Quick<ItemType>::Quick() {
    initVars();
}
template <class ItemType>
void Quick<ItemType>::initVars() {
    comparisons = 0;
    swaps = 0;
}

template <class ItemType>
void Quick<ItemType>::sort(int unsortedLen, ItemType unsorted[]) {    
    if (unsortedLen <= 1) {
        return;
    }
    int pivot = unsorted[0];
    int left = 1;
    int right = unsortedLen - 1;
    while (left <= right) {
        while (unsorted[left] < pivot) {
            left++;
        }
        while (unsorted[right] > pivot) {
            right--;
        }
        if (left <= right) {
            std::swap(unsorted, left, right);
            left++;
            right--;
        }
    }
    sort(left, unsorted);
    sort(unsortedLen - left, unsorted + left);
}

template <class ItemType>
std::tuple<int, int> Quick<ItemType>::returnStats() const {
    return std::make_tuple(comparisons, swaps);
}

template <class ItemType>
std::string Quick<ItemType>::getSortName() const {
    return "Quick";
}