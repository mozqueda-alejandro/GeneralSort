#ifndef SORT_INTERFACE 
#define SORT_INTERFACE 

#include <tuple>


struct SortStats {
    unsigned int comparisons;
    unsigned int swaps;
};

template<class ItemType> 
class SortInterface { 
public: 
    virtual void sort(int unsortedLen, ItemType unsorted[]) = 0;
    virtual std::tuple<unsigned int, unsigned int> returnStats() const = 0;
    virtual std::string getSortName() const = 0;
    virtual void initVars() = 0;
    virtual ~SortInterface() { } 
};

#endif // SORT_INTERFACE