#include "FileManager.h"

// FileManager::FileManager() {

// }

void FileManager::newRandCSV(int arrLen, int arr[]/*= nullptr*/) {
    std::string fileName = "unsorted" + std::to_string(arrLen) + ".csv";
    std::ofstream unsortedcsv(fileName, std::ios::trunc);
    for (int i = 0; i < arrLen; i++) {
        int temp = numberGenerator();
        unsortedcsv << temp;
        if (arr != nullptr) {
            arr[i] = temp;
        }
        if (i == arrLen - 1) {
            unsortedcsv << "\n";
        } else {
            unsortedcsv << ",";
        }
    }
    unsortedcsv.close();
}

void FileManager::newSortedCSV(int arrLen, int arr[]) {
    std::string fileName = "sorted" + std::to_string(arrLen) + ".csv";
    std::ofstream sortedcsv(fileName, std::ios::trunc);
    for (int i = 0; i < arrLen; i++) {
        sortedcsv << arr[i];
        if (i == arrLen - 1) {
            sortedcsv << "\n";
        } else {
            sortedcsv << ",";
        }
    }
    sortedcsv.close();    
}

void FileManager::newStatsCSV(int arrLen, const std::vector<std::vector<std::string>>& stats, std::string algName) {
    std::string fileName = algName + std::to_string(arrLen) + ".csv";
    std::ofstream csvFile(fileName, std::ios::trunc);
    // stats[0] is the CSV header
    for (int i = 0; i < stats.size(); i++) {
        for (int j = 0; j < stats[i].size(); j++) {
            csvFile << stats[i][j];
            if (j == stats[i].size() - 1) {
                csvFile << "\n";
            } else {
                csvFile << ",";
            }
        }
    }
    csvFile.close();
}

void FileManager::csvToArray(int unsorted[], std::string fileName) {
    std::string line, chars, data;
    int counter = 0;
    std::ifstream unsortedcsv(fileName);
    if (unsortedcsv.is_open()) {
        while (std::getline(unsortedcsv, line)) {
            std::stringstream temp(line);
            while (std::getline(temp, chars, ',')) {
                unsorted[counter] = std::stoi(chars);
                counter++;
            }
        }
    } else {
        throw "exception";
    }
    unsortedcsv.close();
}

int FileManager::numberGenerator(int low, int high) {
    return rand() % high + low;
}