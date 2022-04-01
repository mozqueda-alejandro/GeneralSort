//Created by ALejandro Mozqueda

#include <iostream>
#include <time.h>
#include "SortTest.h"

int main() {
    // srand(time(0));

    Selection<int>   select;
    Insertion<int>   insert;
    // Bubble<int>      bubble;
    // Merge<int>       merge;
    Quick<int>       quick;
    // Radix<int>       radix;
    
    SortTest<Selection<int>>  test1(select);
    test1.run();
    SortTest<Insertion<int>>  test2(insert);
    test2.run();
    // SortTest<Bubble<int>>     test3(bubble);
    // test3.run();
    // SortTest<Merge<int>>      test4(merge);
    // test4.run();
    SortTest<Quick<int>>      test5(quick);
    test5.run();
    // SortTest<Radix<int>>      test6(radix);
    // test6.run();

    return 0;
}