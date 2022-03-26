#ifndef INSERTION_
#define INSERTION_

#include <iostream>
#include <array>
#include "SortInterface.h"

template <class ItemType>
class Insertion{// : public SortInterface<ItemType> {
    int comparisons;
    int swaps;
public:
    Insertion();
    void sort(ItemType unsorted[], int unsortedLen) override;
};

#endif //INSERTION_