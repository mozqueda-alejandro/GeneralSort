#ifndef SELECTION_H
#define SELECTION_H

#include "SortBase.h"

template <class T>
class Selection : public SortBase<T>
{
    using SortBase<T>::comparisons;
    using SortBase<T>::swaps;
    using SortBase<T>::sortTime;
public:
    Selection();
    void sort();
    inline std::string getSortName() const;
    typedef T type;
};

#include "Selection.cpp"
#endif //SELECTION_H