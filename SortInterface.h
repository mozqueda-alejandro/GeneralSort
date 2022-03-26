#ifndef SORT_INTERFACE 
#define SORT_INTERFACE 

#include <tuple>

template<class ItemType> 
class SortInterface { 
public: 
    virtual void sort(ItemType unsorted[], int unsortedLen) = 0;
    virtual std::tuple<int, int> returnStats() const = 0;
    virtual std::string getSortName() const = 0;
    virtual ~SortInterface() { } 
};  
#endif // SORT_INTERFACE