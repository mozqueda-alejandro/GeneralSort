#ifndef SORT_BASE_H
#define SORT_BASE_H 

#include <iostream>

template<class T> 
class SortBase
{ 
public: 
    SortBase();
    unsigned int getComparisons() const;
    unsigned int getSwaps() const;
    double getTime() const;

    template<class Iterator>
    void sort(Iterator begin, Iterator end);
    virtual void sort() = 0;
    virtual inline std::string getSortName() const = 0;
    ~SortBase() {} 
// protected:
    unsigned int comparisons;
    unsigned int swaps;
    double sortTime;
};

#include "SortBase.cpp"
#endif // SORT_BASE_H