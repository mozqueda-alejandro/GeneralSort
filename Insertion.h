#ifndef INSERTION_H
#define INSERTION_H

#include <iostream>
#include <array>
#include "SortInterface.h"

template <class ItemType>
class Insertion : public SortInterface<ItemType> {
    SortStats sortStats;
    void initVars();
public:
    Insertion();
    void sort(int unsortedLen, ItemType unsorted[]);
    std::tuple<unsigned int, unsigned int> returnStats() const;
    std::string getSortName() const;
    typedef ItemType type;
};

#include "Insertion.cpp"
#endif // INSERTION_H