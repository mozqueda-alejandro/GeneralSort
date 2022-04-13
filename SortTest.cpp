#include "SortTest.h"

// // int NUM_RUNS = 0;

// /**
//  * @brief Construct a new SortTest object, initializes total statistics, 
//  * creates new CSV files with random data if unseeded.
//  * 
//  * @param rand Determines if only one data set will be repeatedly run or if tests will be run with different data sets.
//  */
// SortTest::SortTest(bool rand/* = false*/) : 
//     seedTests(rand)
// {
//     initVars();
//     if (!seedTests) {
//         FileManager fileManager;
//         for (const auto dataSize : EnumData::All) {
//             fileManager.newRandCSV(dataSize);
//         }   
//     }
//     // ++NUM_RUNS;
// }

// /**
//  * @brief Initializes the variables used to keep track of algorithm performance.
//  */
// void SortTest::initVars() {
//     totalSortTime = 0;
//     totalComparisons = 0;
//     totalSwaps = 0;
//     numSorts = 0;
// }

// /**
//  * @brief Runs all tests for the sorting algorithm.
//  * 
//  * @tparam algorithm The sorting algorithm to be tested.
//  */
// template<class SortType>
// void SortTest::run(SortType& algorithm) {
//     float memUse = approxMemUse<SortType>();
//     if (memUse > 5) {
//         std::cout << "Memory use of " << memUse << " MB is too high for this test.\n";
//         return; // QUESTION: Should this be a return or an exception?
//     }

//     std::vector<std::vector<std::string>> stats;
//     stats.push_back(std::vector<std::string>{"Sort Type", "Sort Time", "Comparisons", "Swaps"});

//     for (const auto dataSize : EnumData::All) {
//         FileManager fileManager = (seedTests) ? FileManager(NUM_TESTS) : FileManager();
//         int constArr[dataSize];
//         int arr[dataSize];
//         if (!seedTests) {
//             std::string unsortedCSV = "unsorted" + std::to_string(dataSize) + ".csv"; // QUESTION: Formatting might change so should this call a file name generator in FileManager?
//             fileManager.csvToArray(constArr, unsortedCSV);
//         }

//         for (int i = 0; i < 2; i++) {
//             std::string sortType = (i == 0) ? "Unsorted" : "Sorted";
//             for (int j = 0; j < NUM_TESTS; j++) {
//                 if (i == 0) {
//                     if (seedTests) {
//                         std::string unsortedCSV = fileManager.newRandCSV(dataSize, algorithm.getSortName());
//                         fileManager.csvToArray(arr, unsortedCSV);
//                     } else {
//                         std::copy(constArr, constArr + dataSize, arr);
//                     }                    
//                 }
//                 double sortTime = timeSort<SortType>(dataSize, arr, algorithm);
//                 unsigned int comparisons, swaps;
//                 std::tie(comparisons, swaps) = algorithm.returnStats();
//                 stats.push_back(std::vector<std::string>{sortType, std::to_string(sortTime), std::to_string(comparisons), std::to_string(swaps)});
//                 totalSortTime += sortTime;
//                 totalComparisons += comparisons;
//                 totalSwaps += swaps;
//                 ++numSorts;
//                 if (seedTests) {
//                     if (i == 0) {
//                         fileManager.newSortedCSV(dataSize, arr, algorithm.getSortName()); // Creates a new CSV for every unsorted test (seeded)
//                     }
//                 } else {
//                     if (i == 0 && j == NUM_TESTS - 1) {
//                         fileManager.newSortedCSV(dataSize, arr); // Creates one CSV for all unsorted tests containing the same data (unseeded)
//                     }
//                 }
//             }
//             std::string aveSortTime, aveComparisons, aveSwaps;
//             sortType += " Average";
//             aveSortTime = formatFloat(totalSortTime / numSorts);
//             aveComparisons = formatFloat(totalComparisons / numSorts);
//             aveSwaps = formatFloat(totalSwaps / numSorts);
//             stats.push_back(std::vector<std::string>{sortType, aveSortTime, aveComparisons, aveSwaps});
//             initVars();
//         }
//         fileManager.newStatsCSV(dataSize, stats, algorithm.getSortName());
//         stats.erase(stats.begin() + 1, stats.end());
//     }
// }

// /**
//  * @brief Formats a float to have no trailing zeroes or decimals.
//  * 
//  * @param floatVal The number to format.
//  * @return std::string The formatted number.
//  */
// std::string SortTest::formatFloat(const float& floatVal) {
//     std::string floatStr = std::to_string(floatVal);
//     if(floatStr.find('.') != std::string::npos) {
//         floatStr = floatStr.substr(0, floatStr.find_last_not_of('0') + 1);
//         if(floatStr.find('.') == floatStr.size() - 1) {
//             floatStr.pop_back();
//         }
//     }
//     return floatStr;
// }

// /**
//  * @brief Runs the sort algorithm on the given array.
//  * 
//  * @param arrLen The size of the array.
//  * @param arr The array to sort.
//  * @tparam algorithm The sorting algorithm to be used.
//  * @return double Runtime needed to sort the array.
//  */
// template<class SortType>
// double SortTest::timeSort(int arrLen, int arr[], SortType& algorithm) {
//     auto start = std::chrono::high_resolution_clock::now();
//     std::ios_base::sync_with_stdio(false);
    
//     algorithm.sort(arrLen, arr);
    
//     auto end = std::chrono::high_resolution_clock::now();
//     return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() * 1e-9;
// }

// /**
//  * @brief Calculates the approximate memory use of testing an algorithm.
//  * 
//  * @return float Approximate memory use in MB.
//  */
// template<class SortType>
// float SortTest::approxMemUse() {
//     float memUse = 0.0f; // in bytes
//     int objTypeSize = sizeof(typename SortType::type);
//     for (const auto dataSize : EnumData::All) {
//         for (int i = 0; i < 2; i++) {
//             int j = 0;
//             do {
//                 float fileSize = dataSize * objTypeSize * 1.725; // ~6.9 bytes per int
//                 memUse += fileSize + (4000 - ((int)fileSize % 4000));
//                 ++j;
//             } while (seedTests && j < NUM_TESTS);
//         }
//     }
//     return memUse / 1024 / 1024;
// }

// // /**
// //  * @brief Generates a random array of ints. 
// //  * Used to make data sets for testing in {@link SortTest} without
// //  * writing to a CSV file.
// //  * 
// //  * @param arrLen The length of the array.
// //  * @param arr The array to be filled.
// //  */
// // void SortTest::newRandArr(int arrLen, int arr[]) {
// //     for (int i = 0; i < arrLen; i++) {
// //         arr[i] = numberGenerator();
// //     }
// // }