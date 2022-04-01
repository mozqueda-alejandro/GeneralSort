#include "SortTest.h"


template<class SortType>
SortTest<SortType>::SortTest(const SortType& alg, bool rand/* = false*/) : 
    algorithm(alg),
    seedTests(rand)
{
    initVars();
}

template<class SortType>
void SortTest<SortType>::initVars() {
    totalSortTime = 0;
    totalComparisons = 0;
    totalSwaps = 0;
    numSorts = 0;
}

template<class SortType>
void SortTest<SortType>::run() {
    float memUse = approxMemUse();
    if (memUse > 5) {
        std::cout << "Memory use of " << memUse << " MB is too high for this test.\n";
        return;
    }
    std::vector<std::vector<std::string>> stats;
    stats.push_back(std::vector<std::string>{"Sort Type", "Sort Time", "Comparisons", "Swaps"});

    for (const auto d : EnumData::All) {
        FileManager fileManager(NUM_TESTS, seedTests); // MUST be instantiated everytime average stats are collected
        int constArr[d];

        if (!seedTests) {
            std::string unsortedCSV = fileManager.newRandCSV(d); // Only creates one random data set per data size
            fileManager.csvToArray(constArr, unsortedCSV);
        }

        // Tests with UNSORTED data if i == 0, else test with SORTED data
        for (int i = 0; i < 2; i++) {
            std::string sortType, aveSortTime, aveComparisons, aveSwaps;
            for (int j = 0; j < NUM_TESTS; j++) {
                int arr[d];
                if (i == 0) {
                    if (seedTests) {
                        std::string unsortedCSV = fileManager.newRandCSV(d, algorithm.getSortName()); // Creates a unique random data set per test (seeded)
                        fileManager.csvToArray(arr, unsortedCSV);
                    } else {
                        std::copy(constArr, constArr + d, arr);
                    }                    
                    sortType = "Unsorted";
                } else {
                    sortType = "Sorted";
                }
                double sortTime = timeSort(d, arr);
                int comparisons, swaps;
                std::tie(comparisons, swaps) = algorithm.returnStats();
                stats.push_back(std::vector<std::string>{sortType, std::to_string(sortTime), std::to_string(comparisons), std::to_string(swaps)});
                totalSortTime += sortTime;
                totalComparisons += comparisons;
                totalSwaps += swaps;
                ++numSorts;
                if (seedTests) {
                    if (i == 0) {
                        fileManager.newSortedCSV(d, arr, algorithm.getSortName()); // Creates a new CSV for every unsorted test (seeded)
                    }
                } else {
                    if (i == 0 && j == NUM_TESTS - 1) {
                        fileManager.newSortedCSV(d, arr); // Creates one CSV for all unsorted tests containing the same data (unseeded)
                    }
                }
            }
            sortType += " Average";
            aveSortTime = formatFloat(std::to_string(totalSortTime / numSorts));
            aveComparisons = formatFloat(std::to_string(totalComparisons / numSorts));
            aveSwaps = formatFloat(std::to_string(totalSwaps / numSorts));
            stats.push_back(std::vector<std::string>{sortType, aveSortTime, aveComparisons, aveSwaps});
            initVars();
        }
        fileManager.newStatsCSV(d, stats, algorithm.getSortName());
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
std::string SortTest<SortType>::formatFloat(std::string floatVal) {
    if(floatVal.find('.') != std::string::npos) {
        floatVal = floatVal.substr(0, floatVal.find_last_not_of('0') + 1);
        if(floatVal.find('.') == floatVal.size() - 1) {
            floatVal.pop_back();
        }
    }
    return floatVal;
}

template<class SortType>
float SortTest<SortType>::approxMemUse() {
    float memUse = 0.0f; // in bytes
    for (const auto dataSize : EnumData::All) {
        for (int i = 0; i < 2; i++) {
            int j = 0;
            do {
                float fileSize = dataSize * 6.9;
                memUse += fileSize + (4000 - ((int)fileSize % 4000));
                ++j;
            } while (seedTests && j < NUM_TESTS);
        }
    }
    // std::cout << "Approximate memory use: " << memUse / 1024 / 1024 << " MB" << std::endl;
    return memUse / 1024 / 1024;
}