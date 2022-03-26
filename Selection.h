#ifndef SELECTION_H
#define SELECTION_H

#include <iostream>
#include <array>
#include "SortInterface.h"

template <class ItemType>
class Selection : public SortInterface<ItemType> {
    int comparisons;
    int swaps;
    void initVars();
public:
    Selection();
    void sort(int unsortedLen, ItemType unsorted[]) override;
    std::tuple<int, int> returnStats() const override;
    std::string getSortName() const override;
};

#include "Selection.cpp"
#endif //SELECTION_H