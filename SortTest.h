#ifndef SORT_TEST_H
#define SORT_TEST_H

#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <string>

#include "FileManager.h"
#include "Container.h"

#include "Selection.h"
#include "Insertion.h"
// #include "Bubble.h"
#include "Merge.h"
#include "Quick.h"
// #include "Radix.h"

namespace EnumData {
    enum Data {
        DATA_SIZE_1 = 1000,
        DATA_SIZE_2 = 10000,
        DATA_SIZE_3 = 100000,
    };
    static const Data All[] = { DATA_SIZE_1, DATA_SIZE_2, DATA_SIZE_3 };
}

template<class SortType>
class SortTest {
    SortType algorithm;
    double totalSortTime;
    float totalComparisons;
    float totalSwaps;
    int numSorts;
    static const int NUM_TESTS = 10;
public:
    SortTest();
    SortTest(const SortType& algorithm);
    void initVars();
    void run();
    double timeSort(int arrLen, int arr[]);
};

#include "SortTest.cpp"
#endif // SORT_TEST_H