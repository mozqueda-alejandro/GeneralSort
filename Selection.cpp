#include "Selection.h"

template <class ItemType>
Selection<ItemType>::Selection() :
    comparisons(0),
    swaps(0) {}

template <class ItemType>
void Selection<ItemType>::sort(ItemType unsorted[], int unsortedLen) {
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
        // ItemType* temp = unsorted[last];
        // unsorted[last] = unsorted[maxIndex];
        // unsorted[maxIndex] = temp;
        std::swap(unsorted[last], unsorted[maxIndex]);
        ++swaps;
    }
    
    
}