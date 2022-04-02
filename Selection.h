#ifndef SELECTION_H
#define SELECTION_H

#include <iostream>
#include <array>
#include "SortInterface.h"

template <class ItemType>
class Selection : public SortInterface<ItemType> {
    SortStats sortStats;
    void initVars();
public:
    Selection();
    void sort(int unsortedLen, ItemType unsorted[]) override;
    std::tuple<unsigned int, unsigned int> returnStats() const;
    std::string getSortName() const;
    typedef ItemType type;
};

#include "Selection.cpp"
#endif //SELECTION_H