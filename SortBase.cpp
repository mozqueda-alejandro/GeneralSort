#include "SortBase.h"


template<class T>
SortBase<T>::SortBase() :
    comparisons(0),
    swaps(0),
    sortTime(0)
{}

template<class T>
unsigned int SortBase<T>::getComparisons() const
{
    return comparisons;
}

template<class T>
unsigned int SortBase<T>::getSwaps() const
{
    return swaps;
}

template<class T>
double SortBase<T>::getTime() const
{
    return sortTime;
}

template<class T>
template<class Iterator>
void SortBase<T>::sort(Iterator begin, Iterator end)
{
    sort();
}