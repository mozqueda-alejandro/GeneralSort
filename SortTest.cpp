#include "SortTest.h"


template<class SortType>
SortTest<SortType>::SortTest() {
    initVars();
}
template<class SortType>
SortTest<SortType>::SortTest(const SortType& alg) : algorithm(alg) {
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
    
    FileManager fileManager;

    std::vector<std::vector<std::string>> stats;
    stats.push_back(std::vector<std::string>{"Sort Type", "Sort Time", "Comparisons", "Swaps"});

    for (const auto d : EnumData::All) {
        int constArr[d];
        fileManager.newRandArr(d, constArr);
        // fileManager.newRandCSV(d); // Generates random data every time for unsorted data
        // fileManager.csvToArray(arr, unsortedCSV);

        // If i == 0 tests with unsorted data, else test with sorted data
        for (int i = 0; i < 2; i++) {
            std::string sortType;
            for (int j = 0; j < NUM_TESTS; j++) {
                int arr[d];
                if (i == 0) {
                    std::string unsortedCSV = "unsorted" + std::to_string(d) + ".csv";
                    std::copy(constArr, constArr + d, arr);
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
                if (i == 0 && j == NUM_TESTS - 1) {
                    fileManager.newSortedCSV(d, arr);
                }
            }
            stats.push_back(std::vector<std::string>{sortType + " Average", std::to_string(totalSortTime / numSorts), std::to_string(totalComparisons / numSorts), std::to_string(totalSwaps / numSorts)});
            initVars();
        }
        fileManager.newStatsCSV(d, stats, algorithm.getSortName());
        stats.erase(stats.begin() + 1, stats.end());
    }
}

template<class SortType>
double SortTest<SortType>::timeSort(int arrLen, int arr[]) {
    auto start = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
    
    algorithm.sort(arrLen, arr);
    
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() * 1e-9;
}