#ifndef SORT_TEST_H
#define SORT_TEST_H

#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <chrono>
#include "FileManager.h"
#include "Selection.h"
#include "Container.h"

class SortTest{
    float totalRuntime;
    int totalSwaps;
    int totalComparisons;
    int numSorts;
public:
    template<class SortType>
    void run();
};

#endif // SORT_TEST_H