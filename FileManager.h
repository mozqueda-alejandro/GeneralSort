#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

class FileManager{
    int NUM_TESTS; // Copy of SortTest.cpp constant. Keeps count of repeated tests of the same type (sort type, data size)
    bool allowDups; // Allows for creation of duplicate CSV files for tests with seeded data
    static const bool uniqueFirstFile = false; // If true, first CSV file will not contain <testNum> suffix

    int numberGenerator(int low = 0, int high = 1e+6 + 1);
    bool fileExists(const char* fileName);
    std::string fileNameGenerator(std::string sortInfo, int arrLen);
    std::string fileNameGenerator(std::string algName, int arrLen, std::string sortType, int testNum = -1);
public:
    FileManager() = default;
    FileManager(int NUM_TESTS, bool allowDups);

    void newRandArr(int arrLen, int arr[]); // Helper function for improved performance
    std::string newRandCSV(int arrLen, std::string algName = "<algorithm>");
    void newSortedCSV(int arrLen, int arr[], std::string algName = "<algorithm>");
    void newStatsCSV(int arrLen, const std::vector<std::vector<std::string>>& stats, std::string algName);
    void csvToArray(int unsorted[], std::string fileName);
};

#endif // FILE_MANAGER_H