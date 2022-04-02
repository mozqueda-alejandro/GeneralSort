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
    long long totalComparisons;
    float totalSwaps;
    int numSorts;
    bool seedTests;
    static const int NUM_TESTS = 10;

    void initVars();
    double timeSort(int arrLen, int arr[]);
    std::string formatFloat(const float& floatVal);
    float approxMemUse();
public:
    SortTest() = default;
    SortTest(const SortType& algorithm, bool seedTests = false);
    ~SortTest() = default;
    void run();
};

extern int NUM_RUNS;

#include "SortTest.cpp"
#endif // SORT_TEST_H