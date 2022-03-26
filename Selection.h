#ifndef SELECTION_H
#define SELECTION_H

#include <iostream>
#include <array>
#include "SortInterface.h"

template <class ItemType>
class Selection : public SortInterface<ItemType> {
    int comparisons;
    int swaps;
public:
    Selection();
    void sort(ItemType unsorted[], int unsortedLen) override;
    std::tuple<int, int> returnStats() const override;
    std::string getSortName() const override;
    void initVars();
};

#include "Selection.cpp"
#endif //SELECTION_H