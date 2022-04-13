#ifndef QUICK_H
#define QUICK_H

#include "SortBase.h"

template <class T>
class Quick : public SortBase<T>
{
    using SortBase<T>::comparisons;
    using SortBase<T>::swaps;
    using SortBase<T>::sortTime;
public:
    Quick();
    void sort();
    inline std::string getSortName() const;
    typedef T type;
private:
    void quickSort(int low, int high, T arr[]);
};

#include "Quick.cpp"
#endif // QUICK_H