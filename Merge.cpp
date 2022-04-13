#include "Merge.h"

template<class T>
Merge<T>::Merge() : SortBase<T>() {}

template<class T>
void Merge<T>::sort()
{
    comparisons = 0;
    swaps = 0;
    sortTime = 0;
    std::cout << "In the merge sort" << std::endl;
    // TODO: Implement Merge Sort
    
}

template<class T>
inline std::string Merge<T>::getSortName() const {
    return "Merge";
}