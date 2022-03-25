#include "SortTest.h"

template<class SortType>
void SortTest::run(SortType algorithm) {
    int test[1000];
    FileManager f;
    f.fillCSV(1000);
    f.readCSV(test, "unsorted1000.csv");

    Selection<int> s;
    s.sort(test, 1000);
    f.fillCSV(1000, test);
    s.sort(test, 1000);

    // READ TEST
    for (int i = 0; i < 20; i++) {
        std::cout << "num " << i << ": " << test[i] << std::endl;
    }
    for (int i = 980; i < 1000; i++) {
        std::cout << "num " << i << ": " << test[i] << std::endl;
    }
    
    // SortType algorithm;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            auto start = std::chrono::high_resolution_clock::now();
            std::ios_base::sync_with_stdio(false); // unsync the I/O of C and C++.
            
            algorithm.sort();
            
            auto end = std::chrono::high_resolution_clock::now();
            double sortTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
            sortTime *= 1e-9;
            std::cout << "Time taken: " << std::fixed << sortTime << std::setprecision(9);
            std::cout << " seconds" << std::endl;
            /*
            Selection object;
            Insertion object;
            QuickSort object;

            readfile1 into const array

            for (10 repeats)
                copy const array
                start time
                    sort method(&arraycopy) override
                end time
                pass stats from sort object to sortTester

                
            */
        }
    }
   
        

}