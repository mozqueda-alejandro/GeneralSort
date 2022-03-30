#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

class FileManager{
    int numberGenerator(int low = 0, int high = 1e+2 + 1);
    bool fileExists(const char* fileName);
public:
    FileManager() = default;
    void newRandArr(int arrLen, int arr[]); // Helper function for improved performance
    void newRandCSV(int arrLen, int arr[] = nullptr);
    void newSortedCSV(int arrLen, int arr[]);
    void newStatsCSV(int arrLen, const std::vector<std::vector<std::string>>& stats, std::string algName = "Sortable");
    void csvToArray(int unsorted[], std::string fileName);
};

#endif // FILE_MANAGER_H