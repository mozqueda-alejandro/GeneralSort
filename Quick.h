#ifndef QUICK_H
#define QUICK_H

#include <iostream>
#include <array>
#include "SortInterface.h"

template <class ItemType>
class Quick : public SortInterface<ItemType> {
    int comparisons;
    int swaps;
    void initVars();
public:
    Quick();
    void sort(int unsortedLen, ItemType unsorted[]);
    void quickSort(int low, int high, ItemType arr[]);
    std::tuple<int, int> returnStats() const;
    std::string getSortName() const;
};

#include "Quick.cpp"
#endif // QUICK_H