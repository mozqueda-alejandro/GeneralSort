#ifndef MERGE_H
#define MERGE_H

#include "SortBase.h"

template<class T>
class Merge : public SortBase<T>
{
    using SortBase<T>::comparisons;
    using SortBase<T>::swaps;
    using SortBase<T>::sortTime;
public:
    Merge();
    void sort();
    inline std::string getSortName() const;
    typedef T type;
};

#include "Merge.cpp"
#endif // MERGE_H