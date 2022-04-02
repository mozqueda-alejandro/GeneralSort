#ifndef QUICK_H
#define QUICK_H

#include <iostream>
#include <array>
#include "SortInterface.h"

template <class ItemType>
class Quick : public SortInterface<ItemType> {
    SortStats sortStats;
    void initVars();
    void quickSort(int low, int high, ItemType arr[]);

public:
    Quick();
    void sort(int unsortedLen, ItemType unsorted[]);
    std::tuple<unsigned int, unsigned int> returnStats() const;
    std::string getSortName() const;
    typedef ItemType type;
};

#include "Quick.cpp"
#endif // QUICK_H