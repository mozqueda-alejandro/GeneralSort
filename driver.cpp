#include <iostream>
#include "SortTest.h"
#include "Selection.h"
#include "Insertion.h"
#include "Quick.h"


int main() {
    Selection<int> sel;
    Insertion<int> ins;
    // Bubble<int> bub;
    // Merge<int> mer;
    // Quick<int> qui;
    
    SortTest test;
    test.run(sel);
    test.run(ins);


    return 0;
}

// std::cout << "Time taken: " << std::fixed << sortTime << std::setprecision(9);
// std::cout << " seconds" << std::endl;
// return 0;