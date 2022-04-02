#ifndef MERGE_H
#define MERGE_H

#include <iostream>
#include <array>
#include "SortInterface.h"

template <class ItemType>
class Merge : public SortInterface<ItemType> {
    SortStats sortStats;
    void initVars();
public:
    Merge();
    void sort(int unsortedLen, ItemType unsorted[]);
    std::tuple<unsigned int, unsigned int> returnStats() const;
    std::string getSortName() const;
    typedef ItemType type;
};

#include "Merge.cpp"
#endif // MERGE_H