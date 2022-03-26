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
#include "Quick.h"

namespace EnumData {
    enum Data {
        DATA_SIZE_1 = 100,
        DATA_SIZE_2 = 200,
        DATA_SIZE_3 = 300,
    };
    static const Data All[] = { DATA_SIZE_1, DATA_SIZE_2, DATA_SIZE_3 };
}

template<class SortType>
class SortTest {
    SortType algorithm;
    double totalRuntime;
    int totalComparisons;
    int totalSwaps;
    int numSorts;
    static const int NUM_TESTS = 10;
public:
    SortTest();
    SortTest(SortType algorithm);
    void initVars();
    void run();
    double timeSort(int arrLen, int arr[]);
};

#include "SortTest.cpp"
#endif // SORT_TEST_H