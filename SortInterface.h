#ifndef SORT_INTERFACE 
#define SORT_INTERFACE 

template<class ItemType> 
class SortInterface { 
public: 
    virtual void sort(ItemType unsorted[], int unsortedLen) = 0;
    virtual ~SortInterface() { } 
};  
#endif // SORT_INTERFACE