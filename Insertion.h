#ifndef INSERTION_H
#define INSERTION_H

#include "SortBase.h"

template<class T>
class Insertion : public SortBase<T>
{
    using SortBase<T>::comparisons;
    using SortBase<T>::swaps;
    using SortBase<T>::sortTime;
public:
    Insertion();
    void sort();
    inline std::string getSortName() const;
    typedef T type;
};

#include "Insertion.cpp"
#endif // INSERTION_H