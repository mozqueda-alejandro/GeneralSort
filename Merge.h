#ifndef MERGE_H
#define MERGE_H

#include <iostream>
#include <array>
#include "SortInterface.h"

template <class ItemType>
class Merge : public SortInterface<ItemType> {
    int comparisons;
    int swaps;
    void initVars();
public:
    Merge();
    void sort(int unsortedLen, ItemType unsorted[]);
    std::tuple<int, int> returnStats() const;
    std::string getSortName() const;
};

#include "Merge.cpp"
#endif // MERGE_H