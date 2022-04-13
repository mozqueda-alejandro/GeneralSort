// #include "FileManager.h"


// FileManager::FileManager() : 
//     allowDups(false) 
// {}

// /**
//  * @brief Construct a new FileManager object
//  * 
//  * @param numTests Constant passed from {@link SortTest}
//  * @param duplicates Variable passed from 'seedTests' in {@link SortTest}.
//  */
// FileManager::FileManager(int numTests) : 
//     NUM_TESTS(numTests),
//     allowDups(true) 
// {}

// /**
//  * @brief Creates a new CSV file with random data.
//  * 
//  * CSV files have the format "unsorted<arrLen>.csv".
//  * Example: unsorted1000.csv
//  * 
//  * If allowDups is true, then the file names of subsequent
//  * files will have the format "<algName><arrLen>unsorted_<testNum>.csv" 
//  * Example: unsorted1000_test2.csv
//  * 
//  * @param arrLen Amount of numbers to be generated.
//  * @param algName The name of the algorithm.
//  * @return std::string Name of newly generated unsorted CSV file.
//  */
// std::string FileManager::newRandCSV(int arrLen, std::string algName/*= "<algorithm>"*/) {
//     std::string fileName;
//     if (allowDups) {
//         static int testNum = -1;
//         testNum = (testNum + 1) % NUM_TESTS;
//         if (uniqueFirstFile && testNum == 0) {
//             fileName = fileNameGenerator(algName, arrLen, "unsorted");
//         } else {
//             fileName = fileNameGenerator(algName, arrLen, "unsorted", testNum);
//         }
//     } else {
//         fileName = fileNameGenerator("unsorted", arrLen);
//     }
//     if (fileExists(fileName.c_str())) {
//         std::cout << "Unsorted file " << fileName << " already exists." << std::endl;
//         return "";
//     }
//     std::ofstream unsortedcsv(fileName, std::ios::trunc);
//     for (int i = 0; i < arrLen; i++) {
//         int temp = numberGenerator();
//         unsortedcsv << temp;
//         if (i == arrLen - 1) {
//             unsortedcsv << "\n";
//         } else {
//             unsortedcsv << ",";
//         }
//     }
//     unsortedcsv.close();
//     return fileName;
// }

// /**
//  * @brief Creates a new CSV file with sorted data.
//  * 
//  * CSV files have the format "sorted<arrLen>.csv".
//  * Example: sorted1000.csv
//  * 
//  * If allowDups is true, then the file names of subsequent
//  * files will have the format "sorted<arrLen>_<testNum>.csv" 
//  * Example: sorted1000_test2.csv
//  * 
//  * @param arrLen Amount of numbers to be added to the CSV file.
//  * @param arr Array of sorted numbers.
//  * @param algName Name of the algorithm used to sort the data.
//  */
// void FileManager::newSortedCSV(int arrLen, int arr[], std::string algName/*= "<algorithm>"*/) {
//     std::string fileName;
//     if (allowDups) {
//         static int testNum = -1;
//         testNum = (testNum + 1) % NUM_TESTS;
//         if (uniqueFirstFile && testNum == 0) {
//             fileName = fileNameGenerator(algName, arrLen, "sorted");
//         } else {
//             fileName = fileNameGenerator(algName, arrLen, "sorted", testNum);
//         }
//     } else {
//         fileName = fileNameGenerator("sorted", arrLen);
//     }
//     if (fileExists(fileName.c_str())) {
//         std::cout << "Sorted file " << fileName << " already exists." << std::endl;
//         return;
//     }
//     std::ofstream sortedcsv(fileName, std::ios::trunc);
//     for (int i = 0; i < arrLen; i++) {
//         sortedcsv << arr[i];
//         if (i == arrLen - 1) {
//             sortedcsv << "\n";
//         } else {
//             sortedcsv << ",";
//         }
//     }
//     sortedcsv.close();    
// }

// /**
//  * @brief Creates a new CSV file with sorting algorithm data.
//  * CSV files have the format "<algorithm><arrLen>.csv".
//  * Example: Bubble1000.csv
//  * 
//  * @param arrLen Amount of numbers sorted by the algorithm.
//  * @param stats Vector of string vectors. Each vector contains the data for one test.
//  * @param algName Name of sorting algorithm used.
//  */
// void FileManager::newStatsCSV(int arrLen, const std::vector<std::vector<std::string>>& stats, std::string algName) {
//     std::string fileName = fileNameGenerator(algName, arrLen);
//     std::ofstream csvFile(fileName, std::ios::trunc);
//     // stats[0] is the CSV header
//     for (int i = 0; i < stats.size(); i++) {
//         for (int j = 0; j < stats[i].size(); j++) {
//             csvFile << stats[i][j];
//             if (j == stats[i].size() - 1) {
//                 csvFile << "\n";
//             } else {
//                 csvFile << ",";
//             }
//         }
//     }
//     csvFile.close();
// }

// /**
//  * @brief Fill an array with data from a CSV file.
//  * 
//  * @param arr Array to be filled with data.
//  * @param fileName Name of CSV file.
//  */
// void FileManager::csvToArray(int arr[], std::string fileName) {
//     std::string line, chars, data;
//     int counter = 0;
//     std::ifstream unsortedcsv(fileName);
//     if (unsortedcsv.is_open()) {
//         while (std::getline(unsortedcsv, line)) {
//             std::stringstream temp(line);
//             while (std::getline(temp, chars, ',')) {
//                 arr[counter] = std::stoi(chars);
//                 counter++;
//             }
//         }
//     } else {
//         throw std::runtime_error("Unsorted file does not exist.");
//     }
//     unsortedcsv.close();
// }

// /**
//  * @brief Generates a random number between low and high parameters.
//  * 
//  * @param low Lowest number to be generated, defaulted to 0.
//  * @param high Highest number to be generated, defaulted to 1e+6.
//  * @return int Random number between 0 and MAX_RAND.
//  */
// int FileManager::numberGenerator(int low, int high) {
//     return rand() % high + low;
// }

// bool FileManager::fileExists(const char* fileName) {
//     std::ifstream infile(fileName);
//     return infile.good();
// }

// /**
//  * @brief Generates a file name for a CSV file generator.
//  * 
//  * @param sortInfo Prefix of file name.
//  * @param arrLen Size of data set.
//  * @return std::string File name.
//  */
// std::string FileManager::fileNameGenerator(std::string sortInfo, int arrLen) {
//     return sortInfo + std::to_string(arrLen) + ".csv";
// }

// /**
//  * @brief Generates a file name for a CSV file generator.
//  * 
//  * @param algName Name of sorting algorithm used.
//  * @param arrLen Size of data set.
//  * @param sortType Determines if data is sorted or unsorted.
//  * @param testNum Number of test, defaulted to -1.
//  * @return std::string File name.
//  */
// std::string FileManager::fileNameGenerator(std::string algName, int arrLen, std::string sortType, int testNum/* = -1*/) {
//     if (testNum == -1) {
//         return algName + std::to_string(arrLen) + sortType + ".csv";
//     } else {
//         return algName + std::to_string(arrLen) + sortType + "_test" + std::to_string(testNum + 1) + ".csv";
//     }
// }