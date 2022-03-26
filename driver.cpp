#include <iostream>
#include <time.h>
#include "SortTest.h"

int main() {
    srand(time(0));

    Selection<int>   select;
    // Insertion<int>   insert;
    // Bubble<int>      bubble;
    // Merge<int>       merge;
    // Quick<int>       quick;
    // Radix<int>       radix;
    
    SortTest<Selection<int>>     test(select);
    test.run();
    // SortTest<Insertion<int>>  test(insert);
    // test.run();
    // SortTest<Bubble<int>>     test(bubble);
    // test.run();
    // SortTest<Merge<int>>      test(merge);
    // test.run();
    // SortTest<Quick<int>>      test(quick);
    // test.run();
    // SortTest<Radix<int>>      test(radix);
    // test.run();

    return 0;
}