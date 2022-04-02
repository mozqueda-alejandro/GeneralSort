#include "SortTest.h"

int NUM_RUNS = 0; // Fix global scope

/**
 * @brief Construct a new SortTest object
 * 
 * @param alg The sorting algorithm to be tested.
 * @param rand Determines if only one data set will be repeatedly run or if tests will be run with different data sets.
 */
template<class SortType>
SortTest<SortType>::SortTest(const SortType& alg, bool rand/* = false*/) : 
    algorithm(alg),
    seedTests(rand)
{
    initVars();
    ++NUM_RUNS;
}

template<class SortType>
void SortTest<SortType>::initVars() {
    totalSortTime = 0;
    totalComparisons = 0;
    totalSwaps = 0;
    numSorts = 0;
}

/**
 * @brief Runs all tests for the sorting algorithm.
 */
template<class SortType>
void SortTest<SortType>::run() {
    float memUse = approxMemUse();
    if (memUse > 5) {
        std::cout << "Memory use of " << memUse << " MB is too high for this test.\n";
        return;
    }

    std::vector<std::vector<std::string>> stats;
    stats.push_back(std::vector<std::string>{"Sort Type", "Sort Time", "Comparisons", "Swaps"});

    for (const auto dataSize : EnumData::All) {
        FileManager fileManager(NUM_TESTS, seedTests); // Must be instantiated everytime average stats are collected
        int constArr[dataSize];
        int arr[dataSize];
        if (!seedTests) {
            std::string unsortedCSV = fileManager.newRandCSV(dataSize); // Creates ONE random data set per data size
            fileManager.csvToArray(constArr, unsortedCSV);
        }

        for (int i = 0; i < 2; i++) {
            std::string sortType = (i == 0) ? "Unsorted" : "Sorted";
            for (int j = 0; j < NUM_TESTS; j++) {
                if (i == 0) {
                    if (seedTests) {
                        std::string unsortedCSV = fileManager.newRandCSV(dataSize, algorithm.getSortName()); // Creates a unique random data set per test (seeded)
                        fileManager.csvToArray(arr, unsortedCSV);
                    } else {
                        std::copy(constArr, constArr + dataSize, arr);
                    }                    
                }
                double sortTime = timeSort(dataSize, arr);
                unsigned int comparisons, swaps; // Unisigned required in case of integer overflow
                std::tie(comparisons, swaps) = algorithm.returnStats();
                stats.push_back(std::vector<std::string>{sortType, std::to_string(sortTime), std::to_string(comparisons), std::to_string(swaps)});
                totalSortTime += sortTime;
                totalComparisons += comparisons;
                totalSwaps += swaps;
                ++numSorts;
                if (seedTests) {
                    if (i == 0) {
                        fileManager.newSortedCSV(dataSize, arr, algorithm.getSortName()); // Creates a new CSV for every unsorted test (seeded)
                    }
                } else {
                    if (i == 0 && j == NUM_TESTS - 1) {
                        fileManager.newSortedCSV(dataSize, arr); // Creates one CSV for all unsorted tests containing the same data (unseeded)
                    }
                }
            }
            std::string aveSortTime, aveComparisons, aveSwaps;
            sortType += " Average";
            aveSortTime = formatFloat(totalSortTime / numSorts);
            aveComparisons = formatFloat(totalComparisons / numSorts);
            aveSwaps = formatFloat(totalSwaps / numSorts);
            stats.push_back(std::vector<std::string>{sortType, aveSortTime, aveComparisons, aveSwaps});
            initVars();
        }
        fileManager.newStatsCSV(dataSize, stats, algorithm.getSortName());
        stats.erase(stats.begin() + 1, stats.end());
    }
}

/**
 * @brief Runs the sort algorithm on the given array.
 * 
 * @param arrLen The size of the array.
 * @param arr The array to sort.
 * @return double Runtime needed to sort the array.
 */
template<class SortType>
double SortTest<SortType>::timeSort(int arrLen, int arr[]) {
    auto start = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
    
    algorithm.sort(arrLen, arr);
    
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() * 1e-9;
}

/**
 * @brief Formats a float to have no trailing zeroes or decimals.
 * 
 * @param floatVal The number to format.
 * @return std::string The formatted number.
 */
template<class SortType>
std::string SortTest<SortType>::formatFloat(const float& floatVal) {
    std::string floatStr = std::to_string(floatVal);
    if(floatStr.find('.') != std::string::npos) {
        floatStr = floatStr.substr(0, floatStr.find_last_not_of('0') + 1);
        if(floatStr.find('.') == floatStr.size() - 1) {
            floatStr.pop_back();
        }
    }
    return floatStr;
}

/**
 * @brief Calculates the approximate memory use of testing an algorithm.
 * 
 * @return float Approximate memory use in MB.
 */
template<class SortType>
float SortTest<SortType>::approxMemUse() {
    float memUse = 0.0f; // in bytes
    int objTypeSize = sizeof(typename SortType::type);
    for (const auto dataSize : EnumData::All) {
        for (int i = 0; i < 2; i++) {
            int j = 0;
            do {
                float fileSize = dataSize * objTypeSize * 1.725; // ~6.9 bytes per int
                memUse += fileSize + (4000 - ((int)fileSize % 4000));
                ++j;
            } while (seedTests && j < NUM_TESTS);
        }
    }
    return memUse / 1024 / 1024;
}