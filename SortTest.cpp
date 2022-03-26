#include "SortTest.h"


template<class SortType>
SortTest<SortType>::SortTest() {
    initVars();
}
template<class SortType>
SortTest<SortType>::SortTest(SortType alg) : algorithm(alg) {
    initVars();
}
template<class SortType>
void SortTest<SortType>::initVars() {
    totalRuntime = 0;
    totalComparisons = 0;
    totalSwaps = 0;
    numSorts = 0;
}

template<class SortType>
void SortTest<SortType>::run() {
    
    FileManager fileManager;

    std::vector<std::vector<std::string>> stats;
    stats.push_back(std::vector<std::string>{"Sort Time", "Comparisons", "Swaps"});
    
    for (const auto d : EnumData::All) {
        int arr[d];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < NUM_TESTS; j++) {
                if (i == 0) {
                    // Tests with sorted and unsorted data for NUM_TESTS times
                    std::string unsortedCSV = "unsorted" + std::to_string(d) + ".csv";
                    fileManager.newRandCSV(d); // Generates random data every time for unsorted data
                    fileManager.csvToArray(arr, unsortedCSV);
                }
                std::cout << i << ") " << j << "-" << arr[0] << std::endl;
                double sortTime = timeSort(d, arr);
                int comparisons, swaps;
                std::tie(comparisons, swaps) = algorithm.returnStats();
                stats.push_back(std::vector<std::string>{std::to_string(sortTime), std::to_string(comparisons), std::to_string(swaps)});
                if (i == 0 && j == NUM_TESTS - 1) {
                    fileManager.newSortedCSV(d, arr);
                }
            }
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