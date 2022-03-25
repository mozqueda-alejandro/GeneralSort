#include "FileManager.h"

// FileManager::FileManager() {

// }

void FileManager::fillCSV(int arrLen, int sorted[]) {
    std::string fileName;
    // sorted[] == nullptr if no array parameter is passed
    if (sorted == nullptr) fileName = "un";
    fileName += "sorted" + std::to_string(arrLen) + ".csv";
    std::ofstream csvFile(fileName, std::ios::trunc);
    for (int i = 0; i < arrLen; i++) {
        if (sorted == nullptr) {
            csvFile << numberGenerator();
        } else {
            csvFile << sorted[i];
        }
        if (i == arrLen - 1) {
            csvFile << "\n";
        } else {
            csvFile << ",";
        }
    }
    csvFile.close();
}

void FileManager::readCSV(int unsorted[], std::string fileName) {
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



// void FileManager::fillRandCSV(int fileLen) {
//     std::string fileName = "unsorted" + std::to_string(fileLen) + ".csv";
//     std::ofstream unsortedcsv(fileName, std::ios::trunc);
//     for (int i = 0; i < fileLen; i++) {
//         unsortedcsv << numberGenerator();
//         if (i == fileLen - 1) {
//             unsortedcsv << "\n";
//         } else {
//             unsortedcsv << ",";
//         }
//     }
//     unsortedcsv.close();
// }
// void FileManager::fillSortedCSV(int sorted[], int sortedLen) {
//     int counter = 0;
//     std::string fileName = "sorted" + std::to_string(sortedLen) + ".csv";
//     std::ofstream sortedcsv(fileName, std::ios::trunc);
//     for (int i = 0; i < sortedLen; i++) {
//         sortedcsv << sorted[i];
//         if (i == sortedLen - 1) {
//             sortedcsv << "\n";
//         } else {
//             sortedcsv << ",";
//         }
//     }
//     sortedcsv.close();    
// }