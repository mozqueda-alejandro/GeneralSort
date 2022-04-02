#include "Quick.h"

template <class ItemType>
Quick<ItemType>::Quick() {
    initVars();
}
template <class ItemType>
void Quick<ItemType>::initVars() {
    sortStats.comparisons = 0;
    sortStats.swaps = 0;
}

template <class ItemType>
void Quick<ItemType>::sort(int unsortedLen, ItemType unsorted[]) {    
    initVars();
    quickSort(0, unsortedLen - 1, unsorted);
}

template <class ItemType>
void Quick<ItemType>::quickSort(int low, int high, ItemType arr[]) {
    if (low < high && low >= 0 && high >= 0) {
        // Hoare Partition
        ItemType pivot = arr[low];
        int first = low - 1;
        int last = high + 1;
        while (true) {
            do {
                ++first;
                ++sortStats.comparisons;
            } while (arr[first] < pivot);

            do {
                --last;
                ++sortStats.comparisons;
            } while (arr[last] > pivot);

            if (first >= last) {
                break;
            }
            std::swap(arr[first], arr[last]);
            ++sortStats.swaps;
        }
        quickSort(low, last, arr);
        quickSort(last + 1, high, arr);
    }
}

template <class ItemType>
std::tuple<unsigned int, unsigned int> Quick<ItemType>::returnStats() const {
    return std::make_tuple(sortStats.comparisons, sortStats.swaps);
}

template <class ItemType>
std::string Quick<ItemType>::getSortName() const {
    return "Quick";
}