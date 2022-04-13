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

// #include "Selection.h"
// #include "Insertion.h"
// // #include "Bubble.h"
// #include "Merge.h"
// #include "Quick.h"
// // #include "Radix.h"

// namespace EnumData {
//     enum Data {
//         DATA_SIZE_1 = 8,
//         DATA_SIZE_2 = 16,
//         DATA_SIZE_3 = 100000,
//     };
//     static const Data All[] = { DATA_SIZE_1, DATA_SIZE_2/*, DATA_SIZE_3*/ };
// }

// class SortTest {
//     double totalSortTime;
//     long long totalComparisons;
//     float totalSwaps;
//     int numSorts;
//     bool seedTests;
//     static const int NUM_TESTS = 2;

//     void initVars();
//     std::string formatFloat(const float& floatVal);
//     void newRandArr(int arrLen, int arr[]); // Helper function for improved performance

//     template<class SortType>
//     double timeSort(int arrLen, int arr[], SortType& algorithm);
//     template<class SortType>
//     float approxMemUse();
// public:
//     SortTest(bool seedTests = false);

//     template<class SortType>
//     void run(SortType& algorithm);
// };

// // extern int NUM_RUNS;

#include "SortTest.cpp"
#endif // SORT_TEST_H