#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <sstream>
#include <fstream>

class FileManager{
    
    int numberGenerator(int low = 0, int high = 1e+6 + 1);
public:
    FileManager() = default;
    void fillCSV(int arrLen, int sorted[] = nullptr);
    void readCSV(int unsorted[], std::string fileName);
    // void fillRandCSV(int fileLen);
    // void fillSortedCSV(int sorted[], int sortedLen);
};

#endif // FILE_MANAGER_H